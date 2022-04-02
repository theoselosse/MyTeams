/*
** EPITECH PROJECT, 2021
** B-NWP-400-LIL-4-1-myteams-theo.selosse
** File description:
** messages
*/

#include "../../include/messages.h"

message_t *create_message(void)
{
    message_t *tmp = malloc(sizeof(message_t));
    tmp->next = NULL;
    return tmp;
}

void dump_messages(message_t *head)
{
    message_t *current = head;

    while (current != NULL) {
        printf("%s %s\n%s\n", current->sender,
        current->target, current->content);
        current = current->next;
    }
}

message_t *init_node(message_t *tmp, char *sender, char *target, char *content)
{
    tmp->sender = strdup(sender);
    tmp->target = strdup(target);
    tmp->content = strdup(content);
    return tmp;
}

message_t *push_msg(message_t *head, char *sender, char *target, char *content)
{
    message_t *tmp;
    message_t *current;
    time_t ti = time(NULL);
    struct tm tm = {};
    char buffer[255];

    memset(&tm, 0, sizeof(tm));
    strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", localtime(&ti));
    tmp = create_message();
    tmp = init_node(tmp, sender, target, content);
    tmp->timestamp = strdup(buffer);
    tmp->ti = ti;
    if (head == NULL)
        return tmp;
    current = head;
    while (current->next != NULL)
        current = current->next;
    current->next = tmp;
    return head;
}