/*
** EPITECH PROJECT, 2021
** B-NWP-400-LIL-4-1-myteams-theo.selosse
** File description:
** updating_file
*/

#include <sys/stat.h>
#include <fcntl.h>
#include "../../include/functions.h"

int loading_save(char *path, client_t *current)
{
    int fd;

    if ((fd = open(path, O_RDONLY)) == -1)
        return -1;
    if (current->connected == false) {
        dprintf(current->fd, "UNAUTHORIZED\n");
        return -1;
    }
    return fd;
}

void check_file(client_t *current)
{
    char *path = get_path(current->uid);
    struct stat st = {};
    FILE *f;

    if (stat(path, &st) == -1) {
        f = fopen(path, "w+");
        fclose(f);
    }
}

char *get_path(char *uid)
{
    char *folder = "./data/";
    char *end = ".txt";
    int size = strlen(folder) + strlen(uid) + strlen(end);
    char *path = malloc(sizeof(char) * size + 1);
    int i = 0;

    if (path == NULL)
        return NULL;
    path[size] = '\0';
    for (; folder[i] != '\0'; i++)
        path[i] = folder[i];
    for (int j = 0; uid[j] != '\0'; j++, i++)
        path[i] = uid[j];
    for (int k = 0; end[k] != '\0'; k++, i++)
        path[i] = end[k];
    return path;
}

void update_file(client_t *saved)
{
    client_t *client = saved;
    FILE *f;

    f = fopen("./data/users.txt", "w+");
    if (f == NULL) {
        perror("fopen():");
        return;
    }
    while (client != NULL) {
        fprintf(f, "%s %s %d\n", client->uid, client->name, client->connected);
        client = client->next;
    }
    fclose(f);
}

void update_t_file(teams_t *head)
{
    teams_t *current = head;
    FILE *f;

    f = fopen("./data/teams.txt", "w+");
    if (f == NULL) {
        perror("fopen():");
        return;
    }
    while (current != NULL) {
        fprintf(f, "%s %s %s\n", current->uid, current->name, current->descr);
        current = current->next;
    }
    fclose(f);
}