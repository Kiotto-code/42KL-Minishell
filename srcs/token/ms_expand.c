/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_expand.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etlaw <ethanlxz@gmail.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 20:42:04 by etlaw             #+#    #+#             */
/*   Updated: 2023/03/23 22:52:58 by etlaw            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"


void find_dollar(t_list **tkn)
{
	int i;
	char *str;

	if (entity[i] == '?')
		str = get_exit_status
	else
		str = find_val 
}

static void expand(t_list **env, t_list **tkn)
{
	char	*replace;

	replace = find_val(env, ((t_token *)(*tkn)->content)->entity);
}

static char	*find_val(t_list **lst, char *s_expand)
{
	t_list	*tmp;

	tmp = lst;
	while (*lst)
	{
		if (ft_strcmp(((t_env *)(*lst)->content)->key, s_expand) == 0)
			return (ft_strdup(((t_env *)(*lst)->content)->value));
		else
			return (0);
	}
}
