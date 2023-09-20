#include "shell.h"

/**
 * custom_free_error - Frees allocated memory when a system error occurs.
 * @argv: Pointer to an array of pointers.
 * @arg: Pointer to a character array.
 *
 * Return: void.
 */
void custom_free_error(char **argv, char *arg)
{
    int index;

    for (index = 0; argv[index]; index++)
        free(argv[index]);
    free(argv);
    free(arg);
    exit(EXIT_FAILURE);
}

/**
 * custom_free_tokens - Frees memory allocated dynamically by custom_tokenize().
 * @ptr: Pointer to allocated memory.
 *
 * Return: void.
 */
void custom_free_tokens(char **ptr)
{
    int index;

    for (index = 0; ptr[index]; index++)
        free(ptr[index]);
    free(ptr);
}

/**
 * custom_free_path - Frees the global variable containing the PATH environment variable value.
 *
 * Return: Nothing.
 */
void custom_free_path(void)
{
    if (environ != NULL)
    {
        size_t i = 0;

        while (environ[i] != NULL)
        {
            if (custom_strncmp(environ[i], "PATH=", 5) == 0)
            {
                free(environ[i]);
                environ[i] = NULL;
                break;
            }
            i++;
        }
    }
}
