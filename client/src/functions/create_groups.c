/*
** EPITECH PROJECT, 2021
** B-NWP-400-LIL-4-1-myteams-theo.selosse
** File description:
** discuss
*/

#include "../../include/list_functions.h"

void team_created(char **cmd, client_t *client)
{
    char *tmp_uid = NULL;
    char *tmp_name = NULL;
    char *tmp_descr = NULL;

    for (int i = 1; cmd[i]; i++) {
        if (i % 3 == 1)
            tmp_name = cmd[i];
        else if (i % 3 == 2)
            tmp_uid = cmd[i];
        else if (i % 3 == 0) {
            tmp_descr = cmd[i];
        }
    }
    (void)client;
    client_event_team_created((const char *)tmp_uid,
    (const char *)tmp_name, (const char *)tmp_descr);
}

void print_team(char **cmd, client_t *client)
{
    char *tmp_uid = NULL;
    char *tmp_name = NULL;
    char *tmp_descr = NULL;

    (void)cmd;
    (void)client;
    for (int i = 1; cmd[i]; i++) {
        if (i % 3 == 1)
            tmp_name = cmd[i];
        else if (i % 3 == 2)
            tmp_uid = cmd[i];
        else if (i % 3 == 0) {
            tmp_descr = cmd[i];
            client_print_teams((const char *)tmp_uid,
            (const char *)tmp_name, (const char *)tmp_descr);
        }
    }
}

void print_team_created(char **cmd, client_t *client)
{
    (void)client;
    client_print_team_created((const char *)cmd[1],
    (const char *)cmd[2], (const char *)cmd[3]);
    client_event_team_created((const char *)cmd[1],
    (const char *)cmd[2], (const char *)cmd[3]);
}

