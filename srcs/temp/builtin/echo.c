/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yichan <yichan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 21:48:06 by etlaw             #+#    #+#             */
/*   Updated: 2023/07/25 01:47:22 by yichan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

// strcmp instead of strncmp
int	ft_strcmp(const char *s1, const char *s2)
{
	size_t	i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
	{
		i++;
	}
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

// echo function
int	ms_echo(char **av)
{
	int	i;
	int	dash_n;

	i = 0;
	dash_n = 0;
	if (ft_strlen(*av) > 1)
	{
		while (av[i])
		{
			if (ft_strcmp(av[i], "-n") == 0)
			{
				dash_n = 1;
				i++;
			}
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
