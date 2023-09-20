#include "shell.h"

/**
 * custom_print_environment - Prints all the environment variables.
 *
 * Return: 0 to continue executing.
 */
int custom_print_environment(void)
{
    int index;

    for (index = 0; environ[index]; index++)
    {
        _puts(environ[index]);
        _putchar('\n');
    }

    return (0);
}
