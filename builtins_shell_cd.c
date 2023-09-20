#include "shell.h"

/**
 * change_current_directory - changes the current working directory of the shell
 * @arguments: array of arguments
 */
void change_current_directory(char **arguments)
{
    char *directory = arguments[1];
    int result;

    /* If no argument is provided, change to the HOME directory */
    if (directory == NULL)
    {
        directory = _getenv("HOME");
        if (directory == NULL)
        {
            _puts("change_current_directory: No HOME directory found\n");
            return;
        }
    }

    result = chdir(directory);
    if (result == -1)
    {
        perror("chdir");
    }
}
