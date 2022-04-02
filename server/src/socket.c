/*
** EPITECH PROJECT, 2021
** prep_team
** File description:
** socket
*/

#include "../include/teams.h"
#include <uuid/uuid.h>

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

int setup_socket(int fd_socket, int port)
{
    struct sockaddr_in addr;
    socklen_t size;

    addr.sin_family = AF_INET;
    addr.sin_port = htons(port);
    addr.sin_addr.s_addr = INADDR_ANY;
    size = sizeof(struct sockaddr_in);
    if (bind(fd_socket, (const struct sockaddr *) &addr, size) == -1) {
        perror("bind() error");
        close_socket(fd_socket);
        return -1;
    }
    return 0;
}

int listen_socket(int fd_socket)
{
    if (listen(fd_socket, 10) != 0) {
        perror("listen() error");
        close_socket(fd_socket);
        return -1;
    }
    return 0;
}

int accept_socket(server_t *serv)
{
    int addrlen = sizeof(serv->addr);
    client_t *client = malloc(sizeof(client_t));
    uuid_t uuid;

    if ((serv->new_c = accept(serv->fd_socket,
        (struct sockaddr *) &serv->addr, (socklen_t *) &addrlen)) < 0) {
        perror("accept() error");
        return -1;
    }
    client->uid = malloc(sizeof(char) * 37);
    uuid_generate_random(uuid);
    uuid_unparse(uuid, client->uid);
    serv->saved = push_back(serv->saved, "empty", client->uid, serv->new_c);
    return 0;
}