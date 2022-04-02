/*
** EPITECH PROJECT, 2021
** B-NWP-400-LIL-4-1-myteams-theo.selosse
** File description:
** server_setup
*/

#include <signal.h>
#include <errno.h>
#include "../include/client.h"
#include "../include/signal_handler.h"

bool execute_action(client_t *client, fd_set fd_read)
{
    if (FD_ISSET(STDIN_FILENO, &fd_read))
        return (send_client(client, 0));
    if (FD_ISSET(client->fd_socket, &fd_read))
        read_client(client->fd_socket, client);
    return true;
}

bool select_setup(void)
{
    if (errno == EINTR)
        return true;
    else {
        perror("select()");
        exit(84);
    }
    return false;
}