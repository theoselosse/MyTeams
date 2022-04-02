/*
** EPITECH PROJECT, 2021
** B-NWP-400-LIL-4-1-myteams-theo.selosse
** File description:
** main
*/

#include "../include/client.h"

void print_usage(void)
{
    printf("USAGE: ./myteams_cli ip port\n");
    printf("\tip is the server ip address");
    printf(" on which the server socket listens\n");
    printf("\tport is the port number on which the server socket listens\n");
}

void check_args(int ac, char **av)
{
    if (ac > 3 || ac < 2) {
        print_usage();
        exit(84);
    } else if (strcmp(av[1], "-help") == 0) {
        print_usage();
        exit(0);
    }
    if (atoi(av[2]) == 0) {
        print_usage();
        exit(84);
    }
}

int main(int ac, char **av)
{
    int client_fd;

    check_args(ac, av);
    if ((client_fd = init_client(atoi(av[2]), av[1])) == -1)
        return 84;
    if (exec_client(client_fd) == -1)
        return 84;
    return 0;
}