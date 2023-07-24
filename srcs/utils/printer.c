/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yichan <yichan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 22:30:25 by yichan            #+#    #+#             */
/*   Updated: 2023/07/22 23:08:46 by yichan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	print_env(t_env *env)
{
	if (env == NULL)
		return ;
	while (env)
	{
		printf("%s\n", env->var);
		printf("%s=%s\n", env->key, env->value);
		env = env->next;
	}
}

void	print_args(t_token *args)
{
	if (args == NULL)
		return ;
	while (args)
	{
		printf("args origin - |%s| \t %d\n", args->entity, args->redirect);
		args = args->next;
	}
}

void	print_cmds(t_cmdl *cmds)
{
	int		it;
	t_redir	*tmp;

	if (cmds == NULL || !cmds->command)
		return ;
	while (cmds)
	{
		it = 0;
		while (cmds->command[it])
		{
			printf("cmds command[%d] - |%s|\t in - |%d|\t out - |%d|\n", \
					it, cmds->command[it], cmds->in, cmds->out);
			it++;
		}
		tmp = (t_redir *) cmds->redir;
		while (tmp)
		{
			printf("redirect type - |%s| \t name - |%s|\n", tmp->type, tmp->name);
			tmp = tmp->next;
		}
		cmds = cmds->next;
	}
}

void	print_redir(t_cmdl *cmds)
{
	t_redir	*tmp;

	if (cmds == NULL)
		return ;
	while (cmds)
	{
		tmp =  cmds->redir;
		if (tmp == NULL)
			break ;
		while (tmp)
		{
			printf("redirect type - |%s| \t name - |%s|\n", tmp->type, tmp->name);
			tmp = tmp->next;
		}
		cmds = cmds->next;
	}
}

int	print_msg(int ret_val, char *message, int ext_stat)
{
	// ft_putstr_fd(BEGIN(49, 32)"./minishell>$ "CLOSE, STDERR_FILENO);
	ft_putendl_fd(message, STDERR_FILENO);
//	(void)ext_stat;
	g_exit_status = ext_stat;
	return (ret_val);
}

void	error_msg(char *message)
{
	if (message)
		ft_putendl_fd(message, STDERR_FILENO);
	else
		perror("Error");
	g_exit_status = 128;
}

void	no_such_message(char *message)
{
	ft_putstr_fd("minishell: ", STDERR_FILENO);
	ft_putstr_fd(message, STDERR_FILENO);
	ft_putstr_fd(": ", STDERR_FILENO);
	ft_putendl_fd(strerror(errno), STDERR_FILENO);
	// ft_putendl_fd(strerror(g_exit_status), STDERR_FILENO);
}
