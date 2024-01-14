/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbousfir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 22:16:23 by wbousfir          #+#    #+#             */
/*   Updated: 2023/12/16 04:07:42 by wbousfir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include <stdio.h>
# include <stdlib.h>
# include <signal.h>
# include <unistd.h>
# include <string.h>
# include <sys/wait.h>
# include <pwd.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <errno.h>
# include <stdint.h>
# include <stdbool.h>

# define BUFFER_SIZE 5000
# define PATH_MAX 4096
# define MAX 1844674407370955161
# define MAX_INPUT_LENGTH 1024

typedef enum s_token
{
	GREAT,
	DGREAT,
	LESS,
	DLESS,
}					t_token;

typedef struct s_redirection
{
	int						fd_in;
	int						fd_out;
	char					*word;
	t_token					token;
	char					*herdoc_input;
	char					**herdoc_data;
	struct s_redirection	*next;
	struct s_redirection	*prev;
}					t_redirection;

typedef struct s_data
{
	char			**str;
	int				builtins;
	t_redirection	*redirections;
	int				exit_status;
	struct s_data	*next;
	struct s_data	*prev;
}					t_data;

typedef struct s_tools
{
	char	*input;
	size_t	i;
	size_t	j;
}t_tools;

typedef struct t_EnvironmentVariable
{
	char							*key;
	char							*value;
	struct t_EnvironmentVariable	*next;
}					t_EnvironmentVariable;

typedef struct t_Environment
{
	t_EnvironmentVariable	*head;
}					t_Environment;

typedef struct t_AssignementVariable
{
	char							*assignment;
	struct t_AssignementVariable	*next;
}					t_AssignementVariable;

int	g_signo[10];

/* 	LIBFT */
int						handel_specialcase(t_tools *k, char **result,
							size_t *resultindex, t_Environment *env);
char					*find_executable(char *command, t_Environment *env);
char					**remove_empty_str(char **str);
char					*my_strtok(char *str, const char delim);
size_t					my_strspn(const char *str, const char *charset);
char					*my_strcat(char *dest, const char *src);
char					*ft_strncat(char *dest,
							const char *src, int nb);
int						ft_isalpha(int c);
int						ft_isdigit(int c);
int						ft_isalnum(int c);
int						ft_isascii(int c);
int						ft_isprint(int c);
size_t					ft_strlen(const char	*s);
void					*ft_memset(void *s, int c, size_t n);
void					*ft_bzero(void *s, size_t n);
size_t					ft_strspn(const char *str, const char *charset);
char					*ft_strcat(char *dest, char *src);
void					*ft_memcpy(void *dst,
							const void *src, size_t n);
void					*ft_memmove(void *dst,
							const void *src, size_t len);
size_t					ft_strlcpy(char *dst,
							const char *src, size_t size);
size_t					ft_strlcat(char *dest,
							const char *src, size_t size);
int						ft_toupper(int c);
int						ft_tolower(int c);
char					*ft_strchr(const char *s, int c);
int						ft_strncmp(const char *s1,
							const char *s2, size_t n);
void					*ft_memchr(const void *s, int c, size_t n);
int						ft_memcmp(const void *s1,
							const void *s2, size_t n);
char					*ft_strrchr(const char *s, int c);
char					*ft_strnstr(const char *haystack,
							const char *needle, size_t len);
int						ft_atoi(const char *str);
void					*ft_calloc(size_t count, size_t size);
char					*ft_substr(char const *s,
							unsigned int start, size_t len);
char					*ft_strdup(const char *s1);
char					*ft_strjoin(char const *s1, char const *s2);
char					*ft_strtrim(char const *s1);
char					**ft_split(char const *s, char c);
char					*ft_itoa(int n);
char					*ft_strmapi(char const *s,
							char (*f)(unsigned int, char));
void					ft_striteri(char *s, void (*f)(unsigned int, char*));
void					ft_putchar_fd(char c, int fd);
void					ft_putstr_fd(char *s, int fd);
void					ft_putendl_fd(char *s, int fd);
void					ft_putnbr_fd(int n, int fd);
char					*ft_strncpy(char *dest,
							const char *src, unsigned int n);
size_t					ft_strlen_helmoue(const char *str);
size_t					ft_strcspn_helmoue(const char *str, const char *reject);
int						ft_strcmp(char *s1, char *s2);
char					**ft_split(char const *s, char c);
char					*ft_strrcpy(char *s1, char *s2, int n);
int						lenalloc_wbousfir(char *str);
char					**ft_split_cmd(char *str);
void					ft_putstr_fd_wbousfir(char *s, int fd);
void					ft_putchar_fd_wbousfir(char c, int fd);
char					*ft_strdup_wbousfir(char *src);
char					*ft_strdup_wbousfirr(const char *src);
char					*ft_strtok(char *str, const char *delim);
void					ft_strtok_utils(char *tokenend, char *lasttoken);

char					*int_to_string(int num);
void					ft_putchar(char c);
void					ft_putstr(char *str);
char					*ft_strcpy(char *dest, char *src);

/* BUILTIN */

int						check_all_built_ins(t_data *cmds, t_Environment *env);
int						check_built_ins_special(char **args, t_Environment *env,
							t_AssignementVariable *assignement_variables);
int						built_in_unset_handling(
							t_Environment *env, char **args,
							t_AssignementVariable *assignement_variables);
int						built_in_export_handling(
							t_Environment *env, char **args);
int						built_in_export_full_handling(t_Environment *env,
							char **args,
							t_AssignementVariable *assignement_variables);
int						built_in_exit_handling(char **args, t_Environment *env);
int						built_in_echo_handling(char **args, t_Environment *env);
int						built_in_pwd_handling(char **args, t_Environment *env);
int						built_in_env_handling(t_Environment *env, char **args);

/* BUILTIN UTILS */

void					handle_export_args(t_Environment *env, char **args,
							t_AssignementVariable *assignement_variables);
void					handle_var_assignment(t_Environment *env,
							char *var_assignment);
void					handle_no_var_assignment(
							t_Environment *env, char *args);
void					handle_cd_no_arguments(char **args,
							t_Environment *env, int fd);
void					handle_cd_parent_directory(void);
void					handle_cd_home_directory(t_Environment *env, int fd);
void					handle_cd_custom_directory(char *directory);
int						handling_cd(char **args, t_Environment *env);
char					*the_builtin(char *command);
int						change_directory(char *path_to, t_Environment *env);
char					*parse_path(char **cmd, t_Environment *env);
int						count(char **cmd);

/* MAIN */

void					initialize_environment(t_Environment *env,
							char **env_data);
void					shell_loop(t_Environment *env);
void					cleanup_and_exit(t_Environment *env,
							t_AssignementVariable *assignement_variables);
void					print_prompt(void);
int						is_normal_builtin(char **command);
int						is_builtin(char **command);
int						is_special_builtin(char **command);
void					get_hostname_local(char str_hostname[MAX_INPUT_LENGTH]);
char					**copy_double_ptr(char **env);
void					copy_to_array(t_Environment *env, char **result);
char					**convert_to_double_pointer(t_Environment *env);
int						count_non_empty_pairs(t_Environment *env);
void					free_double_pointer(char **env);
void					ctrlchandler(int sig);
char					*cutable(char *command, t_Environment *env);
char					*get_path_copy(t_Environment *env);
char					*search_executable(char *command, char *path_copy);
int						is_executable(const char *path);
int						main_check(t_data *cmds, t_Environment *env,
							t_AssignementVariable *assignement_variables);
int						main_setup(t_Environment *env, t_data *cmds);
void					initialize_environment(t_Environment *env,
							char **env_data);
char					**initialize_shell_loop_variables(
							t_data **cmds, char **input);
void					setup_environment(t_Environment *env_copy,
							char **env);
void					shell_loop(t_Environment *env);
void					shell_loop_exit(char **allcommands,
							t_data *cmds, char *input, t_Environment *env);
void					handle_signal(void);
char					*find_equal_sign(char *str);
void					setup_save_env_user(t_Environment *env_copy);
void					setup_process_environment_variable(
							t_Environment *env_copy, char *name, char *value);

/* ENVIRONNEMENT */
/* set_env_var utils */

void					set_env_var(t_Environment *env, const char *key,
							const char *value);
void					update_existing_var(t_EnvironmentVariable *current,
							const char *value);
t_EnvironmentVariable	*create_new_var(const char *key, const char *value);
void					add_new_var_to_head(t_Environment *env,
							t_EnvironmentVariable *new_var);

/**/

void					unset_env_var(t_Environment *env, const char *key,
							t_AssignementVariable *assignement_variables);
void					unset_assignement_var(const char *assignement,
							t_AssignementVariable **assignement_variables);
void					print_var_env_reverse(
							const t_EnvironmentVariable *current, int counter);
void					print_var_env(const t_Environment *env);
void					print_env_export(const t_Environment *env);
void					print_env_export_reverse(
							const t_EnvironmentVariable *current);

/* ENVIRONNEMENT UTILS */

char					**copy_double_ptr(char **env);
void					save_environment_variable(t_Environment *env,
							const char *key, const char *value);
void					save_assignement_variable(char *assignment);
void					add_assignment(char *assignment,
							t_AssignementVariable *assignement_variables);
void					update_assignment(t_AssignementVariable *variable,
							const char *assignment);
char					*retrieve_assignement_variable(const char *var_name,
							t_AssignementVariable *assignement_variables);
char					*get_assignement_var_name(const char *input);
char					*get_get_env_var(const t_Environment *env, char *key);
char					*get_env_var(t_Environment *env, const char *key);

/* ENVIRONNEMENT UTILS SECONDARY */

int						is_valid_variable_name_double(const char *args);
int						is_valid_variable_name_utils(const char *args,
							size_t j, const char *right_string);
int						check_if_assignement(t_data *cmds,
							t_AssignementVariable *assignement_variables);
int						len_env(char **env);
char					*int_to_string(int num);
void					convert_env_to_list(t_Environment *env, char **envp);
int						is_valid_variable_name(const char *var_name);
void					free_linked_lists(t_Environment *env_copy, 
							t_AssignementVariable *assignement_variables);
void					free_double_pointer(char **array);
char					*get_get_env_var_reverse(
							const t_EnvironmentVariable *current,
							char *key, int counter);
int						check_if_assignement_variable_exist(
							const char *assignment,
							t_AssignementVariable *assignement_variables);
int						check_if_enviroment_variable_exist(const char *key,
							t_EnvironmentVariable *environment_variables);
char					*find_assignment_value(char *search_key,
							t_AssignementVariable *assignement_variables);
t_AssignementVariable	*find_assignment(const char *assignment,
							t_AssignementVariable *assignement_variables);

/* EXECUTION */
void					execute_multiple_pipe_commands(t_Environment *env,
							t_data *cmds);
int						execute_single_command(t_data *cmds, t_Environment *env,
							int *child, int *save);
char					**get_bin_paths(t_Environment *env);
int						execute_cmd(t_data *cmds, t_Environment *env,
							int *save, bool *in_fork);
void					execute_child_process(t_data *cmds, int pipe_fd[2],
							int *save, t_Environment *env);
void					execute_parent_process(int *save, int pipe_fd[2]);
int						execute_command_loop(t_data *cmds, t_Environment *env,
							t_AssignementVariable *assignement_variables,
							int *child);
int						execute_command_loop_utils(t_data *cmds,
							t_Environment *env,
							t_AssignementVariable *assignement_variables,
							int *child);
int						execute_utils(t_data *cmd, t_Environment *env,
							int *save);
void					perform_shell_loop(t_Environment *env,
							char **allcommands, char *input);
void					get_bin_and_exec(char **env_copy, t_data *cmds,
							t_Environment *env);
int						build_redirections(t_data *cmds, int *pipe_fd,
							int *save, t_Environment *env);
int						check_redirections(t_redirection *redirection,
							t_Environment *env);
int						execute_builtin_special(t_data *cmds,
							t_Environment *env);
int						execute_builtin_special_or_assign(t_data *cmds,
							t_Environment *env, bool *in_fork);
void					handle_redirections(t_redirection *redirections,
							int fd_in, int fd_out);
char					*get_exit_status(const t_Environment *env);
char					*get_exit_status_utils(
							const t_EnvironmentVariable *current);
char					*check_if_command_include_path(char *command);
void					check_after_execution(t_data *cmds, t_Environment *env);
void					print_the_error(t_data *cmds, t_Environment *env);
void					ft_exit(t_Environment *env, int return_status,
							int fork_status, bool *in_fork);
void					put_cmd_error(char *cmd_str, char *error_str,
							t_Environment *env);
void					put_strerror(t_data *cmds, int __errno,
							t_Environment *env);
/* EXECUTION UTILS */

int						is_valid_exit(char *str);
void					print_exit_handling(char *str, t_Environment *env);

/* SIGNAL */

int						wtermsig_wbousfir(int status);
int						wifsignaled_wbousfir(int status);
int						wexitstatus_wbousfir(int status, t_Environment *env);

/* PARSING */

/* To_data utils */
t_data					*to_data(char **command, int i, t_data *prev,
							t_Environment *env);
t_data					*initialize_data(char **command, int i);
void					to_data_var(t_data *cmds, t_Environment *env);
void					handle_norm_to_data(t_data *cmds,
							t_Environment *env);
int						ll(t_data *cmds);
int						norm_to_data(char **str, int j);
char					*removeand(char *str);

/*   */

int						parsing(char ***allcommands,
							char *line, t_Environment *env);
char					**ft_pipe_split(char *s);
int						quotes_checker_for_pipe(const char *str, int j);
int						quotes_cheker_for_pipe(const char *str, int j);
char					quotes_open(const char *str, int j);
char					*remove_quotes(char *str);
void					free_doc_data(t_redirection *redirections);
int						is_her(char *command);

/* 	HAMZA UTILS */

char					**split_main1(char **allcommands, char *line);
void					free_all(char **allcommands, t_data *cmds);
void					print2d(char **str);
void					free2d(char **arr);
void					free_data(t_data *cmds);
void					norm_for_this_file(char *new_str,
							char *str, int *i, int *j);
char					*replace_env_var(char *input, t_Environment *env);

/* PARSING UTILS */

void					replace_env_variable(char **result,
							size_t *resultindex, const char *envvalue);
void					handle_character(char **result, size_t *resultindex,
							char character);
size_t					process_env_var(char **result,
							size_t *resultindex,
							char **input, t_Environment *env);
char					*extract_varname(const char *afterdollarpos);
char					*allocate_memory(size_t size);

/* REDIRECTION SECONDARY FUNCTIONS */

char					*add_space_after_redirection(char *str);
char					*add_space_befor_redirection(char *str);
char					**remove_redirection(char **str);
int						great_less_cheker(char *line);
int						dless_is_quote(char c);
int						dless_check_quote(char *line, int *i);
int						dless_check_redirect(char *line, int *i,
							int double_redirect);
int						dless_process_redirect(char *line, int *i);
int						cheker(char *line);
int						great_great_less_less_cheker(char *line);

/* open herdoc utils*/
char					**open_herdoc(char *str, t_Environment *env);
char					*prepare_exit_string(char *str);
char					*read_heredoc_utils(char *line,
							char *exit, t_Environment *env);
// char					**open_herdoc_loop(char *exit,
// 							t_Environment *env, char *line);
/**/
char					*convert_herdoc(char **herdoc_data);
int						cheker(char *line);
int						quotes_cheker(char *str);
int						pipe_cheker(char *line);

/* CHECKER.C */

int						ft_loop_cherker(char *line, int *i, int k);
int						great_less_cheker(char *line);
int						great_great_less_less_cheker(char *line);
int						ft_loop2_cherker(char *line, int *i, int k);
int						check_the_word_after_quotes(char *line);

/* HAMZA REDIRECTION */

t_redirection			*norm1(char **str, int *i,
							t_redirection **prev, t_Environment *env);
t_redirection			*norm2(char **str, int *i,
							t_redirection **prev, t_Environment *env);
t_redirection			*norm3(char **str, int *i,
							t_redirection **prev, t_Environment *env);
t_redirection			*norm4(char **str, int *i,
							t_redirection **prev, t_Environment *env);
t_redirection			*hel_redirection(char **str,
							t_redirection *prev, t_Environment *env);
t_redirection			get_the_last_redirection(t_redirection *redirections);
int						check_w_acc(char *file);
int						overwrite_append(t_redirection *redirections);
int						stdin_redirections(t_redirection *redirections,
							t_Environment *env);
void					get_doc_data(t_redirection *redirections);
void					join_and_free(t_redirection *token, char *str);

/* GETNEXTLINE UTILS */

char					*nwline(char *p);
char					*cutline(char *p);
int						strlen_hlpr(const char *s);
char					*strdup_hlpr(char *str);
char					*strchr_hlpr(const char *s, int c);
char					*substr_hlpr(const char *s, int start, int len);
char					*strjoin_hlpr(char *s1, char *s2);

/* chi_hajat */

void					ft_some(char **result, size_t *resultIndex,
							size_t plus);
int						rr(char *input, size_t i);
void					init_for_replace_env_var(size_t *inputLength,
							char **result, size_t *resultIndex, char *input);
int						ft_con(char *input, size_t i);
void					nonorm(int *i, char *str);

#endif
