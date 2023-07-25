/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_redirect.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yichan <yichan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 17:23:21 by yichan            #+#    #+#             */
/*   Updated: 2023/07/25 03:59:13 by yichan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	is_redirect(char *argument)
{
	if ((ft_strcmp(argument, ">") == 0)
		|| (ft_strcmp(argument, ">>") == 0)
		|| (ft_strcmp(argument, "<") == 0)
		|| (ft_strcmp(argument, "<<") == 0))
		return (1);
	return (0);
}

void	set_redirect(t_token *args)
{
	while (args)
	{
		if (is_redirect(args->entity) == 1)
		{
			args->redirect = 1;
			args->next->redirect = 2;
			args = args->next->next;
		}
		else if (args)
			args = args->next;
	}
}
