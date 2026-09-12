#include <bios.h>

bios_stat_t bios_motor(bool on) {
    bios_rcb_t rcb;
    rcb.rqno = BIOS_REQ_OUTPUT;
    rcb.rcbsta = 0;
    rcb.data.motor.motorf = on ? BIOS_MOTOR_ON : BIOS_MOTOR_OFF;
    bios_call(&rcb);
    return rcb.rcbsta;
}

bios_stat_t bios_output(const char* str, uint16_t n) {
    bios_rcb_t rcb;
    rcb.rqno = BIOS_REQ_OUTPUT;
    rcb.rcbsta = 0;
    rcb.data.generic.rcbdba = str;
    rcb.data.generic.rcblnh = n;
    rcb.data.generic.rcbbmh = 0;
    bios_call(&rcb);
    return rcb.rcbsta;
}