#include <bios.h>

int main(void) {

    // Raw low level BIOS call
    bios_rcb_t rcb;
    char str[] = "ABC";
    rcb.rqno = BIOS_REQ_OUTPUT;
    rcb.rcbsta = 0;
    rcb.data.generic.rcbdba = str;
    rcb.data.generic.rcblnh = 3;
    rcb.data.generic.rcbbmh = 0;
    uint8_t ll_status = bios_call(&rcb);

    if (ll_status == BIOS_STAT_OK) {
        // do something
    }

    // Alternatively (and less error prone) using the high level wrapper
    uint8_t hl_status = bios_output("ABC", 3);

    if (hl_status == BIOS_STAT_ERR_SUB_CMD) {
        // do some error handling
    }

    return 0;
}

