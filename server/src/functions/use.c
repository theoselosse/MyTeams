/*
** EPITECH PROJECT, 2021
** B-NWP-400-LIL-4-1-myteams-theo.selosse
** File description:
** connexions
*/

#include "../../include/functions.h"
#include "../../include/client.h"
#include <uuid/uuid.h>

void use(char **cmd, server_t *server, client_t *current)
{
    int i;

    for (i = 0; cmd[i] != NULL; i++);
    if (i > 4 && i < 1) {
        dprintf(0, "501 Wrong nb of arg, check /help command\n");
        dprintf(current->fd, "501 Wrong nb of arg, check /help command\r\n");
        return;
    }
    if (current->cont_t == NULL && i == 2)
        use_team(cmd, server, current);
    else if (i == 1) {
        current->cont_c = NULL;
        current->cont_t = NULL;
        current->cont_th = NULL;
    }
}

void use_team(char **cmd, server_t *server, client_t *current)
{
    teams_t *current_t = server->team_list;

    while (current_t != NULL) {
        if (strncmp(current_t->name, cmd[1], strlen(current_t->name)) == 0) {
            current->cont_t = current_t;
            return;
        }
        current_t = current_t->next;
    }
    dprintf(current->fd, "UNKNOWN_TEAM %s\n", cmd[1]);
}
