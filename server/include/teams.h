/*
** EPITECH PROJECT, 2021
** B-NWP-400-LIL-4-1-myftp-hugo.humez
** File description:
** ftp
*/

#ifndef FTP_H_
#define FTP_H_

#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <ctype.h>

#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/select.h>

#include <stdbool.h>
#include <errno.h>
#include <linux/limits.h>
#include "server.h"
#include "../../libs/myteams/logging_server.h"
#include "client.h"
#include "list_functions.h"
#include "functions.h"

int teams(server_t *serv);

int ftp(int port, server_t *server);

//Socket
int open_socket();
int close_socket(int);
int setup_socket(int fd_socket, int port);
int listen_socket(int fd_socket);
int accept_socket(server_t * serv);

//Client
int accept_client(server_t *serv);
int send_client(int fd, char *text);
void exit_client(server_t *serv, int i);
void exit_clients(server_t *serv, int max_clients);

char *clean_input(char *str);
char *convert_space(char *input);
char **str_to_array(char *input);
char **remove_quotes(char ** array);
int count_word(char *input);
int count(char **array);

int get_index(server_t *serv);

void init_client(client_t *client);

int check_cmd(server_t *serv, char *buffer);
client_t *is_saved(client_t *saved, char *name);

//fetch saved data
teams_t *fetch_save_groups(server_t *serv, char *line, size_t len);

#endif /* !FTP_H_ */