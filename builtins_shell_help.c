#include "shell.h"

/**
 * custom_display_help - displays help information for built-in commands
 */
void custom_display_help(void)
{
    _puts("\nCustom Shell Version 1.0.0\n\n");
    _puts("Usage: ./custom_shell\n\n");
    _puts("Custom Shell built-in commands:\n\n");
    _puts("help\t\tDisplay this help information\n\n");
    _puts("navigate [dir]\tChange the current working directory\n\n");
    _puts("listenv\t\tDisplay the environment variables\n\n");
    _puts("modifyenv\tSet or modify an environment variable\n\n");
    _puts("removeenv\tUnset an environment variable\n\n");
    _puts("quit\t\tExit the custom shell\n\n");
}
