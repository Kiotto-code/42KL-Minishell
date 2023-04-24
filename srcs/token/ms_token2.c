/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_token2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yichan <yichan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 21:40:52 by yichan            #+#    #+#             */
/*   Updated: 2023/04/25 02:06:25 by yichan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ms_deltoken(t_token *lst, void (*del)(void *))
{
	if (!lst || !del)
		return ;
	del(lst->entity);
	if (lst->prev)
		lst->prev->next = 0;
	free(lst);
}

void	ms_tokenlclear(t_token **lst, void (*del)(void *))
{
	t_token	*temp;

	while (*lst)
	{
		temp = *lst;
		*lst = (*lst)->next;
		ms_deltoken(temp, del);
	}
}

t_token	*ft_tokenllast(t_token *lst)
{
	if (!lst)
		return (lst);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

void	ms_tokenladd_back(t_token **lst, t_token *new)
{
	if (*lst)
	{
		new->prev = ft_tokenllast(*lst);
		ft_tokenllast(*lst)->next = new;
		// (*lst)->next = new;
	}
	else
		*lst = new;
}
