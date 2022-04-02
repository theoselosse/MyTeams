/*
** EPITECH PROJECT, 2021
** prep_team
** File description:
** clients
*/

#include "../include/teams.h"
#include <signal.h>

static int runn;

void select_client(server_t *serv, int max_clients)
{
    int activity;

    FD_ZERO(&serv->fd_read);
    FD_SET(serv->fd_socket, &serv->fd_read);
    for (int i = 0; i < max_clients; i++) {
        serv->current = serv->clients[i].fd;
        if (serv->current > 0)
            FD_SET(serv->current, &serv->fd_read);
        if (serv->current > serv->m_sock)
            serv->m_sock = serv->current;
    }
    activity = select(serv->m_sock + 1, &serv->fd_read, NULL, NULL, NULL);
    if (activity < 0) {
        if (errno == EINTR) {
            exit_clients(serv, max_clients);
            close_socket(serv->fd_socket);
            exit(0);
        }
        perror("select() error");
    }
}

void is_active(server_t *serv, int max_clients)
{
    int msg_size;
    char buffer[1025];

    for (int i = 0; i < max_clients; i++) {
        serv->current = serv->clients[i].fd;
        if (FD_ISSET(serv->current, &serv->fd_read)) {
            if ((msg_size = read(serv->current, buffer, 1024)) == 0) {
                exit_client(serv, i);
            } else {
                buffer[msg_size - 1] = '\0';
                if (check_cmd(serv, buffer) == 0) {
                    send_client(serv->current, "500 Wrong command\r\n");
                }
                else if (serv->clients[i].quitting == true)
                    exit_client(serv, i);
            }
        }
    }
}

bool add_to_list(server_t *server, int max_clients, int new_client)
{
    for (int i = 0; i < max_clients; i++) {
        if (server->clients[i].fd == 0) {
            server->clients[i].fd = new_client;
            server->clients[i].connected = false;
            return true;
        }
    }
    return false;
}

void handle_sigint(int sig)
{
    (void)sig;
    runn = 0;
}

int accept_client(server_t *serv)
{
    int max_clients = 30;

    runn = 1;
    serv->running = runn;
    signal(SIGINT, handle_sigint);
    while (serv->running != 0) {
        select_client(serv, max_clients);
        if (FD_ISSET(serv->fd_socket, &serv->fd_read)) {
            if (accept_socket(serv) == -1)
                return -1;
            add_to_list(serv, max_clients, serv->new_c);
        }
        if (runn != 0)
            is_active(serv, max_clients);
    }
    return 0;
}