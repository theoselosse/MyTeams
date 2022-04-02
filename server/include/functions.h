/*
** EPITECH PROJECT, 2021
** B-NWP-400-LIL-4-1-myteams-theo.selosse
** File description:
** functions
*/

#ifndef FUNCTIONS_H_
#define FUNCTIONS_H_

#include <sys/stat.h>
#include <time.h>
#include <fcntl.h>
#include "teams.h"

void help(char **cmd, server_t *server, client_t *);
void login(char **cmd, server_t *server, client_t *);
void logout(char **cmd, server_t *server, client_t *);
void send_msg(char **cmd, server_t *server, client_t *current);
void messages(char **cmd, server_t *server, client_t *current);
void exit_c(char **cmd, server_t *server, client_t *);
void users(char **cmd, server_t *server, client_t *current);
void user(char **cmd, server_t *server, client_t *current);
void create(char **cmd, server_t *server, client_t *);
void create_team(char **cmd, server_t *server, client_t *current, int size);
void create_channel(char **cmd, server_t *server, client_t *current, int size);
void create_thread(char **cmd, server_t *server, client_t *current, int size);
void create_reply(char **cmd, server_t *server, client_t *current, int size);
void use(char **cmd, server_t *server, client_t *current);
void use_team(char **cmd, server_t *server, client_t *current);
void list(char **cmd, server_t *server, client_t *);
void list_team(char **cmd, server_t *server, client_t *current);

void update_file(client_t *saved);
void update_t_file(teams_t *team_list);
int check_team_name(char *name, teams_t *head);
int check_all_errors(char **cmd, server_t *server, client_t *current, int size);
char *get_path(char *uid);
void check_file(client_t *current);
int loading_save(char *path, client_t *current);

void first_client(client_t *current, server_t *server, char **cmd, int i);
void new_client(client_t *current, client_t *saved, server_t *server, int i);
bool already_created(client_t *curr, client_t *saved, server_t *server, int i);

#endif /* !FUNCTIONS_H_ */
