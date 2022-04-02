/*
** EPITECH PROJECT, 2021
** B-NWP-400-LIL-4-1-myteams-theo.selosse
** File description:
** connexions
*/

#include "../../include/functions.h"

bool check_requirements(client_t *current, char **cmd)
{
    if (current == NULL)
        return true;
    if (current->connected == true) {
        dprintf(0, "Already connected\n");
        dprintf(current->fd, "Already connected\r\n");
        return false;
    }
    if (count(cmd) != 2) {
        dprintf(0, "501 Wrong nb of arg, check /help command\n");
        dprintf(current->fd, "501 Wrong nb of arg, check /help command\r\n");
        return false;
    }
    if (cmd[1][0] == '\0') {
        dprintf(0, "username can't be empty\n");
        dprintf(current->fd, "username can't be empty\r\n");
        return false;
    }
    return true;
}

void login(char **cmd, server_t *server, client_t *current)
{
    client_t *saved = NULL;
    int i = get_index(server);

    if (check_requirements(current, cmd) == false)
        return;
    if ((saved = is_saved(server->saved, cmd[1])) != NULL) {
        if (already_created(current, saved, server, i) == true)
            return;
        else if (current->fd != saved->fd) {
            new_client(current, saved, server, i);
        }
    } else
        first_client(current, server, cmd, i);
    update_file(server->saved);
}

void logout(char **cmd, server_t *server, client_t *current)
{
    if (current->connected == false) {
        dprintf(current->fd, "UNAUTHORIZED\n");
        return;
    }
    dprintf(current->fd, "LOGOUT\n");
    exit_c(cmd, server, current);
    update_file(server->saved);
}

void exit_c(char **cmd, server_t *server, client_t *current)
{
    int i = get_index(server);

    (void)cmd;
    if (strncmp(current->name, "empty", 6) != 0) {
        server_event_user_logged_out(current->uid);
        server->clients[i].connected = false;
        current->connected = false;
    }
}