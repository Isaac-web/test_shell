#include "shell.h"

/**
 * custom_set_environment - Set the value of an environment variable
 * @arguments: Arguments (name and value of the environment variable)
 *
 * Return: Nothing
 */
int custom_set_environment(char **arguments)
{
    char *variable_name, *variable_value;

    if (arguments[1] == NULL || arguments[2] == NULL)
    {
        _puterror("Usage: custom_setenv VARIABLE VALUE\n");
        return (-1);
    }

    variable_name = arguments[1];
    variable_value = arguments[2];

    if (setenv(variable_name, variable_value, 1) != 0)
    {
        _puterror("custom_set_environment");
        return (-1);
    }
    return (0);
}

/**
 * custom_unset_environment - Unset an environment variable
 * @arguments: Arguments (name of the environment variable)
 *
 * Return: Nothing
 */
int custom_unset_environment(char **arguments)
{
    char *variable_name;

    if (arguments[1] == NULL)
    {
        _puterror("Usage: custom_unsetenv VARIABLE\n");
        return (-1);
    }

    variable_name = arguments[1];

    if (unsetenv(variable_name) != 0)
    {
        _puterror("custom_unset_environment");
    }
    return (0);
}
