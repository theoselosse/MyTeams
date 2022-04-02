/*
** EPITECH PROJECT, 2021
** prep_team
** File description:
** communication
*/

#include "../include/teams.h"

client_t *is_saved(client_t *saved, char *name)
{
    client_t *current = saved;

    while (current != NULL) {
        if (strncmp(current->name, name, strlen(current->name)) == 0) {
            return current;
        }
        current = current->next;
    }
    return NULL;
}

int send_client(int fd, char *text)
{
    size_t size = strlen(text);

    return write(fd, text, size);
}

int get_index(server_t *serv)
{
    int index = 0;

    for (int i = 0; i < 30; i++) {
        if (serv->clients[i].fd == serv->current)
            index = i;
    }
    return index;
}

client_t *get_current(server_t *serv, int flag)
{
    client_t *current = serv->saved;

    while (current != NULL) {
        if (flag == 0) {
            if (current->fd == serv->current)
                return current;
        } else {
            if (current->fd == serv->current && current->connected == true)
                return current;
        }
        current = current->next;
    }
    return NULL;
}

int check_cmd(server_t *serv, char *buffer)
{
    char *clean = clean_input(buffer);
    char **parsed = str_to_array(clean);
    client_t *current = get_current(serv, 0);
    function_t *curr_func = serv->functions;

    if (clean[0] == '\0' || (parsed = remove_quotes(parsed)) == NULL) {
        return 1;
    }
    while (curr_func != NULL) {
        if (strncmp(parsed[0], curr_func->name, strlen(parsed[0])) == 0
        && strlen(parsed[0]) == strlen(curr_func->name)) {
            curr_func->ptr(parsed, serv, current);
            return 1;
        }
        curr_func = curr_func->next;
    }
    return 0;
}