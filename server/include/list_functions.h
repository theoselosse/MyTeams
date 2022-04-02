/*
** EPITECH PROJECT, 2021
** B-NWP-400-LIL-4-1-myteams-theo.selosse
** File description:
** list_functions
*/

#ifndef LIST_FUNCTIONS_H_
#define LIST_FUNCTIONS_H_

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "server.h"
#include "client.h"

typedef struct function_s function_t;

typedef struct server_s server_t;

typedef void (*f_ptr)(char **cmd, server_t *server, client_t *current);

struct function_s {
    char *name;
    f_ptr ptr;
    function_t *next;
};

function_t *push_b(function_t *head, char *name,
void (*)(char **cmd, server_t *server, client_t *current));

#endif /* !LIST_FUNCTIONS_H_ */
