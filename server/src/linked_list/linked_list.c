/*
** EPITECH PROJECT, 2021
** B-NWP-400-LIL-4-1-myteams-theo.selosse
** File description:
** linked_list
*/

#include "../../include/client.h"

client_t *create_node(void)
{
    client_t *tmp = malloc(sizeof(client_t));
    tmp->next = NULL;
    return tmp;
}

client_t *push_back(client_t *head, char *name, char *uid, int fd)
{
    client_t *tmp;
    client_t *current;

    tmp = create_node();
    tmp->name = strdup(name);
    tmp->uid = strdup(uid);
    tmp->fd = fd;
    tmp->connected = 0;
    tmp->next = NULL;
    if (head == NULL)
        return tmp;
    current = head;
    while (current->next != NULL)
        current = current->next;
    current->next = tmp;
    return head;
}

void dump_list(client_t *head)
{
    client_t *current = head;

    while (current != NULL) {
        printf("%s\t%s\t%d\t%d\n",
        current->name, current->uid, current->fd, current->connected);
        current = current->next;
    }
}

client_t *remove_first(client_t *head, client_t *current, char *name)
{
    client_t *tmp = head;

    if (head == NULL || name[0] == '\0' || current->fd != -1)
        return head;
    if (strncmp(name, current->name, strlen(name)) == 0 && current->fd == -1) {
        head = head->next;
        free(tmp);
        return head;
    }
    return head;
}

client_t *remove_at(client_t *head, char *n)
{
    client_t *c = head;
    client_t *p;
    client_t *tmp;

    if (!head || (strncmp(n, c->name, strlen(n)) == 0 &&
    c->connected == -1))
        return (remove_first(head, c, n));
    for (; c != NULL; p = c, c = c->next) {
        if (strncmp(n, c->name, strlen(n)) == 0) {
            if (c->next != NULL && c->fd == -1) {
                p->next = c->next;
                free(c);
                return head;
            }
        }
        if ((tmp = remove_last(c, p, n, head)) != NULL)
            return tmp;
    }
    return head;
}