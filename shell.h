#ifndef _SHELL_H
#define _SHELL_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <errno.h>
#include <fcntl.h>
#include <signal.h>
#include <limits.h>

#define BUFFSIZE 1024
#define TOK_BUFFSIZE 128
#define TOK_DELIM " \t\r\n\a"

/* Points to an array of pointers to strings called the "environment" */
extern char **environ;


/**
 * struct data_list - struct that contains all relevant data on runtime
 * @av: argument vector
 * @input: command line written by the user
 * @args: tokens of the command line
 * @status: last status of the shell
 * @count: lines counter
 * @_environ: environment variable
 * @pid: process ID of the shell
 */
typedef struct data_list
{
	char **av;
	char *input;
	char **args;
	int status;
	int count;
	char **_env;
	char *pid;
} list_shell;

/**
 * struct sep_lists - single linked list
 * @separator: ; | &
 * @next: next node
 * Description: single linked list to store separators
 */
typedef struct sep_lists
{
	char separator;
	struct sep_lists *next;
} sepp_lists;

/**
 * struct line_lists - single linked list
 * @line: command line
 * @next: next node
 * Description: single linked list to store command lines
 */
typedef struct line_lists
{
	char *line;
	struct line_lists *next;
} line_l;

/**
 * struct r_var_l - single linked list
 * @len_var: length of the variable
 * @val: value of the variable
 * @len_val: length of the value
 * @next: next node
 * Description: single linked list to store variables
 */
typedef struct r_var_l
{
	int len_var;
	char *val;
	int len_val;
	struct r_var_l *next;
} r_variable;

/**
 * struct builtin_s - Builtin struct for command args.
 * @name: The name of the command builtin i.e cd, exit, env
 * @f: data type pointer function.
 */
typedef struct builtin_struct
{
	char *name;
	int (*f)(list_shell *datash);
} builtin_st;

/* lists.c */
sepp_lists *add_sep_node_end(sepp_lists **head, char sep);
void free_sep_list(sepp_lists **head);
line_l *add_line_node_end(line_l **head, char *line);
void free_line_list(line_l **head);

/* lists2.c */
r_variable *add_rvar_node(r_variable **head, int lvar, char *var, int lval);
void free_rvar_list(r_variable **head);

/* str functions */
char *_strcat(char *dest, const char *src);
char *_strcpy(char *dest, char *src);
int _strcmp(char *s1, char *s2);
char *_strchr(char *s, char c);
int _strspn(char *s, char *accept);

/* memory.c */
void _memcpy(void *newptr, const void *ptr, unsigned int size);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
char **_reallocdp(char **ptr, unsigned int old_size, unsigned int new_size);

/* string2.c */
char *_strdup(const char *s);
int _strlen(const char *s);
int cmp_chars(char str[], const char *delim);
char *_strtok(char str[], const char *delim);
int _isdigit(const char *s);

/* string3.c */
void rev_string(char *s);

/* syntax_error.c */
int repeated_char(char *input, int i);
int error_sep_op(char *input, int i, char last);
int first_char(char *input, int *i);
void print_syntax_error(list_shell *datash, char *input, int i, int bool);
int check_syntax_error(list_shell *datash, char *input);

/* loop.c */
char *without_comment(char *in);
void shell_loop(list_shell *datash);

/* read_line.c */
char *read_line(int *i_eof);

/* split_line.c */
char *swap_char(char *input, int bool);
void add_nodes(sepp_lists **head_s, line_l **head_l, char *input);
void go_next(sepp_lists **list_s, line_l **list_l, list_shell *datash);
int split_commands(list_shell *datash, char *input);
char **split_line(char *input);

/* var.c */
void check_env(r_variable **h, char *in, list_shell *data);
int check_vars(r_variable **h, char *in, char *st, list_shell *data);
char *replace_input(r_variable **head, char *input, char *new_input, int nlen);
char *rep_var(char *input, list_shell *datash);

/* get_line.c */
void bring_line(char **lineptr, size_t *n, char *buff, size_t j);
ssize_t get_line(char **lineptr, size_t *n, FILE *stream);

/* execute.c */
int exec_line(list_shell *datash);

/* cmd_exec.c */
int is_cdir(char *path, int *i);
char *_which(char *cmd, char **_env);
int is_executable(list_shell *datash);
int check_error_cmd(char *dir, list_shell *datash);
int cmd_exec(list_shell *datash);

/* env.c */
char *_getenv(const char *name, char **_env);
int _environ(list_shell *datash);

/* env2.c */
char *copy_info(char *name, char *value);
void set_env(char *name, char *value, list_shell *datash);
int _setenv(list_shell *datash);
int _unsetenv(list_shell *datash);

/* cd.c */
void cd_dot(list_shell *datash);
void cd_to(list_shell *datash);
void cd_previous(list_shell *datash);
void cd_to_home(list_shell *datash);

/* cd_shell.c */
int cd_shell(list_shell *datash);

/* builtin.c */
int (*get_builtin(char *cmd))(list_shell *datash);

/* exit.c */
int exit_shell(list_shell *datash);

/* stdlib.c */
int get_len(int n);
char *aux_itoa(int n);
int _atoi(char *s);

/* error.c */
char *strcat_cd(list_shell *, char *, char *, char *);
char *error_get_cd(list_shell *datash);
char *error_not_found(list_shell *datash);
char *error_exit_shell(list_shell *datash);

/* error2.c */
char *error_get_alias(char **args);
char *error_env(list_shell *datash);
char *error_syntax(char **args);
char *error_permission(char **args);
char *error_path_126(list_shell *datash);


/* get_error.c */
int get_error(list_shell *datash, int eval);

/* get_signal.c */
void get_sigint(int sig);

/* help.c */
void aux_help_env(void);
void aux_help_setenv(void);
void aux_help_unsetenv(void);
void aux_help_general(void);
void aux_help_exit(void);

/* help2.c */
void aux_help(void);
void aux_help_alias(void);
void aux_help_cd(void);

/* get_help.c */
int get_help(list_shell *datash);

/* shell.c */
void free_data(list_shell *datash);
void set_data(list_shell *datash, char **av);
int main(int ac, char **av);

#endif
