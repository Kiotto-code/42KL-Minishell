/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_envp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yichan <yichan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 00:40:48 by yichan            #+#    #+#             */
/*   Updated: 2023/04/25 01:52:00 by yichan           ###   ########.fr       */
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
		// (*lst)->content = (t_env *)((*lst)->content);
	}
	// printf ("%s \n", ((t_env *)(*lst)->content)->var);
	return (0);
}

int	name_expand(t_env **lst, char **arr)
{
	t_env	*lst_itr;
	// t_env	*env;

	if (!lst || !arr)
		return (0);
	lst_itr = (*lst);
	while ((lst_itr))
	{
		lst_itr->value = get_env_val(lst_itr->var);
		lst_itr->key = ft_substr(lst_itr->var, 0, \
			ft_strlen(lst_itr->var) - ft_strlen(lst_itr->value) - 1);
		// printf("%s\n", lst_itr->key);
		// printf("%s\n", lst_itr->value);
		(lst_itr) = (lst_itr)->next;
	}
	// printf ("%s \n", (*lst)->value);
	return (0);
}

void	record_init(t_book *record, char **envp)
{
	record->env = 0;
	record->token = 0;
	record->anchor = NEUTRAL;
	ft_arr2envl(&(record->env), envp);
	name_expand(&(record->env), envp);
}