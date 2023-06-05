/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etlaw <ethanlxz@gmail.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 18:21:34 by etlaw             #+#    #+#             */
/*   Updated: 2023/05/22 22:43:16 by etlaw            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	update_pwd(t_list **env, char *path)
{
	char	buf[100];
	char	*oldpwd;
	t_list	*tmp;

	tmp = *env;
	getcwd(buf, 100);
	while (*env)
	{
		if (ft_strcmp(((t_env *)(*env)->content)->key, "PWD") == 0)
		{
			oldpwd = ft_strdup(((t_env *)(*env)->content)->value);
			free(((t_env *)(*env)->content)->value);
			free(((t_env *)(*env)->content)->var);
			((t_env *)(*env)->content)->value = ft_strdup(buf);
			((t_env *)(*env)->content)->var = var_strjoin
				(((t_env *)(*env)->content)->key,
					((t_env *)(*env)->content)->value);
		}
		if (ft_strcmp(((t_env *)(*env)->content)->key, "OLDPWD") == 0)
		{
			free(((t_env *)(*env)->content)->value);
			free(((t_env *)(*env)->content)->var);
			((t_env *)(*env)->content)->value = ft_strdup(oldpwd);
			((t_env *)(*env)->content)->var = var_strjoin
				(((t_env *)(*env)->content)->key,
					((t_env *)(*env)->content)->value);
			free(oldpwd);
		}
		*env = (*env)->next;
	}
	*env = tmp;
}

int	ms_cd(t_list **env, char *path)
{
	int	ret;

	ret = chdir(path);
	if (ret == 0)
	{
		update_pwd(env, path);
		return (0);
	}
	ft_errormessage(path, 2);
	return (0);
}
