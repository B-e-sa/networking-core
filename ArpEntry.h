#include <stdint.h>

struct ArpEntry
{
    uint8_t mac[6];
    uint8_t ipv4[4];
};