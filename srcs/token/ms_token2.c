/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_token2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yichan <yichan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 21:40:52 by yichan            #+#    #+#             */
/*   Updated: 2023/04/08 21:48:53 by yichan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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
