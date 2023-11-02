#ifndef IIS2MDC_H
#define IIS2MDC_H

#include "iis2mdc_enums.h"
#include "iis2mdc_reg_utils.h"
#include "iis2mdc_regs.h"
#include <stdbool.h>
#include <stdint.h>

// ======== General Definitions ================================================

/**
 * @brief Driver error codes
 */
typedef enum {
  E_IIS2MDC_SUCCESS = 0,            //!< Success
  E_IIS2MDC_NULLPTR_ERR = (1 << 0), //!< Nullpointer error
  E_IIS2MDC_COM_ERR = (1 << 1),     //!< Communication error
  E_IIS2MDC_CONFIG_ERR = (1 << 2),  //!< Configuration error
  E_IIS2MDC_ERR = (1 << 3),         //!< Other error
} iis2mdc_err_t;

#define IIS2MDC_I2C_ADR_7BIT = (0x1E);

// ======== Configuration ======================================================

/** @brief Hard-iron offset configuration*/
struct iis2mdc_offset_cfg {
  int16_t offset_x;
  int16_t offset_y;
  int16_t offset_z;
};

/** @brief Device configuration */
struct iis2mdc_cfg {
  // CFG_A
  /** @brief Magnetic sensor operating mode */
  enum iis2mdc_md op_mode;
  /** @brief Magnetic sensor output data rate */
  enum iis2mdc_odr odr;
  /** @brief Enable Low power mode */
  bool low_power_en;
  /** @brief Soft-Reset sensor */
  bool soft_rst;
  /** @brief Reboot sensor */
  bool reboot;
  /** @brief Enable sensor temperature compensation */
  bool comp_temp_en;

  // CFG_B
  /** @brief Enable low-pass filter */
  bool lpf_en;
  /** @brief Enable hard-iron offset cancellation */
  bool offset_cancel_en;
  /** @brief Set-pulse signal is realeased only on power-on (instead of every 63 ODR)*/
  bool set_pulse_only_power_on;
  /** @brief Interrupt block checks for conditions after the offset is applied */
  bool int_after_offset;
  /** @brief Enable offset cancellation for one-shot mode */
  bool offset_cancel_one_shot_en;

  // CFG_C
  /** @brief Enable self-test */
  bool self_test_en;
  /** @brief Invert byte order of output data */
  bool byte_order_invert;
  /** @brief If true, tried to prevent race conditions when data is read while the sensor updates it */
  bool latch_data;
  /** @brief Disable I2C interface, only SPI is supported */
  bool i2c_disable;
};

/** @brief Device interrupt configuration */
struct iis2mdc_int_cfg {
  // CFG_C
  /** @brief Enable interrupt generation on data ready */
  bool drdy_on_pin;
  /** @brief Enable interrupt generation on magnetic field conditions */
  bool int_on_pin;

  // INT_CRTL
  /** @brief Global interrupt enable */
  bool int_en;
  /** @brief Interrupt latched or pulsed */
  bool int_latched;
  /** @brief Interrupt active high */
  bool int_active_high;
  /** @brief Interrupt detection for x axis enabled */
  bool int_x_en;
  /** @brief Interrupt detection for y axis enabled */
  bool int_y_en;
  /** @brief Interrupt detection for z axis enabled */
  bool int_z_en;

  /** @brief Interrupt threshold. Value is common for all three axes. Unsigned (it is absolute value) */
  uint16_t int_threshold;
};

// ======== Handle Definition ==================================================

/**
 * @brief Device Handle struct.
 * Represents a single physical device. Holds the hardware-specific interface functions,
 * and device configuration.
 */
struct iis2mdc_h {
  // === Interface function pointers. Required. ===
  /**
   * @brief Device-specific read-register functions
   * @warning Required!
   *
   * @param reg_adr Register address at which to start reading.
   * @param n Number of registers to read.
   * @param buf Buffer to store results.
   * @return @ref E_IIS2MDC_SUCCESS if read was successful, otherwise @ref E_IIS2MDC_COM_ERR.
   */
  iis2mdc_err_t (*read_regs)(uint8_t reg_adr, uint32_t n, uint8_t *buf);

  /**
   * @brief Device-specific write-register functions
   * @warning Required!
   *
   * @param reg_adr Register address at which to start writing.
   * @param n Number of registers to write.
   * @param buf Buffer of data to hold.
   * @return @ref E_IIS2MDC_SUCCESS if write was successful, otherwise @ref E_IIS2MDC_COM_ERR.
   */
  iis2mdc_err_t (*write_regs)(uint8_t reg_adr, uint32_t n, const uint8_t *buf);

  // === Interface function pointers. Optional. ===

  /**
   * @brief Pointer to logging function.
   * Called by the driver to log status and error messages, with an optional integer
   * variable to log. Note that the string does not contain any formatting specifiers,
   * and should be logged as follows (if has_int_arg is true):
   *
   * printf("%s: %s %i", is_err ? "ERR" : "LOG", msg, arg);
   *
   * @param msg the log message
   * @param is_err indicates if this is an error message
   * @param has_int_arg indicates if this message is accompanied by an integer variable to log.
   * @param arg the integer variable to log if has_int_arg is true.
   */
  //   void (*log)(char *msg, bool is_err, bool has_int_arg, uint32_t arg);
};

// ======== Function Prototypes ================================================

/**
 * @brief Reset the device
 *
 * @param h Device handle
 * @return @ref E_IIS2MDC_SUCCESS if reset was successful, otherwise an error code from @ref E_IIS2MDC_COM_ERR.
 */
iis2mdc_err_t iis2mdc_reset(const struct iis2mdc_h *h);

/**
 * @brief Initialize the device
 *
 * @param h Device handle
 * @param cfg Device configuration
 * @return @ref E_IIS2MDC_SUCCESS if initialization was successful, otherwise an error code from @ref E_IIS2MDC_COM_ERR.
 */
iis2mdc_err_t iis2mdc_init(const struct iis2mdc_h *h, const struct iis2mdc_cfg *cfg);

/**
 * @brief Basic configuration of the device
 * @note Already called by @ref iis2mdc_init
 *
 * @param h Device handle
 * @param cfg Device configuration
 * @return @ref E_IIS2MDC_SUCCESS if configuration was successful, otherwise an error code from @ref E_IIS2MDC_COM_ERR.
 */
iis2mdc_err_t iis2mdc_config(const struct iis2mdc_h *h, const struct iis2mdc_cfg *cfg);

/**
 * @brief Configure device interrupts
 *
 *  @param h Device handle
 * @param cfg Interrupt configuration
 * @return @ref E_IIS2MDC_SUCCESS if configuration was successful, otherwise an error code from @ref E_IIS2MDC_COM_ERR.
 */
iis2mdc_err_t iis2mdc_cfg_interupt(const struct iis2mdc_h *h, const struct iis2mdc_int_cfg *cfg);

/**
 * @brief Configure Hard-iron offsets
 *
 * @param h Device handle
 * @param cfg Offset configuration
 * @return @ref E_IIS2MDC_SUCCESS if configuration was successful, otherwise an error code from @ref E_IIS2MDC_COM_ERR.
 */
iis2mdc_err_t iis2mdc_cfg_offset(const struct iis2mdc_h *h, const struct iis2mdc_offset_cfg *cfg);

/**
 * @brief Read magnetometer data
 *
 * @param h Device handle
 * @param data Pointer to data buffer to store results. 3x 16-bit signed integers are required.
 * @return @ref E_IIS2MDC_SUCCESS if read was successful, otherwise an error code from @ref E_IIS2MDC_COM_ERR.
 */
iis2mdc_err_t iis2mdc_read_mag(const struct iis2mdc_h *h, int16_t *data);

/**
 * @brief Read temperature data. The nominal sensitivity is 8 LSB/°C.
 *
 * @param h Device handle
 * @param temp Pointer to data buffer to store results. 16-bit signed integer is required.
 * @return @ref E_IIS2MDC_SUCCESS if read was successful, otherwise an error code from @ref E_IIS2MDC_COM_ERR.
 */
iis2mdc_err_t iis2mdc_read_temp(const struct iis2mdc_h *h, int16_t *temp);
#endif // IIS2MDC_H
