/*
** EPITECH PROJECT, 2021
** prep_team
** File description:
** teams
*/

#include "../include/teams.h"
#include <uuid/uuid.h>

void setup_files(void)
{
    FILE *f;
    struct stat st = {};

    if (stat("./data", &st) == -1)
        mkdir("./data", 0700);
    if (stat("./data/users.txt", &st) == -1) {
        f = fopen("./data/users.txt", "w+");
        fclose(f);
    }
}

void init_functions(server_t *serv)
{
    serv->functions = NULL;
    serv->functions = push_b(serv->functions, "/help", help);
    push_b(serv->functions, "/login", login);
    push_b(serv->functions, "/send", send_msg);
    push_b(serv->functions, "/logout", logout);
    push_b(serv->functions, "/exit", exit_c);
    push_b(serv->functions, "/users", users);
    push_b(serv->functions, "/user", user);
    push_b(serv->functions, "/messages", messages);
    push_b(serv->functions, "/create", create);
    push_b(serv->functions, "/list", list);
    push_b(serv->functions, "/use", use);
}

client_t *fetch_save(client_t *client, char *line, size_t len)
{
    FILE *fp;
    ssize_t read;
    char **array;
    bool empty = true;

    if ((fp = fopen("./data/users.txt", "r")) == NULL)
        return NULL;
    while ((read = getline(&line, &len, fp)) != -1) {
        if (line[read - 1] == '\n')
            line[read - 1] = '\0';
        array = str_to_array(line);
        if (count(array) == 3) {
            empty = false;
            client = push_back(client, array[1], array[0], -1);
        }
    }
    fclose(fp);
    if (empty == false)
        return client;
    return NULL;
}

void init_struct(server_t *serv)
{
    client_t *tmp = NULL;
    serv->saved = NULL;

    for (int i = 0; i < 30; i++) {
        serv->clients[i].fd = 0;
        serv->clients[i].cont_c = NULL;
        serv->clients[i].cont_t = NULL;
        serv->clients[i].cont_th = NULL;
    }
    setup_files();
    serv->team_list = NULL;
    serv->saved = fetch_save(serv->saved, NULL, 0);
    serv->team_list = fetch_save_groups(serv, NULL, 0);
    tmp = serv->saved;
    while (tmp != NULL) {
        if (strcmp(tmp->name, "empty") != 0)
            server_event_user_loaded(tmp->uid, tmp->name);
        tmp = tmp->next;
    }
}

int teams(server_t *serv)
{
    serv->fd_socket = open_socket(serv->fd_socket);
    serv->m_sock = serv->fd_socket;
    if (serv->fd_socket == -1) {
        fprintf(stderr, "Error while opening the socket\n");
        return 84;
    }
    if (setup_socket(serv->fd_socket, serv->port) == -1) {
        fprintf(stderr, "Error while setuping the socket\n");
        return 84;
    }
    if (listen_socket(serv->fd_socket) == -1) {
        fprintf(stderr, "Error while listening the socket\n");
        return 84;
    }
    init_struct(serv);
    init_functions(serv);
    return serv->fd_socket;
}