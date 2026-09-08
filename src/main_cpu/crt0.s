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

    sts _os_stack

    lds #HARDWARE_STACK_TOP
    ldu #USER_STACK_TOP

    andcc #0xAF

    jsr main

_exit:
    lds _os_stack
    rts

.section .bss
_os_stack:
    .space 2
