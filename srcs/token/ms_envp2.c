/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_envp2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yichan <yichan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 19:02:29 by yichan            #+#    #+#             */
/*   Updated: 2023/04/08 20:59:41 by yichan           ###   ########.fr       */
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
		// (*lst)->next = new;
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
	node->var = content;
	return (node);
}