/*
** EPITECH PROJECT, 2021
** B-NWP-400-LIL-4-1-myteams-theo.selosse
** File description:
** errors_client
*/

#include "../../include/list_functions.h"

char *get_path(char *uid)
{
    char *folder = "./data/";
    char *end = ".txt";
    int size = strlen(folder) + strlen(uid) + strlen(end);
    char *path = malloc(sizeof(char) * size + 1);
    int i = 0;

    if (path == NULL)
        return NULL;
    path[size] = '\0';
    for (; folder[i] != '\0'; i++)
        path[i] = folder[i];
    for (int j = 0; uid[j] != '\0'; j++, i++)
        path[i] = uid[j];
    for (int k = 0; end[k] != '\0'; k++, i++)
        path[i] = end[k];
    return path;
}

void unauthorized(char **cmd, client_t *client)
{
    (void)client;
    (void)cmd;
    client_error_unauthorized();
}

void unknown(char **cmd, client_t *client)
{
    (void)client;
    client_error_unknown_user(cmd[1]);
}

void already_exist(char **cmd, client_t *client)
{
    (void)cmd;
    (void)client;
    client_error_already_exist();
}

void unknown_team(char **cmd, client_t *client)
{
    (void)client;
    client_error_unknown_team(cmd[1]);
}