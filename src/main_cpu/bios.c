#include <bios.h>

uint8_t bios_motor(bool on) {
    bios_rcb_t rcb;
    rcb.rqno = BIOS_REQ_MOTOR;
    rcb.data.motor.motorf = on ? BIOS_MOTOR_ON : BIOS_MOTOR_OFF;
    bios_call(&rcb);
    return rcb.rcbsta;
}

uint8_t bios_ctbwrt(uint8_t data) {
    bios_rcb_t rcb;
    rcb.rqno = BIOS_REQ_CTBWRT;
    rcb.data.cassette.crwdat = data;
    bios_call(&rcb);
    return rcb.rcbsta;
}

uint8_t bios_ctbred(uint8_t* data) {
    bios_rcb_t rcb;
    rcb.rqno = BIOS_REQ_CTBRED;
    bios_call(&rcb);
    *data = rcb.data.cassette.crwdat;
    return rcb.rcbsta;
}

uint8_t bios_screen(void* buffer, uint8_t color_bitmask) {
    bios_rcb_t rcb;
    rcb.rqno = BIOS_REQ_SCREEN;
    rcb.data.screen.buffer = buffer;
    rcb.data.screen.rcbcdt = color_bitmask;
    bios_call(&rcb);
    return rcb.rcbsta;
}

uint8_t bios_restor(uint8_t drive) {
    bios_rcb_t rcb;
    rcb.rqno = BIOS_REQ_RESTOR;
    rcb.data.disk.rcbunt = drive;
    bios_call(&rcb);
    return rcb.rcbsta;
}

uint8_t bios_dwrite(const void* buffer, uint8_t drive, uint8_t disk_side, uint8_t track, uint8_t sector) {
    bios_rcb_t rcb;
    rcb.rqno = BIOS_REQ_DWRITE;
    rcb.data.disk.buffer = buffer;
    rcb.data.disk.rcbtrk = track;
    rcb.data.disk.rcbsct = sector;
    rcb.data.disk.rcbsid = disk_side;
    rcb.data.disk.rcbunt = drive;
    bios_call(&rcb);
    return rcb.rcbsta;
}

uint8_t bios_dread(void* buffer, uint8_t drive, uint8_t disk_side, uint8_t track, uint8_t sector) {
    bios_rcb_t rcb;
    rcb.rqno = BIOS_REQ_DREAD;
    rcb.data.disk.buffer = buffer;
    rcb.data.disk.rcbtrk = track;
    rcb.data.disk.rcbsct = sector;
    rcb.data.disk.rcbsid = disk_side;
    rcb.data.disk.rcbunt = drive;
    bios_call(&rcb);
    return rcb.rcbsta;
}

uint8_t bios_beepon(void) {
    bios_rcb_t rcb;
    rcb.rqno = BIOS_REQ_BEEPON;
    bios_call(&rcb);
    return rcb.rcbsta;
}

uint8_t bios_beepof(void) {
    bios_rcb_t rcb;
    rcb.rqno = BIOS_REQ_BEEPOF;
    bios_call(&rcb);
    return rcb.rcbsta;
}

uint8_t bios_output(const char* str, uint16_t n) {
    bios_rcb_t rcb;
    rcb.rqno = BIOS_REQ_OUTPUT;
    rcb.data.generic.rcbdba = str;
    rcb.data.generic.rcblnh = n;
    bios_call(&rcb);
    return rcb.rcbsta;
}

uint8_t bios_screen(void* buffer, uint16_t jis_code) {
    bios_rcb_t rcb;
    rcb.rqno = BIOS_REQ_KANJIR;
    rcb.data.kanji.buffer = buffer;
    rcb.data.kanji.rcbjcd = jis_code;
    bios_call(&rcb);
    return rcb.rcbsta;
}

uint8_t bios_biinit(void) {
    bios_rcb_t rcb;
    rcb.rqno = BIOS_REQ_BIINIT;
    bios_call(&rcb);
    return rcb.rcbsta;
}