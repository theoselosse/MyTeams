/*
** EPITECH PROJECT, 2021
** B-NWP-400-LIL-4-1-myteams-theo.selosse
** File description:
** linked_list2
*/

#include "../../include/client.h"

client_t *get_node(client_t *head, char *uid)
{
    client_t *found = head;

    while (found != NULL) {
        if (strncmp(uid, found->uid, strlen(uid)) == 0)
            return found;
        found = found->next;
    }
    return NULL;
}

client_t *remove_last(client_t *c, client_t *p, char *n, client_t *head)
{
    if (c->next == NULL && strncmp(n, c->name, strlen(n)) == 0 &&
    c->fd == -1) {
        p->next = NULL;
        free(c);
        return head;
    }
    return NULL;
}