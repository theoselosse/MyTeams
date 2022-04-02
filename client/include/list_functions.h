/*
** EPITECH PROJECT, 2021
** B-NWP-400-LIL-4-1-myteams-theo.selosse
** File description:
** list_functions
*/

#ifndef LIST_FUNCTIONS_H_
#define LIST_FUNCTIONS_H_

#include "client.h"

typedef struct client_s client_t;
typedef struct function_s function_t;
typedef void (*f_ptr)(char **cmd, client_t *current);

struct function_s {
    char *name;
    f_ptr ptr;
    function_t *next;
};

function_t *push_b(function_t *head, char *name,
void (*)(char **cmd, client_t *current));

void change_name(char **cmd, client_t *client);
void change_uid(char **cmd, client_t *client);
void login(char **cmd, client_t *client);
void logout(char **cmd, client_t *client);
void send_reply(char **cmd, client_t *client);
void goodbye(char **cmd, client_t *client);
void unauthorized(char **cmd, client_t *client);
void unknown(char **cmd, client_t *client);
void dump_client(char **cmd, client_t *client);
void list_clients(char **cmd, client_t *client);
void list_messages(char **cmd, client_t *client);
void team_created(char **cmd, client_t *client);
void already_exist(char **cmd, client_t *client);
void unknown_team(char **cmd, client_t *client);
void print_team(char **cmd, client_t *client);
void print_team_created(char **cmd, client_t *client);

char *get_path(char *);

#endif /* !LIST_FUNCTIONS_H_ */
