#include <stdio.h>
#include <stdint.h>
#include "ArpEntry.h"
#include "RoutingEntry.h"

enum ConnectionType 
{
	DHCP,
	FIXED_IP,
	PPPOE
};

struct NetworkDevice
{
	enum ConnectionType connectionType;
	struct ArpEntry arpTable[254];
	uint8_t mac[6];
	uint8_t ipv4[4];
	uint8_t ipv6[16];
	uint8_t defaultGateway[4];
	uint8_t subnetMask[4];
	uint8_t dnsDomain[4];
	uint8_t availablePorts;
};

struct Router
{
	enum ConnectionType connectionType;
	struct RoutingEntry routingTable[254];
	uint8_t routingCount;
	struct ArpEntry arpTable[254];
	uint8_t arpCount;
	uint8_t mac[6];
	uint8_t ipv4[4];
	uint8_t ipv6[16];
	uint8_t subnetMask[4];
	uint8_t startIp[4];
	uint8_t endIp[4];
	uint8_t dnsDomain[4];
	uint8_t availablePorts;
};