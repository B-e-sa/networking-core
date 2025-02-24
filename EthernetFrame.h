#include <stdio.h>
#include <stdint.h>
#include <string.h>

#define ETHERNET_PAYLOAD_MIN 46
#define ETHERNET_PAYLOAD_MAX 1500

struct EthernetFrame
{
    uint8_t preamble[7]; // preamble de 7 bits, seguido por
    uint8_t sfd;         // um sfd de 1 bit, totalizando 8 bits (1 byte)
    uint8_t dest[6];
    uint8_t src[6];
    uint16_t typeLength;
    uint8_t payload[ETHERNET_PAYLOAD_MAX];
    uint32_t fcs;
};