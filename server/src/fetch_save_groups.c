/*
** EPITECH PROJECT, 2021
** fetch saved teams, channels, threads and replies
** File description:
** teams
*/

#include "../include/teams.h"
#include <uuid/uuid.h>

teams_t *fetch_save_groups(server_t *s, char *line, size_t len)
{
    FILE *fp;
    ssize_t read;
    char **a;
    bool empty = true;

    if ((fp = fopen("./data/teams.txt", "r")) == NULL)
        return NULL;
    while ((read = getline(&line, &len, fp)) != -1) {
        if (line[read - 1] == '\n')
            line[read - 1] = '\0';
        a = str_to_array(line);
        if (count(a) == 3) {
            empty = false;
            s->team_list = push_b_teams(s->team_list, a[1], a[0], a[2]);
        }
    }
    fclose(fp);
    if (empty == false)
        return s->team_list;
    return NULL;
}