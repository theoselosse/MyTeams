/*
** EPITECH PROJECT, 2021
** B-NWP-400-LIL-4-1-myftp-hugo.humez
** File description:
** server
*/

#ifndef SERVER_H_
#define SERVER_H_

#include <netinet/in.h>
#include "list_functions.h"
#include "client.h"

typedef struct server_s server_t;

typedef struct function_s function_t;

typedef void (*f_ptr)(char **cmd, server_t *server, client_t *current);

struct server_s {
    int fd_socket;
    int port;

    bool running;

    int new_c;
    struct sockaddr_in addr;
    fd_set fd_read;
    fd_set fd_write;
    int current;
    int m_sock;

    teams_t *team_list;
    function_t *functions;
    client_t clients[30];

    client_t *saved;
};


#endif /* !SERVER_H_ */
