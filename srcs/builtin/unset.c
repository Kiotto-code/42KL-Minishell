/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etlaw <ethanlxz@gmail.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 17:50:29 by etlaw             #+#    #+#             */
/*   Updated: 2023/06/08 18:36:31 by etlaw            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

// frees node of linked list
static void	free_node(t_env *lst)
{
	t_env	*tmp;

	tmp = lst->next->next;
	free(lst->next->var);
	free(lst->next->key);
	free(lst->next->value);
	free(lst->next->next);
	free(lst->next->prev);
	free(lst->next);
	lst->next = tmp;
}

/* 
	loops through the list and compares the values with the str

	if found, it will free the node
*/
static void	remove_node(t_env **envr, t_env **export, char *str)
{
	t_env	*env;
	t_env	*exp;
	t_env	*tmp;
	char	*key;

	env = *envr;
	exp = *export;
	key = get_env_name(str);
	while (env)
	{
		if (ft_strcmp(key, env->next->key) == 0)
		{
			free_node(env);
		}
		env = env->next;
	}
	while (exp)
	{
		if (ft_strcmp(key, exp->next->key) == 0)
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
