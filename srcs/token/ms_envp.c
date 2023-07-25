/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_envp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etlaw <ethanlxz@gmail.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 00:40:48 by yichan            #+#    #+#             */
/*   Updated: 2023/07/25 21:15:10 by etlaw            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*get_env_val(char *env)
{
	char	*str;
	char	*ret;

	str = ft_strchr(env, '=');
	ret = ft_substr(str, 1, ft_strlen(str));
	return (ret);
}

// t_env	*newenvl(char *content)
// {
// 	t_env	*node;

// 	node = ft_calloc(sizeof(t_env));
// 	if (!node)
// 		return (0);
// 	node->var = content;
// 	return (node);
// }

int	ft_arr2envl(t_env **lst, char **arr)
{
	int	i;
	int	arr_len;

	if (!lst || !arr)
		return (0);
	i = -1;
	arr_len = ft_arrind(arr);
	while (++i < arr_len)
	{
		ms_envladd_back(lst, (newenvl(arr[i])));
	}
	return (0);
}

int	env_rec(t_env **lst, char **arr)
{
	t_env	*lst_itr;

	if (!lst || !arr)
		return (0);
	lst_itr = (*lst);
	while ((lst_itr))
	{
		lst_itr->value = get_env_val(lst_itr->var);
		lst_itr->key = ft_substr(lst_itr->var, 0, \
			ft_strlen(lst_itr->var) - ft_strlen(lst_itr->value) - 1);
		(lst_itr) = (lst_itr)->next;
	}
	return (0);
}

/**
 * @brief open t_book as a main struct of organizing
 * 			different variables and required llist ptr
 * 			Initialize 0 value for convenient use.
 * 			ft_arr2envl to apart them into key:value pair got convenient use
 * @param record 
 * @param envp 
 */
void	record_init(t_book *record, char **envp)
{
	record->env = 0;
	record->cmds = 0;
	record->args = 0;
	record->env_arr = 0;
	record->input = 0;
	record->anchor = NEUTRAL;
	ft_arr2envl(&(record->env), envp);
	env_rec(&(record->env), envp);
	record->export = record->env;
}
