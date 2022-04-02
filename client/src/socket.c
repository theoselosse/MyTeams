/*
** EPITECH PROJECT, 2021
** B-NWP-400-LIL-4-1-myteams-theo.selosse
** File description:
** socket
*/

#include "../include/client.h"

int open_socket(int fd_socket)
{
    fd_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (fd_socket == -1) {
        perror("socket() error");
        return -1;
    }
    return fd_socket;
}

int close_socket(int fd_socket)
{
    if (close(fd_socket) == -1) {
        perror("close() error");
        return -1;
    }
    return 0;
}

int connect_socket(int fd_socket, int port, char *ip)
{
    struct sockaddr_in sockaddr;
    socklen_t size;

    sockaddr.sin_family = AF_INET;
    sockaddr.sin_port = htons(port);
    sockaddr.sin_addr.s_addr = inet_addr(ip);
    size = sizeof(struct sockaddr_in);
    if (connect(fd_socket, (const struct sockaddr *) &sockaddr, size) == -1) {
        perror("connect() error");
        if (close_socket(fd_socket) == -1)
            return (-1);
        return -1;
    }
    return (0);
}

int init_client(int port, char *ip)
{
    int fd_client = 0;

    if ((fd_client = open_socket(fd_client)) == -1)
        return -1;
    if (connect_socket(fd_client, port, ip) == -1)
        return -1;
    return fd_client;
}