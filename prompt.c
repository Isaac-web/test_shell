#include "shell.h"

/**
 * custom_print_prompt - Print a custom shell prompt to stdin stream.
 *
 * Return: void.
 */
void custom_print_prompt(void)
{
    _puts(CUSTOM_PROMPT);
    fflush(stdout);
}
