/*
** EPITECH PROJECT, 2021
** B-NWP-400-LIL-4-1-myteams-theo.selosse
** File description:
** replies linked_list
*/

#include "../../include/client.h"

reply_t *set_info_reply(client_t *author, char *comment)
{
    reply_t *tmp;

    tmp = malloc(sizeof(thread_t));
    tmp->next = NULL;
    tmp->comment = strdup(comment);
    tmp->author = author;
    return tmp;
}

teams_t *push_b_reply(teams_t *head, client_t *current_c, reply_t *new_r)
{
    reply_t *current_r;
    thread_t *current_th;
    channel_t *current_ch;
    teams_t *current_t;

    if (head == NULL)
        return NULL;
    current_t = get_team_context(head, current_c);
    current_ch = get_channel_context(current_t->list_channel, current_c);
    current_th = get_thread_context(current_ch->list_thread, current_c);
    if (current_th->list_replies == NULL) {
        current_th->list_replies = new_r;
        return (head);
    } else {
        current_r = current_th->list_replies;
        while (current_r->next != NULL)
            current_r = current_r->next;
        current_r->next = new_r;
        return (head);
    }
}

void dump_l_reply(reply_t *head)
{
    reply_t *current = head;

    while (current != NULL) {
        printf("%s\n", current->comment);
        current = current->next;
    }
}