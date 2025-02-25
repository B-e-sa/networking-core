#include "Devices.h"
#include <string.h>


// TODO: DHCP DISC, REQ, OFF, ACK
struct Cable 
{
    // Dispositivo -> Roteador
    int connect(
        NetworkDevice* srcDevice,
        Router* endDevice)
    {
        if (srcDevice->availablePorts != 0 && endDevice->availablePorts != 0)
        {
            // desaloca portas disponíveis
            srcDevice->availablePorts--;
            endDevice->availablePorts--;

            // preechimento da tabela arp
            memcpy(
                endDevice->arpTable[endDevice->arpCount].ipv4, 
                srcDevice->ipv4, 
                sizeof(srcDevice->ipv4)); // IPv4
            memcpy(
                endDevice->arpTable[endDevice->arpCount].mac, 
                srcDevice->mac, 
                sizeof(srcDevice->mac)); // MAC
            endDevice->arpCount++;

            // preenchimento da tabela de roteamento
            memcpy(
                endDevice->routingTable[endDevice->routingCount].dest, 
                srcDevice->ipv4, 
                sizeof(srcDevice->ipv4)); // IPv4
            memcpy(
                endDevice->routingTable[endDevice->routingCount].gateway, 
                srcDevice->mac, 
                sizeof(srcDevice->mac)); // gateway
            memcpy(
                endDevice->routingTable[endDevice->routingCount].mask,
                srcDevice->subnetMask, 
                sizeof(srcDevice->subnetMask)); // máscara

            endDevice->routingTable[endDevice->routingCount]
                .interface = 0; // indicando conexão a interface 0, ethernet
        }
    };
};