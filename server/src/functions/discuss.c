/*
** EPITECH PROJECT, 2021
** B-NWP-400-LIL-4-1-myteams-theo.selosse
** File description:
** discuss
*/

#include <sys/stat.h>
#include <fcntl.h>
#include "../../include/functions.h"

bool error_send(client_t *current, client_t *target, char **cmd)
{
    if (current->connected == false || target->connected == false) {
        write(current->fd, "UNAUTHORIZED\n", 14);
        return true;
    }
    if (strlen(cmd[2]) > 512) {
        write(0, "The message body is too long\n", 30);
        dprintf(current->fd, "The message body is too long\r\n");
        return true;
    }
    return false;
}

void messages(char **cmd, server_t *server, client_t *current)
{
    int fd;
    struct stat st = {};
    char *path = get_path(current->uid);
    char *content;

    (void)cmd;
    (void)server;
    if ((fd = loading_save(path, current)) == -1)
        return;
    if (stat(path, &st) == -1)
        return;
    if ((content = malloc(sizeof(char) * st.st_size)) == NULL)
        return;
    if (fd != -1) {
        read(fd, content, st.st_size);
        dprintf(current->fd, "LIST_MESSAGES %s\n", content);
        close(fd);
    }
    free(content);
}

void send_msg(char **cmd, server_t *server, client_t *current)
{
    client_t *target;

    if (count(cmd) != 3) {
        dprintf(0, "501 Wrong nb of arg, check /help command\n");
        dprintf(current->fd, "501 Wrong nb of arg, check /help command\r\n");
        return;
    }
    if ((target = get_node(server->saved, cmd[1])) == NULL) {
        dprintf(current->fd, "UNKNOWN %s\n", cmd[1]);
        return;
    }
    if (error_send(current, target, cmd) == true)
        return;
    server_event_private_message_sended(current->uid, target->uid, cmd[2]);
    dprintf(target->fd, "SEND %s %s %s\n", current->uid, target->uid, cmd[2]);
}

void users(char **cmd, server_t *server, client_t *current)
{
    (void)cmd;
    (void)server;
    char *content;
    int fd = open("./data/users.txt", O_RDONLY);
    struct stat st = {};

    if (current->connected == false) {
        dprintf(current->fd, "UNAUTHORIZED\n");
        return;
    }
    if (stat("./data/users.txt", &st) == -1)
        return;
    if ((content = malloc(sizeof(char) * st.st_size)) == NULL)
        return;
    if (fd != -1) {
        read(fd, content, st.st_size);
        dprintf(current->fd, "LIST_CLIENTS %s\n", content);
        close(fd);
    }
    free(content);
}

void user(char **cmd, server_t *server, client_t *current)
{
    client_t *target;

    if (count(cmd) != 2) {
        dprintf(0, "501 Wrong nb of arg, check /help command\n");
        dprintf(current->fd, "501 Wrong nb of arg, check /help command\r\n");
        return;
    }
    if (current->connected == false) {
        dprintf(current->fd, "UNAUTHORIZED\n");
        return;
    } if ((target = get_node(server->saved, cmd[1])) == NULL) {
        dprintf(current->fd, "UNKNOWN %s\n", cmd[1]);
        return;
    } if (target->fd != -1) {
        dprintf(current->fd, "DUMP_CLIENT %s %s %d\n",
        target->uid, target->name, target->connected);
    }
}
