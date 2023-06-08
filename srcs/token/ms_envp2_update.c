/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_envp2_update.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etlaw <ethanlxz@gmail.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 21:51:28 by etlaw             #+#    #+#             */
/*   Updated: 2023/06/06 22:42:06 by etlaw            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_env	*ft_envllast(t_env *lst)
{
	if (!lst)
		return (lst);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

void	ms_envladd_back(t_env **lst, t_env *new)
{
	if (*lst)
	{
		new->prev = ft_envllast(*lst);
		ft_envllast(*lst)->next = new;
	}
	else
		*lst = new;
}

// updated new envl list 

t_env	*newenvl(char *content)
{
	t_env	*node;

	node = ft_calloc(sizeof(t_env));
	if (!node)
		return (0);
	node->var = content;
	if (ft_strchr(content, '=') == NULL)
	{
		node->value = 0;
		node->key = ft_strdup(content);
		return (node);
	}
	node->value = get_env_val(lst_itr->var);
	node->key = ft_substr(content, 0, \
			ft_strlen(content) - ft_strlen(lst_itr->value) - 1);
	return (node);
}
