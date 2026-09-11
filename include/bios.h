#ifndef _FM7_BIOS_H_
#define _FM7_BIOS_H_

/// @brief BIOS request type
typedef enum bios_req_t {
    BIOS_REQ_OUTPUT = 20
} bios_req_t;

/// @brief BIOS request control block
typedef struct bios_rcb_t {
    /// @brief Request number
    unsigned char rqno;
    /// @brief Return status
    unsigned char rcbsta;
    /// @brief Data buffer
    void* rcbdba;
    /// @brief Data buffer length
    unsigned int rcblnh;
    /// @brief TODO
    unsigned int rcbbmh;
} bios_rcb_t;

/// @brief Low level function that passes a raw request control block to the BIOS
/// @param rcb The request control block
/// @return The request status
extern unsigned char bios_call(bios_rcb_t* rcb);

/// @brief Calls the BIOS routine to output characters to the screen
/// @param str The string to output
/// @param n The length of the string
void bios_output(char* str, unsigned char n);

#endif