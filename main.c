#include <stdio.h>
#include <string.h>
#include "EthernetFrame.h"
#include "Devices.h"

int main() {
	/**
	 * Configuração do roteador:
	 * Portas fisicas:     4
	 * Conexão:            IP Fixo
	 * Servidor dns:       8.8.8.8
	 * Máscara de subrede: 255.255.255.0
	 * Endereço IPv4:      192.168.2.1
	 * Inicio de pool:     192.168.2.0
	 * Fim de pool:        192.168.2.254
	 */
	// ###### INICIO DE CONFIGURACAO ROTEADOR ######
	struct Router router;
	router.availablePorts = 4;
	router.arpCount = 0;
	router.routingCount = 0;
	router.connectionType = FIXED_IP;

	uint8_t startIp[4] = {192,168,1,0};
	memcpy(router.startIp, startIp, sizeof(startIp));

	uint8_t endIp[4] = {192,168,1,254};
	memcpy(router.endIp, endIp, endIp);

	uint8_t ipv4[4] = {192,168,2,1};
	memcpy(router.ipv4, ipv4, sizeof(ipv4));

	uint8_t dns[4] = {8,8,8,8};
	memcpy(router.dnsDomain, dns, sizeof(dns));

	uint8_t mask[4] = {255,255,255,0};
	memcpy(router.subnetMask, mask, sizeof(mask));
	// ###### FIM DE CONFIGURACAO ROTEADOR ######
}