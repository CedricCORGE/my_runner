/*
** EPITECH PROJECT, 2020
** my_revstr.c
** File description:
** Reverse a string
*/

void my_putchar(char c);

char *my_revstr(char *str)
{
    int i = 0;
    int counter = 0;
    char a;

    while (str[counter] != '\0') {
        counter++;
    }
    counter--;
    while (i <= counter) {
        a = str[i];
        str[i] = str[counter];
        str[counter] = a;
        i++;
        counter--;
    }
    return (str);
}
