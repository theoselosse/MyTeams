/*
** EPITECH PROJECT, 2021
** B-NWP-400-LIL-4-1-myteams-theo.selosse
** File description:
** logging_out_clients
*/

#include "../include/teams.h"

void exit_clients(server_t *serv, int max_clients)
{
    for (int i = 0; i < max_clients; i++) {
        if (serv->clients[i].fd != 0) {
            if (serv->clients[i].connected == true)
                server_event_user_logged_out(serv->clients[i].uid);
            dprintf(serv->clients[i].fd, "GOODBYE\r\n");
            close_socket(serv->clients[i].fd);
            serv->clients[i].fd = 0;
        }
    }
}