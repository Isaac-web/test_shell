#include "shell.h"

/**
 * is_builtin_command - checks if the command is a builtin
 * @arguments: the arguments array
 *
 * Return: 1 if command is a builtin, 0 otherwise
 */
int is_builtin_command(char **arguments)
{
    if (!arguments[0])
        return (0);
    if (!_strcmp(arguments[0], "exit"))
        custom_shell_exit(arguments);
    else if (!_strcmp(arguments[0], "env"))
        custom_shell_env();
    else if (!_strcmp(arguments[0], "setenv"))
        custom_shell_setenv(arguments);
    else if (!_strcmp(arguments[0], "unsetenv"))
        custom_shell_unsetenv(arguments);
    else if (!_strcmp(arguments[0], "help"))
        custom_shell_help();
    else if (!_strcmp(arguments[0], "cd"))
        custom_shell_cd(arguments);
    else if (!_strcmp(arguments[0], "clear"))
        custom_shell_clear(arguments);
    else
        return (0);
    return (1);
}
