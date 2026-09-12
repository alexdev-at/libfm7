#include <bios.h>

bios_stat_t bios_motor(bool on) {
    bios_rcb_t rcb;
    rcb.rqno = BIOS_REQ_MOTOR;
    rcb.data.motor.motorf = on ? BIOS_MOTOR_ON : BIOS_MOTOR_OFF;
    bios_call(&rcb);
    return rcb.rcbsta;
}

bios_stat_t bios_ctbwrt(uint8_t data) {
    bios_rcb_t rcb;
    rcb.rqno = BIOS_REQ_CTBWRT;
    rcb.data.cassette.crwdat = data;
    bios_call(&rcb);
    return rcb.rcbsta;
}

bios_stat_t bios_ctbred(uint8_t* data) {
    bios_rcb_t rcb;
    rcb.rqno = BIOS_REQ_CTBRED;
    bios_call(&rcb);
    *data = rcb.data.cassette.crwdat;
    return rcb.rcbsta;
}

bios_stat_t bios_output(const char* str, uint16_t n) {
    bios_rcb_t rcb;
    rcb.rqno = BIOS_REQ_OUTPUT;
    rcb.data.generic.rcbdba = str;
    rcb.data.generic.rcblnh = n;
    bios_call(&rcb);
    return rcb.rcbsta;
}