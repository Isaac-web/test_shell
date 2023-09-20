#include "shell.h"

/**
 * custom_clear_terminal - clears the terminal screen.
 * @arguments: an array of arguments
 *
 * Return: 1 to continue executing,
 *         or 0 to exit.
 */
int custom_clear_terminal(char **arguments)
{
    (void)arguments; /* Avoid "unused parameter" warning */
    _puts("\033[2J\033[H");
    return (1);
}
