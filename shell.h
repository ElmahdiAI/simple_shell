#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <unistd.h>
#include <errno.h>
#include <dirent.h>
#include <signal.h>

/*constants*/
#define EXTERNAL_CMD 1
#define INTERNAL_CMD 2
#define PATH_CMD 3
#define INVALID_CMD -1

#define min(x, y) (((x) < (y)) ? (x) : (y))

/**
 *struct map - a struct that maps a command name to a function
 *
 *@command_name: name of the command
 *@func: the function that executes the command
 */

typedef struct map
{
	char *command_name;
	void (*func)(char **command);
} function_map;

/**
 *struct gvars - a struct that contains global var
 * @environ: environ
 * @line: line
 * @commands: commands
 * @shell_name: shall name
 * @status: status of exit
 */
typedef struct gvars
{
	char **environ;
	char *line;
	char **commands;
	char *shell_name;
	int status;
} vars;

/*string_tools*/
int _strcmp(char *, char *);
char *_strcat(char *, char *);
int _strspn(char *, char *);
int _strcspn(char *, char *);
char *_strchr(char *, char);
/*string_tools2*/
char *_strtok_r(char *, char *, char **);
int _atoi(char *);
void comment(char *);
void _strcpy(char *, char *);
int _strlen(char *);
/*tools1*/
int parse_cmd(char *);
void execute_cmd(char **, int);
char *check_path(char *);
void (*get_func(char *))(char **);
char *_getenv(char *);
/*tools2*/
char **tokenizer(char *, char *);
void _print(char *, int);
void remove_newline(char *);
void *_realloc(void *, unsigned int, unsigned int);
void ctrl_c_handler(int);
/*tools3*/
void env(char **);
void quit(char **);
/*interactive_mode*/
extern void uninteractive(void);
extern void initializer(char **, int);
#endif /*SHELL_H*/
