/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_envp2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etlaw <ethanlxz@gmail.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 19:02:29 by yichan            #+#    #+#             */
/*   Updated: 2023/08/04 01:39:49 by etlaw            ###   ########.fr       */
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

t_env	*newenvl(char *content)
{
	t_env	*node;

	node = ft_calloc(sizeof(t_env));
	if (!node)
		return (0);
	node->var = ft_strdup(content);
	node->next = NULL;
	return (node);
}

t_env	*ms_getenv_vkey(t_env *lst, char *key)
{
	if (!lst)
		return (lst);
	while (lst->next)
	{
		if (ft_strcmp(lst->key, key) == 0)
		{
			break ;
		}
		lst = lst->next;
	}
	return (lst);
}

t_env	*ms_getenv_vvar(t_env *lst, char *var)
{
	if (!lst)
		return (lst);
	while (lst->next)
	{
		if (ft_strcmp(lst->var, var) == 0)
		{
			break ;
		}
		lst = lst->next;
	}
	return (lst);
}