/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yichan <yichan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 18:21:34 by etlaw             #+#    #+#             */
/*   Updated: 2023/07/24 13:51:26 by yichan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	update_pwd(t_env **env, char *path)
{
	char	buf[100];
	char	*oldpwd;
	t_env	*tmp;

	(void)path;
	tmp = *env;
	getcwd(buf, 100);
	while (*env)
	{
		if (ft_strcmp((*env)->key, "PWD") == 0)
		{
			oldpwd = ft_strdup((*env)->value);
			free((*env)->value);
			free((*env)->var);
			(*env)->value = ft_strdup(buf);
			(*env)->var = var_strjoin((*env)->key, (*env)->value);
		}
		if (ft_strcmp((*env)->key, "OLDPWD") == 0)
		{
			free((*env)->value);
			free((*env)->var);
			(*env)->value = ft_strdup(oldpwd);
			(*env)->var = var_strjoin((*env)->key, (*env)->value);
			free(oldpwd);
		}
		*env = (*env)->next;
	}
	*env = tmp;
}

// cd function
int	ms_cd(t_env **env, char *path)
{
	int	ret;

	ret = chdir(path);
	if (ret == 0)
	{
		update_pwd(env, path);
		return (0);
	}
	ft_errormessage(path, 2);
	return (1);
}
