/*
** EPITECH PROJECT, 2021
** B-NWP-400-LIL-4-1-myftp-hugo.humez
** File description:
** client
*/

#ifndef CLIENT_H_
#define CLIENT_H_

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

typedef struct teams_s teams_t;
typedef struct channel_s channel_t;
typedef struct thread_s thread_t;
typedef struct reply_s reply_t;

typedef struct client_s {
    int fd;
    int name_ok;
    int connected;
    int quitting;

    char *uid;
    char *name;

    teams_t *cont_t;
    channel_t *cont_c;
    thread_t *cont_th;
    struct client_s *next;
} client_t;

client_t *push_back(client_t *head, char *name, char *uid, int);
void dump_list(client_t *head);
client_t *remove_at(client_t *head, char *name);
client_t *get_node(client_t *head, char *uid);
client_t *remove_last(client_t *c, client_t *p, char *n, client_t *head);

typedef struct teams_s {
    char *uid;
    char *name;
    char *descr;

    struct teams_s *next;
    struct channel_s *list_channel;
    struct client_s *client_sub;
} teams_t;

typedef struct channel_s {
    char *uid;
    char *name;
    char *descr;

    struct channel_s *next;
    struct thread_s *list_thread;
} channel_t;

typedef struct thread_s {
    char *uid;
    char *name;
    char *message;

    struct thread_s *next;
    struct reply_s *list_replies;
} thread_t;

typedef struct reply_s {
    char *comment;

    struct reply_s *next;
    struct client_s *author;
} reply_t;

//manage teams linked list

teams_t *push_b_teams(teams_t *head, char *name, char *uid, char *descr);
void dump_l_team(teams_t *head);

//manage channels linked lists

channel_t *set_info_channel(char *name, char *uid, char *descr);
teams_t *push_b_channel(teams_t *head, client_t *current, channel_t *new_c);
void dump_l_channel(channel_t *head);

//manage threads linked lists

thread_t *set_info_thread(char *name, char *uid, char *descr);
teams_t *push_b_thread(teams_t *head, client_t *current, thread_t *new_t);
void dump_l_thread(thread_t *head);

//manage replies linked lists

reply_t *set_info_reply(client_t *author, char *comment);
teams_t *push_b_reply(teams_t *head, client_t *current, reply_t *new_r);
void dump_l_reply(reply_t *head);

//get context functions
teams_t *get_team_context(teams_t *head, client_t *current_c);
channel_t *get_channel_context(channel_t *head, client_t *current_c);
thread_t *get_thread_context(thread_t *head, client_t *current_c);

#endif /* !CLIENT_H_ */
