#
# IIS2MDC makefile
# Philipp Schilk, 2022
# Free to use with no restrictions but no guarantees.
#
#
################################################################################
#               ____  _____ _____ _____ ___ _   _  ____ ____
#              / ___|| ____|_   _|_   _|_ _| \ | |/ ___/ ___|
#              \___ \|  _|   | |   | |  | ||  \| | |  _\___ \
#               ___) | |___  | |   | |  | || |\  | |_| |___) |
#              |____/|_____| |_|   |_| |___|_| \_|\____|____/
#
#################################################################################

# Compiler + Flags
CC=gcc
LDFLAGS=
CFLAGS=-Wall -Wextra -Wpedantic -Werror=vla -fsanitize=address -g -Isrc -Iinc -Itest/Unity -I. -Itest/util
DEPFLAGS=-MMD -MP -MF $(BUILDDIR)/$*.d

# Sources:
SOURCES=src/iis2mdc.c

# Automatically generated sources lists usually do not have to be changed:
TEST_SOURCES=$(wildcard test/*.c)
TESTS=$(addprefix $(BUILDDIR)/,$(TEST_SOURCES:.c=.out))
OBJECTS=$(addprefix $(BUILDDIR)/,$(SOURCES:.c=.o))
DEPENDENCIES=$(addprefix $(BUILDDIR)/,$(SOURCES:.c=.d))
DEPENDENCIES+=$(addprefix $(BUILDDIR)/,$(TEST_SOURCES:.c=.d))

BUILDDIR=build

# Set to '@' to supress commands being echoed
SILENT?=

# Reginald commit to use:
REGINALD_COMMIT_LOCK=80ee99a

# Files generated by reginald:
REGINALD_OUTPUT_FILES= inc/iis2mdc_regs.h inc/iis2mdc_enums.h inc/iis2mdc_reg_utils.h
REGINALD_OUTPUT_FILES+= inc/iis2mdc_emb_regs.h inc/iis2mdc_emb_enums.h inc/iis2mdc_emb_reg_utils.h

# Reginald location:
REGINALD_REPO=scripts/reginald
REGINALD=$(REGINALD_REPO)/run.py
REGINALD_PYTHON=$(REGINALD_REPO)/env/bin/python


################################################################################
#         ____ ___  __  __ ____ ___ _        _  _____ ___ ___  _   _
#        / ___/ _ \|  \/  |  _ \_ _| |      / \|_   _|_ _/ _ \| \ | |
#       | |  | | | | |\/| | |_) | || |     / _ \ | |  | | | | |  \| |
#       | |__| |_| | |  | |  __/| || |___ / ___ \| |  | | |_| | |\  |
#        \____\___/|_|  |_|_|  |___|_____/_/   \_\_| |___\___/|_| \_|
#
################################################################################

.PHONY: all
all: run_tests

.PHONY: run_tests
run_tests: build_tests
	@echo "Running Test Suits....."
	-python3 scripts/run_tests.py $(TESTS)

.PHONY: build_tests
build_tests: $(TESTS)

.PHONY: clean
clean:
	rm -rf $(BUILDDIR)

.PHONY: clean_all
clean_all: clean
	rm $(REGINALD_OUTPUT_FILES)
	rm $(REGINALD_REPO) -rf

# Link tests:
$(BUILDDIR)/%.out: $(BUILDDIR)/%.o $(OBJECTS)
	@echo "Linking $@.."
	$(SILENT) $(CC) $(CFLAGS) $^ -o $@

# Compile sources and test sources
$(BUILDDIR)/%.o: %.c makefile $(REGINALD_OUTPUT_FILES)
	@mkdir -p $(dir $@)
	$(SILENT) $(CC) -c $(CFLAGS) $(DEPFLAGS) $*.c -o $@


################################################################################
#                   _   _ _____ ___ _     ___ _______   __
#                  | | | |_   _|_ _| |   |_ _|_   _\ \ / /
#                  | | | | | |  | || |    | |  | |  \ V /
#                  | |_| | | |  | || |___ | |  | |   | |
#                   \___/  |_| |___|_____|___| |_|   |_|
#
################################################################################

.PHONY: format
format:
	python3 scripts/clang_format.py

# Generate documentation using doxygen:
.PHONY: doc
doc:
	doxygen
	firefox doc/html/index.html


# Generate register header files using reginald:
inc/iis2mdc_regs.h inc/iis2mdc_enums.h inc/iis2mdc_reg_utils.h &: iis2mdc_regs.yaml $(REGINALD)
	$(SILENT) $(REGINALD_PYTHON) $(REGINALD) iis2mdc_regs.yaml c.funcpack inc/ --no-field-enum-prefix
	$(SILENT) clang-format -i -style=file inc/iis2mdc_regs.h inc/iis2mdc_enums.h inc/iis2mdc_reg_utils.h

# Setup the correct version of reginald:
$(REGINALD): | $(REGINALD_REPO)
	@echo ""
	@echo "==== Installing Reginald: Reginald checkout... =========================================="
	@echo ""
	$(SILENT) git -C $(REGINALD_REPO) checkout $(REGINALD_COMMIT_LOCK)
	@echo ""
	@echo "==== Installing reginald dependencies into venv... ======================================"
	@echo ""
	$(SILENT) $(REGINALD_PYTHON) -m pip install -r scripts/reginald/requirements.txt
	@echo ""
	@echo "==== Reginald Ready! ===================================================================="
	@echo ""

$(REGINALD_REPO):
	@echo ""
	@echo "==== Installing Reginald: Cloning Reginald repo... ======================================"
	@echo ""
	$(SILENT) git clone git@github.com:schilkp/reginald.git scripts/reginald
	@echo ""
	@echo "==== Setting up python venv... =========================================================="
	@echo ""
	$(SILENT) python -m venv $(REGINALD_REPO)/env

# Keep dependencies around, make them an explicit target:
$(DEPENDENCIES):

# Keep object files and output files:
.PRECIOUS: $(BUILDDIR)/%.out
.PRECIOUS: $(BUILDDIR)/%.o

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(MAKECMDGOALS),format)
ifneq ($(MAKECMDGOALS),compile_commands)
include $(DEPENDENCIES)
endif
endif
endif