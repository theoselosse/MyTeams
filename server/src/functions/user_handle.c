/*
** EPITECH PROJECT, 2021
** B-NWP-400-LIL-4-1-myteams-theo.selosse
** File description:
** user_handle
*/

#include "../../include/functions.h"
#include <uuid/uuid.h>

bool already_created(client_t *curr, client_t *saved, server_t *server, int i)
{
    if (saved->fd != -1 && saved->connected == 1) {
        dprintf(curr->fd, "UNAUTHORIZED\n");
        return true;
    }
    if (strncmp(curr->name, saved->name, strlen(saved->name)) == 0 &&
    strncmp(curr->uid, saved->uid, strlen(saved->uid)) == 0) {
        server_event_user_logged_in(curr->uid);
        curr->connected = 1;
        server->clients[i].connected = curr->connected;
        check_file(curr);
        dprintf(curr->fd, "LOGIN %s %s\r\n",
        curr->name, curr->uid);
        update_file(server->saved);
        return true;
    }
    return false;
}

void new_client(client_t *current, client_t *saved, server_t *server, int i)
{

    if (strncmp(current->name, "empty", 6) == 0) {
        free(current->name);
        free(current->uid);
        current->name = strdup(saved->name);
        current->uid = strdup(saved->uid);
        server->clients[i].uid = current->uid;
    }
    server_event_user_logged_in(current->uid);
    saved->connected = 1;
    saved->fd = current->fd;
    current->fd = -1;
    current->connected = -1;
    server->clients[i].connected = true;
    server->clients[i].fd = saved->fd;
    check_file(current);
    dprintf(saved->fd, "LOGIN %s %s\r\n", current->name, current->uid);
    server->saved = remove_at(server->saved, current->name);
}

void first_client(client_t *current, server_t *server, char **cmd, int i)
{
    uuid_t uuid;
    char *uid;
    client_t *saved = NULL;

    if (current != NULL && strncmp(current->name, "empty", 6) == 0) {
        free(current->name);
        current->name = strdup(cmd[1]);
        server_event_user_created(current->uid, current->name);
        server_event_user_logged_in(current->uid);
        current->connected = 1;
        current->fd = server->current;
        server->clients[i].fd = server->current;
        server->clients[i].uid = current->uid;
        server->clients[i].connected = current->connected;
        check_file(current);
        dprintf(current->fd, "LOGIN %s %s\r\n", current->name, current->uid);
    } else {
        uid = malloc(sizeof(char) * 37);
        uuid_generate_random(uuid);
        uuid_unparse(uuid, uid);
        server->saved = push_back(server->saved, cmd[1], uid, current->fd);
        server_event_user_created(uid, cmd[1]);
        server_event_user_logged_in(uid);
        server->clients[i].uid = uid;
        saved = is_saved(server->saved, cmd[1]);
        saved->connected = 1;
        check_file(saved);
        server->clients[i].connected = saved->connected;
        dprintf(current->fd, "LOGIN %s %s\r\n", cmd[1], saved->uid);
    }
}