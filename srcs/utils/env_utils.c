/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yichan <yichan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 22:29:45 by yichan            #+#    #+#             */
/*   Updated: 2023/08/06 00:27:25 by yichan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// void	envl_lstdelone(t_env *lst)
// {
// 	if (!lst)
// 		return ;
// 	ft_free(lst->var);
// 	lst->var = NULL;
// 	ft_free(lst->key);
// 	lst->key = NULL;
// 	ft_free(lst->value);
// 	lst->value = NULL;
// 	ft_free(lst);
// 	lst = NULL;
// }

// void	envl_destroy(t_env **lst)
// {
// 	t_env	*tmp;

// 	if (!lst)
// 		return ;
// 	while (*lst)
// 	{
// 		tmp = (*lst)->next;
// 		envl_lstdelone(*lst);
// 		*lst = tmp;
// 	}
// 	*lst = NULL;
// }

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
		if (!ft_strcmp(env->key, key))
			return (env->value);
		env = env->next;
	}
	return ("");
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
				ft_free(env->var);
			env->var = ft_strjoin_con(key, "=", value);
			if (env->value)
				ft_free(env->value);
			env->value = ft_strdup(value);
			return ;
		}
		env = env->next;
	}
}

char	**env_to_array(t_env *env)
{
	int		row_count;
	int		i;
	char	**env_arr;

	if (env == NULL)
		return (NULL);
	row_count = env_lstsize(env);
	env_arr = (char **)malloc(sizeof(char *) * (row_count + 1));
	if (!env_arr)
		return (NULL);
	i = 0;
	while (env && (row_count != 0))
	{
		env_arr[i] = ft_strdup(env->var);
		i++;
		row_count--;
		env = env->next;
	}
	env_arr[i] = NULL;
	return (env_arr);
}
