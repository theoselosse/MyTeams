/*
** EPITECH PROJECT, 2021
** B-NWP-400-LIL-4-1-myftp-hugo.humez
** File description:
** tools
*/

#include "../include/teams.h"

int count(char **array)
{
    int i;

    for (i = 0; array[i]; i++);
    return (i);
}

int count_word(char *input)
{
    int i = 0;
    int nb_word = 1;

    for (; input[i] != '\0'; i++) {
        if (input[i] == ' ')
            nb_word++;
    }
    return (nb_word);
}

char **str_to_array(char *input)
{
    int i = 0;
    char *token = NULL;
    char **array = NULL;

    array = malloc(sizeof(char *) * (count_word(input) + 1));
    token = strtok(input, " ");
    while (token != NULL) {
        array[i] = token;
        token = strtok(NULL, " ");
        i++;
    }
    array[i] = NULL;
    return array;
}

char *convert_space(char *input)
{
    char *new_str = malloc(sizeof(char) * (strlen(input) + 1));
    int j = 0;

    for (int i = 0; input[i] != '\0'; i++) {
        if (input[i] == '\r' || input[i] == '\t' || input[i] == '\n') {
            new_str[j] = ' ';
            j++;
            continue;
        }
        new_str[j] = input[i];
        j++;
    }
    new_str[j] = '\0';
    return new_str;
}

char *clean_input(char *str)
{
    int tmp = 0;
    int i = 0;
    int count = 0;
    char *new_str = malloc(sizeof(char) * (strlen(str) + 1));
    char *string = convert_space(str);

    for (; string[i] != '\0'; i++) {
        if (tmp == 0 && string[i] == ' ');
        else if ((string[i] == ' ' && string[i + 1] == ' ') ||
            (string[i] == ' ' && string[i + 1] == '\0')) {
        } else {
            tmp = 1;
            new_str[count] = string[i];
            count++;
        }
    }
    new_str[i] = '\0';
    return new_str;
}