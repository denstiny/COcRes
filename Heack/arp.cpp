#include<sys/socket.h>
#include<sys/types.h>
#include<sys/types.h>
#include<linux/if_ether.h>
#include<netinet/if_ether.h>
#include<arpa/inet.h>
#include<netpacket/packet.h>
#include<net/if.h>
struct arpbuf
{
	struct enther_header eth;
	struct enther_arp arp;
};

