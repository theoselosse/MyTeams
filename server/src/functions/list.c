/*
** EPITECH PROJECT, 2021
** B-NWP-400-LIL-4-1-myteams-theo.selosse
** File description:
** connexions
*/

#include "../../include/functions.h"
#include "../../include/client.h"
#include <uuid/uuid.h>

void list(char **cmd, server_t *server, client_t *current)
{
    int i;

    for (i = 0; cmd[i] != NULL; i++);
    if (i > 3 && i < 2) {
        dprintf(0, "501 Wrong nb of arg, check /help command\n");
        dprintf(current->fd, "501 Wrong nb of arg, check /help command\r\n");
        return;
    }
    if (current->cont_t == NULL)
        list_team(cmd, server, current);
    else if (current->cont_c == NULL)
        return;
    else if (current->cont_th == NULL)
        return;
    else
        return;
}

void list_team(char **cmd, server_t *server, client_t *current)
{
    (void)cmd;
    (void)server;
    char *content;
    int fd = open("./data/teams.txt", O_RDONLY);
    struct stat st = {};

    if (current->connected == false) {
        dprintf(current->fd, "UNAUTHORIZED\n");
        return;
    }
    if (stat("./data/teams.txt", &st) == -1)
        return;
    if ((content = malloc(sizeof(char) * st.st_size)) == NULL)
        return;
    if (fd != -1) {
        read(fd, content, st.st_size);
        dprintf(current->fd, "PRINT_TEAM %s\n", content);
        close(fd);
    }
    free(content);
}