/*
** EPITECH PROJECT, 2021
** B-NWP-400-LIL-4-1-myteams-theo.selosse
** File description:
** helper
*/

#include "../../include/functions.h"

void disp_help2(int fd)
{
    dprintf(fd, "/help: show help\n");
    dprintf(fd, "/login [\"user_name\"]: set the user_name used by client\r\n");
    dprintf(fd, "/logout: disconnect the client from the server\r\n");
    dprintf(fd, "%s%s", "/users: get the list of all",
    " users that exist on the domain\r\n");
    dprintf(fd, "/user [\"user_uuid\"]: get information about a user\r\n");
    dprintf(fd, "/create [\"group_name\"] [\"group_descr\"]: create group\n");
}

void help(char **cmd, server_t *server, client_t *current)
{
    dprintf(0, "/help: show help\n");
    dprintf(0, "/login [\"user_name\"]: set the user_name used by client\n");
    dprintf(0, "/logout: disconnect the client from the server\n");
    dprintf(0, "/users: get the list of all users that exist on the domain\n");
    dprintf(0, "/user [\"user_uuid\"]: get information about a user\n");
    dprintf(0, "/create [\"group_name\"] [\"group_descr\"]: create group\n");
    disp_help2(server->current);
    (void)cmd;
    (void)current;
}