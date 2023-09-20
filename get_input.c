#include "shell.h"

static char *recent_input;

/**
 * custom_get_input - Read a line of input from the user.
 *
 * Return: Pointer to a buffer containing the user's input.
 */
char *custom_get_input(void)
{
    char *input_buffer = NULL;
    size_t buffer_size = 0;
    ssize_t read_size;

    do {
        /* Print the shell prompt */
        custom_prompt();

        /* Get a line of input from the user */
        read_size = getline(&input_buffer, &buffer_size, stdin);

        /* Check for EOF or error */
        if (read_size == -1)
        {
            free(input_buffer);
            _puts("\n");
            return (NULL);
        }

        /* Remove trailing newline character */
        input_buffer[read_size - 1] = '\0';

    } while (input_buffer[0] == '\0' || isspace(input_buffer[0]));

    /* Update recent_input to point to the new input */
    recent_input = input_buffer;
    return (input_buffer);
}

/**
 * custom_free_recent_input - Frees the most recently entered input by the user.
 *
 * This function frees the memory allocated for the most recent input string
 * entered by the user. It should be called after the input string is no longer
 * needed.
 */
void custom_free_recent_input(void)
{
    free(recent_input);
    recent_input = NULL;
}
