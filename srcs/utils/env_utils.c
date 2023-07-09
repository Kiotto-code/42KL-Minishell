/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yichan <yichan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 22:29:45 by yichan            #+#    #+#             */
/*   Updated: 2023/07/09 01:19:38 by yichan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	envl_lstdelone(t_env *lst)
{
	if (!lst)
		return ;
	free(lst->var);
	lst->var = NULL;
	free(lst->key);
	lst->key = NULL;
	free(lst->value);
	lst->value = NULL;
	free(lst);
	lst = NULL;
}

void	envl_destroy(t_env **lst)
{
	t_env	*tmp;

	if (!lst)
		return ;
	while (*lst)
	{
		tmp = (*lst)->next;
		envl_lstdelone(*lst);
		*lst = tmp;
	}
	*lst = NULL;
}

int	env_lstsize(t_env *env)
{
	int		count;

	if (!env)
		return (-1);
	count = 0;
	while (env)
	{
		env = env->next;
		count++;
	}
	return (count);
}


/**
 * @brief if env->key == key, return the whole env_value string line
 * 
 * @param env 
 * @param key 
 * @return char* 
 */
char	*check_envvar(t_env *env, char *key)
{
	if (!env || !key)
		return (NULL);
	while (env)
	{
		// printf(RED"%s \n"DEFAULT, env->value);
		if (!ft_strcmp(env->key, key))
			return (env->value);
		env = env->next;
	}
	return (NULL);
}

void	chg_shlvl(t_env *env, char *key, char *value)
{
	if (!env || !key || !value)
		return ;
	while (env)
	{
		if (!ft_strcmp(env->key, key))
		{
			if (env->var)
				free(env->var);
			env->var = ft_strjoin_con(key, "=", value);
			if (env->value)
				free(env->value);
			env->value = ft_strdup(value);
			return ;
		}
		env = env->next;
	}
}
