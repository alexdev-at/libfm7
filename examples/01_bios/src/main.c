#include <bios.h>

int main(void) {
    bios_rcb_t rcb;
    char str[] = "ABC";
    rcb.rqno = BIOS_REQ_OUTPUT;
    rcb.rcbsta = 0;
    rcb.rcbdba = str;
    rcb.rcblnh = 3;
    rcb.rcbbmh = 0;
    bios_call(&rcb);
    return 0;
}

