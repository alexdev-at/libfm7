ASM_SRCS = $(filter-out src/main_cpu/crt0.s, $(wildcard src/main_cpu/*.s))
C_SRCS = $(wildcard src/main_cpu/*.c)

ASM_OBJS = $(ASM_SRCS:.s=.s.o)
C_OBJS = $(C_SRCS:.c=.c.o)
OBJS = $(ASM_OBJS) $(C_OBJS)

all: src/main_cpu/crt0.o lib/libfm7.a

src/main_cpu/crt0.o: src/main_cpu/crt0.s
	vasm6809_std -quiet -Fvobj -o $@ $<

lib/libfm7.a: $(OBJS)
	mkdir -p lib
	ar rcs $@ $(OBJS)

%.s.o: %.s
	vasm6809_std -quiet -Fvobj -o $@ $<

%.c.o: %.c
	vc +libfm7 -O1 -c -o $@ $<

clean:
	rm -f src/main_cpu/*.o src/main_cpu/*.s.o src/main_cpu/*.c.o lib/*.a
