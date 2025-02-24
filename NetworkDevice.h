#include <stdio.h>
#include <stdint.h>

typedef enum ConnectionType 
{
	DHCP,
	FIXED_IP,
	PPPoE
}

typedef struct NetworkDevice
{
	ConnectionType;
	uint8_t mac[6]
	uint8_t ipv4[4]
	uint8_t ipv6[16]
	uint8_t defaultGateway[4]
	uint8_t subnetMask[4]
	uint8_t dnsDomain[4]
}