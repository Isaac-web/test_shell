#include "shell.h"

/**
 * custom_shell - Implements a simple shell.
 *
 * Return: EXIT_SUCCESS.
 */
int main(void)
{
    char *user_input;
    char **arguments;
    int execution_status;

    /* Register signal handlers */
    custom_signal(SIGINT, custom_handle_sigint);
    custom_signal(SIGQUIT, custom_handle_sigquit);
    custom_signal(SIGTSTP, custom_handle_sigstp);

    do {
        user_input = custom_get_input();
        if (!user_input || !*user_input) /* EOF detected, exit the loop */
            break;

        arguments = custom_tokenize_input(user_input);
        if (!arguments || !*arguments)
        {
            free(user_input);
            custom_free_tokens(arguments);
            continue;
        }

        execution_status = custom_execute(arguments);

        free(user_input);
        custom_free_tokens(arguments);

        /* Execution status is set to 1 to make the loop continue */
        execution_status = 1;
    } while (execution_status);

    return (EXIT_SUCCESS);
}
