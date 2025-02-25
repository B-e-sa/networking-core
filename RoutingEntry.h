#include <stdint.h>

struct RoutingEntry
{
    uint8_t dest[4];
    uint8_t gateway[4];
    uint8_t mask[4];
    uint8_t interface;
};