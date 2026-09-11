MEMORY
{
  ram (rwx) : ORIGIN = 0x2000, LENGTH = 0x5000
}

SECTIONS
{
  .text : {
    *(.text)
    *(.rodata*)
  } > ram
  
  .data : {
    *(.data)
  } > ram
  
  .bss : {
    __bss_start = .;
    *(.bss)
    __bss_end = .;
  } > ram
}

