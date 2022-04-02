/*
** EPITECH PROJECT, 2021
** B-NWP-400-LIL-4-1-myteams-theo.selosse
** File description:
** connexions
*/

#include "../../include/functions.h"
#include "../../include/client.h"
#include <uuid/uuid.h>

int check_team_name(char *name, teams_t *head)
{
    teams_t *current = head;

    while (current != NULL) {
        if (strncmp(current->name, name, strlen(current->name) + 1) == 0)
            return (1);
        current = current->next;
    }
    return (0);
}

int check_all_errors(char **cmd, server_t *server, client_t *current, int size)
{
    if (size != 3 || current->cont_c != NULL || current->cont_t != NULL
    || current->cont_th != NULL || current->connected == false) {
        dprintf(current->fd, "UNAUTHORIZED\n");
        return (1);
    } if (check_team_name(cmd[1], server->team_list) == 1) {
        dprintf(current->fd, "ALR_EXIST\n");
        return (1);
    }
    return (0);
}

