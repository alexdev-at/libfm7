SRCS = $(wildcard src/*.c) $(wildcard src/*.s)
TARGET_BIN = build/out.bin
TARGET_D77 = build/out.d77

all: $(TARGET_D77)

$(TARGET_D77): $(TARGET_BIN)
	d77fileutil $(TARGET_D77) -new -savem $(TARGET_BIN) OUT 0x2000 0x2000

$(TARGET_BIN): $(SRCS)
	mkdir -p build
	vc +libfm7 -O1 -o $(TARGET_BIN) $(SRCS)

clean:
	rm -rf build *.o

