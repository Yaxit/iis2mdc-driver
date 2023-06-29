/*!
 * \file iis2mdc_reg_utils.h
 * \brief IIS2MDC Registers Utilities.
 * \note Do not edit: Generated using Reginald.
 */

#ifndef IIS2MDC_REG_UTILS_H_
#define IIS2MDC_REG_UTILS_H_

#include "iis2mdc_enums.h"
#include "iis2mdc_regs.h"
#include <stdint.h>

/**
 * @brief Lookup a register's reset value
 * @param adr register address
 * @param val buffer to store reset value. invalid if function returns 0.
 * @return 1 if a register exists at this address and has a resetval, 0 otherwise.
 */
static inline int iis2mdc_lookup_resetval(uint8_t adr, uint8_t *val) {
  switch (adr) {
    case IIS2MDC_REG_OFFSET_X_REG_L:
      *val = IIS2MDC_REG_OFFSET_X_REG_L__RESETVAL;
      return 1;
    case IIS2MDC_REG_OFFSET_X_REG_H:
      *val = IIS2MDC_REG_OFFSET_X_REG_H__RESETVAL;
      return 1;
    case IIS2MDC_REG_OFFSET_Y_REG_L:
      *val = IIS2MDC_REG_OFFSET_Y_REG_L__RESETVAL;
      return 1;
    case IIS2MDC_REG_OFFSET_Y_REG_H:
      *val = IIS2MDC_REG_OFFSET_Y_REG_H__RESETVAL;
      return 1;
    case IIS2MDC_REG_OFFSET_Z_REG_L:
      *val = IIS2MDC_REG_OFFSET_Z_REG_L__RESETVAL;
      return 1;
    case IIS2MDC_REG_OFFSET_Z_REG_H:
      *val = IIS2MDC_REG_OFFSET_Z_REG_H__RESETVAL;
      return 1;
    case IIS2MDC_REG_WHO_AM_I:
      *val = IIS2MDC_REG_WHO_AM_I__RESETVAL;
      return 1;
    case IIS2MDC_REG_CFG_REG_A:
      *val = IIS2MDC_REG_CFG_REG_A__RESETVAL;
      return 1;
    case IIS2MDC_REG_CFG_REG_B:
      *val = IIS2MDC_REG_CFG_REG_B__RESETVAL;
      return 1;
    case IIS2MDC_REG_CFG_REG_C:
      *val = IIS2MDC_REG_CFG_REG_C__RESETVAL;
      return 1;
    case IIS2MDC_REG_INT_CTRL_REG:
      *val = IIS2MDC_REG_INT_CTRL_REG__RESETVAL;
      return 1;
    case IIS2MDC_REG_INT_THS_L_REG:
      *val = IIS2MDC_REG_INT_THS_L_REG__RESETVAL;
      return 1;
    case IIS2MDC_REG_INT_THS_H_REG:
      *val = IIS2MDC_REG_INT_THS_H_REG__RESETVAL;
      return 1;
    default:
      return 0;
  }
}

/**
 * \defgroup IIS2MDC_GENERICFUNCS Generic register modify/pack/unpack utilities.
 * @{
 */

// Disable clang-format for this section, since _Generic formatting is buggy up to v14 and
// v15 is too new to require.
// clang-format off

/**
 * @brief Modify a register's binary representation
 * All fields are replaced with the struct's values.
 * All 'always_write' bits (if any) are forced to the correct value.
 * All other bits are kept the same.
 * @note This is a generic macro that picks the correct function based on _struct_ptr_'s type.
 * @param _struct_ptr_ struct holding register fields
 * @param _val_ current binary register representation
 * @return packed register representation
 */
#define IIS2MDC_MODIFY(_struct_ptr_, _val_) _Generic((_struct_ptr_), \
    struct iis2mdc_reg_offset_x_reg_l* : iis2mdc_modify_offset_x_reg_l,  \
    struct iis2mdc_reg_offset_x_reg_h* : iis2mdc_modify_offset_x_reg_h,  \
    struct iis2mdc_reg_offset_y_reg_l* : iis2mdc_modify_offset_y_reg_l,  \
    struct iis2mdc_reg_offset_y_reg_h* : iis2mdc_modify_offset_y_reg_h,  \
    struct iis2mdc_reg_offset_z_reg_l* : iis2mdc_modify_offset_z_reg_l,  \
    struct iis2mdc_reg_offset_z_reg_h* : iis2mdc_modify_offset_z_reg_h,  \
    struct iis2mdc_reg_who_am_i* : iis2mdc_modify_who_am_i,  \
    struct iis2mdc_reg_cfg_reg_a* : iis2mdc_modify_cfg_reg_a,  \
    struct iis2mdc_reg_cfg_reg_b* : iis2mdc_modify_cfg_reg_b,  \
    struct iis2mdc_reg_cfg_reg_c* : iis2mdc_modify_cfg_reg_c,  \
    struct iis2mdc_reg_int_ctrl_reg* : iis2mdc_modify_int_ctrl_reg,  \
    struct iis2mdc_reg_int_source_reg* : iis2mdc_modify_int_source_reg,  \
    struct iis2mdc_reg_int_ths_l_reg* : iis2mdc_modify_int_ths_l_reg,  \
    struct iis2mdc_reg_int_ths_h_reg* : iis2mdc_modify_int_ths_h_reg,  \
    struct iis2mdc_reg_status_reg* : iis2mdc_modify_status_reg,  \
    struct iis2mdc_reg_outx_l_reg* : iis2mdc_modify_outx_l_reg,  \
    struct iis2mdc_reg_outx_h_reg* : iis2mdc_modify_outx_h_reg,  \
    struct iis2mdc_reg_outy_l_reg* : iis2mdc_modify_outy_l_reg,  \
    struct iis2mdc_reg_outy_h_reg* : iis2mdc_modify_outy_h_reg,  \
    struct iis2mdc_reg_outz_l_reg* : iis2mdc_modify_outz_l_reg,  \
    struct iis2mdc_reg_outz_h_reg* : iis2mdc_modify_outz_h_reg,  \
    struct iis2mdc_reg_temp_out_l_reg* : iis2mdc_modify_temp_out_l_reg,  \
    struct iis2mdc_reg_temp_out_h_reg* : iis2mdc_modify_temp_out_h_reg  \
  )(_struct_ptr_, _val_)

/**
 * @brief Pack a register's fields into their binary representation
 * All fields are set to the struct's values.
 * All 'always_write' bits (if any) are set to the correct value.
 * All other bits are are set to 0.
 * @note This is a generic macro that picks the correct function based on _struct_ptr_'s type.
 * @param _struct_ptr_r struct holding register fields
 * @return packed register representation
 */
#define IIS2MDC_PACK(_struct_ptr_) _Generic((_struct_ptr_), \
    struct iis2mdc_reg_offset_x_reg_l* : iis2mdc_pack_offset_x_reg_l,  \
    struct iis2mdc_reg_offset_x_reg_h* : iis2mdc_pack_offset_x_reg_h,  \
    struct iis2mdc_reg_offset_y_reg_l* : iis2mdc_pack_offset_y_reg_l,  \
    struct iis2mdc_reg_offset_y_reg_h* : iis2mdc_pack_offset_y_reg_h,  \
    struct iis2mdc_reg_offset_z_reg_l* : iis2mdc_pack_offset_z_reg_l,  \
    struct iis2mdc_reg_offset_z_reg_h* : iis2mdc_pack_offset_z_reg_h,  \
    struct iis2mdc_reg_who_am_i* : iis2mdc_pack_who_am_i,  \
    struct iis2mdc_reg_cfg_reg_a* : iis2mdc_pack_cfg_reg_a,  \
    struct iis2mdc_reg_cfg_reg_b* : iis2mdc_pack_cfg_reg_b,  \
    struct iis2mdc_reg_cfg_reg_c* : iis2mdc_pack_cfg_reg_c,  \
    struct iis2mdc_reg_int_ctrl_reg* : iis2mdc_pack_int_ctrl_reg,  \
    struct iis2mdc_reg_int_source_reg* : iis2mdc_pack_int_source_reg,  \
    struct iis2mdc_reg_int_ths_l_reg* : iis2mdc_pack_int_ths_l_reg,  \
    struct iis2mdc_reg_int_ths_h_reg* : iis2mdc_pack_int_ths_h_reg,  \
    struct iis2mdc_reg_status_reg* : iis2mdc_pack_status_reg,  \
    struct iis2mdc_reg_outx_l_reg* : iis2mdc_pack_outx_l_reg,  \
    struct iis2mdc_reg_outx_h_reg* : iis2mdc_pack_outx_h_reg,  \
    struct iis2mdc_reg_outy_l_reg* : iis2mdc_pack_outy_l_reg,  \
    struct iis2mdc_reg_outy_h_reg* : iis2mdc_pack_outy_h_reg,  \
    struct iis2mdc_reg_outz_l_reg* : iis2mdc_pack_outz_l_reg,  \
    struct iis2mdc_reg_outz_h_reg* : iis2mdc_pack_outz_h_reg,  \
    struct iis2mdc_reg_temp_out_l_reg* : iis2mdc_pack_temp_out_l_reg,  \
    struct iis2mdc_reg_temp_out_h_reg* : iis2mdc_pack_temp_out_h_reg  \
  )(_struct_ptr_)

/**
 * @brief Unpack a register's binary representation into seperate fields
 * @note This is a generic macro that picks the correct function based on _struct_ptr_'s type.
 * @param _struct_ptr_ buffer to store the unpacked fields
 * @param _val_ packed register representation
 */
#define IIS2MDC_UNPACK(_struct_ptr_, _val_) _Generic((_struct_ptr_), \
    struct iis2mdc_reg_offset_x_reg_l* : iis2mdc_unpack_offset_x_reg_l,  \
    struct iis2mdc_reg_offset_x_reg_h* : iis2mdc_unpack_offset_x_reg_h,  \
    struct iis2mdc_reg_offset_y_reg_l* : iis2mdc_unpack_offset_y_reg_l,  \
    struct iis2mdc_reg_offset_y_reg_h* : iis2mdc_unpack_offset_y_reg_h,  \
    struct iis2mdc_reg_offset_z_reg_l* : iis2mdc_unpack_offset_z_reg_l,  \
    struct iis2mdc_reg_offset_z_reg_h* : iis2mdc_unpack_offset_z_reg_h,  \
    struct iis2mdc_reg_who_am_i* : iis2mdc_unpack_who_am_i,  \
    struct iis2mdc_reg_cfg_reg_a* : iis2mdc_unpack_cfg_reg_a,  \
    struct iis2mdc_reg_cfg_reg_b* : iis2mdc_unpack_cfg_reg_b,  \
    struct iis2mdc_reg_cfg_reg_c* : iis2mdc_unpack_cfg_reg_c,  \
    struct iis2mdc_reg_int_ctrl_reg* : iis2mdc_unpack_int_ctrl_reg,  \
    struct iis2mdc_reg_int_source_reg* : iis2mdc_unpack_int_source_reg,  \
    struct iis2mdc_reg_int_ths_l_reg* : iis2mdc_unpack_int_ths_l_reg,  \
    struct iis2mdc_reg_int_ths_h_reg* : iis2mdc_unpack_int_ths_h_reg,  \
    struct iis2mdc_reg_status_reg* : iis2mdc_unpack_status_reg,  \
    struct iis2mdc_reg_outx_l_reg* : iis2mdc_unpack_outx_l_reg,  \
    struct iis2mdc_reg_outx_h_reg* : iis2mdc_unpack_outx_h_reg,  \
    struct iis2mdc_reg_outy_l_reg* : iis2mdc_unpack_outy_l_reg,  \
    struct iis2mdc_reg_outy_h_reg* : iis2mdc_unpack_outy_h_reg,  \
    struct iis2mdc_reg_outz_l_reg* : iis2mdc_unpack_outz_l_reg,  \
    struct iis2mdc_reg_outz_h_reg* : iis2mdc_unpack_outz_h_reg,  \
    struct iis2mdc_reg_temp_out_l_reg* : iis2mdc_unpack_temp_out_l_reg,  \
    struct iis2mdc_reg_temp_out_h_reg* : iis2mdc_unpack_temp_out_h_reg  \
  )(_struct_ptr_, _val_)

// clang-format on

/** @} */

/**
 * \defgroup IIS2MDC_OFFSET_X_REG_L_FUNCS OFFSET_X_REG_L register modify/pack/unpack utilities.
 * @{
 */
/**
 * @brief Modify the 'OFFSET_X_REG_L' register's binary representation
 * All fields are replaced with the struct's values.
 * All 'always_write' bits (if any) are forced to the correct value.
 * All other bits are kept the same.
 * @param r struct holding register fields
 * @param val current binary register representation
 * @return packed register representation
 */
static inline uint8_t iis2mdc_modify_offset_x_reg_l(const struct iis2mdc_reg_offset_x_reg_l *r, uint8_t val) {
  val = (val & ~0xFFU) | (uint8_t)((r->val & 0xFFU) << 0U);
  return val;
}

/**
 * @brief Pack the 'OFFSET_X_REG_L' register's fields into their binary representation
 * All fields are set to the struct's values.
 * All 'always_write' bits (if any) are set to the correct value.
 * All other bits are are set to 0.
 * @param r struct holding register fields
 * @return packed register representation
 */
static inline uint8_t iis2mdc_pack_offset_x_reg_l(const struct iis2mdc_reg_offset_x_reg_l *r) {
  return iis2mdc_modify_offset_x_reg_l(r, 0);
}

/**
 * @brief Unpack the 'OFFSET_X_REG_L' register's binary representation into seperate fields
 * @param r buffer to store the unpacked fields
 * @param val packed register representation
 */
static inline void iis2mdc_unpack_offset_x_reg_l(struct iis2mdc_reg_offset_x_reg_l *r, uint8_t val) {
  r->val = (uint8_t)((val & 0xFFU) >> 0U);
}

/**
 * @brief Unpack the 'OFFSET_X_REG_L' register's binary representation into a struct initialiser.
 * @note use static iis2mdc_unpack_offset_x_reg_l() to unpack into an exsisting struct.
 * Example:
 *   `struct iis2mdc_reg_offset_x_reg_l reg = IIS2MDC_UNPACK_OFFSET_X_REG_L(0xAB);`
 *
 * @param _VAL_ packed register representation
 */
#define IIS2MDC_UNPACK_OFFSET_X_REG_L(_VAL_)                                                                           \
  { .val = (uint8_t)(((_VAL_)&0xFFU) >> 0U), }

/** @} */

/**
 * \defgroup IIS2MDC_OFFSET_X_REG_H_FUNCS OFFSET_X_REG_H register modify/pack/unpack utilities.
 * @{
 */
/**
 * @brief Modify the 'OFFSET_X_REG_H' register's binary representation
 * All fields are replaced with the struct's values.
 * All 'always_write' bits (if any) are forced to the correct value.
 * All other bits are kept the same.
 * @param r struct holding register fields
 * @param val current binary register representation
 * @return packed register representation
 */
static inline uint8_t iis2mdc_modify_offset_x_reg_h(const struct iis2mdc_reg_offset_x_reg_h *r, uint8_t val) {
  val = (val & ~0xFFU) | (uint8_t)((r->val & 0xFFU) << 0U);
  return val;
}

/**
 * @brief Pack the 'OFFSET_X_REG_H' register's fields into their binary representation
 * All fields are set to the struct's values.
 * All 'always_write' bits (if any) are set to the correct value.
 * All other bits are are set to 0.
 * @param r struct holding register fields
 * @return packed register representation
 */
static inline uint8_t iis2mdc_pack_offset_x_reg_h(const struct iis2mdc_reg_offset_x_reg_h *r) {
  return iis2mdc_modify_offset_x_reg_h(r, 0);
}

/**
 * @brief Unpack the 'OFFSET_X_REG_H' register's binary representation into seperate fields
 * @param r buffer to store the unpacked fields
 * @param val packed register representation
 */
static inline void iis2mdc_unpack_offset_x_reg_h(struct iis2mdc_reg_offset_x_reg_h *r, uint8_t val) {
  r->val = (uint8_t)((val & 0xFFU) >> 0U);
}

/**
 * @brief Unpack the 'OFFSET_X_REG_H' register's binary representation into a struct initialiser.
 * @note use static iis2mdc_unpack_offset_x_reg_h() to unpack into an exsisting struct.
 * Example:
 *   `struct iis2mdc_reg_offset_x_reg_h reg = IIS2MDC_UNPACK_OFFSET_X_REG_H(0xAB);`
 *
 * @param _VAL_ packed register representation
 */
#define IIS2MDC_UNPACK_OFFSET_X_REG_H(_VAL_)                                                                           \
  { .val = (uint8_t)(((_VAL_)&0xFFU) >> 0U), }

/** @} */

/**
 * \defgroup IIS2MDC_OFFSET_Y_REG_L_FUNCS OFFSET_Y_REG_L register modify/pack/unpack utilities.
 * @{
 */
/**
 * @brief Modify the 'OFFSET_Y_REG_L' register's binary representation
 * All fields are replaced with the struct's values.
 * All 'always_write' bits (if any) are forced to the correct value.
 * All other bits are kept the same.
 * @param r struct holding register fields
 * @param val current binary register representation
 * @return packed register representation
 */
static inline uint8_t iis2mdc_modify_offset_y_reg_l(const struct iis2mdc_reg_offset_y_reg_l *r, uint8_t val) {
  val = (val & ~0xFFU) | (uint8_t)((r->val & 0xFFU) << 0U);
  return val;
}

/**
 * @brief Pack the 'OFFSET_Y_REG_L' register's fields into their binary representation
 * All fields are set to the struct's values.
 * All 'always_write' bits (if any) are set to the correct value.
 * All other bits are are set to 0.
 * @param r struct holding register fields
 * @return packed register representation
 */
static inline uint8_t iis2mdc_pack_offset_y_reg_l(const struct iis2mdc_reg_offset_y_reg_l *r) {
  return iis2mdc_modify_offset_y_reg_l(r, 0);
}

/**
 * @brief Unpack the 'OFFSET_Y_REG_L' register's binary representation into seperate fields
 * @param r buffer to store the unpacked fields
 * @param val packed register representation
 */
static inline void iis2mdc_unpack_offset_y_reg_l(struct iis2mdc_reg_offset_y_reg_l *r, uint8_t val) {
  r->val = (uint8_t)((val & 0xFFU) >> 0U);
}

/**
 * @brief Unpack the 'OFFSET_Y_REG_L' register's binary representation into a struct initialiser.
 * @note use static iis2mdc_unpack_offset_y_reg_l() to unpack into an exsisting struct.
 * Example:
 *   `struct iis2mdc_reg_offset_y_reg_l reg = IIS2MDC_UNPACK_OFFSET_Y_REG_L(0xAB);`
 *
 * @param _VAL_ packed register representation
 */
#define IIS2MDC_UNPACK_OFFSET_Y_REG_L(_VAL_)                                                                           \
  { .val = (uint8_t)(((_VAL_)&0xFFU) >> 0U), }

/** @} */

/**
 * \defgroup IIS2MDC_OFFSET_Y_REG_H_FUNCS OFFSET_Y_REG_H register modify/pack/unpack utilities.
 * @{
 */
/**
 * @brief Modify the 'OFFSET_Y_REG_H' register's binary representation
 * All fields are replaced with the struct's values.
 * All 'always_write' bits (if any) are forced to the correct value.
 * All other bits are kept the same.
 * @param r struct holding register fields
 * @param val current binary register representation
 * @return packed register representation
 */
static inline uint8_t iis2mdc_modify_offset_y_reg_h(const struct iis2mdc_reg_offset_y_reg_h *r, uint8_t val) {
  val = (val & ~0xFFU) | (uint8_t)((r->val & 0xFFU) << 0U);
  return val;
}

/**
 * @brief Pack the 'OFFSET_Y_REG_H' register's fields into their binary representation
 * All fields are set to the struct's values.
 * All 'always_write' bits (if any) are set to the correct value.
 * All other bits are are set to 0.
 * @param r struct holding register fields
 * @return packed register representation
 */
static inline uint8_t iis2mdc_pack_offset_y_reg_h(const struct iis2mdc_reg_offset_y_reg_h *r) {
  return iis2mdc_modify_offset_y_reg_h(r, 0);
}

/**
 * @brief Unpack the 'OFFSET_Y_REG_H' register's binary representation into seperate fields
 * @param r buffer to store the unpacked fields
 * @param val packed register representation
 */
static inline void iis2mdc_unpack_offset_y_reg_h(struct iis2mdc_reg_offset_y_reg_h *r, uint8_t val) {
  r->val = (uint8_t)((val & 0xFFU) >> 0U);
}

/**
 * @brief Unpack the 'OFFSET_Y_REG_H' register's binary representation into a struct initialiser.
 * @note use static iis2mdc_unpack_offset_y_reg_h() to unpack into an exsisting struct.
 * Example:
 *   `struct iis2mdc_reg_offset_y_reg_h reg = IIS2MDC_UNPACK_OFFSET_Y_REG_H(0xAB);`
 *
 * @param _VAL_ packed register representation
 */
#define IIS2MDC_UNPACK_OFFSET_Y_REG_H(_VAL_)                                                                           \
  { .val = (uint8_t)(((_VAL_)&0xFFU) >> 0U), }

/** @} */

/**
 * \defgroup IIS2MDC_OFFSET_Z_REG_L_FUNCS OFFSET_Z_REG_L register modify/pack/unpack utilities.
 * @{
 */
/**
 * @brief Modify the 'OFFSET_Z_REG_L' register's binary representation
 * All fields are replaced with the struct's values.
 * All 'always_write' bits (if any) are forced to the correct value.
 * All other bits are kept the same.
 * @param r struct holding register fields
 * @param val current binary register representation
 * @return packed register representation
 */
static inline uint8_t iis2mdc_modify_offset_z_reg_l(const struct iis2mdc_reg_offset_z_reg_l *r, uint8_t val) {
  val = (val & ~0xFFU) | (uint8_t)((r->val & 0xFFU) << 0U);
  return val;
}

/**
 * @brief Pack the 'OFFSET_Z_REG_L' register's fields into their binary representation
 * All fields are set to the struct's values.
 * All 'always_write' bits (if any) are set to the correct value.
 * All other bits are are set to 0.
 * @param r struct holding register fields
 * @return packed register representation
 */
static inline uint8_t iis2mdc_pack_offset_z_reg_l(const struct iis2mdc_reg_offset_z_reg_l *r) {
  return iis2mdc_modify_offset_z_reg_l(r, 0);
}

/**
 * @brief Unpack the 'OFFSET_Z_REG_L' register's binary representation into seperate fields
 * @param r buffer to store the unpacked fields
 * @param val packed register representation
 */
static inline void iis2mdc_unpack_offset_z_reg_l(struct iis2mdc_reg_offset_z_reg_l *r, uint8_t val) {
  r->val = (uint8_t)((val & 0xFFU) >> 0U);
}

/**
 * @brief Unpack the 'OFFSET_Z_REG_L' register's binary representation into a struct initialiser.
 * @note use static iis2mdc_unpack_offset_z_reg_l() to unpack into an exsisting struct.
 * Example:
 *   `struct iis2mdc_reg_offset_z_reg_l reg = IIS2MDC_UNPACK_OFFSET_Z_REG_L(0xAB);`
 *
 * @param _VAL_ packed register representation
 */
#define IIS2MDC_UNPACK_OFFSET_Z_REG_L(_VAL_)                                                                           \
  { .val = (uint8_t)(((_VAL_)&0xFFU) >> 0U), }

/** @} */

/**
 * \defgroup IIS2MDC_OFFSET_Z_REG_H_FUNCS OFFSET_Z_REG_H register modify/pack/unpack utilities.
 * @{
 */
/**
 * @brief Modify the 'OFFSET_Z_REG_H' register's binary representation
 * All fields are replaced with the struct's values.
 * All 'always_write' bits (if any) are forced to the correct value.
 * All other bits are kept the same.
 * @param r struct holding register fields
 * @param val current binary register representation
 * @return packed register representation
 */
static inline uint8_t iis2mdc_modify_offset_z_reg_h(const struct iis2mdc_reg_offset_z_reg_h *r, uint8_t val) {
  val = (val & ~0xFFU) | (uint8_t)((r->val & 0xFFU) << 0U);
  return val;
}

/**
 * @brief Pack the 'OFFSET_Z_REG_H' register's fields into their binary representation
 * All fields are set to the struct's values.
 * All 'always_write' bits (if any) are set to the correct value.
 * All other bits are are set to 0.
 * @param r struct holding register fields
 * @return packed register representation
 */
static inline uint8_t iis2mdc_pack_offset_z_reg_h(const struct iis2mdc_reg_offset_z_reg_h *r) {
  return iis2mdc_modify_offset_z_reg_h(r, 0);
}

/**
 * @brief Unpack the 'OFFSET_Z_REG_H' register's binary representation into seperate fields
 * @param r buffer to store the unpacked fields
 * @param val packed register representation
 */
static inline void iis2mdc_unpack_offset_z_reg_h(struct iis2mdc_reg_offset_z_reg_h *r, uint8_t val) {
  r->val = (uint8_t)((val & 0xFFU) >> 0U);
}

/**
 * @brief Unpack the 'OFFSET_Z_REG_H' register's binary representation into a struct initialiser.
 * @note use static iis2mdc_unpack_offset_z_reg_h() to unpack into an exsisting struct.
 * Example:
 *   `struct iis2mdc_reg_offset_z_reg_h reg = IIS2MDC_UNPACK_OFFSET_Z_REG_H(0xAB);`
 *
 * @param _VAL_ packed register representation
 */
#define IIS2MDC_UNPACK_OFFSET_Z_REG_H(_VAL_)                                                                           \
  { .val = (uint8_t)(((_VAL_)&0xFFU) >> 0U), }

/** @} */

/**
 * \defgroup IIS2MDC_WHO_AM_I_FUNCS WHO_AM_I register modify/pack/unpack utilities.
 * @{
 */
/**
 * @brief Modify the 'WHO_AM_I' register's binary representation
 * All fields are replaced with the struct's values.
 * All 'always_write' bits (if any) are forced to the correct value.
 * All other bits are kept the same.
 * @param r struct holding register fields
 * @param val current binary register representation
 * @return packed register representation
 */
static inline uint8_t iis2mdc_modify_who_am_i(const struct iis2mdc_reg_who_am_i *r, uint8_t val) {
  val = (val & ~0xFFU) | (uint8_t)((r->id & 0xFFU) << 0U);
  return val;
}

/**
 * @brief Pack the 'WHO_AM_I' register's fields into their binary representation
 * All fields are set to the struct's values.
 * All 'always_write' bits (if any) are set to the correct value.
 * All other bits are are set to 0.
 * @param r struct holding register fields
 * @return packed register representation
 */
static inline uint8_t iis2mdc_pack_who_am_i(const struct iis2mdc_reg_who_am_i *r) {
  return iis2mdc_modify_who_am_i(r, 0);
}

/**
 * @brief Unpack the 'WHO_AM_I' register's binary representation into seperate fields
 * @param r buffer to store the unpacked fields
 * @param val packed register representation
 */
static inline void iis2mdc_unpack_who_am_i(struct iis2mdc_reg_who_am_i *r, uint8_t val) {
  r->id = (uint8_t)((val & 0xFFU) >> 0U);
}

/**
 * @brief Unpack the 'WHO_AM_I' register's binary representation into a struct initialiser.
 * @note use static iis2mdc_unpack_who_am_i() to unpack into an exsisting struct.
 * Example:
 *   `struct iis2mdc_reg_who_am_i reg = IIS2MDC_UNPACK_WHO_AM_I(0xAB);`
 *
 * @param _VAL_ packed register representation
 */
#define IIS2MDC_UNPACK_WHO_AM_I(_VAL_)                                                                                 \
  { .id = (uint8_t)(((_VAL_)&0xFFU) >> 0U), }

/** @} */

/**
 * \defgroup IIS2MDC_CFG_REG_A_FUNCS CFG_REG_A register modify/pack/unpack utilities.
 * @{
 */
/**
 * @brief Modify the 'CFG_REG_A' register's binary representation
 * All fields are replaced with the struct's values.
 * All 'always_write' bits (if any) are forced to the correct value.
 * All other bits are kept the same.
 * @param r struct holding register fields
 * @param val current binary register representation
 * @return packed register representation
 */
static inline uint8_t iis2mdc_modify_cfg_reg_a(const struct iis2mdc_reg_cfg_reg_a *r, uint8_t val) {
  val = (val & ~0x3U) | (uint8_t)((r->md & 0x3U) << 0U);
  val = (val & ~0xCU) | (uint8_t)((r->odr & 0x3U) << 2U);
  val = (val & ~0x10U) | (uint8_t)((r->lp & 0x1U) << 4U);
  val = (val & ~0x20U) | (uint8_t)((r->soft_rst & 0x1U) << 5U);
  val = (val & ~0x40U) | (uint8_t)((r->reboot & 0x1U) << 6U);
  val = (val & ~0x80U) | (uint8_t)((r->comp_temp_en & 0x1U) << 7U);
  return val;
}

/**
 * @brief Pack the 'CFG_REG_A' register's fields into their binary representation
 * All fields are set to the struct's values.
 * All 'always_write' bits (if any) are set to the correct value.
 * All other bits are are set to 0.
 * @param r struct holding register fields
 * @return packed register representation
 */
static inline uint8_t iis2mdc_pack_cfg_reg_a(const struct iis2mdc_reg_cfg_reg_a *r) {
  return iis2mdc_modify_cfg_reg_a(r, 0);
}

/**
 * @brief Unpack the 'CFG_REG_A' register's binary representation into seperate fields
 * @param r buffer to store the unpacked fields
 * @param val packed register representation
 */
static inline void iis2mdc_unpack_cfg_reg_a(struct iis2mdc_reg_cfg_reg_a *r, uint8_t val) {
  r->md = (enum iis2mdc_md)((val & 0x3U) >> 0U);
  r->odr = (enum iis2mdc_odr)((val & 0xCU) >> 2U);
  r->lp = (enum iis2mdc_enable)((val & 0x10U) >> 4U);
  r->soft_rst = (enum iis2mdc_enable)((val & 0x20U) >> 5U);
  r->reboot = (enum iis2mdc_enable)((val & 0x40U) >> 6U);
  r->comp_temp_en = (enum iis2mdc_enable)((val & 0x80U) >> 7U);
}

/**
 * @brief Unpack the 'CFG_REG_A' register's binary representation into a struct initialiser.
 * @note use static iis2mdc_unpack_cfg_reg_a() to unpack into an exsisting struct.
 * Example:
 *   `struct iis2mdc_reg_cfg_reg_a reg = IIS2MDC_UNPACK_CFG_REG_A(0xAB);`
 *
 * @param _VAL_ packed register representation
 */
#define IIS2MDC_UNPACK_CFG_REG_A(_VAL_)                                                                                \
  {                                                                                                                    \
    .md = (enum iis2mdc_md)(((_VAL_)&0x3U) >> 0U), .odr = (enum iis2mdc_odr)(((_VAL_)&0xCU) >> 2U),                    \
    .lp = (enum iis2mdc_enable)(((_VAL_)&0x10U) >> 4U), .soft_rst = (enum iis2mdc_enable)(((_VAL_)&0x20U) >> 5U),      \
    .reboot = (enum iis2mdc_enable)(((_VAL_)&0x40U) >> 6U),                                                            \
    .comp_temp_en = (enum iis2mdc_enable)(((_VAL_)&0x80U) >> 7U),                                                      \
  }

/** @} */

/**
 * \defgroup IIS2MDC_CFG_REG_B_FUNCS CFG_REG_B register modify/pack/unpack utilities.
 * @{
 */
/**
 * @brief Modify the 'CFG_REG_B' register's binary representation
 * All fields are replaced with the struct's values.
 * All 'always_write' bits (if any) are forced to the correct value.
 * All other bits are kept the same.
 * @param r struct holding register fields
 * @param val current binary register representation
 * @return packed register representation
 */
static inline uint8_t iis2mdc_modify_cfg_reg_b(const struct iis2mdc_reg_cfg_reg_b *r, uint8_t val) {
  val = (val & ~0x1U) | (uint8_t)((r->lpf & 0x1U) << 0U);
  val = (val & ~0x2U) | (uint8_t)((r->off_canc & 0x1U) << 1U);
  val = (val & ~0x4U) | (uint8_t)((r->set_freq & 0x1U) << 2U);
  val = (val & ~0x8U) | (uint8_t)((r->int_on_dataoff & 0x1U) << 3U);
  val = (val & ~0x10U) | (uint8_t)((r->off_canc_one_shot & 0x1U) << 4U);
  return val;
}

/**
 * @brief Pack the 'CFG_REG_B' register's fields into their binary representation
 * All fields are set to the struct's values.
 * All 'always_write' bits (if any) are set to the correct value.
 * All other bits are are set to 0.
 * @param r struct holding register fields
 * @return packed register representation
 */
static inline uint8_t iis2mdc_pack_cfg_reg_b(const struct iis2mdc_reg_cfg_reg_b *r) {
  return iis2mdc_modify_cfg_reg_b(r, 0);
}

/**
 * @brief Unpack the 'CFG_REG_B' register's binary representation into seperate fields
 * @param r buffer to store the unpacked fields
 * @param val packed register representation
 */
static inline void iis2mdc_unpack_cfg_reg_b(struct iis2mdc_reg_cfg_reg_b *r, uint8_t val) {
  r->lpf = (enum iis2mdc_enable)((val & 0x1U) >> 0U);
  r->off_canc = (enum iis2mdc_enable)((val & 0x2U) >> 1U);
  r->set_freq = (enum iis2mdc_set_freq)((val & 0x4U) >> 2U);
  r->int_on_dataoff = (enum iis2mdc_enable)((val & 0x8U) >> 3U);
  r->off_canc_one_shot = (enum iis2mdc_enable)((val & 0x10U) >> 4U);
}

/**
 * @brief Unpack the 'CFG_REG_B' register's binary representation into a struct initialiser.
 * @note use static iis2mdc_unpack_cfg_reg_b() to unpack into an exsisting struct.
 * Example:
 *   `struct iis2mdc_reg_cfg_reg_b reg = IIS2MDC_UNPACK_CFG_REG_B(0xAB);`
 *
 * @param _VAL_ packed register representation
 */
#define IIS2MDC_UNPACK_CFG_REG_B(_VAL_)                                                                                \
  {                                                                                                                    \
    .lpf = (enum iis2mdc_enable)(((_VAL_)&0x1U) >> 0U), .off_canc = (enum iis2mdc_enable)(((_VAL_)&0x2U) >> 1U),       \
    .set_freq = (enum iis2mdc_set_freq)(((_VAL_)&0x4U) >> 2U),                                                         \
    .int_on_dataoff = (enum iis2mdc_enable)(((_VAL_)&0x8U) >> 3U),                                                     \
    .off_canc_one_shot = (enum iis2mdc_enable)(((_VAL_)&0x10U) >> 4U),                                                 \
  }

/** @} */

/**
 * \defgroup IIS2MDC_CFG_REG_C_FUNCS CFG_REG_C register modify/pack/unpack utilities.
 * @{
 */
/**
 * @brief Modify the 'CFG_REG_C' register's binary representation
 * All fields are replaced with the struct's values.
 * All 'always_write' bits (if any) are forced to the correct value.
 * All other bits are kept the same.
 * @param r struct holding register fields
 * @param val current binary register representation
 * @return packed register representation
 */
static inline uint8_t iis2mdc_modify_cfg_reg_c(const struct iis2mdc_reg_cfg_reg_c *r, uint8_t val) {
  val &= ~IIS2MDC_REG_CFG_REG_C__ALWAYSWRITE_MASK;
  val |= IIS2MDC_REG_CFG_REG_C__ALWAYSWRITE_VAL;
  val = (val & ~0x1U) | (uint8_t)((r->drdy_on_pin & 0x1U) << 0U);
  val = (val & ~0x2U) | (uint8_t)((r->self_test & 0x1U) << 1U);
  val = (val & ~0x8U) | (uint8_t)((r->ble & 0x1U) << 3U);
  val = (val & ~0x10U) | (uint8_t)((r->bdu & 0x1U) << 4U);
  val = (val & ~0x20U) | (uint8_t)((r->i2c_dis & 0x1U) << 5U);
  val = (val & ~0x40U) | (uint8_t)((r->int_on_pin & 0x1U) << 6U);
  return val;
}

/**
 * @brief Pack the 'CFG_REG_C' register's fields into their binary representation
 * All fields are set to the struct's values.
 * All 'always_write' bits (if any) are set to the correct value.
 * All other bits are are set to 0.
 * @param r struct holding register fields
 * @return packed register representation
 */
static inline uint8_t iis2mdc_pack_cfg_reg_c(const struct iis2mdc_reg_cfg_reg_c *r) {
  return iis2mdc_modify_cfg_reg_c(r, 0);
}

/**
 * @brief Unpack the 'CFG_REG_C' register's binary representation into seperate fields
 * @param r buffer to store the unpacked fields
 * @param val packed register representation
 */
static inline void iis2mdc_unpack_cfg_reg_c(struct iis2mdc_reg_cfg_reg_c *r, uint8_t val) {
  r->drdy_on_pin = (enum iis2mdc_enable)((val & 0x1U) >> 0U);
  r->self_test = (enum iis2mdc_enable)((val & 0x2U) >> 1U);
  r->ble = (enum iis2mdc_enable)((val & 0x8U) >> 3U);
  r->bdu = (enum iis2mdc_enable)((val & 0x10U) >> 4U);
  r->i2c_dis = (enum iis2mdc_enable)((val & 0x20U) >> 5U);
  r->int_on_pin = (enum iis2mdc_enable)((val & 0x40U) >> 6U);
}

/**
 * @brief Unpack the 'CFG_REG_C' register's binary representation into a struct initialiser.
 * @note use static iis2mdc_unpack_cfg_reg_c() to unpack into an exsisting struct.
 * Example:
 *   `struct iis2mdc_reg_cfg_reg_c reg = IIS2MDC_UNPACK_CFG_REG_C(0xAB);`
 *
 * @param _VAL_ packed register representation
 */
#define IIS2MDC_UNPACK_CFG_REG_C(_VAL_)                                                                                \
  {                                                                                                                    \
    .drdy_on_pin = (enum iis2mdc_enable)(((_VAL_)&0x1U) >> 0U),                                                        \
    .self_test = (enum iis2mdc_enable)(((_VAL_)&0x2U) >> 1U), .ble = (enum iis2mdc_enable)(((_VAL_)&0x8U) >> 3U),      \
    .bdu = (enum iis2mdc_enable)(((_VAL_)&0x10U) >> 4U), .i2c_dis = (enum iis2mdc_enable)(((_VAL_)&0x20U) >> 5U),      \
    .int_on_pin = (enum iis2mdc_enable)(((_VAL_)&0x40U) >> 6U),                                                        \
  }

/** @} */

/**
 * \defgroup IIS2MDC_INT_CTRL_REG_FUNCS INT_CTRL_REG register modify/pack/unpack utilities.
 * @{
 */
/**
 * @brief Modify the 'INT_CTRL_REG' register's binary representation
 * All fields are replaced with the struct's values.
 * All 'always_write' bits (if any) are forced to the correct value.
 * All other bits are kept the same.
 * @param r struct holding register fields
 * @param val current binary register representation
 * @return packed register representation
 */
static inline uint8_t iis2mdc_modify_int_ctrl_reg(const struct iis2mdc_reg_int_ctrl_reg *r, uint8_t val) {
  val &= ~IIS2MDC_REG_INT_CTRL_REG__ALWAYSWRITE_MASK;
  val |= IIS2MDC_REG_INT_CTRL_REG__ALWAYSWRITE_VAL;
  val = (val & ~0x1U) | (uint8_t)((r->int_en & 0x1U) << 0U);
  val = (val & ~0x2U) | (uint8_t)((r->int_mode & 0x1U) << 1U);
  val = (val & ~0x4U) | (uint8_t)((r->int_polarity & 0x1U) << 2U);
  val = (val & ~0x20U) | (uint8_t)((r->int_z_en & 0x1U) << 5U);
  val = (val & ~0x40U) | (uint8_t)((r->int_y_en & 0x1U) << 6U);
  val = (val & ~0x80U) | (uint8_t)((r->int_x_en & 0x1U) << 7U);
  return val;
}

/**
 * @brief Pack the 'INT_CTRL_REG' register's fields into their binary representation
 * All fields are set to the struct's values.
 * All 'always_write' bits (if any) are set to the correct value.
 * All other bits are are set to 0.
 * @param r struct holding register fields
 * @return packed register representation
 */
static inline uint8_t iis2mdc_pack_int_ctrl_reg(const struct iis2mdc_reg_int_ctrl_reg *r) {
  return iis2mdc_modify_int_ctrl_reg(r, 0);
}

/**
 * @brief Unpack the 'INT_CTRL_REG' register's binary representation into seperate fields
 * @param r buffer to store the unpacked fields
 * @param val packed register representation
 */
static inline void iis2mdc_unpack_int_ctrl_reg(struct iis2mdc_reg_int_ctrl_reg *r, uint8_t val) {
  r->int_en = (enum iis2mdc_enable)((val & 0x1U) >> 0U);
  r->int_mode = (enum iis2mdc_int_mode)((val & 0x2U) >> 1U);
  r->int_polarity = (enum iis2mdc_int_polarity)((val & 0x4U) >> 2U);
  r->int_z_en = (enum iis2mdc_enable)((val & 0x20U) >> 5U);
  r->int_y_en = (enum iis2mdc_enable)((val & 0x40U) >> 6U);
  r->int_x_en = (enum iis2mdc_enable)((val & 0x80U) >> 7U);
}

/**
 * @brief Unpack the 'INT_CTRL_REG' register's binary representation into a struct initialiser.
 * @note use static iis2mdc_unpack_int_ctrl_reg() to unpack into an exsisting struct.
 * Example:
 *   `struct iis2mdc_reg_int_ctrl_reg reg = IIS2MDC_UNPACK_INT_CTRL_REG(0xAB);`
 *
 * @param _VAL_ packed register representation
 */
#define IIS2MDC_UNPACK_INT_CTRL_REG(_VAL_)                                                                             \
  {                                                                                                                    \
    .int_en = (enum iis2mdc_enable)(((_VAL_)&0x1U) >> 0U), .int_mode = (enum iis2mdc_int_mode)(((_VAL_)&0x2U) >> 1U),  \
    .int_polarity = (enum iis2mdc_int_polarity)(((_VAL_)&0x4U) >> 2U),                                                 \
    .int_z_en = (enum iis2mdc_enable)(((_VAL_)&0x20U) >> 5U),                                                          \
    .int_y_en = (enum iis2mdc_enable)(((_VAL_)&0x40U) >> 6U),                                                          \
    .int_x_en = (enum iis2mdc_enable)(((_VAL_)&0x80U) >> 7U),                                                          \
  }

/** @} */

/**
 * \defgroup IIS2MDC_INT_SOURCE_REG_FUNCS INT_SOURCE_REG register modify/pack/unpack utilities.
 * @{
 */
/**
 * @brief Modify the 'INT_SOURCE_REG' register's binary representation
 * All fields are replaced with the struct's values.
 * All 'always_write' bits (if any) are forced to the correct value.
 * All other bits are kept the same.
 * @param r struct holding register fields
 * @param val current binary register representation
 * @return packed register representation
 */
static inline uint8_t iis2mdc_modify_int_source_reg(const struct iis2mdc_reg_int_source_reg *r, uint8_t val) {
  val = (val & ~0x1U) | (uint8_t)((r->int & 0x1U) << 0U);
  val = (val & ~0x2U) | (uint8_t)((r->mroi & 0x1U) << 1U);
  val = (val & ~0x4U) | (uint8_t)((r->nth_z & 0x1U) << 2U);
  val = (val & ~0x8U) | (uint8_t)((r->nth_y & 0x1U) << 3U);
  val = (val & ~0x10U) | (uint8_t)((r->nth_x & 0x1U) << 4U);
  val = (val & ~0x20U) | (uint8_t)((r->pth_z & 0x1U) << 5U);
  val = (val & ~0x40U) | (uint8_t)((r->pth_y & 0x1U) << 6U);
  val = (val & ~0x80U) | (uint8_t)((r->pth_x & 0x1U) << 7U);
  return val;
}

/**
 * @brief Pack the 'INT_SOURCE_REG' register's fields into their binary representation
 * All fields are set to the struct's values.
 * All 'always_write' bits (if any) are set to the correct value.
 * All other bits are are set to 0.
 * @param r struct holding register fields
 * @return packed register representation
 */
static inline uint8_t iis2mdc_pack_int_source_reg(const struct iis2mdc_reg_int_source_reg *r) {
  return iis2mdc_modify_int_source_reg(r, 0);
}

/**
 * @brief Unpack the 'INT_SOURCE_REG' register's binary representation into seperate fields
 * @param r buffer to store the unpacked fields
 * @param val packed register representation
 */
static inline void iis2mdc_unpack_int_source_reg(struct iis2mdc_reg_int_source_reg *r, uint8_t val) {
  r->int = (enum iis2mdc_enable)((val & 0x1U) >> 0U);
  r->mroi = (enum iis2mdc_enable)((val & 0x2U) >> 1U);
  r->nth_z = (enum iis2mdc_enable)((val & 0x4U) >> 2U);
  r->nth_y = (enum iis2mdc_enable)((val & 0x8U) >> 3U);
  r->nth_x = (enum iis2mdc_enable)((val & 0x10U) >> 4U);
  r->pth_z = (enum iis2mdc_enable)((val & 0x20U) >> 5U);
  r->pth_y = (enum iis2mdc_enable)((val & 0x40U) >> 6U);
  r->pth_x = (enum iis2mdc_enable)((val & 0x80U) >> 7U);
}

/**
 * @brief Unpack the 'INT_SOURCE_REG' register's binary representation into a struct initialiser.
 * @note use static iis2mdc_unpack_int_source_reg() to unpack into an exsisting struct.
 * Example:
 *   `struct iis2mdc_reg_int_source_reg reg = IIS2MDC_UNPACK_INT_SOURCE_REG(0xAB);`
 *
 * @param _VAL_ packed register representation
 */
#define IIS2MDC_UNPACK_INT_SOURCE_REG(_VAL_)                                                                           \
  {                                                                                                                    \
    .int = (enum iis2mdc_enable)(((_VAL_)&0x1U) >> 0U), .mroi = (enum iis2mdc_enable)(((_VAL_)&0x2U) >> 1U),           \
    .nth_z = (enum iis2mdc_enable)(((_VAL_)&0x4U) >> 2U), .nth_y = (enum iis2mdc_enable)(((_VAL_)&0x8U) >> 3U),        \
    .nth_x = (enum iis2mdc_enable)(((_VAL_)&0x10U) >> 4U), .pth_z = (enum iis2mdc_enable)(((_VAL_)&0x20U) >> 5U),      \
    .pth_y = (enum iis2mdc_enable)(((_VAL_)&0x40U) >> 6U), .pth_x = (enum iis2mdc_enable)(((_VAL_)&0x80U) >> 7U),      \
  }

/** @} */

/**
 * \defgroup IIS2MDC_INT_THS_L_REG_FUNCS INT_THS_L_REG register modify/pack/unpack utilities.
 * @{
 */
/**
 * @brief Modify the 'INT_THS_L_REG' register's binary representation
 * All fields are replaced with the struct's values.
 * All 'always_write' bits (if any) are forced to the correct value.
 * All other bits are kept the same.
 * @param r struct holding register fields
 * @param val current binary register representation
 * @return packed register representation
 */
static inline uint8_t iis2mdc_modify_int_ths_l_reg(const struct iis2mdc_reg_int_ths_l_reg *r, uint8_t val) {
  val = (val & ~0xFFU) | (uint8_t)((r->ths & 0xFFU) << 0U);
  return val;
}

/**
 * @brief Pack the 'INT_THS_L_REG' register's fields into their binary representation
 * All fields are set to the struct's values.
 * All 'always_write' bits (if any) are set to the correct value.
 * All other bits are are set to 0.
 * @param r struct holding register fields
 * @return packed register representation
 */
static inline uint8_t iis2mdc_pack_int_ths_l_reg(const struct iis2mdc_reg_int_ths_l_reg *r) {
  return iis2mdc_modify_int_ths_l_reg(r, 0);
}

/**
 * @brief Unpack the 'INT_THS_L_REG' register's binary representation into seperate fields
 * @param r buffer to store the unpacked fields
 * @param val packed register representation
 */
static inline void iis2mdc_unpack_int_ths_l_reg(struct iis2mdc_reg_int_ths_l_reg *r, uint8_t val) {
  r->ths = (uint8_t)((val & 0xFFU) >> 0U);
}

/**
 * @brief Unpack the 'INT_THS_L_REG' register's binary representation into a struct initialiser.
 * @note use static iis2mdc_unpack_int_ths_l_reg() to unpack into an exsisting struct.
 * Example:
 *   `struct iis2mdc_reg_int_ths_l_reg reg = IIS2MDC_UNPACK_INT_THS_L_REG(0xAB);`
 *
 * @param _VAL_ packed register representation
 */
#define IIS2MDC_UNPACK_INT_THS_L_REG(_VAL_)                                                                            \
  { .ths = (uint8_t)(((_VAL_)&0xFFU) >> 0U), }

/** @} */

/**
 * \defgroup IIS2MDC_INT_THS_H_REG_FUNCS INT_THS_H_REG register modify/pack/unpack utilities.
 * @{
 */
/**
 * @brief Modify the 'INT_THS_H_REG' register's binary representation
 * All fields are replaced with the struct's values.
 * All 'always_write' bits (if any) are forced to the correct value.
 * All other bits are kept the same.
 * @param r struct holding register fields
 * @param val current binary register representation
 * @return packed register representation
 */
static inline uint8_t iis2mdc_modify_int_ths_h_reg(const struct iis2mdc_reg_int_ths_h_reg *r, uint8_t val) {
  val = (val & ~0xFFU) | (uint8_t)((r->ths & 0xFFU) << 0U);
  return val;
}

/**
 * @brief Pack the 'INT_THS_H_REG' register's fields into their binary representation
 * All fields are set to the struct's values.
 * All 'always_write' bits (if any) are set to the correct value.
 * All other bits are are set to 0.
 * @param r struct holding register fields
 * @return packed register representation
 */
static inline uint8_t iis2mdc_pack_int_ths_h_reg(const struct iis2mdc_reg_int_ths_h_reg *r) {
  return iis2mdc_modify_int_ths_h_reg(r, 0);
}

/**
 * @brief Unpack the 'INT_THS_H_REG' register's binary representation into seperate fields
 * @param r buffer to store the unpacked fields
 * @param val packed register representation
 */
static inline void iis2mdc_unpack_int_ths_h_reg(struct iis2mdc_reg_int_ths_h_reg *r, uint8_t val) {
  r->ths = (uint8_t)((val & 0xFFU) >> 0U);
}

/**
 * @brief Unpack the 'INT_THS_H_REG' register's binary representation into a struct initialiser.
 * @note use static iis2mdc_unpack_int_ths_h_reg() to unpack into an exsisting struct.
 * Example:
 *   `struct iis2mdc_reg_int_ths_h_reg reg = IIS2MDC_UNPACK_INT_THS_H_REG(0xAB);`
 *
 * @param _VAL_ packed register representation
 */
#define IIS2MDC_UNPACK_INT_THS_H_REG(_VAL_)                                                                            \
  { .ths = (uint8_t)(((_VAL_)&0xFFU) >> 0U), }

/** @} */

/**
 * \defgroup IIS2MDC_STATUS_REG_FUNCS STATUS_REG register modify/pack/unpack utilities.
 * @{
 */
/**
 * @brief Modify the 'STATUS_REG' register's binary representation
 * All fields are replaced with the struct's values.
 * All 'always_write' bits (if any) are forced to the correct value.
 * All other bits are kept the same.
 * @param r struct holding register fields
 * @param val current binary register representation
 * @return packed register representation
 */
static inline uint8_t iis2mdc_modify_status_reg(const struct iis2mdc_reg_status_reg *r, uint8_t val) {
  val = (val & ~0x1U) | (uint8_t)((r->xda & 0x1U) << 0U);
  val = (val & ~0x2U) | (uint8_t)((r->yda & 0x1U) << 1U);
  val = (val & ~0x4U) | (uint8_t)((r->zda & 0x1U) << 2U);
  val = (val & ~0x8U) | (uint8_t)((r->zyxda & 0x1U) << 3U);
  val = (val & ~0x10U) | (uint8_t)((r->xor &0x1U) << 4U);
  val = (val & ~0x20U) | (uint8_t)((r->yor & 0x1U) << 5U);
  val = (val & ~0x40U) | (uint8_t)((r->zor & 0x1U) << 6U);
  val = (val & ~0x80U) | (uint8_t)((r->zyxor & 0x1U) << 7U);
  return val;
}

/**
 * @brief Pack the 'STATUS_REG' register's fields into their binary representation
 * All fields are set to the struct's values.
 * All 'always_write' bits (if any) are set to the correct value.
 * All other bits are are set to 0.
 * @param r struct holding register fields
 * @return packed register representation
 */
static inline uint8_t iis2mdc_pack_status_reg(const struct iis2mdc_reg_status_reg *r) {
  return iis2mdc_modify_status_reg(r, 0);
}

/**
 * @brief Unpack the 'STATUS_REG' register's binary representation into seperate fields
 * @param r buffer to store the unpacked fields
 * @param val packed register representation
 */
static inline void iis2mdc_unpack_status_reg(struct iis2mdc_reg_status_reg *r, uint8_t val) {
  r->xda = (enum iis2mdc_enable)((val & 0x1U) >> 0U);
  r->yda = (enum iis2mdc_enable)((val & 0x2U) >> 1U);
  r->zda = (enum iis2mdc_enable)((val & 0x4U) >> 2U);
  r->zyxda = (enum iis2mdc_enable)((val & 0x8U) >> 3U);
  r->xor = (enum iis2mdc_enable)((val & 0x10U) >> 4U);
  r->yor = (enum iis2mdc_enable)((val & 0x20U) >> 5U);
  r->zor = (enum iis2mdc_enable)((val & 0x40U) >> 6U);
  r->zyxor = (enum iis2mdc_enable)((val & 0x80U) >> 7U);
}

/**
 * @brief Unpack the 'STATUS_REG' register's binary representation into a struct initialiser.
 * @note use static iis2mdc_unpack_status_reg() to unpack into an exsisting struct.
 * Example:
 *   `struct iis2mdc_reg_status_reg reg = IIS2MDC_UNPACK_STATUS_REG(0xAB);`
 *
 * @param _VAL_ packed register representation
 */
#define IIS2MDC_UNPACK_STATUS_REG(_VAL_)                                                                               \
  {                                                                                                                    \
    .xda = (enum iis2mdc_enable)(((_VAL_)&0x1U) >> 0U), .yda = (enum iis2mdc_enable)(((_VAL_)&0x2U) >> 1U),            \
    .zda = (enum iis2mdc_enable)(((_VAL_)&0x4U) >> 2U), .zyxda = (enum iis2mdc_enable)(((_VAL_)&0x8U) >> 3U),          \
    .xor = (enum iis2mdc_enable)(((_VAL_)&0x10U) >> 4U), .yor = (enum iis2mdc_enable)(((_VAL_)&0x20U) >> 5U),          \
    .zor = (enum iis2mdc_enable)(((_VAL_)&0x40U) >> 6U), .zyxor = (enum iis2mdc_enable)(((_VAL_)&0x80U) >> 7U),        \
  }

/** @} */

/**
 * \defgroup IIS2MDC_OUTX_L_REG_FUNCS OUTX_L_REG register modify/pack/unpack utilities.
 * @{
 */
/**
 * @brief Modify the 'OUTX_L_REG' register's binary representation
 * All fields are replaced with the struct's values.
 * All 'always_write' bits (if any) are forced to the correct value.
 * All other bits are kept the same.
 * @param r struct holding register fields
 * @param val current binary register representation
 * @return packed register representation
 */
static inline uint8_t iis2mdc_modify_outx_l_reg(const struct iis2mdc_reg_outx_l_reg *r, uint8_t val) {
  val = (val & ~0xFFU) | (uint8_t)((r->outx & 0xFFU) << 0U);
  return val;
}

/**
 * @brief Pack the 'OUTX_L_REG' register's fields into their binary representation
 * All fields are set to the struct's values.
 * All 'always_write' bits (if any) are set to the correct value.
 * All other bits are are set to 0.
 * @param r struct holding register fields
 * @return packed register representation
 */
static inline uint8_t iis2mdc_pack_outx_l_reg(const struct iis2mdc_reg_outx_l_reg *r) {
  return iis2mdc_modify_outx_l_reg(r, 0);
}

/**
 * @brief Unpack the 'OUTX_L_REG' register's binary representation into seperate fields
 * @param r buffer to store the unpacked fields
 * @param val packed register representation
 */
static inline void iis2mdc_unpack_outx_l_reg(struct iis2mdc_reg_outx_l_reg *r, uint8_t val) {
  r->outx = (uint8_t)((val & 0xFFU) >> 0U);
}

/**
 * @brief Unpack the 'OUTX_L_REG' register's binary representation into a struct initialiser.
 * @note use static iis2mdc_unpack_outx_l_reg() to unpack into an exsisting struct.
 * Example:
 *   `struct iis2mdc_reg_outx_l_reg reg = IIS2MDC_UNPACK_OUTX_L_REG(0xAB);`
 *
 * @param _VAL_ packed register representation
 */
#define IIS2MDC_UNPACK_OUTX_L_REG(_VAL_)                                                                               \
  { .outx = (uint8_t)(((_VAL_)&0xFFU) >> 0U), }

/** @} */

/**
 * \defgroup IIS2MDC_OUTX_H_REG_FUNCS OUTX_H_REG register modify/pack/unpack utilities.
 * @{
 */
/**
 * @brief Modify the 'OUTX_H_REG' register's binary representation
 * All fields are replaced with the struct's values.
 * All 'always_write' bits (if any) are forced to the correct value.
 * All other bits are kept the same.
 * @param r struct holding register fields
 * @param val current binary register representation
 * @return packed register representation
 */
static inline uint8_t iis2mdc_modify_outx_h_reg(const struct iis2mdc_reg_outx_h_reg *r, uint8_t val) {
  val = (val & ~0xFFU) | (uint8_t)((r->outx & 0xFFU) << 0U);
  return val;
}

/**
 * @brief Pack the 'OUTX_H_REG' register's fields into their binary representation
 * All fields are set to the struct's values.
 * All 'always_write' bits (if any) are set to the correct value.
 * All other bits are are set to 0.
 * @param r struct holding register fields
 * @return packed register representation
 */
static inline uint8_t iis2mdc_pack_outx_h_reg(const struct iis2mdc_reg_outx_h_reg *r) {
  return iis2mdc_modify_outx_h_reg(r, 0);
}

/**
 * @brief Unpack the 'OUTX_H_REG' register's binary representation into seperate fields
 * @param r buffer to store the unpacked fields
 * @param val packed register representation
 */
static inline void iis2mdc_unpack_outx_h_reg(struct iis2mdc_reg_outx_h_reg *r, uint8_t val) {
  r->outx = (uint8_t)((val & 0xFFU) >> 0U);
}

/**
 * @brief Unpack the 'OUTX_H_REG' register's binary representation into a struct initialiser.
 * @note use static iis2mdc_unpack_outx_h_reg() to unpack into an exsisting struct.
 * Example:
 *   `struct iis2mdc_reg_outx_h_reg reg = IIS2MDC_UNPACK_OUTX_H_REG(0xAB);`
 *
 * @param _VAL_ packed register representation
 */
#define IIS2MDC_UNPACK_OUTX_H_REG(_VAL_)                                                                               \
  { .outx = (uint8_t)(((_VAL_)&0xFFU) >> 0U), }

/** @} */

/**
 * \defgroup IIS2MDC_OUTY_L_REG_FUNCS OUTY_L_REG register modify/pack/unpack utilities.
 * @{
 */
/**
 * @brief Modify the 'OUTY_L_REG' register's binary representation
 * All fields are replaced with the struct's values.
 * All 'always_write' bits (if any) are forced to the correct value.
 * All other bits are kept the same.
 * @param r struct holding register fields
 * @param val current binary register representation
 * @return packed register representation
 */
static inline uint8_t iis2mdc_modify_outy_l_reg(const struct iis2mdc_reg_outy_l_reg *r, uint8_t val) {
  val = (val & ~0xFFU) | (uint8_t)((r->outy & 0xFFU) << 0U);
  return val;
}

/**
 * @brief Pack the 'OUTY_L_REG' register's fields into their binary representation
 * All fields are set to the struct's values.
 * All 'always_write' bits (if any) are set to the correct value.
 * All other bits are are set to 0.
 * @param r struct holding register fields
 * @return packed register representation
 */
static inline uint8_t iis2mdc_pack_outy_l_reg(const struct iis2mdc_reg_outy_l_reg *r) {
  return iis2mdc_modify_outy_l_reg(r, 0);
}

/**
 * @brief Unpack the 'OUTY_L_REG' register's binary representation into seperate fields
 * @param r buffer to store the unpacked fields
 * @param val packed register representation
 */
static inline void iis2mdc_unpack_outy_l_reg(struct iis2mdc_reg_outy_l_reg *r, uint8_t val) {
  r->outy = (uint8_t)((val & 0xFFU) >> 0U);
}

/**
 * @brief Unpack the 'OUTY_L_REG' register's binary representation into a struct initialiser.
 * @note use static iis2mdc_unpack_outy_l_reg() to unpack into an exsisting struct.
 * Example:
 *   `struct iis2mdc_reg_outy_l_reg reg = IIS2MDC_UNPACK_OUTY_L_REG(0xAB);`
 *
 * @param _VAL_ packed register representation
 */
#define IIS2MDC_UNPACK_OUTY_L_REG(_VAL_)                                                                               \
  { .outy = (uint8_t)(((_VAL_)&0xFFU) >> 0U), }

/** @} */

/**
 * \defgroup IIS2MDC_OUTY_H_REG_FUNCS OUTY_H_REG register modify/pack/unpack utilities.
 * @{
 */
/**
 * @brief Modify the 'OUTY_H_REG' register's binary representation
 * All fields are replaced with the struct's values.
 * All 'always_write' bits (if any) are forced to the correct value.
 * All other bits are kept the same.
 * @param r struct holding register fields
 * @param val current binary register representation
 * @return packed register representation
 */
static inline uint8_t iis2mdc_modify_outy_h_reg(const struct iis2mdc_reg_outy_h_reg *r, uint8_t val) {
  val = (val & ~0xFFU) | (uint8_t)((r->outy & 0xFFU) << 0U);
  return val;
}

/**
 * @brief Pack the 'OUTY_H_REG' register's fields into their binary representation
 * All fields are set to the struct's values.
 * All 'always_write' bits (if any) are set to the correct value.
 * All other bits are are set to 0.
 * @param r struct holding register fields
 * @return packed register representation
 */
static inline uint8_t iis2mdc_pack_outy_h_reg(const struct iis2mdc_reg_outy_h_reg *r) {
  return iis2mdc_modify_outy_h_reg(r, 0);
}

/**
 * @brief Unpack the 'OUTY_H_REG' register's binary representation into seperate fields
 * @param r buffer to store the unpacked fields
 * @param val packed register representation
 */
static inline void iis2mdc_unpack_outy_h_reg(struct iis2mdc_reg_outy_h_reg *r, uint8_t val) {
  r->outy = (uint8_t)((val & 0xFFU) >> 0U);
}

/**
 * @brief Unpack the 'OUTY_H_REG' register's binary representation into a struct initialiser.
 * @note use static iis2mdc_unpack_outy_h_reg() to unpack into an exsisting struct.
 * Example:
 *   `struct iis2mdc_reg_outy_h_reg reg = IIS2MDC_UNPACK_OUTY_H_REG(0xAB);`
 *
 * @param _VAL_ packed register representation
 */
#define IIS2MDC_UNPACK_OUTY_H_REG(_VAL_)                                                                               \
  { .outy = (uint8_t)(((_VAL_)&0xFFU) >> 0U), }

/** @} */

/**
 * \defgroup IIS2MDC_OUTZ_L_REG_FUNCS OUTZ_L_REG register modify/pack/unpack utilities.
 * @{
 */
/**
 * @brief Modify the 'OUTZ_L_REG' register's binary representation
 * All fields are replaced with the struct's values.
 * All 'always_write' bits (if any) are forced to the correct value.
 * All other bits are kept the same.
 * @param r struct holding register fields
 * @param val current binary register representation
 * @return packed register representation
 */
static inline uint8_t iis2mdc_modify_outz_l_reg(const struct iis2mdc_reg_outz_l_reg *r, uint8_t val) {
  val = (val & ~0xFFU) | (uint8_t)((r->outz & 0xFFU) << 0U);
  return val;
}

/**
 * @brief Pack the 'OUTZ_L_REG' register's fields into their binary representation
 * All fields are set to the struct's values.
 * All 'always_write' bits (if any) are set to the correct value.
 * All other bits are are set to 0.
 * @param r struct holding register fields
 * @return packed register representation
 */
static inline uint8_t iis2mdc_pack_outz_l_reg(const struct iis2mdc_reg_outz_l_reg *r) {
  return iis2mdc_modify_outz_l_reg(r, 0);
}

/**
 * @brief Unpack the 'OUTZ_L_REG' register's binary representation into seperate fields
 * @param r buffer to store the unpacked fields
 * @param val packed register representation
 */
static inline void iis2mdc_unpack_outz_l_reg(struct iis2mdc_reg_outz_l_reg *r, uint8_t val) {
  r->outz = (uint8_t)((val & 0xFFU) >> 0U);
}

/**
 * @brief Unpack the 'OUTZ_L_REG' register's binary representation into a struct initialiser.
 * @note use static iis2mdc_unpack_outz_l_reg() to unpack into an exsisting struct.
 * Example:
 *   `struct iis2mdc_reg_outz_l_reg reg = IIS2MDC_UNPACK_OUTZ_L_REG(0xAB);`
 *
 * @param _VAL_ packed register representation
 */
#define IIS2MDC_UNPACK_OUTZ_L_REG(_VAL_)                                                                               \
  { .outz = (uint8_t)(((_VAL_)&0xFFU) >> 0U), }

/** @} */

/**
 * \defgroup IIS2MDC_OUTZ_H_REG_FUNCS OUTZ_H_REG register modify/pack/unpack utilities.
 * @{
 */
/**
 * @brief Modify the 'OUTZ_H_REG' register's binary representation
 * All fields are replaced with the struct's values.
 * All 'always_write' bits (if any) are forced to the correct value.
 * All other bits are kept the same.
 * @param r struct holding register fields
 * @param val current binary register representation
 * @return packed register representation
 */
static inline uint8_t iis2mdc_modify_outz_h_reg(const struct iis2mdc_reg_outz_h_reg *r, uint8_t val) {
  val = (val & ~0xFFU) | (uint8_t)((r->outz & 0xFFU) << 0U);
  return val;
}

/**
 * @brief Pack the 'OUTZ_H_REG' register's fields into their binary representation
 * All fields are set to the struct's values.
 * All 'always_write' bits (if any) are set to the correct value.
 * All other bits are are set to 0.
 * @param r struct holding register fields
 * @return packed register representation
 */
static inline uint8_t iis2mdc_pack_outz_h_reg(const struct iis2mdc_reg_outz_h_reg *r) {
  return iis2mdc_modify_outz_h_reg(r, 0);
}

/**
 * @brief Unpack the 'OUTZ_H_REG' register's binary representation into seperate fields
 * @param r buffer to store the unpacked fields
 * @param val packed register representation
 */
static inline void iis2mdc_unpack_outz_h_reg(struct iis2mdc_reg_outz_h_reg *r, uint8_t val) {
  r->outz = (uint8_t)((val & 0xFFU) >> 0U);
}

/**
 * @brief Unpack the 'OUTZ_H_REG' register's binary representation into a struct initialiser.
 * @note use static iis2mdc_unpack_outz_h_reg() to unpack into an exsisting struct.
 * Example:
 *   `struct iis2mdc_reg_outz_h_reg reg = IIS2MDC_UNPACK_OUTZ_H_REG(0xAB);`
 *
 * @param _VAL_ packed register representation
 */
#define IIS2MDC_UNPACK_OUTZ_H_REG(_VAL_)                                                                               \
  { .outz = (uint8_t)(((_VAL_)&0xFFU) >> 0U), }

/** @} */

/**
 * \defgroup IIS2MDC_TEMP_OUT_L_REG_FUNCS TEMP_OUT_L_REG register modify/pack/unpack utilities.
 * @{
 */
/**
 * @brief Modify the 'TEMP_OUT_L_REG' register's binary representation
 * All fields are replaced with the struct's values.
 * All 'always_write' bits (if any) are forced to the correct value.
 * All other bits are kept the same.
 * @param r struct holding register fields
 * @param val current binary register representation
 * @return packed register representation
 */
static inline uint8_t iis2mdc_modify_temp_out_l_reg(const struct iis2mdc_reg_temp_out_l_reg *r, uint8_t val) {
  val = (val & ~0xFFU) | (uint8_t)((r->temp & 0xFFU) << 0U);
  return val;
}

/**
 * @brief Pack the 'TEMP_OUT_L_REG' register's fields into their binary representation
 * All fields are set to the struct's values.
 * All 'always_write' bits (if any) are set to the correct value.
 * All other bits are are set to 0.
 * @param r struct holding register fields
 * @return packed register representation
 */
static inline uint8_t iis2mdc_pack_temp_out_l_reg(const struct iis2mdc_reg_temp_out_l_reg *r) {
  return iis2mdc_modify_temp_out_l_reg(r, 0);
}

/**
 * @brief Unpack the 'TEMP_OUT_L_REG' register's binary representation into seperate fields
 * @param r buffer to store the unpacked fields
 * @param val packed register representation
 */
static inline void iis2mdc_unpack_temp_out_l_reg(struct iis2mdc_reg_temp_out_l_reg *r, uint8_t val) {
  r->temp = (uint8_t)((val & 0xFFU) >> 0U);
}

/**
 * @brief Unpack the 'TEMP_OUT_L_REG' register's binary representation into a struct initialiser.
 * @note use static iis2mdc_unpack_temp_out_l_reg() to unpack into an exsisting struct.
 * Example:
 *   `struct iis2mdc_reg_temp_out_l_reg reg = IIS2MDC_UNPACK_TEMP_OUT_L_REG(0xAB);`
 *
 * @param _VAL_ packed register representation
 */
#define IIS2MDC_UNPACK_TEMP_OUT_L_REG(_VAL_)                                                                           \
  { .temp = (uint8_t)(((_VAL_)&0xFFU) >> 0U), }

/** @} */

/**
 * \defgroup IIS2MDC_TEMP_OUT_H_REG_FUNCS TEMP_OUT_H_REG register modify/pack/unpack utilities.
 * @{
 */
/**
 * @brief Modify the 'TEMP_OUT_H_REG' register's binary representation
 * All fields are replaced with the struct's values.
 * All 'always_write' bits (if any) are forced to the correct value.
 * All other bits are kept the same.
 * @param r struct holding register fields
 * @param val current binary register representation
 * @return packed register representation
 */
static inline uint8_t iis2mdc_modify_temp_out_h_reg(const struct iis2mdc_reg_temp_out_h_reg *r, uint8_t val) {
  val = (val & ~0xFFU) | (uint8_t)((r->temp & 0xFFU) << 0U);
  return val;
}

/**
 * @brief Pack the 'TEMP_OUT_H_REG' register's fields into their binary representation
 * All fields are set to the struct's values.
 * All 'always_write' bits (if any) are set to the correct value.
 * All other bits are are set to 0.
 * @param r struct holding register fields
 * @return packed register representation
 */
static inline uint8_t iis2mdc_pack_temp_out_h_reg(const struct iis2mdc_reg_temp_out_h_reg *r) {
  return iis2mdc_modify_temp_out_h_reg(r, 0);
}

/**
 * @brief Unpack the 'TEMP_OUT_H_REG' register's binary representation into seperate fields
 * @param r buffer to store the unpacked fields
 * @param val packed register representation
 */
static inline void iis2mdc_unpack_temp_out_h_reg(struct iis2mdc_reg_temp_out_h_reg *r, uint8_t val) {
  r->temp = (uint8_t)((val & 0xFFU) >> 0U);
}

/**
 * @brief Unpack the 'TEMP_OUT_H_REG' register's binary representation into a struct initialiser.
 * @note use static iis2mdc_unpack_temp_out_h_reg() to unpack into an exsisting struct.
 * Example:
 *   `struct iis2mdc_reg_temp_out_h_reg reg = IIS2MDC_UNPACK_TEMP_OUT_H_REG(0xAB);`
 *
 * @param _VAL_ packed register representation
 */
#define IIS2MDC_UNPACK_TEMP_OUT_H_REG(_VAL_)                                                                           \
  { .temp = (uint8_t)(((_VAL_)&0xFFU) >> 0U), }

/** @} */

#endif /* IIS2MDC_REG_UTILS_H_ */
