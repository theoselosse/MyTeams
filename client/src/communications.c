/*
** EPITECH PROJECT, 2021
** B-NWP-400-LIL-4-1-myteams-theo.selosse
** File description:
** communications
*/

#include "../include/client.h"

void read_client(int fd, client_t *client)
{
    size_t size = 0;
    char buffer[5016];
    bool running = true;

    while (running) {
        if ((size = read(fd, buffer, 5016)) > 0) {
            buffer[size] = '\0';
            if (check_cmd(client, buffer) == 0) {
                write(0, buffer, strlen(buffer));
            }
        }
        running = parse_entry(buffer);
    }
}

bool send_client(client_t *client, int c)
{
    char buffer[5016];
    size_t size = 0;

    if ((size = read(c, buffer, 5016)) > 0) {
        buffer[size] = '\0';
        write(client->fd_socket, buffer, strlen(buffer));
        return true;
    }
    return false;
}

bool parse_entry(char *buffer)
{
    char *end = NULL;
    int end_pos;

    end = strstr(buffer, "123TD");
    if (!end)
        return false;
    end_pos = strlen(buffer) - strlen(end);
    buffer[end_pos] = '\0';
    return true;
}