#include "shell.h"

/**
 * handle_sigint - Signal handler for SIGINT (Ctrl+C)
 * @sig: Signal number
 *
 * Return: Nothing
 */
void custom_handle_sigint(int sig)
{
    (void) sig;
    _putchar('\n');
    custom_print_prompt(); // Use the appropriate custom function
}

/**
 * handle_sigquit - Signal handler for SIGQUIT (Ctrl+\)
 * @sig: Signal number
 *
 * Return: Nothing
 */
void custom_handle_sigquit(int sig)
{
    (void) sig;
    _puterror("Quit (core dumped)\n");
    exit(EXIT_SUCCESS);
}

/**
 * handle_sigstp - Signal handler for SIGTSTP (Ctrl+Z)
 * @sig: Signal number
 *
 * Return: Nothing
 */
void custom_handle_sigstp(int sig)
{
    (void) sig;
    _puts("\n");
    custom_print_prompt(); // Use the appropriate custom function
}
