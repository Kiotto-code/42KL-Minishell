/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_inputloop.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etlaw <ethanlxz@gmail.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 23:03:16 by yichan            #+#    #+#             */
/*   Updated: 2023/03/22 22:06:14 by etlaw            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ms_inputloop(t_book *record)
{
	while (1)
	{
		record->input = readline("./minishell> ");
		if (record->input == NULL)
			exit (exit_status);
		ms_token(record);
		free(record->input);
	}
	return (0);
}
