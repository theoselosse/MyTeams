/*
** EPITECH PROJECT, 2021
** prep_team
** File description:
** main
*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "../include/teams.h"

void check_args(int ac, char **av)
{
    if (ac != 2) {
        fprintf(stderr, "Not the right number of arguments\n");
        exit (84);
    }
    for (int i = 0; av[1][i] != 0; i++) {
        if (!isdigit(av[1][i])) {
            fprintf(stderr, "port is not a positive number\n");
            exit (84);
        }
    }
}

int main(int ac, char **av)
{
    server_t server;

    check_args(ac, av);
    server.port = atoi(av[1]);
    if (teams(&server) == 84)
        return 84;
    accept_client(&server);
    if (close_socket(server.fd_socket) == -1) {
        fprintf(stderr, "Error while closing the socket\n");
        return 84;
    }
    return (0);

}