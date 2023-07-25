/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tgetstr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yichan <yichan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 12:48:04 by yichan            #+#    #+#             */
/*   Updated: 2023/07/25 09:50:43 by yichan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	cursor_plc(int times)
{
	const char	*termtype = getenv("TERM");
	int			success;
	char		*cm;

	if (termtype == NULL)
	{
		printf("TERM environment variable not set.\n");
		return (1);
	}
	success = tgetent(NULL, termtype);
	if (success != 1)
	{
		printf("Failed to retrieve terminal capabilities.\n");
		return (1);
	}
	cm = tgetstr("up", NULL);
	if (cm == NULL)
	{
		printf("cm capability not found.\n");
		return (1);
	}
	tputs(cm, 1, putchar);
	while (times --)
		printf(">");
	return (0);
}
