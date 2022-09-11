#include <sys/socket.h>
#include <netdb.h>
#include <ifaddrs.h>
#include <stdio.h>
#include <stdlib.h>

int print_addr(char buff[], struct sockaddr **address) {
    struct sockaddr *addr = *address;
    return sprintf(buff, "Address: %hhu", addr->sa_family);
}

int main() {
    struct ifaddrs *addresses;
    if (getifaddrs(&addresses) == -1) {
        printf("getifaddrs call failed\n");
        return -1;
    }

    struct ifaddrs *address = addresses;

    while ( address ) {
        int family = address->ifa_addr->sa_family;
        if ( family == AF_INET || family == AF_INET6 ) {
            printf("%s\t", address->ifa_name);
            printf("%s\t", family == AF_INET ? "IPv4" : "IPv6");
            char ip[100];
            const int family_size = family == AF_INET ? sizeof(struct sockaddr_in) : sizeof(struct sockaddr_in6);

            getnameinfo(address->ifa_addr, family_size, ip, sizeof(ip), 0, 0, NI_NUMERICHOST);
            printf("\t%s\n", ip);
        }
        
        address = address->ifa_next;
    }

    freeifaddrs(addresses);
    return 0;
}