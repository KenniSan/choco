/*
** EPITECH PROJECT, 2023
** mini_printf
** File description:
** a function named mini_printf to learn how to use va_args.
*/
#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>

int dacase(va_list args, const char *format, int i)
{
    switch (format[i + 1]) {
    case 'd' :
        my_put_nbr(va_arg(args, int));
        break;
    case 'i' :
        my_put_nbr(va_arg(args, int));
        break;
    case 'c' :
        my_putchar(va_arg(args, int));
        break;
    case 's' :
        my_putstr(va_arg(args, char *));
        break;
    case '%' :
        my_putchar('%');
        break;
    }
    return i;
}

int mini_printf(const char *format, ...)
{
    int i = 0;
    va_list args;

    va_start(args, format);
    for (i = 0; format[i] != '\0'; i++) {
        if (format[i] != '%') {
            my_putchar(format[i]);
        } else {
            i = dacase(args, format, i);
            i = i + 1;
        }
    }
        va_end(args);
    return i;
}
