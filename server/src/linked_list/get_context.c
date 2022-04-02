/*
** EPITECH PROJECT, 2021
** B-NWP-400-LIL-4-1-myteams-theo.selosse
** File description:
** channels linked_list
*/

#include "../../include/client.h"

teams_t *get_team_context(teams_t *head, client_t *current_c)
{
    teams_t *current_t;

    if (head == NULL)
        return NULL;
    current_t = head;
    while (current_t->next != NULL) {
        if (strncmp(current_t->uid, current_c->cont_t->uid,
        strlen(current_t->uid)) == 0)
            return (current_t);
        current_t = current_t->next;
    }
    return (NULL);
}

channel_t *get_channel_context(channel_t *head, client_t *current_c)
{
    channel_t *current_ch;

    if (head == NULL)
        return NULL;
    current_ch = head;
    while (current_ch->next != NULL) {
        if (strncmp(current_ch->uid, current_c->cont_c->uid,
        strlen(current_ch->uid)) == 0)
            return (current_ch);
        current_ch = current_ch->next;
    }
    return (NULL);
}

thread_t *get_thread_context(thread_t *head, client_t *current_c)
{
    thread_t *current_th;

    if (head == NULL)
        return NULL;
    current_th = head;
    while (current_th->next != NULL) {
        if (strncmp(current_th->uid, current_c->cont_c->uid,
        strlen(current_th->uid)) == 0)
            return (current_th);
        current_th = current_th->next;
    }
    return (NULL);
}