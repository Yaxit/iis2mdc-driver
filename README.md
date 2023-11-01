# IIS2MDC Driver

Andrea Ronco
PBL, D-ITET, ETH Zürich

## Overview

Generic (Hardware/OS agnostic) driver.

## Reginald

All register-manipulation code is automatically generated using [Reginald](https://github.com/schilkp/reginald) from
[`iis2mdc_regs.yaml`]. Run `make all` to regenerate. This does not have to be done when using the driver as-is.
