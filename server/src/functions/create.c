/*
** EPITECH PROJECT, 2021
** B-NWP-400-LIL-4-1-myteams-theo.selosse
** File description:
** connexions
*/

#include "../../include/functions.h"
#include "../../include/client.h"
#include <uuid/uuid.h>

void create(char **cmd, server_t *server, client_t *current)
{
    int i;

    for (i = 0; cmd[i] != NULL; i++);
    if (i > 3 && i < 2) {
        dprintf(0, "501 Wrong nb of arg, check /help command\n");
        dprintf(current->fd, "501 Wrong nb of arg, check /help command\r\n");
        return;
    }
    if (current->cont_t == NULL) {
        create_team(cmd, server, current, i);
        update_t_file(server->team_list);
    }
    else if (current->cont_c == NULL)
        return;
    else if (current->cont_th == NULL)
        return;
    else
        return;
}

void create_team(char **cmd, server_t *server, client_t *current, int size)
{
    char *uid = malloc(sizeof(char) * 37);
    uuid_t uuid;
    client_t *current_c = server->saved;

    if (check_all_errors(cmd, server, current, size) == 1)
        return;
    uuid_generate_random(uuid);
    uuid_unparse(uuid, uid);
    server->team_list = push_b_teams(server->team_list, cmd[1], uid, cmd[2]);
    server_event_team_created((const char *)uid, (const char *)cmd[1],
    (const char *)current->uid);
    dprintf(current->fd, "PRINT_TEAM_CREATED %s %s %s\n", cmd[1],
    uid, cmd[2]);
    while (current_c != NULL) {
        if (current_c->connected == true && current_c->fd != current->fd) {
            dprintf(current_c->fd, "TEAM_CREATED %s %s %s\n", cmd[1],
            uid, cmd[2]);
        }
        current_c = current_c->next;
    }
}

void create_channel(char **cmd, server_t *server, client_t *current, int size)
{
    char *uid;
    uuid_t uuid;

    if (size != 3 || current->cont_c != NULL || current->cont_t == NULL
    || current->cont_th != NULL)
        return;
    uid = malloc(sizeof(char) * 37);
    uuid_generate_random(uuid);
    uuid_unparse(uuid, uid);
    server->team_list = push_b_channel(server->team_list, current,
    set_info_channel(cmd[1], uid, cmd[2]));
}

void create_thread(char **cmd, server_t *server, client_t *current, int size)
{
    char *uid;
    uuid_t uuid;

    if (size != 3 || current->cont_c == NULL || current->cont_t == NULL
    || current->cont_th != NULL)
        return;
    uid = malloc(sizeof(char) * 37);
    uuid_generate_random(uuid);
    uuid_unparse(uuid, uid);
    server->team_list = push_b_thread(server->team_list, current,
    set_info_thread(cmd[1], uid, cmd[2]));
}

void create_reply(char **cmd, server_t *server, client_t *current, int size)
{
    char *uid;
    uuid_t uuid;

    if (size != 3 || current->cont_c == NULL || current->cont_t == NULL
    || current->cont_th != NULL)
        return;
    uid = malloc(sizeof(char) * 37);
    uuid_generate_random(uuid);
    uuid_unparse(uuid, uid);
    server->team_list = push_b_reply(server->team_list, current,
    set_info_reply(current, cmd[1]));
}