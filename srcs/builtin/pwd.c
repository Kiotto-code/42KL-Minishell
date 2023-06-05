/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etlaw <ethanlxz@gmail.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 18:23:46 by etlaw             #+#    #+#             */
/*   Updated: 2023/04/06 18:35:15 by etlaw            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ms_pwd(t_list **env)
{
	t_list	*tmp;

	tmp = *env;
	while (*env)
	{
		if (ft_strcmp(((t_env *)(*env)->content)->key, "PWD") == 0)
		{
			printf("%s/n", ((t_env *)(*env)->content)->value);
			break ;
		}
		*env = (*env)->next;
	}
	*env = tmp;
}
