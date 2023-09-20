#include "shell.h"

/**
 * custom_exit_shell - Exit the shell.
 * @arguments: Arguments.
 *
 * Return: Nothing.
 */
void custom_exit_shell(char **arguments)
{
    int exit_status = 0;

    if (arguments[1] != NULL)
    {
        exit_status = _atoi(arguments[1]);
    }
    free_tokens(arguments);
    free_last_input();
    exit(exit_status);
}
