/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yichan <yichan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 17:50:29 by etlaw             #+#    #+#             */
/*   Updated: 2023/07/31 21:01:55 by yichan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// frees node of linked list
static void	free_node(t_env *lst)
{
	t_env	*tmp;

	tmp = 0;
	if (lst->next)
		tmp = lst->next->next;
	ft_free(lst->next->var);
	ft_free(lst->next->key);
	ft_free(lst->next->value);
	ft_free(lst->next);
	lst->next = tmp;
}

/* 
	loops through the list and compares the values with the str

	if found, it will ft_free the node
*/
static void	remove_node(t_env **envr, t_env **export, char *str)
{
	t_env	*env;
	t_env	*exp;
	char	*key;

	env = *envr;
	exp = *export;
	key = get_env_name(str);
	while (env)
	{
		if (env->next && ft_strcmp(key, env->next->key) == 0)
		{
			free_node(env);
		}
		env = env->next;
	}
	while (exp)
	{
		if (exp->next && ft_strcmp(key, exp->next->key) == 0)
		{
			free_node(exp);
		}
		exp = exp->next;
	}
}

// unset function
int	ms_unset(t_env **env, t_env **export, char **tkn)
{
	int	res;

	if (!tkn[1])
		return (0);
	res = is_iden(tkn[1], 3);
	if (res == 1)
		return (1);
	else if (res == 2)
	{
		ft_errormessage(tkn[1], 3);
		return (1);
	}
	else if (res == 3)
	{
		remove_node(env, export, tkn[1]);
	}
	return (0);
}
