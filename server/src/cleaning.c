/*
** EPITECH PROJECT, 2021
** B-NWP-400-LIL-4-1-myteams-theo.selosse
** File description:
** cleaning
*/

#include "../include/teams.h"

void exit_client(server_t *serv, int i)
{
    if (serv->clients[i].quitting == true) {
        close(serv->current);
        serv->clients[i].fd = 0;
        serv->clients[i].name_ok = -1;
        serv->clients[i].connected = 0;
        serv->clients[i].quitting = 0;
    } else {
        close(serv->current);
        serv->clients[i].fd = 0;
        serv->clients[i].name_ok = -1;
        serv->clients[i].connected = 0;
        serv->clients[i].quitting = 0;
    }
}

char *replace_string(int pos, char *str, char *tmp)
{
    tmp = malloc(sizeof(char) * pos + 1);
    tmp[pos] = '\0';
    strcpy(tmp, str);
    str[pos - 2] = '\0';
    for (int j = 0, k = 0; j < pos && str[j] != '\0' &&
    tmp[k] != '\0'; j++, k++) {
        if (tmp[k] == '"')
            k++;
        str[j] = tmp[k];
    }
    return str;
}

char **remove_quotes(char ** array)
{
    int pos = 0;
    char *tmp = NULL;

    if (count(array) == 1)
        return array;
    for (int i = 0; array[i] != NULL; i++) {
        if (i == 0)
            continue;
        if (array[i][0] != '"' || array[i][strlen(array[i]) - 1] != '"')
            return NULL;
        else {
            pos = strlen(array[i]);
            if (pos < 2)
                continue;
            array[i] = replace_string(pos, array[i], tmp);
        }
    }
    return array;
}