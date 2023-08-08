/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_token2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yichan <yichan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 21:40:52 by yichan            #+#    #+#             */
/*   Updated: 2023/08/08 21:52:23 by yichan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// int		check_quote(int c)
// {
// 	if (c == '\'' || c == '\"')
// 		return (1);
// 	return (0);
// }

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
	if (new == NULL)
		return ;
	if (*lst)
	{
		new->prev = ft_tokenllast(*lst);
		ft_tokenllast(*lst)->next = new;
	}
	else
		*lst = new;
}

/**
 * @brief Split the input into 
 * 
 * @param record 
 * @return int 
 */
void	ms_token(t_book *record)
{
	if (*record->input == '#')
		return ;
	ms_quotesplit(record, 0, 0, NULL);
	set_redirect(record->args);
	if (record->args == NULL)
	{
		ft_free(record->input);
		record->input = NULL;
	}
}
