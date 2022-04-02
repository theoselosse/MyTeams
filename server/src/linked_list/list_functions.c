/*
** EPITECH PROJECT, 2021
** B-NWP-400-LIL-4-1-myteams-theo.selosse
** File description:
** list_functions
*/

#include "../../include/list_functions.h"

function_t *create_n(void)
{
    function_t *tmp = malloc(sizeof(function_t));
    tmp->next = NULL;
    return tmp;
}

function_t *push_b(function_t *head, char *name, void
(*f)(char **, server_t *, client_t *))
{
    function_t *tmp;
    function_t *current;

    tmp = create_n();
    tmp->name = strdup(name);
    tmp->ptr = f;
    if (head == NULL)
        return tmp;
    current = head;
    while (current->next != NULL)
        current = current->next;
    current->next = tmp;
    return head;
}

function_t *remove_f(function_t *head, function_t *current, char *name)
{
    if (head == NULL || name[0] == '\0')
        return head;
    if (strncmp(name, current->name, strlen(name)) == 0) {
        head = current->next;
        free(current);
        return head;
    }
    return head;
}

function_t *delete_node(function_t *c, char *name,
function_t *previous, function_t *head)
{
    if (!c->next &&
        strncmp(name, c->name, strlen(name)) == 0) {
            previous->next = NULL;
            free(c);
            return head;
    }
    return NULL;
}

function_t *remove_at2(function_t *head, char *name)
{
    function_t *current = head;
    function_t *previous;

    if (head == NULL || strncmp(name, current->name, strlen(name)) == 0)
        return (remove_f(head, current, name));
    while (current != NULL) {
        if (strncmp(name, current->name, strlen(name)) == 0) {
            if (current->next != NULL) {
                previous->next = current->next;
                free(current);
                return head;
            }
        }
        if ((head = delete_node(current, name, previous, head)) != NULL)
            return head;
        previous = current;
        current = current->next;
    }
    return head;
}