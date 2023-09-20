#include "shell.h"

/**
 * custom_execute_command - Execute a command with arguments.
 * @arguments: An array of strings containing the command and its arguments.
 *
 * Return: The exit status of the executed command.
 */
int custom_execute_command(char **arguments)
{
    pid_t process_id;
    int exit_status = 0;
    char *command_path, *environment[2];

    if (arguments == NULL || *arguments == NULL)
        return (exit_status);
    if (is_builtin_command(arguments))
        return (exit_status);

    process_id = fork();
    if (process_id < 0)
    {
        custom_print_error("fork");
        return (1);
    }
    if (process_id == -1)
        perror(arguments[0]), custom_free_tokens(arguments), custom_free_last_input();
    if (process_id == 0)
    {
        environment[0] = custom_get_path();
        environment[1] = NULL;
        command_path = NULL;
        if (arguments[0][0] != '/')
            command_path = custom_find_in_path(arguments[0]);
        if (command_path == NULL)
            command_path = arguments[0];
        if (execve(command_path, arguments, environment) == -1)
        {
            perror(arguments[0]);
            custom_free_tokens(arguments);
            custom_free_last_input();
            exit(EXIT_FAILURE);
        }
    }
    else
    {
        do {
            waitpid(process_id, &exit_status, WUNTRACED);
        } while (!WIFEXITED(exit_status) && !WIFSIGNALED(exit_status));
    }
    return (exit_status);
}
