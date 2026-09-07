SRCS = $(wildcard src/*.c) $(wildcard src/*.s)
TARGET = build/out.bin

all: $(TARGET)

$(TARGET): $(SRCS)
	mkdir -p build
	vc +libfm7 -O1 -o $(TARGET) $(SRCS)

clean:
	rm -rf build *.o
