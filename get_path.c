#include "shell.h"

/**
 * custom_get_path - Returns the value of the PATH environment variable.
 *
 * Return: Pointer to the value of the PATH variable.
 */
char *custom_get_path(void)
{
    return (custom_get_environment("PATH"));
}
