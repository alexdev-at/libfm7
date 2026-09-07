@echo off
setlocal

set "SDK_ROOT=%~dp0"
set "CMD=%~1"

if "%CMD%"=="init" (
    echo Initializing libfm7 project...
    copy "%SDK_ROOT%scripts\Makefile.template" "Makefile" >nul
    mkdir src 2>nul
    copy "%SDK_ROOT%scripts\main.c.template" "src\main.c" >nul
    echo Done.
    exit /b 0
)

if "%CMD%"=="make" (
    echo Running make inside libfm7-toolchain...
    docker run --rm -v "%SDK_ROOT%:/opt/libfm7" -v "%cd%:/app" -w /app libfm7-toolchain make %2 %3 %4 %5 %6 %7 %8 %9
    exit /b %ERRORLEVEL%
)

echo Usage: libfm7 [init ^| make]
exit /b 1

