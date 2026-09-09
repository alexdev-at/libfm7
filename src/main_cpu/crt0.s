.section .text

.global _start
.global main
.global _exit

.global __bss_start
.global __bss_end

.equ HARDWARE_STACK_TOP, 0x7FFF
.equ USER_STACK_TOP, 0x1FFF

_start:
    orcc #0x50

    sts _os_s
    stu _os_u

    lds #HARDWARE_STACK_TOP
    ldu #USER_STACK_TOP

    andcc #0xAF

    jsr main

_exit:
    ldu _os_u
    lds _os_s

    rts

.section .bss

_os_s:
    .space 2
_os_u:
    .space 2
    