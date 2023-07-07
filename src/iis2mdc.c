#include "iis2mdc_enums.h"
#include "iis2mdc_regs.h"
#include "iis2mdc_reg_utils.h"
#include "iis2mdc.h"

// ======== Private Prototypes =================================================================
static iis2mdc_err_t check_connection(const struct iis2mdc_h *h);
static iis2mdc_err_t validate_handle(const struct iis2mdc_h *h);


// ======== Public Functions =================================================================

iis2mdc_err_t iis2mdc_reset(const struct iis2mdc_h *h){
    iis2mdc_err_t err = E_IIS2MDC_SUCCESS;
    err |= validate_handle(h);
    if (err) return err;

    uint8_t reg;
    err |= h->read_regs(IIS2MDC_REG_CFG_REG_A, 1, &reg);
    struct iis2mdc_reg_cfg_reg_a cfg = IIS2MDC_UNPACK_CFG_REG_A(reg);
    cfg.soft_rst = 1;
    reg = IIS2MDC_PACK(&cfg);
    err |= h->write_regs(IIS2MDC_REG_CFG_REG_A, 1, &reg);
    return err;
}

iis2mdc_err_t iis2mdc_init(const struct iis2mdc_h *h, const struct iis2mdc_cfg *cfg){
    iis2mdc_err_t err = E_IIS2MDC_SUCCESS;
    err |= validate_handle(h);
    if (err) return err;

    // check connection by reading whoami register
    err |= check_connection(h);
    if (err) return err;

    // reset device (TODO: investigate what is reboot instead)
    err |= iis2mdc_reset(h);
    //TODO handle errors!!!
    if (err) return err;

    // set device configuration
    err |= iis2mdc_config(h, cfg);
    if (err) return err;

    return err;
}

iis2mdc_err_t iis2mdc_config(const struct iis2mdc_h *h, const struct iis2mdc_cfg *cfg){
    iis2mdc_err_t err = E_IIS2MDC_SUCCESS;
    err |= validate_handle(h);
    if (err) return err;

    uint8_t regs[3];
    err |= h->read_regs(IIS2MDC_REG_CFG_REG_A, 3, regs);
    struct iis2mdc_reg_cfg_reg_a cfg_reg_a = IIS2MDC_UNPACK_CFG_REG_A(regs[0]);
    cfg_reg_a.md = cfg->op_mode;
    cfg_reg_a.odr = cfg->odr;
    cfg_reg_a.lp = cfg->low_power_en;
    cfg_reg_a.soft_rst = 0;
    cfg_reg_a.reboot = 0;
    cfg_reg_a.comp_temp_en = cfg->comp_temp_en;
    regs[0] = IIS2MDC_PACK(&cfg_reg_a);

    struct iis2mdc_reg_cfg_reg_b cfg_reg_b = IIS2MDC_UNPACK_CFG_REG_B(regs[1]);
    cfg_reg_b.lpf = cfg->lpf_en;
    cfg_reg_b.off_canc = cfg->offset_cancel_en;
    cfg_reg_b.set_pulse_freq = cfg->set_pulse_only_power_on;
    cfg_reg_b.int_on_dataoff = cfg->int_after_offset;
    cfg_reg_b.off_canc_one_shot = cfg->offset_cancel_one_shot_en;
    regs[1] = IIS2MDC_PACK(&cfg_reg_b);

    struct iis2mdc_reg_cfg_reg_c cfg_reg_c = IIS2MDC_UNPACK_CFG_REG_C(regs[2]);
    cfg_reg_c.self_test = cfg->self_test_en;
    cfg_reg_c.ble = cfg->byte_order_invert;
    cfg_reg_c.bdu = cfg->latch_data;
    cfg_reg_c.i2c_dis = cfg->i2c_disable;
    regs[2] = IIS2MDC_PACK(&cfg_reg_c);

    err |= h->write_regs(IIS2MDC_REG_CFG_REG_A, 3, regs);

    return err;
}

iis2mdc_err_t iis2mdc_cfg_interupt(const struct iis2mdc_h *h, const struct iis2mdc_int_cfg *cfg){
    iis2mdc_err_t err = E_IIS2MDC_SUCCESS;
    err |= validate_handle(h);
    if (err) return err;

    // we only use the threshold registers if we have interrupts on thresholds
    bool set_thresholds = cfg->int_x_en || cfg->int_y_en || cfg->int_z_en;

    uint8_t regs[2];
    err |= h->read_regs(IIS2MDC_REG_CFG_REG_C, 1, regs);

    struct iis2mdc_reg_cfg_reg_c cfg_reg_c = IIS2MDC_UNPACK_CFG_REG_C(regs[0]);
    cfg_reg_c.int_on_pin = cfg->int_on_pin;
    cfg_reg_c.drdy_on_pin = cfg->drdy_on_pin;

    // INT_CTRL_REG is always completely overwritten, no need to read (2 always write bits)
    struct iis2mdc_reg_int_ctrl_reg int_ctrl_reg;
    int_ctrl_reg.int_en = cfg->int_en;
    int_ctrl_reg.int_mode = cfg->int_latched;
    int_ctrl_reg.int_polarity = cfg->int_active_high;
    int_ctrl_reg.int_x_en = cfg->int_x_en;
    int_ctrl_reg.int_y_en = cfg->int_y_en;
    int_ctrl_reg.int_z_en = cfg->int_z_en;

    regs[0] = IIS2MDC_PACK(&cfg_reg_c);
    regs[1] = IIS2MDC_PACK(&int_ctrl_reg);

    err |= h->write_regs(IIS2MDC_REG_CFG_REG_C, 2, regs);

    if(set_thresholds){
        struct iis2mdc_reg_int_ths_l_reg ths_l;
        ths_l.ths = cfg->int_threshold & 0xFFu;
        struct iis2mdc_reg_int_ths_h_reg ths_h;
        ths_h.ths = (cfg->int_threshold >> 8u) & 0xFFu;

        regs[0] = IIS2MDC_PACK(&ths_l);
        regs[1] = IIS2MDC_PACK(&ths_h);

        err |= h->write_regs(IIS2MDC_REG_INT_THS_L_REG, 2, regs);
    }

    return err;
}

iis2mdc_err_t iis2mdc_cfg_offset(const struct iis2mdc_h *h, const struct iis2mdc_offset_cfg *cfg){
    iis2mdc_err_t err = E_IIS2MDC_SUCCESS;
    err |= validate_handle(h);
    if (err) return err;

    uint8_t regs[6];
    struct iis2mdc_reg_offset_x_reg_l x_l;
    x_l.val = cfg->offset_x & 0xFFu;
    struct iis2mdc_reg_offset_x_reg_h x_h;
    x_h.val = (cfg->offset_x >> 8u) & 0xFFu;
    struct iis2mdc_reg_offset_y_reg_l y_l;
    y_l.val = cfg->offset_y & 0xFFu;
    struct iis2mdc_reg_offset_y_reg_h y_h;
    y_h.val = (cfg->offset_y >> 8u) & 0xFFu;
    struct iis2mdc_reg_offset_z_reg_l z_l;
    z_l.val = cfg->offset_z & 0xFFu;
    struct iis2mdc_reg_offset_z_reg_h z_h;
    z_h.val = (cfg->offset_z >> 8u) & 0xFFu;

    regs[0] = IIS2MDC_PACK(&x_l);
    regs[1] = IIS2MDC_PACK(&x_h);
    regs[2] = IIS2MDC_PACK(&y_l);
    regs[3] = IIS2MDC_PACK(&y_h);
    regs[4] = IIS2MDC_PACK(&z_l);
    regs[5] = IIS2MDC_PACK(&z_h);

    err |= h->write_regs(IIS2MDC_REG_OFFSET_X_REG_L, 6, regs);

    return err;
}

iis2mdc_err_t iis2mdc_read_mag(const struct iis2mdc_h *h, int16_t *data){
    iis2mdc_err_t err = E_IIS2MDC_SUCCESS;
    err |= validate_handle(h);
    if (err) return err;

    uint8_t regs[6]; //TODO could read directly in the out buffer

    err |= h->read_regs(IIS2MDC_REG_OUTX_L_REG, 6, regs);

    data[0] = regs[0] | (regs[1] << 8u);
    data[1] = regs[2] | (regs[3] << 8u);
    data[2] = regs[4] | (regs[5] << 8u);

    return err;
}

iis2mdc_err_t iis2mdc_read_temp(const struct iis2mdc_h *h, int16_t *temp){
    iis2mdc_err_t err = E_IIS2MDC_SUCCESS;
    err |= validate_handle(h);
    if (err) return err;

    uint8_t regs[2];

    err |= h->read_regs(IIS2MDC_REG_TEMP_OUT_L_REG, 2, regs);

    *temp = regs[0] | (regs[1] << 8u);

    return err;
}

// ======== Private Functions =================================================================

static iis2mdc_err_t validate_handle(const struct iis2mdc_h *h){
    if(h == 0) return E_IIS2MDC_NULLPTR_ERR;
    if(h->read_regs == 0) return E_IIS2MDC_NULLPTR_ERR;
    if(h->write_regs == 0) return E_IIS2MDC_NULLPTR_ERR;
    return E_IIS2MDC_SUCCESS;
}

static iis2mdc_err_t check_connection(const struct iis2mdc_h *h){
    iis2mdc_err_t err = E_IIS2MDC_SUCCESS;

    uint8_t who_am_i = 0;

    err |= h->read_regs(IIS2MDC_REG_WHO_AM_I, 1, &who_am_i);

    if(who_am_i != IIS2MDC_REG_WHO_AM_I__RESETVAL){
        err |= E_IIS2MDC_COM_ERR;
    }
    return err;
}
