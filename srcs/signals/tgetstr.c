/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tgetstr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yichan <yichan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 12:48:04 by yichan            #+#    #+#             */
/*   Updated: 2023/08/05 21:10:15 by yichan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	cursor_plc(int times)
{
	const char	*termtype = getenv("TERM");
	int			success;
	char		*cm;

	if (termtype == NULL)
		return (printf("TERM environment variable not set.\n"), 1);
	success = tgetent(NULL, termtype);
	if (success != 1)
		return (printf("Failed to retrieve terminal capabilities.\n"), 1);
	cm = tgetstr("up", NULL);
	if (cm == NULL)
		return (printf("cm capability not found.\n"), 1);
	tputs(cm, 1, putchar);
	rl_redisplay();
	(void)times;
	return (0);
}
