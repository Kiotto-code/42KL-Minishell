/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etlaw <ethanlxz@gmail.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 21:48:06 by etlaw             #+#    #+#             */
/*   Updated: 2023/07/25 21:11:27 by etlaw            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// checks for "-n" option 

int	n_check(char *str)
{
	int	i;

	if (str[0] == '-')
	{
		if (str[1] == 'n')
		{
			i = 1;
			while (str[i])
			{
				if (str[i] != 'n')
					return (0);
				i++;
			}
			return (1);
		}
		else
			return (0);
	}
	return (0);
}

// echo function
int	ms_echo(char **av)
{
	int	i;
	int	dash_n;

	i = 1;
	dash_n = 0;
	if (n_check(av[i]))
	{
		dash_n = 1;
		i++;
	}
	if (ft_strlen(*av) > 1)
	{
		while (av[i])
		{
			ft_putstr_fd(av[i], 1);
			if (av[i + 1] && av[i][0] != '\0')
				write(1, " ", 1);
			i++;
		}
	}
	if (dash_n == 0)
		write(1, "\n", 1);
	return (0);
}
