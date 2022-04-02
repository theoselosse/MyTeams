/*
** EPITECH PROJECT, 2021
** B-NWP-400-LIL-4-1-myteams-theo.selosse
** File description:
** client
*/

#ifndef CLIENT_H_
#define CLIENT_H_

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <sys/select.h>
#include <arpa/inet.h>
#include <stdbool.h>
#include "list_functions.h"
#include "../../libs/myteams/logging_client.h"
#include "messages.h"

typedef struct function_s function_t;
typedef struct message_s message_t;

typedef struct client_s {
    int fd_socket;

    int name_ok;
    int connected;
    int quitting;

    char *uid;
    char *name;

    function_t *functions;
    struct client_s *next;

    message_t *pms;

} client_t;

int init_client(int port, char *ip);
int exec_client(int);
bool select_setup();
bool send_client(client_t *client, int c);
void read_client(int fd, client_t *client);
bool execute_action(client_t *client, fd_set fd_read);

char *clean_input(char *str);
char *convert_space(char *input);
char **str_to_array(char *input);
int count_word(char *input);
int count(char **array);

bool parse_entry(char *buffer);
void handle_sigint(int sig);

bool check_cmd(client_t *client, char *buffer);

#endif /* !CLIENT_H_ */
