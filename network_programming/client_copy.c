#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <unistd.h>
#include <errno.h>
#include <stdio.h>
#include <time.h>
#include <string.h>


int main(int argv, char *argc[]) {
    printf("Connecting to remote server!");
    struct addrinfo hints;
    memset(&hints, 0, sizeof(hints));
    hints.ai_socktype = SOCK_STREAM;

    struct addrinfo *server_address;

    if (getaddrinfo("localhost", "8000", &hints, &server_address)) {
        fprintf(stderr, "Failed\n");
        return 1;
    }

    int socket_remote;

    socket_remote = socket(
        server_address->ai_family,
        server_address->ai_socktype,
        server_address->ai_protocol
    );

    if (socket_remote < 0) {
        fprintf(stderr, "socket() failed.");
        return 1;
    }

    if (connect(socket_remote, server_address->ai_addr, server_address->ai_addrlen)) {
        fprintf(stderr, "connect() failed");
        return 1;
    }

    freeaddrinfo(server_address);

    while (1) {
        fd_set reads;
        FD_ZERO(&reads);
        FD_SET(socket_remote, &reads);
        FD_SET(0, &reads); // Set stdin

        struct timeval timeout;
        timeout.tv_sec = 0;
        timeout.tv_usec = 100000;

        if (select(socket_remote + 1, &reads, 0, 0, &timeout) < 0) {
            fprintf(stderr, "select failed");
            return 1;
        }

        if (FD_ISSET(socket_remote, &reads)) {
            char read[4096];
            int bytes_received = recv(socket_remote, read, 4096, 0);
            if (bytes_received < 1) {
                printf("connection closed\n");
                break;
            }
            printf("received %d: %.*s", bytes_received, bytes_received, read);
        }

        if (FD_ISSET(0, &reads)) {
            char read[4096];

            if (!fgets(read, 4096, stdin)) break;

            printf("Sending: %s", read);
            int bytes_sent = send(socket_remote, read, strlen(read), 0);

            printf("sent %d bytes,\n", bytes_sent);
        }
        
    }

    return 0;
}