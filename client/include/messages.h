/*
** EPITECH PROJECT, 2021
** B-NWP-400-LIL-4-1-myteams-theo.selosse
** File description:
** messages
*/

#ifndef MESSAGES_H_
#define MESSAGES_H_

#include "client.h"

typedef struct message_s {

    char *sender;
    char *target;
    char *timestamp;
    char *content;

    unsigned long ti;

    struct message_s *next;

} message_t;

message_t *push_msg(message_t *head, char *sender, char *target,
char *content);
void dump_messages(message_t *head);
message_t *create_message(void);

#endif /* !MESSAGES_H_ */
