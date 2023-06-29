# IS31FL3194 Driver

Andrea Ronco
PBL, D-ITET, ETH Zürich

## Overview

Generic (Hardware/OS agnostic) driver.

## Usage:

** TODO **

## Usage: Development

 - The driver and unit tests can be compiled and run via make:

```bash
# Compile + Run unit tests:
$ make all

# Clean:
$ make clean
```
 - All unit tests are found in `test/`. Additional test sources need to be added to the makefile.
 - All code should be formatted according to the `.clang-format` file provided:

```bash
$ make format
```

 - For LSP support using `clangd`, a `compile_commands.json` can be generated using [bear](https://github.com/rizsotto/Bear):

```bash
$ make clean
$ bear -- make
```
