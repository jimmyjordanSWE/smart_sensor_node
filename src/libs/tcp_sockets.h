/*
    Creates, handles and destroys TCP sockets
*/
#ifndef TCP_SOCKETS_H
#define TCP_SOCKETS_H

#include <stdint.h>
#include <sys/socket.h>

// Socket creation and destruction
int tcps_create_socket(int* socket_fd);
void tcps_destroy_socket(int socket_fd);

ssize_t tcps_receive(int socket_fd, void* buffer, size_t length, int flags);
ssize_t tcps_send(int socket_fd, const void* buffer, size_t length, int flags);

// Socket configuration
int tcps_bind_to_address(int socket_fd, uint16_t port, const char* ip_address);

#endif // TCP_SOCKETS_H