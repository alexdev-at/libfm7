#ifndef _FM7_BIOS_H_
#define _FM7_BIOS_H_

#include <types.h>

/// @brief BIOS request type
typedef enum bios_req_t {
    BIOS_REQ_MOTOR = 1,
    BIOS_REQ_CTBWRT = 2,
    BIOS_REQ_CTBRED = 3,
    BIOS_REQ_SCREEN = 5,
    BIOS_REQ_RESTOR = 8,
    BIOS_REQ_DWRITE = 9,
    BIOS_REQ_DREAD = 10,
    BIOS_REQ_BEEPON = 12,
    BIOS_REQ_BEEPOF = 13,
    BIOS_REQ_OUTPUT = 20
} bios_req_t;

/// @brief BIOS return status codes (RCBSTA)
typedef enum bios_stat_t {
    /// @brief Success
    BIOS_STAT_OK = 0,
    /// @brief Request control block parameter error
    BIOS_ERR_RCB = 1,
    /// @brief Device unavailable or uninstalled optional hardware
    BIOS_ERR_DEV_UNAVAIL = 2,
    /// @brief Floppy drive not ready
    BIOS_ERR_FDC_NOT_READY = 10,
    /// @brief Floppy write protected
    BIOS_ERR_FDC_WRITE_PROT = 11,
    /// @brief Record not found / seek error
    BIOS_ERR_FDC_RECORD_NF = 12,
    /// @brief Data CRC check error
    BIOS_ERR_FDC_CRC = 13,
    /// @brief Deleted data mark detected
    BIOS_ERR_FDC_DELETED_REC = 14,
    /// @brief Floppy operation timeout error
    BIOS_ERR_FDC_TIMEOUT = 15,
    /// @brief Printer out of paper
    BIOS_ERR_LP_PAPER_EMPTY = 50,
    /// @brief Printer offline or not ready
    BIOS_ERR_LP_NOT_READY = 51,
    /// @brief Cassette tape read or framing error
    BIOS_ERR_CAS_READ = 52,
    /// @brief Sub-System init parameter error
    BIOS_ERR_SUB_INIT = 60,
    /// @brief Sub-System console coordinate error
    BIOS_ERR_SUB_CONSOLE_CRD = 61,
    /// @brief Sub-System multi-byte order sequence parameter missing error
    BIOS_ERR_SUB_SEQ_DATA = 62,
    /// @brief Sub-System graphic coordinate error
    BIOS_ERR_SUB_GRAPHIC_CRD = 63,
    /// @brief Sub-System unusable or undefined function code
    BIOS_ERR_SUB_FUNC_CODE = 64,
    /// @brief Sub-System coordinate count out of range
    BIOS_ERR_SUB_CRD_COUNT = 65,
    /// @brief Sub-System character count out of range
    BIOS_ERR_SUB_CHAR_COUNT = 66,
    /// @brief Sub-System color count out of range
    BIOS_ERR_SUB_COLOR_COUNT = 67,
    /// @brief Sub-System function key number error
    BIOS_ERR_SUB_PFKEY_NUM = 68,
    /// @brief Sub-System general parameter error
    BIOS_ERR_SUB_PARAM = 69,
    /// @brief Sub-System command error
    BIOS_ERR_SUB_CMD = 70
} bios_stat_t;

/// @brief BIOS motor control flag
typedef enum bios_motor_flag_t {
    BIOS_MOTOR_ON = 0xFF,
    BIOS_MOTOR_OFF = 0x00
} bios_motor_flag_t;

/// @brief BIOS disk side
typedef enum bios_disk_side_t {
    BIOS_DISK_FRONT,
    BIOS_DISK_BACK
} bios_disk_side_t;

/// @brief BIOS request control block
typedef struct bios_rcb_t {
    /// @brief Request number
    uint8_t rqno;
    /// @brief Return status
    uint8_t rcbsta;
    
    union data {

        /// @brief Generic request control block layout that works for all commands
        struct generic {
            /// @brief Data buffer
            void* rcbdba;
            /// @brief Data buffer length
            uint16_t rcblnh;
            /// @brief TODO
            uint16_t rcbbmh;
        } generic;

        /// @brief Cassette motor control request control block layout
        struct motor {
            /// @brief The motor flag
            bios_motor_flag_t motorf;
        } motor;

        /// @brief Cassette read / write data request control block layout
        struct cassette {
            /// @brief The read / write data
            uint8_t crwdat;
        } cassette;

        /// @brief Screen hardcopy to parallel printer request control block layout
        struct screen {
            /// @brief Pointer to the 209 byte workspace buffer
            void* buffer;
            /// @brief Color filter bitmask
            uint8_t rcbcdt;
        } screen;

        /// @brief Disk control request control block layout
        struct disk {
            /// @brief Pointer to the 256 byte source / destination buffer
            void* buffer;
            /// @brief Track number
            uint8_t rcbtrk;
            /// @brief Sector number
            uint8_t rcbsct;
            /// @brief Disk side
            bios_disk_side_t rcbsid;
            /// @brief Drive number
            uint8_t rcbunt;
        } disk;

    } data;

} bios_rcb_t;

/// @brief Low level function that passes a raw request control block to the BIOS
/// @param rcb The request control block
/// @return The status code returned by the BIOS call
extern bios_stat_t bios_call(bios_rcb_t* rcb);

/// @brief Calls the BIOS routine to control the audio cassete motor
/// @param on Whether the motor should be on or not
/// @return The status code returned by the BIOS call
bios_stat_t bios_motor(bool on);

/// @brief Calls the BIOS routine to write a byte of data to the cassette tape
/// @param data The byte to write
/// @return The status code returned by the BIOS call
bios_stat_t bios_ctbwrt(uint8_t data);

/// @brief Calls the BIOS routine to read a byte of data from the cassette tape
/// @param data Pointer to the variable where the read byte will be stored
/// @return The status code returned by the BIOS call
bios_stat_t bios_ctbred(uint8_t* data);

/// @brief Calls the BIOS routine to send a 1:1 copy of the screen to the parallel printer
/// @param buffer Pointer to the start of the workspace buffer
/// @param color_bitmask Color bitmask to filter which colors are sent
/// @return The status code returned by the BIOS call
bios_stat_t bios_screen(void* buffer, uint8_t color_bitmask);

/// @brief Calls the BIOS routine to turn on the internal buzzer
/// @param drive The drive number
/// @return The status code returned by the BIOS call
bios_stat_t bios_restor(uint8_t drive);

/// @brief Calls the BIOS routine to write a sector to a floppy disk
/// @param buffer Pointer to the start of the source buffer
/// @param drive The drive number
/// @param disk_side The disk side
/// @param track The track number
/// @param sector The sector number
/// @return The status code returned by the BIOS call
bios_stat_t bios_dwrite(const void* buffer, uint8_t drive, bios_disk_side_t disk_side, uint8_t track, uint8_t sector);

/// @brief Calls the BIOS routine to write a sector to a floppy disk
/// @param buffer Pointer to the start of the destination buffer
/// @param drive The drive number
/// @param disk_side The disk side
/// @param track The track number
/// @param sector The sector number
/// @return The status code returned by the BIOS call
bios_stat_t bios_dread(void* buffer, uint8_t drive, bios_disk_side_t disk_side, uint8_t track, uint8_t sector);

/// @brief Calls the BIOS routine to turn on the internal buzzer
/// @return The status code returned by the BIOS call
bios_stat_t bios_beepon();

/// @brief Calls the BIOS routine to turn off the internal buzzer
/// @return The status code returned by the BIOS call
bios_stat_t bios_beepof();

/// @brief Calls the BIOS routine to output characters to the screen
/// @param str The string to output
/// @param n The length of the string
/// @return The status code returned by the BIOS call
bios_stat_t bios_output(const char* str, uint16_t n);

#endif