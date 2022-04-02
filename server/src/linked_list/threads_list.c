/*
** EPITECH PROJECT, 2021
** B-NWP-400-LIL-4-1-myteams-theo.selosse
** File description:
** threads linked_list
*/

#include "../../include/client.h"

thread_t *set_info_thread(char *name, char *uid, char *message)
{
    thread_t *tmp;

    tmp = malloc(sizeof(thread_t));
    tmp->next = NULL;
    tmp->name = strdup(name);
    tmp->uid = strdup(uid);
    tmp->message = strdup(message);
    tmp->list_replies = NULL;
    return tmp;
}

teams_t *push_b_thread(teams_t *head, client_t *current_c, thread_t *new_t)
{
    thread_t *current_th;
    channel_t *current_ch;
    teams_t *current_t;

    if (head == NULL)
        return NULL;
    current_t = get_team_context(head, current_c);
    current_ch = get_channel_context(current_t->list_channel, current_c);
    if (current_ch->list_thread == NULL) {
        current_ch->list_thread = new_t;
        return (head);
    } else {
        current_th = current_ch->list_thread;
        while (current_th->next != NULL)
            current_th = current_th->next;
        current_th->next = new_t;
        return (head);
    }
}

void dump_l_thread(thread_t *head)
{
    thread_t *current = head;

    while (current != NULL) {
        printf("%s\t%s\t%s\n", current->name, current->uid, current->message);
        current = current->next;
    }
}