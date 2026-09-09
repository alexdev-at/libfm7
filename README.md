# libfm7

libfm7 is a modern C SDK for the Fujitsu FM-7 series microcomputers.

## Prerequisites

- [Docker Desktop](https://www.docker.com/) (must be running in the background)
- [Node.js](https://nodejs.org/) (includes `npm`)
- [XM7 Emulator](https://retropc.net/ryu/xm7/xm7.shtml) (or any FM-7 compatible emulator)

## Installation

Install the `libfm7` CLI globally:

```bash
npm install -g libfm7
```

*(Alternatively, you can run commands directly without installing using `npx libfm7 init` and `npx libfm7 make`).*

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
