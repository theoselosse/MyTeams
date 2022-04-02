/*
** EPITECH PROJECT, 2021
** B-NWP-400-LIL-4-1-myteams-theo.selosse
** File description:
** execution
*/

#include <signal.h>
#include <errno.h>
#include "../include/client.h"
#include "../include/signal_handler.h"

static bool running;

void init_functions(client_t *client)
{
    client->functions = NULL;
    client->functions = push_b(client->functions, "CHANGE_NAME", change_name);
    push_b(client->functions, "CHANGE_UID", change_uid);
    push_b(client->functions, "LOGIN", login);
    push_b(client->functions, "LOGOUT", logout);
    push_b(client->functions, "SEND", send_reply);
    push_b(client->functions, "GOODBYE", goodbye);
    push_b(client->functions, "UNAUTHORIZED", unauthorized);
    push_b(client->functions, "UNKNOWN", unknown);
    push_b(client->functions, "DUMP_CLIENT", dump_client);
    push_b(client->functions, "LIST_CLIENTS", list_clients);
    push_b(client->functions, "LIST_MESSAGES", list_messages);
    push_b(client->functions, "TEAM_CREATED", team_created);
    push_b(client->functions, "ALR_EXIST", already_exist);
    push_b(client->functions, "UNKNOWN_TEAM", unknown_team);
    push_b(client->functions, "PRINT_TEAM", print_team);
    push_b(client->functions, "PRINT_TEAM_CREATED", print_team_created);
}

void setup_client(client_t *client, int fd)
{
    client->uid = strdup("empty");
    client->name = strdup("empty");
    client->fd_socket = fd;
    init_functions(client);
}

void handle_sigint(int sig)
{
    (void)sig;
    running = 0;
}

bool check_cmd(client_t *client, char *buffer)
{
    char *clean = clean_input(buffer);
    char **parsed = str_to_array(clean);
    function_t *curr_func = client->functions;

    if (clean[0] == '\0') {
        write(0, "Please enter a command\r\n", 25);
        return 1;
    }
    while (curr_func != NULL) {
        if (strncmp(parsed[0], curr_func->name, strlen(parsed[0])) == 0
        && strlen(parsed[0]) == strlen(curr_func->name)) {
            curr_func->ptr(parsed, client);
            return 1;
        }
        curr_func = curr_func->next;
    }
    return 0;
}

int exec_client(int fd)
{
    client_t *client = malloc(sizeof(client_t));
    setup_client(client, fd);
    fd_set fd_read;
    running = 1;

    signal(SIGINT, handle_sigint);
    while (running != 0) {
        FD_ZERO(&fd_read);
        FD_SET(client->fd_socket, &fd_read);
        FD_SET(STDIN_FILENO, &fd_read);
        if (select(client->fd_socket + 1, &fd_read, NULL, NULL, NULL) == -1) {
            if (select_setup() == true)
                continue;
        }
        running = execute_action(client, fd_read);
    }
    if (client->connected == true)
        logout(NULL, client);
    write(client->fd_socket, "/exit", 6);
    exit(0);
}