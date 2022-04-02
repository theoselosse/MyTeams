/*
** EPITECH PROJECT, 2021
** B-NWP-400-LIL-4-1-myteams-theo.selosse
** File description:
** channels linked_list
*/

#include "../../include/client.h"

channel_t *set_info_channel(char *name, char *uid, char *descr)
{
    channel_t *tmp;

    tmp = malloc(sizeof(channel_t));
    tmp->next = NULL;
    tmp->name = strdup(name);
    tmp->uid = strdup(uid);
    tmp->descr = strdup(descr);
    tmp->list_thread = NULL;
    return tmp;
}

teams_t *push_b_channel(teams_t *head, client_t *current_c, channel_t *new_c)
{
    channel_t *current_ch;
    teams_t *current_t;

    if (head == NULL)
        return NULL;
    current_t = get_team_context(head, current_c);
    if (current_t->list_channel == NULL) {
        current_t->list_channel = new_c;
        return (head);
    } else {
        current_ch = current_t->list_channel;
        while (current_ch->next != NULL)
            current_ch = current_ch->next;
        current_ch->next = new_c;
        return (head);
    }
}

void dump_l_channel(channel_t *head)
{
    channel_t *current = head;

    while (current != NULL) {
        printf("%s\t%s\t%s\n", current->name, current->uid, current->descr);
        current = current->next;
    }
}