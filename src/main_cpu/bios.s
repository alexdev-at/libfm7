.section .text

.global bios_call

bios_call:
    tfr d, x
    jsr [0xFBFA]
    ldb 1, x
    rts

