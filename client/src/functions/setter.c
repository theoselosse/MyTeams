/*
** EPITECH PROJECT, 2021
** B-NWP-400-LIL-4-1-myteams-theo.selosse
** File description:
** setter
*/

#include "../../include/list_functions.h"

void change_name(char **cmd, client_t *client)
{
    free(client->name);
    client->name = strdup(cmd[1]);
}

void change_uid(char **cmd, client_t *client)
{
    free(client->uid);
    client->uid = strdup(cmd[2]);
}

void login(char **cmd, client_t *client)
{
    change_name(cmd, client);
    change_uid(cmd, client);
    client->connected = true;
    client_event_logged_in(cmd[2], cmd[1]);
}

void logout(char **cmd, client_t *client)
{
    (void)cmd;
    client->connected = false;
    client_event_logged_out(client->uid, client->name);
}

void goodbye(char **cmd, client_t *client)
{
    (void)cmd;
    if (strncmp(client->name, "empty", 6) != 0)
        client_event_logged_out(client->uid, client->name);
    exit(0);
}