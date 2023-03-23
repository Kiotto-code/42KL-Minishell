/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_envp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etlaw <ethanlxz@gmail.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 00:40:48 by yichan            #+#    #+#             */
/*   Updated: 2023/03/22 22:06:54 by etlaw            ###   ########.fr       */
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

t_env	*newenvl(char *content)
{
	t_env	*node;

	node = ft_calloc(sizeof(t_env));
	if (!node)
		return (0);
	node->var = content;
	return (node);
}

int	ft_arr2envl(t_list **lst, char **arr)
{
	int	i;
	int	arr_len;

	if (!lst || !arr)
		return (0);
	i = -1;
	arr_len = ft_arrind(arr);
	while (++i < arr_len)
	{
		ft_lstadd_back(lst, ft_lstnew(newenvl(arr[i])));
	}
	return (0);
}

int	name_expand(t_list **lst, char **arr)
{
	t_list	*lst_itr;
	t_env	*env;

	if (!lst || !arr)
		return (0);
	lst_itr = (*lst);
	while ((lst_itr))
	{
		env = lst_itr->content;
		env->value = get_env_val(env->var);
		env->key = ft_substr(env->var, 0, env->value - env->var);
		(lst_itr) = (lst_itr)->next;
		// printf("%s", env->key);
		// printf("%s\n", env->value);
	}
	return (0);
}

// pid_t	file_open(char *path, char *flag)

void	record_init(t_book *record, char **envp)
{
	record->env = 0;
	record->token = 0;
	record->anchor = NEUTRAL;
	ft_arr2envl(&(record->env), envp);
	name_expand(&(record->env), envp);
}
