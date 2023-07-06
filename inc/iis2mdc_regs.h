/*!
 * \file iis2mdc_regs.h
 * \brief IIS2MDC Registers.
 * \note Do not edit: Generated using Reginald.
 */

#ifndef IIS2MDC_REGS_H_
#define IIS2MDC_REGS_H_

#include "iis2mdc_enums.h"
#include <stdint.h>

// ==== Register Addresses =====================================================
#define IIS2MDC_REG_OFFSET_X_REG_L                                                                                     \
  (0x45U) //!< OFFSET_X_REG_L Address (16bit two's complement offset to compensate environmental/board effects.)
#define IIS2MDC_REG_OFFSET_X_REG_H                                                                                     \
  (0x46U) //!< OFFSET_X_REG_H Address (16bit two's complement offset to compensate environmental/board effects.)
#define IIS2MDC_REG_OFFSET_Y_REG_L                                                                                     \
  (0x47U) //!< OFFSET_Y_REG_L Address (16bit two's complement offset to compensate environmental/board effects.)
#define IIS2MDC_REG_OFFSET_Y_REG_H                                                                                     \
  (0x48U) //!< OFFSET_Y_REG_H Address (16bit two's complement offset to compensate environmental/board effects.)
#define IIS2MDC_REG_OFFSET_Z_REG_L                                                                                     \
  (0x49U) //!< OFFSET_Z_REG_L Address (16bit two's complement offset to compensate environmental/board effects.)
#define IIS2MDC_REG_OFFSET_Z_REG_H                                                                                     \
  (0x4AU) //!< OFFSET_Z_REG_H Address (16bit two's complement offset to compensate environmental/board effects.)
#define IIS2MDC_REG_WHO_AM_I       (0x4FU) //!< WHO_AM_I Address (Device identification register.)
#define IIS2MDC_REG_CFG_REG_A      (0x60U) //!< CFG_REG_A Address
#define IIS2MDC_REG_CFG_REG_B      (0x61U) //!< CFG_REG_B Address
#define IIS2MDC_REG_CFG_REG_C      (0x62U) //!< CFG_REG_C Address
#define IIS2MDC_REG_INT_CTRL_REG   (0x63U) //!< INT_CTRL_REG Address
#define IIS2MDC_REG_INT_SOURCE_REG (0x64U) //!< INT_SOURCE_REG Address
#define IIS2MDC_REG_INT_THS_L_REG                                                                                      \
  (0x65U) //!< INT_THS_L_REG Address (This register contains the least significant bits of the threshold value chosen
          //!< for the interrupt. Threshold is common for all axes, and both positive and negative sides.)
#define IIS2MDC_REG_INT_THS_H_REG                                                                                      \
  (0x66U) //!< INT_THS_H_REG Address (This register contains the most significant bits of the threshold value chosen for
          //!< the interrupt. Threshold is common for all axes, and both positive and negative sides.)
#define IIS2MDC_REG_STATUS_REG     (0x67U) //!< STATUS_REG Address
#define IIS2MDC_REG_OUTX_L_REG     (0x68U) //!< OUTX_L_REG Address
#define IIS2MDC_REG_OUTX_H_REG     (0x69U) //!< OUTX_H_REG Address
#define IIS2MDC_REG_OUTY_L_REG     (0x6AU) //!< OUTY_L_REG Address
#define IIS2MDC_REG_OUTY_H_REG     (0x6BU) //!< OUTY_H_REG Address
#define IIS2MDC_REG_OUTZ_L_REG     (0x6CU) //!< OUTZ_L_REG Address
#define IIS2MDC_REG_OUTZ_H_REG     (0x6DU) //!< OUTZ_H_REG Address
#define IIS2MDC_REG_TEMP_OUT_L_REG (0x6EU) //!< TEMP_OUT_L_REG Address
#define IIS2MDC_REG_TEMP_OUT_H_REG (0x6FU) //!< TEMP_OUT_H_REG Address

// ==== OFFSET_X_REG_L =========================================================

#define IIS2MDC_REG_OFFSET_X_REG_L__RESETVAL (0x0U) //!< OFFSET_X_REG_L Reset Value

/**
 * @brief OFFSET_X_REG_L Register Struct
 * Address: 0x45.
 * Use \ref IIS2MDC_OFFSET_X_REG_L_FUNCS or \ref IIS2MDC_GENERICFUNCS to convert this struct to and from it's packed
 * binary form. 16bit two's complement offset to compensate environmental/board effects.
 */
struct iis2mdc_reg_offset_x_reg_l {
  uint8_t val : 8;
};

// ==== OFFSET_X_REG_H =========================================================

#define IIS2MDC_REG_OFFSET_X_REG_H__RESETVAL (0x0U) //!< OFFSET_X_REG_H Reset Value

/**
 * @brief OFFSET_X_REG_H Register Struct
 * Address: 0x46.
 * Use \ref IIS2MDC_OFFSET_X_REG_H_FUNCS or \ref IIS2MDC_GENERICFUNCS to convert this struct to and from it's packed
 * binary form. 16bit two's complement offset to compensate environmental/board effects.
 */
struct iis2mdc_reg_offset_x_reg_h {
  uint8_t val : 8;
};

// ==== OFFSET_Y_REG_L =========================================================

#define IIS2MDC_REG_OFFSET_Y_REG_L__RESETVAL (0x0U) //!< OFFSET_Y_REG_L Reset Value

/**
 * @brief OFFSET_Y_REG_L Register Struct
 * Address: 0x47.
 * Use \ref IIS2MDC_OFFSET_Y_REG_L_FUNCS or \ref IIS2MDC_GENERICFUNCS to convert this struct to and from it's packed
 * binary form. 16bit two's complement offset to compensate environmental/board effects.
 */
struct iis2mdc_reg_offset_y_reg_l {
  uint8_t val : 8;
};

// ==== OFFSET_Y_REG_H =========================================================

#define IIS2MDC_REG_OFFSET_Y_REG_H__RESETVAL (0x0U) //!< OFFSET_Y_REG_H Reset Value

/**
 * @brief OFFSET_Y_REG_H Register Struct
 * Address: 0x48.
 * Use \ref IIS2MDC_OFFSET_Y_REG_H_FUNCS or \ref IIS2MDC_GENERICFUNCS to convert this struct to and from it's packed
 * binary form. 16bit two's complement offset to compensate environmental/board effects.
 */
struct iis2mdc_reg_offset_y_reg_h {
  uint8_t val : 8;
};

// ==== OFFSET_Z_REG_L =========================================================

#define IIS2MDC_REG_OFFSET_Z_REG_L__RESETVAL (0x0U) //!< OFFSET_Z_REG_L Reset Value

/**
 * @brief OFFSET_Z_REG_L Register Struct
 * Address: 0x49.
 * Use \ref IIS2MDC_OFFSET_Z_REG_L_FUNCS or \ref IIS2MDC_GENERICFUNCS to convert this struct to and from it's packed
 * binary form. 16bit two's complement offset to compensate environmental/board effects.
 */
struct iis2mdc_reg_offset_z_reg_l {
  uint8_t val : 8;
};

// ==== OFFSET_Z_REG_H =========================================================

#define IIS2MDC_REG_OFFSET_Z_REG_H__RESETVAL (0x0U) //!< OFFSET_Z_REG_H Reset Value

/**
 * @brief OFFSET_Z_REG_H Register Struct
 * Address: 0x4A.
 * Use \ref IIS2MDC_OFFSET_Z_REG_H_FUNCS or \ref IIS2MDC_GENERICFUNCS to convert this struct to and from it's packed
 * binary form. 16bit two's complement offset to compensate environmental/board effects.
 */
struct iis2mdc_reg_offset_z_reg_h {
  uint8_t val : 8;
};

// ==== WHO_AM_I ===============================================================

#define IIS2MDC_REG_WHO_AM_I__RESETVAL (0x40U) //!< WHO_AM_I Reset Value

/**
 * @brief WHO_AM_I Register Struct
 * Address: 0x4F.
 * Use \ref IIS2MDC_WHO_AM_I_FUNCS or \ref IIS2MDC_GENERICFUNCS to convert this struct to and from it's packed binary
 * form. Device identification register.
 */
struct iis2mdc_reg_who_am_i {
  uint8_t id : 8;
};

// ==== CFG_REG_A ==============================================================

#define IIS2MDC_REG_CFG_REG_A__RESETVAL (0x3U) //!< CFG_REG_A Reset Value

/**
 * @brief CFG_REG_A Register Struct
 * Address: 0x60.
 * Use \ref IIS2MDC_CFG_REG_A_FUNCS or \ref IIS2MDC_GENERICFUNCS to convert this struct to and from it's packed binary
 * form.
 */
struct iis2mdc_reg_cfg_reg_a {
  /** @brief Operating mode selection. */
  enum iis2mdc_md md : 2;
  /** @brief Output data rate selection. */
  enum iis2mdc_odr odr : 2;
  /** @brief Set to 1 to enable low-power mode. */
  uint8_t lp : 1;
  /** @brief Set to 1 to reset. Flash memory content is not affected. */
  uint8_t soft_rst : 1;
  /** @brief Set to 1 to reboot memory content */
  uint8_t reboot : 1;
  /** @brief Temperature compensation enable. This bit MUST be set to 1 for correct operation. */
  uint8_t comp_temp_en : 1;
};

// ==== CFG_REG_B ==============================================================

#define IIS2MDC_REG_CFG_REG_B__RESETVAL (0x0U) //!< CFG_REG_B Reset Value

/**
 * @brief CFG_REG_B Register Struct
 * Address: 0x61.
 * Use \ref IIS2MDC_CFG_REG_B_FUNCS or \ref IIS2MDC_GENERICFUNCS to convert this struct to and from it's packed binary
 * form.
 */
struct iis2mdc_reg_cfg_reg_b {
  /** @brief Low-pass filter enable. BW: ODR/2 when LP=0, BW: ODR/4 when LP=1 */
  uint8_t lpf : 1;
  /** @brief Set to 1 to enable offset cancellation in single mode only. */
  uint8_t off_canc : 1;
  /** @brief Selects the frequency of the set pulse (default 0). */
  enum iis2mdc_set_freq set_freq : 1;
  /** @brief If 1, the interrupt block recognition checks data after the hard-iron correction to discover the interrupt
   * (default 0) */
  uint8_t int_on_dataoff : 1;
  /** @brief Enables offset cancellation in single measurement mode. The OFF_CANC bit must be set to 1 when enabling
   * offset cancellation in single measurement mode (default 0) */
  uint8_t off_canc_one_shot : 1;
};

// ==== CFG_REG_C ==============================================================

#define IIS2MDC_REG_CFG_REG_C__RESETVAL (0x0U) //!< CFG_REG_C Reset Value

#define IIS2MDC_REG_CFG_REG_C__ALWAYSWRITE_MASK (0x84U) //!< CFG_REG_C Always Write Mask
#define IIS2MDC_REG_CFG_REG_C__ALWAYSWRITE_VAL  (0x0U)  //!< CFG_REG_C Always Write Value

/**
 * @brief CFG_REG_C Register Struct
 * Address: 0x62.
 * Use \ref IIS2MDC_CFG_REG_C_FUNCS or \ref IIS2MDC_GENERICFUNCS to convert this struct to and from it's packed binary
 * form.
 */
struct iis2mdc_reg_cfg_reg_c {
  /** @brief If 1, the data-ready signal (Zyxda bit in STATUS_REG (67h)) is driven on the INT/DRDY pin. The INT/DRDY pin
   * is configured in push-pull output mode. Default value: 0 */
  uint8_t drdy_on_pin : 1;
  /** @brief Self-test enable. Default value: 0 */
  uint8_t self_test : 1;
  /** @brief Big/little endian data selection. Default value: 0 */
  uint8_t ble : 1;
  /** @brief Block data update. If enable, grants that high and low parts of the data belong to the same sample. Default
   * value: 0 */
  uint8_t bdu : 1;
  /** @brief Disable I2C interface. If 1, I2C interface is inhibited and only SPI can be used. Default value: 0 */
  uint8_t i2c_dis : 1;
  /** @brief If 1, the INTERRUPT signal (INT bit in INT_SOURCE_REG (64h)) is driven on the INT/DRDY pin. The INT/DRDY
   * pin is configured in push-pull output mode. Default value: 0 */
  uint8_t int_on_pin : 1;
};

// ==== INT_CTRL_REG ===========================================================

#define IIS2MDC_REG_INT_CTRL_REG__RESETVAL (0xE0U) //!< INT_CTRL_REG Reset Value

#define IIS2MDC_REG_INT_CTRL_REG__ALWAYSWRITE_MASK (0x18U) //!< INT_CTRL_REG Always Write Mask
#define IIS2MDC_REG_INT_CTRL_REG__ALWAYSWRITE_VAL  (0x0U)  //!< INT_CTRL_REG Always Write Value

/**
 * @brief INT_CTRL_REG Register Struct
 * Address: 0x63.
 * Use \ref IIS2MDC_INT_CTRL_REG_FUNCS or \ref IIS2MDC_GENERICFUNCS to convert this struct to and from it's packed
 * binary form.
 */
struct iis2mdc_reg_int_ctrl_reg {
  /** @brief Interrupt enable. Default value: 0 */
  uint8_t int_en : 1;
  /** @brief Configures interrupt in pulsed or latched configuration */
  enum iis2mdc_int_mode int_mode : 1;
  /** @brief Interrupt active-high/low. Default value: 0 */
  enum iis2mdc_int_polarity int_polarity : 1;
  /** @brief Enable interrupt generation on Z axis. Default value: 1 */
  uint8_t int_z_en : 1;
  /** @brief Enable interrupt generation on Y axis. Default value: 1 */
  uint8_t int_y_en : 1;
  /** @brief Enable interrupt generation on X axis. Default value: 1 */
  uint8_t int_x_en : 1;
};

// ==== INT_SOURCE_REG =========================================================

/**
 * @brief INT_SOURCE_REG Register Struct
 * Address: 0x64.
 * Use \ref IIS2MDC_INT_SOURCE_REG_FUNCS or \ref IIS2MDC_GENERICFUNCS to convert this struct to and from it's packed
 * binary form. Interrupt source register.
 * @note when interrupt is latched, rall bits are reset upon reading this register.
 */
struct iis2mdc_reg_int_source_reg {
  /** @brief Interrupt active. Default value: 0 */
  uint8_t int_active : 1;
  /** @brief Magnetic data overrun. Default value: 0 */
  uint8_t mroi : 1;
  /** @brief Z negative threshold. Default value: 0 */
  uint8_t nth_z : 1;
  /** @brief Y negative threshold. Default value: 0 */
  uint8_t nth_y : 1;
  /** @brief X negative threshold. Default value: 0 */
  uint8_t nth_x : 1;
  /** @brief Z positive threshold. Default value: 0 */
  uint8_t pth_z : 1;
  /** @brief Y positive threshold. Default value: 0 */
  uint8_t pth_y : 1;
  /** @brief X positive threshold. Default value: 0 */
  uint8_t pth_x : 1;
};

// ==== INT_THS_L_REG ==========================================================

#define IIS2MDC_REG_INT_THS_L_REG__RESETVAL (0x0U) //!< INT_THS_L_REG Reset Value

/**
 * @brief INT_THS_L_REG Register Struct
 * Address: 0x65.
 * Use \ref IIS2MDC_INT_THS_L_REG_FUNCS or \ref IIS2MDC_GENERICFUNCS to convert this struct to and from it's packed
 * binary form. This register contains the least significant bits of the threshold value chosen for the interrupt.
 * Threshold is common for all axes, and both positive and negative sides.
 */
struct iis2mdc_reg_int_ths_l_reg {
  /** @brief Threshold value. Default value: 0 */
  uint8_t ths : 8;
};

// ==== INT_THS_H_REG ==========================================================

#define IIS2MDC_REG_INT_THS_H_REG__RESETVAL (0x0U) //!< INT_THS_H_REG Reset Value

/**
 * @brief INT_THS_H_REG Register Struct
 * Address: 0x66.
 * Use \ref IIS2MDC_INT_THS_H_REG_FUNCS or \ref IIS2MDC_GENERICFUNCS to convert this struct to and from it's packed
 * binary form. This register contains the most significant bits of the threshold value chosen for the interrupt.
 * Threshold is common for all axes, and both positive and negative sides.
 */
struct iis2mdc_reg_int_ths_h_reg {
  /** @brief Threshold value. Default value: 0 */
  uint8_t ths : 8;
};

// ==== STATUS_REG =============================================================

/**
 * @brief STATUS_REG Register Struct
 * Address: 0x67.
 * Use \ref IIS2MDC_STATUS_REG_FUNCS or \ref IIS2MDC_GENERICFUNCS to convert this struct to and from it's packed binary
 * form.
 */
struct iis2mdc_reg_status_reg {
  /** @brief X-axis new data available. Default value: 0 */
  uint8_t xda : 1;
  /** @brief Y-axis new data available. Default value: 0 */
  uint8_t yda : 1;
  /** @brief Z-axis new data available. Default value: 0 */
  uint8_t zda : 1;
  /** @brief X, Y and Z-axis new data available. Default value: 0 */
  uint8_t zyxda : 1;
  /** @brief X-axis data overrun. Default value: 0 */
  uint8_t xor : 1;
  /** @brief Y-axis data overrun. Default value: 0 */
  uint8_t yor : 1;
  /** @brief Z-axis data overrun. Default value: 0 */
  uint8_t zor : 1;
  /** @brief X, Y and Z-axis data overrun. Default value: 0 */
  uint8_t zyxor : 1;
};

// ==== OUTX_L_REG =============================================================

/**
 * @brief OUTX_L_REG Register Struct
 * Address: 0x68.
 * Use \ref IIS2MDC_OUTX_L_REG_FUNCS or \ref IIS2MDC_GENERICFUNCS to convert this struct to and from it's packed binary
 * form.
 */
struct iis2mdc_reg_outx_l_reg {
  uint8_t outx : 8;
};

// ==== OUTX_H_REG =============================================================

/**
 * @brief OUTX_H_REG Register Struct
 * Address: 0x69.
 * Use \ref IIS2MDC_OUTX_H_REG_FUNCS or \ref IIS2MDC_GENERICFUNCS to convert this struct to and from it's packed binary
 * form.
 */
struct iis2mdc_reg_outx_h_reg {
  uint8_t outx : 8;
};

// ==== OUTY_L_REG =============================================================

/**
 * @brief OUTY_L_REG Register Struct
 * Address: 0x6A.
 * Use \ref IIS2MDC_OUTY_L_REG_FUNCS or \ref IIS2MDC_GENERICFUNCS to convert this struct to and from it's packed binary
 * form.
 */
struct iis2mdc_reg_outy_l_reg {
  uint8_t outy : 8;
};

// ==== OUTY_H_REG =============================================================

/**
 * @brief OUTY_H_REG Register Struct
 * Address: 0x6B.
 * Use \ref IIS2MDC_OUTY_H_REG_FUNCS or \ref IIS2MDC_GENERICFUNCS to convert this struct to and from it's packed binary
 * form.
 */
struct iis2mdc_reg_outy_h_reg {
  uint8_t outy : 8;
};

// ==== OUTZ_L_REG =============================================================

/**
 * @brief OUTZ_L_REG Register Struct
 * Address: 0x6C.
 * Use \ref IIS2MDC_OUTZ_L_REG_FUNCS or \ref IIS2MDC_GENERICFUNCS to convert this struct to and from it's packed binary
 * form.
 */
struct iis2mdc_reg_outz_l_reg {
  uint8_t outz : 8;
};

// ==== OUTZ_H_REG =============================================================

/**
 * @brief OUTZ_H_REG Register Struct
 * Address: 0x6D.
 * Use \ref IIS2MDC_OUTZ_H_REG_FUNCS or \ref IIS2MDC_GENERICFUNCS to convert this struct to and from it's packed binary
 * form.
 */
struct iis2mdc_reg_outz_h_reg {
  uint8_t outz : 8;
};

// ==== TEMP_OUT_L_REG =========================================================

/**
 * @brief TEMP_OUT_L_REG Register Struct
 * Address: 0x6E.
 * Use \ref IIS2MDC_TEMP_OUT_L_REG_FUNCS or \ref IIS2MDC_GENERICFUNCS to convert this struct to and from it's packed
 * binary form.
 */
struct iis2mdc_reg_temp_out_l_reg {
  uint8_t temp : 8;
};

// ==== TEMP_OUT_H_REG =========================================================

/**
 * @brief TEMP_OUT_H_REG Register Struct
 * Address: 0x6F.
 * Use \ref IIS2MDC_TEMP_OUT_H_REG_FUNCS or \ref IIS2MDC_GENERICFUNCS to convert this struct to and from it's packed
 * binary form.
 */
struct iis2mdc_reg_temp_out_h_reg {
  uint8_t temp : 8;
};

#endif /* IIS2MDC_REGS_H_ */
