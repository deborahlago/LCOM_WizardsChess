#include "RTC.h"

/* Globals */

int rtcHookId;


/* Read/Write functions */

uint8_t rtc_read_reg(uint32_t port){

    uint8_t data;

    sys_outb(RTC_ADDR_REG, port);
    util_sys_inb(RTC_DATA_REG, &data);

    return data;
}

void rtc_write_data(uint32_t port, uint32_t data){

    sys_outb(RTC_ADDR_REG, port);
    sys_outb(RTC_DATA_REG, data);
}


/* Functions */

int rtc_subscribe_int(uint8_t* bit_no){
    rtcHookId = *bit_no;

    if (sys_irqsetpolicy(RTC_IRQ, IRQ_REENABLE, &rtcHookId) == EXIT_SUCCESS){
        if (sys_irqenable(&rtcHookId) == EXIT_SUCCESS)
            return EXIT_SUCCESS;
    }

    return EXIT_FAILURE;
}

int rtc_unsubscribe_int(){

    if (sys_irqrmpolicy(&rtcHookId) == EXIT_SUCCESS)
        return EXIT_SUCCESS;

    return EXIT_FAILURE;
}

void rtc_enable_int(){

    uint8_t reg_b_cfg = rtc_read_reg(RTC_REG_B);
    reg_b_cfg |= BIT(4);

    rtc_write_data(RTC_REG_B, reg_b_cfg);
}

void rtc_disable_int(){

    uint8_t reg_b_cfg = rtc_read_reg(RTC_REG_B);
    reg_b_cfg &= ~BIT(4);

    rtc_write_data(RTC_REG_B, reg_b_cfg);
}

uint8_t rtc_bcd_to_bin(uint8_t date){

    // date = date - 6 * (date >> 4);
    date = (((date & 0xF0) >> 4) * 10 + (date & 0x0F));

    return date;
}

void rtc_read_time(rtc_time_t* time){

    _Bool bcd = true;
    uint8_t reg_b_cfg = rtc_read_reg(RTC_REG_B);

    if (reg_b_cfg & BIT(2))
        bcd = false;

    time->hours = rtc_read_reg(RTC_HRS);
    time->mins = rtc_read_reg(RTC_MIN);
    time->secs = rtc_read_reg(RTC_SEC);

    if (bcd){
        time->hours = rtc_bcd_to_bin(time->hours);
        time->mins = rtc_bcd_to_bin(time->mins);
        time->secs = rtc_bcd_to_bin(time->secs);
    }
}

