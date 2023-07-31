/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shlvl_change.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yichan <yichan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 22:30:30 by yichan            #+#    #+#             */
/*   Updated: 2023/07/31 21:01:55 by yichan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	shlvl_down(t_book *record)
{
	char	*cur_lvl;
	char	*up_lvl;

	cur_lvl = check_envvar(record->env, "SHLVL");
	up_lvl = ft_itoa(ft_atoi(cur_lvl) - 1);
	chg_shlvl(record->env, "SHLVL", up_lvl);
	ft_free(up_lvl);
}

void	shlvl_up(t_book *record)
{
	char	*cur_lvl;
	char	*up_lvl;

	cur_lvl = check_envvar(record->env, "SHLVL");
	up_lvl = ft_itoa(ft_atoi(cur_lvl) + 1);
	chg_shlvl(record->env, "SHLVL", up_lvl);
	ft_free(up_lvl);
}
