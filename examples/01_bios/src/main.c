#include <bios.h>

int main(void) {

    // Raw low level BIOS call
    bios_rcb_t rcb;
    char str[] = "ABC";
    rcb.rqno = BIOS_REQ_OUTPUT;
    rcb.rcbsta = 0;
    rcb.rcbdba = str;
    rcb.rcblnh = 3;
    rcb.rcbbmh = 0;
    bios_call(&rcb);

    // Alternatively (and less error prone) using the high level wrapper
    bios_output("ABC", 3);

    return 0;
}

