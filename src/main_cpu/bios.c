#include <bios.h>

void bios_output(char* str, unsigned char n) {
    bios_rcb_t rcb;
    rcb.rqno = BIOS_REQ_OUTPUT;
    rcb.rcbsta = 0;
    rcb.rcbdba = str;
    rcb.rcblnh = n;
    rcb.rcbbmh = 0;
    bios_call(&rcb);
}