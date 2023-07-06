/*!
 * \file iis2mdc_enums.h
 * \brief IIS2MDC Register Enums.
 * \note Do not edit: Generated using Reginald.
 */

#ifndef IIS2MDC_ENUMS_H_
#define IIS2MDC_ENUMS_H_

// ==== Shared Enums ===========================================================

// ==== CFG_REG_A Enums ========================================================

/** @brief Operating mode selection. */
enum iis2mdc_md {
  /** @brief Continuous-acqusition mode. */
  IIS2MDC_MD_CONTINUOUS = 0x0U,
  /** @brief Single-acquisition mode. */
  IIS2MDC_MD_SINGLE = 0x1U,
  /** @brief Idle mode. SPI/I2C are active (default). */
  IIS2MDC_MD_IDLE = 0x3U,
};

/** @brief Output data rate selection. */
enum iis2mdc_odr {
  /** @brief 10Hz (default). */
  IIS2MDC_ODR_10HZ = 0x0U,
  /** @brief 20Hz. */
  IIS2MDC_ODR_20HZ = 0x1U,
  /** @brief 50Hz. */
  IIS2MDC_ODR_50HZ = 0x2U,
  /** @brief 100Hz. */
  IIS2MDC_ODR_100HZ = 0x3U,
};

// ==== CFG_REG_B Enums ========================================================

/** @brief Selects the frequency of the set pulse (default 0). */
enum iis2mdc_set_freq {
  /** @brief Set pulse released every 63 ODR. */
  IIS2MDC_SET_FREQ_63_ODR = 0x0U,
  /** @brief Set pulse released only at power on, after PD condition */
  IIS2MDC_SET_FREQ_PD = 0x1U,
};

// ==== INT_CTRL_REG Enums =====================================================

/** @brief Configures interrupt in pulsed or latched configuration */
enum iis2mdc_int_mode {
  /** @brief Pulsed (default) */
  IIS2MDC_INT_MODE_PULSED = 0x0U,
  /** @brief Latched */
  IIS2MDC_INT_MODE_LATCHED = 0x1U,
};

/** @brief Interrupt active-high/low. Default value: 0 */
enum iis2mdc_int_polarity {
  /** @brief Active low (default) */
  IIS2MDC_INT_POLARITY_ACTIVE_LOW = 0x0U,
  /** @brief Active high */
  IIS2MDC_INT_POLARITY_ACTIVE_HIGH = 0x1U,
};

#endif /* IIS2MDC_ENUMS_H_ */
