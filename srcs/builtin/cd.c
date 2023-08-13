/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etlaw <ethanlxz@gmail.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 18:21:34 by etlaw             #+#    #+#             */
/*   Updated: 2023/08/13 23:37:59 by etlaw            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*replace_pwd(t_env *env, char *buf)
{
	char	*oldpwd;

	oldpwd = ft_strdup(env->value);
	ft_free(env->value);
	ft_free(env->var);
	env->value = ft_strdup(buf);
	env->var = ft_strjoin_con(env->key, "=", env->value);
	return (oldpwd);
}

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
			oldpwd = replace_pwd(*env, buf);
		if (ft_strcmp((*env)->key, "OLDPWD") == 0)
		{
			ft_free((*env)->value);
			ft_free((*env)->var);
			(*env)->value = oldpwd;
			(*env)->var = ft_strjoin_con((*env)->key, "=", (*env)->value);
		}
		*env = (*env)->next;
	}
	*env = tmp;
}

// updates the env and export list
static void	update_cd(t_env **env, t_env **export, char *path)
{
	update_lst(env, "PWD");
	update_lst(export, "PWD");
	update_lst(env, "OLDPWD");
	update_lst(export, "OLDPWD");
	update_pwd(env, path);
	update_pwd(export, path);
}

// checks if path is "-"
static char	*prev_dir(t_env *env, char *path)
{
	char	tmp[100];

	if (path == NULL)
		return (0);
	ft_strlcpy(tmp, path, ft_strlen(path) +1);
	if (ft_strcmp(tmp, "-") == 0)
	{
		path = check_envvar(env, "OLDPWD");
		if (*path == 0)
		{
			ft_putstr_fd("minishell: cd: OLDPWD not set\n", 2);
			return (0);
		}
		printf("%s\n", path);
	}
	return (path);
}

// cd function
int	ms_cd(t_env **env, t_env **export, char *path)
{
	int		ret;
	t_env	*tmp;

	path = prev_dir(*env, path);
	if (path == NULL)
		return (0);
	if (ft_strcmp(path, "~") == 0)
	{
		tmp = ms_getenv_vkey(*env, "HOME");
		if (!tmp)
			path = getenv("HOME");
		else
			path = tmp->value;
		if (path == NULL)
			return (0);
	}
	ret = chdir(path);
	if (ret == 0)
	{
		update_cd(env, export, path);
		return (0);
	}
	return (ft_errormessage(path, 2), 1);
}
