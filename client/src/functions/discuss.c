/*
** EPITECH PROJECT, 2021
** B-NWP-400-LIL-4-1-myteams-theo.selosse
** File description:
** discuss
*/

#include <time.h>
#include "../../include/list_functions.h"

void update_msg(client_t *client, message_t *msg)
{
    message_t *message = msg;
    FILE *f;
    char *path = get_path(client->uid);

    f = fopen(path, "w+");
    if (f == NULL) {
        perror("fopen():");
        return;
    }
    while (message != NULL) {
        fprintf(f, "%s %s %lu %s\n", message->sender, message->target,
        message->ti, message->content);
        message = message->next;
    }
    fclose(f);
}

void send_reply(char **cmd, client_t *client)
{
    client_event_private_message_received(cmd[1], cmd[3]);
    client->pms = push_msg(client->pms, cmd[1], cmd[2], cmd[3]);
    update_msg(client, client->pms);
}

void dump_client(char **cmd, client_t *client)
{
    int status = atoi(cmd[3]);

    (void)client;
    client_print_user(cmd[1], cmd[2], status);
}

void list_messages(char **cmd, client_t *client)
{
    char *tmp_sender = NULL;
    char *tmp_content = NULL;
    unsigned long t;
    struct tm tm = {};

    (void)cmd;
    (void)client;
    for (int i = 1; cmd[i]; i++) {
        memset(&tm, 0, sizeof(tm));
        if (i % 4 == 1)
            tmp_sender = cmd[i];
        else if (i % 4 == 3) {
            t = strtoul(cmd[i], NULL, 10);
        }
        else if (i % 4 == 0) {
            tmp_content = cmd[i];
            client_private_message_print_messages(tmp_sender, t, tmp_content);
        }
    }
}

void list_clients(char **cmd, client_t *client)
{
    char *tmp_uid = NULL;
    char *tmp_name = NULL;
    char *tmp_status = NULL;

    (void)cmd;
    (void)(client);
    for (int i = 1; cmd[i]; i++) {
        if (i % 3 == 1)
            tmp_uid = cmd[i];
        else if (i % 3 == 2)
            tmp_name = cmd[i];
        else if (i % 3 == 0) {
            tmp_status = cmd[i];
            if (strncmp(tmp_name, "empty", 6) != 0)
                client_print_user(tmp_uid, tmp_name, atoi(tmp_status));
        }
    }
}