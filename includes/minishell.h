/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etlaw <ethanlxz@gmail.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 18:17:57 by yichan            #+#    #+#             */
/*   Updated: 2023/07/28 00:09:19 by etlaw            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <stdlib.h>
# include <signal.h>
# include <termios.h>
# include <sys/types.h> //pid_t data type
# include <sys/errno.h>
# include <sys/wait.h>
# include <readline/history.h>
# include <readline/readline.h>
# include "../libft/includes/libft.h"
# include <unistd.h>
# include <curses.h>
# include <term.h>

# define DEFAULT	"\033[0m"
# define CYAN		"\033[0;36m"
# define RED		"\033[0;31m"

# define CLOSE		"\001\033[0m\002"
# define BOLD		"\001\033[1m\002"
// # define BEGIN(x,y) "\001\033["#x";"#y"m\002"
// x: background change font, y: foreground change color

# define SQUOTE		1
# define DQUOTE		2
# define DOLLAR		4
# define QUOTE		8
# define NEUTRAL	0

# define PIPE		4
# define QUERY		5
// # define DOLLAR		6
# define LEFT		7
# define RIGHT		8
# define LITERAL	9
# define DLEFT		10
# define DRIGHT		11

int	g_exit_status;

//envl
typedef struct s_env
{
	char			*var;
	char			*key;
	char			*value;
	struct s_env	*prev;
	struct s_env	*next;
}	t_env;

//argl
typedef struct s_token
{
	char			*entity;
	int				redirect;
	struct s_token	*prev;
	struct s_token	*next;
}	t_token;

//cmdl
typedef struct s_cmdl
{
	char			**command;
	int				in;
	int				out;
	int				pipe_fd[2];
	int				fork;
	pid_t			pid;
	struct s_redir	*redir;
	struct s_cmdl	*next;
}				t_cmdl;

//shell
typedef struct s_book
{
	char			**env_arr;
	char			*input;
	int				anchor;
	t_env			*env;
	t_env			*export;
	t_token			*args;
	t_cmdl			*cmds;
	struct termios	termios_current;
}	t_book;

typedef struct s_redir
{
	char			*type;
	char			*name;
	struct s_redir	*next;
}				t_redir;

/**
* EXECUTION:
*/
// execute_cmds.c
void	execute_cmds(t_book *mini, t_cmdl *cmds);
void	executing(t_book *record, t_cmdl *cmds);
char	**env_to_array(t_env *env);
//here_doc.c
void	heredoc_processing(t_book *record, t_cmdl *cmd, t_env *env);
int		heredoc_checking(t_cmdl *cmd);
bool	pre_execv(t_book *record, t_cmdl *cmds);
//path_processing.c
char	*path_processing(t_book *mini, char *line);
//pipex.c
int		pipe_creator(t_cmdl *cmds);
// builtin.c
int		builtin_checker(char *command);
void	builtin_executing(t_book *mini, t_cmdl *cmds);
//execve.c
void	path_execve(t_book *record, t_cmdl *cmds, char *file, char **env_arr);

/**
 * PARSE:
 */
//parser_utils.c
int		pass_whitespaces(char *input, int it);
void	fd_opening(t_cmdl *cmds);
//redirect_processing.c
t_redir	*redirect_processing(t_token **args);
//validator.c
int		validator(char *input);
int		counting_redirect(char *input, int *it, char redirect);
//commands_processing.c
void	ms_cmds(t_book *record);
//cmdl_create.c
void	cmds_lstadd_back(t_cmdl	**list, t_cmdl *new);
t_cmdl	*cmds_lstnew(t_token *args);
// postparser.c
char	*postparser(char *input);
char	*is_slash(char *input, int *it);
// quote_processing.c
char	*is_quote(char *input, int *it);
char	*is_db_quote(char *input, int *it, t_env *env);
// dollar_processing.c
char	*is_dollar(char *input, int *it, t_env *env);
// set_redirect.c
void	set_redirect(t_token *args);

/**
 * SIGNALS:
 */
// sig_interactive.c
void	sigs_interactive_shell(struct termios *termios_current);
void	reset_termios(struct termios *termios_current);
void	sig_interrupt_here(int sig);

// sig_non_interactive.c
void	sigs_non_interactive_shell(void);

// tgetstr.c
int		cursor_plc(int i);

/**
 * TOKEN:
 */
//ms_envp.c
char	*get_env_val(char *env);
// ms_envp2.c
void	ms_envladd_back(t_env **lst, t_env *new);
t_env	*newenvl(char *content);
t_env	*ft_envllast(t_env *lst);
// ms_token2.c
void	ms_tokenladd_back(t_token **lst, t_token *new);
t_token	*ft_tokenllast(t_token *lst);
int		check_quote(int c);
//ms_token.c
void	ms_token(t_book *record);
int		ms_inputloop(t_book *record);
void	record_init(t_book *record, char **envp);
//ms_expandenv.c
char	*expandenv(t_book *record, char **str);
char	*here_xpnd(t_book *record, char **str);

/**
 * UTILS:
 */
//argument_utils.c
void	args_lstdelnode(t_token **args);
void	args_destroy(t_token **lst);
//env_utils.c
int		env_lstsize(t_env *env);
char	*check_envvar(t_env *env, char *key);
void	chg_shlvl(t_env *env, char *key, char *value);
//execute_utils.c
int		execute_dup2(t_cmdl *cmds);
// memory_processing.c
void	array_liberator(char **array);
void	cleaner(t_book *record);;
// command_utils.c
void	cmds_destroy(t_cmdl **lst);
// shlvl_change.c
void	shlvl_up(t_book *record);
void	shlvl_down(t_book *record);

/*
 * //only for printing; No particular usage
 */
void	print_env(t_env *env);
void	print_args(t_token *args);
void	print_cmds(t_cmdl *cmds);
void	print_redir(t_cmdl *cmds);
int		print_msg(int ret_val, char *message, int ext_stat);
void	no_such_message(char *message);
void	error_msg(char *message);

void	sig_non_interactive_quit(int sig);
void	sig_ignore(void);
void	sig_interrupt(int sig);

/**
 * BUILTIN:
 */
// builtin_utils.c
void	ft_errormessage(char *str, int format);
void	free_2arr(char **arr);
int		is_iden(char *str, int format);
t_env	*newenvlist(char *content);
// echo.c
int		ms_echo(char **av);
// env.c
int		ms_env(t_env *env);
// export.c
char	*get_env_name(char *str);
void	change_value(t_env *env, char *tkn);
int		update_lst(t_env **lst, char *tkn);
int		ms_export(t_env **env, t_env **export, char **tkn);
// print_export.c
int		str_env_len(t_env *lst);
char	*env_to_str(t_env *env);
void	sort_env(char **env);
void	print_export_env(t_env **env);
// pwd.c
int		ms_pwd(t_env *env);
// unset.c
int		ms_unset(t_env **env, t_env **export, char **tkn);
// cd.c
int		ms_cd(t_env **env, t_env **export, char *path);
//exit.c
int		ms_exit(t_book *mini, char **argv);

//builtin
# define EXPORT		1
# define CD			2

// typedef struct s_env
// {
// 	char			*var;
// 	char			*key;
// 	char			*value;
// 	struct s_env	*next;
// 	struct s_env	*prev;
// }	t_env;

// typedef struct s_token
// {
// 	char			*entity;
// 	int				type;
// }	t_token;

// typedef struct s_book
// {
// 	char	**env_arr;
// 	char	*input;
// 	int		anchor;
// 	t_list	*env;
// 	t_list	*token;
// }	t_book;

//----utils
//ms_libft.c

//----allocate
//ms_initiate.c
// void	ms_token(t_book *record);
// int		ms_inputloop(t_book *record);
// void	record_init(t_book *record, char **envp);
// // ms_lexer.c
// int		ms_lexer(t_book *record, t_token *token);

void	ft_errormessage(char *str, int format);

#endif
