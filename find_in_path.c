#include "shell.h"

/**
 * custom_find_command_in_path - Looks for a command in each directory specified
 *                              in the PATH environment variable.
 * @command: Pointer to the `command` string to look for.
 *
 * Return: Pointer to a string containing the full path (success) if it is found,
 *         or NULL if it is not found (failure).
 */
char *custom_find_command_in_path(char *command)
{
    struct stat file_stat;
    int stat_result, i;
    char path_buffer[MAX_PATH_LENGTH], *path_variable, *result, **path_directories;

    path_variable = custom_get_path();
    if (!path_variable)
        return (NULL);

    path_directories = custom_tokenize(path_variable, PATH_SEPARATOR);
    if (!path_directories)
        return (NULL);

    for (i = 0; path_directories[i]; i++)
    {
        custom_memset(path_buffer, 0, MAX_PATH_LENGTH);
        custom_strcpy(path_buffer, path_directories[i]);
        custom_strcat(path_buffer, "/");
        custom_strcat(path_buffer, command);

        stat_result = stat(path_buffer, &file_stat);
        if (stat_result == 0 && S_ISREG(file_stat.st_mode) && (file_stat.st_mode & S_IXUSR))
        {
            custom_free_tokens(path_directories);
            result = custom_malloc(sizeof(char) * (custom_strlen(path_buffer) + 1));
            if (!result)
                return (NULL);
            custom_strcpy(result, path_buffer);
            return (result);
        }
    }

    if (stat_result == -1)
        custom_free_tokens(path_directories);

    return (NULL);
}
