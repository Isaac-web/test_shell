#ifndef _CUSTOM_SHELL_H_
#define _CUSTOM_SHELL_H_
#define _GNU_SOURCE

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <limits.h>
#include <fcntl.h>
#include <errno.h>
#include <stdarg.h>
#include <ctype.h>

/* Macros */
#define CUSTOM_PATH_MAX_LENGTH 4096
#define CUSTOM_PATH_SEPARATOR ":"
#define CUSTOM_PROMPT "$ "
#define CUSTOM_MAX_TOKENS 1024
#define CUSTOM_BUFFER_SIZE 1024

/* prompt.c */
void custom_print_prompt(void);

/* get_input.c */
char *custom_get_input(void);
void custom_free_last_input(void);

/* get_line.c */
void *custom_get_line(void);

/* built-in funcs */
int custom_check_for_builtin(char **args);
int custom_execute_builtin(char *cmd, char **args);
void custom_shell_help(void);
void custom_shell_exit(char **args);
void custom_shell_cd(char **args);
int custom_shell_setenv(char **args);
int custom_shell_unsetenv(char **args);
int custom_shell_env(void);
int custom_shell_clear(char **args);

/* signal_handler.c */
void custom_handle_sigint(int sig);
void custom_handle_sigquit(int sig);
void custom_handle_sigstp(int sig);

/* execute.c */
int custom_execute(char **args);

/* parser.c */
char **custom_tokenize(char *str, const char *delim);
char **custom_tokenize_input(char *input);

/* get_env.c */
char *custom_get_environment(const char *name);

/* get_path.c */
char *custom_get_path(void);

/* find_in_path.c */
char *custom_find_in_path(char *command);

/* free.c */
void custom_free_error(char **argv, char *arg);
void custom_free_tokens(char **ptr);
void custom_free_path(void);

/* error.c */
void custom_puts(char *str);
void custom_puterror(char *err);

/* utils_funcs1.c */
int _strlen(const char *);
int _strcmp(const char *s1, const char *s2);
int _strncmp(const char *s1, const char *s2, size_t n);
char *custom_strstr(char *haystack, char *needle);
char *custom_strchr(char *s, char c);

/* utils_funcs2.c */
char *_strcpy(char *, char *);
char *_strcat(char *, const char *);
char *_strdup(const char *);
int custom_putchar(char);
unsigned int custom_strspn(char *s, char *accept);

/* utils_funcs3.c */
int custom_atoi(const char *str);
char *custom_memset(char *, char, unsigned int);
char *custom_memcpy(char *dest, char *src, unsigned int n);
void *custom_realloc(void *, unsigned int, unsigned int);
void *custom_calloc(unsigned int nmemb, unsigned int size);

#endif
