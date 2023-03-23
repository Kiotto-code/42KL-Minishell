/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etlaw <ethanlxz@gmail.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 20:29:21 by etlaw             #+#    #+#             */
/*   Updated: 2023/03/21 18:33:15 by etlaw            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	ms_env(t_list **lst)
{
	t_list	*tmp;

	tmp = *lst;
	while (*lst)
	{
		if (((t_env *)(*lst)->content)->var != 0)
			printf("%s\n", ((t_env *)(*lst)->content)->var);
		*lst = (*lst)->next;
	}
	*lst = tmp;
	return ;
}
