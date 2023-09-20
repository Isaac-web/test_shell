#include "shell.h"

/**
 * custom_tokenize - Parsing user input into arguments by splitting an array string into tokens using a delimiter.
 * @str: The string to be tokenized.
 * @delim: The delimiter used to split the string.
 *
 * Return: An array of pointers to the tokens, or NULL if an error occurs.
 */
char **custom_tokenize(char *str, const char *delim)
{
    char *token = NULL;
    char **token_array = NULL;
    int token_count = 0;

    token = strtok(str, delim);
    while (token)
    {
        token_array = realloc(token_array, sizeof(char *) * (token_count + 1));
        if (token_array == NULL)
            return (NULL);

        token_array[token_count] = malloc(custom_strlen(token) + 1);
        if (!token_array[token_count])
            return (NULL);

        custom_strcpy(token_array[token_count], token);
        token = strtok(NULL, delim);
        token_count++;
    }

    /* Increase the size of the array */
    token_array = realloc(token_array, (token_count + 1) * sizeof(char *));
    if (!token_array)
        return (NULL);

    token_array[token_count] = NULL;
    return (token_array);
}

/**
 * custom_tokenize_input - Splits a user input string into tokens with custom_tokenize().
 * @input: The user input string to be tokenized.
 *
 * Return: An array of pointers to the tokens, or NULL if an error occurs.
 */
char **custom_tokenize_input(char *input)
{
    char **tokens = NULL;
    char *temporary_input = NULL;

    temporary_input = custom_strdup(input);
    if (temporary_input == NULL)
    {
        _puts("Memory allocation error\n");
        exit(EXIT_FAILURE);
    }

    tokens = custom_tokenize(temporary_input, " \t\r\n\a");
    free(temporary_input);

    return (tokens);
}
