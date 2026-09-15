# libfm7

libfm7 is a modern C SDK for the Fujitsu FM series microcomputers.

> [!CAUTION]
> The SDK is in its earliest stages and currently NOT really usable. Please visit regularly to check for updates.

## Hardware Compatibility

- [ ] FM-8
- [x] FM-7
- [x] FM-new7
- [ ] FM-77
- [ ] FM-77AV
- [ ] FM-77AV20
- [ ] FM-77AV40
- [ ] FM-77AV20EX
- [ ] FM-77AV40EX
- [ ] FM-77AV40SX

## Prerequisites

- [Docker Desktop](https://www.docker.com/)
- [Node.js](https://nodejs.org/)
- Fujitsu FM Emulator (like XM7)

## Installation

Install the `libfm7` CLI globally:

```bash
npm install -g alexdev-at/libfm7
```

## Usage

### 1. Initialize a Project

Create a new directory and initialize your project:

```bash
mkdir my_project
cd my_project
libfm7 init
```

This generates:
- `Makefile`
- `src/main.c`

### 2. Build Your Project

Inside your project directory, build the binary and disk image:

```bash
libfm7 make
```

The build produces:
- `build/out.bin` — Raw machine code binary
- `build/out.d77` — Ready-to-mount F-BASIC 2D disk image

To clean build artifacts:
```bash
libfm7 make clean
```

### 3. Run in Emulator

1. Open your FM-7 emulator (e.g., XM7).
2. Insert an F-BASIC system disk into **Drive 0**.
3. Insert your compiled disk (`build/out.d77`) into **Drive 1**.
4. In F-BASIC, load and run the program:
```basic
LOADM "1:OUT",,R
```
