#include "shell.h"

/**
 * custom_get_environment - Get the value of an environment variable
 * @variable_name: Name of the environment variable
 *
 * Return: Value of the environment variable, or NULL if it doesn't exist
 */
char *custom_get_environment(const char *variable_name)
{
    char **environment;
    size_t name_length = custom_strlen(variable_name);

    for (environment = environ; *environment != NULL; environment++)
    {
        if (custom_strncmp(*environment, variable_name, name_length) == 0 && (*environment)[name_length] == '=')
        {
            return (&(*environment)[name_length + 1]);
        }
    }

    return (NULL);
}
