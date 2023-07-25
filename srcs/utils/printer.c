/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yichan <yichan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 22:30:25 by yichan            #+#    #+#             */
/*   Updated: 2023/07/25 09:47:03 by yichan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	print_msg(int ret_val, char *message, int ext_stat)
{
	ft_putendl_fd(message, STDERR_FILENO);
	g_exit_status = ext_stat;
	return (ret_val);
}

void	error_msg(char *message)
{
	if (message)
		ft_putendl_fd(message, STDERR_FILENO);
	else
		perror("Error");
	g_exit_status = 128;
}

void	no_such_message(char *message)
{
	ft_putstr_fd("minishell: ", STDERR_FILENO);
	ft_putstr_fd(message, STDERR_FILENO);
	ft_putstr_fd(": ", STDERR_FILENO);
	ft_putendl_fd(strerror(errno), STDERR_FILENO);
}
