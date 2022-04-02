/*
** EPITECH PROJECT, 2021
** B-NWP-400-LIL-4-1-myteams-theo.selosse
** File description:
** teams linked_list
*/

#include "../../include/client.h"

teams_t *push_b_teams(teams_t *head, char *name, char *uid, char *descr)
{
    teams_t *tmp;
    teams_t *current;

    tmp = malloc(sizeof(teams_t));
    tmp->next = NULL;
    tmp->name = strdup(name);
    tmp->uid = strdup(uid);
    tmp->descr = strdup(descr);
    tmp->list_channel = NULL;
    tmp->client_sub = NULL;
    if (head == NULL)
        return tmp;
    current = head;
    while (current->next != NULL)
        current = current->next;
    current->next = tmp;
    return head;
}

void dump_l_team(teams_t *head)
{
    teams_t *current = head;

    while (current != NULL) {
        printf("%s\t%s\t%s\n", current->name, current->uid, current->descr);
        current = current->next;
    }
}