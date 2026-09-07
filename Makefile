ASM_SRCS = $(wildcard src/main_cpu/*.s)
C_SRCS = $(wildcard src/main_cpu/*.c)

ASM_OBJS = $(ASM_SRCS:.s=.o)
C_OBJS = $(C_SRCS:.c=.o)
OBJS = $(ASM_OBJS) $(C_OBJS)

all: $(OBJS)

%.o: %.s
	vasm6809_std -quiet -Fvobj -o $@ $<

%.o: %.c
	vc +libfm7 -O1 -c -o $@ $<

clean:
	rm -f $(OBJS)
