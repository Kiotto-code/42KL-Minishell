/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yichan <yichan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 23:45:27 by yichan            #+#    #+#             */
/*   Updated: 2023/07/27 00:51:27 by yichan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	exit_error(t_book *mini, char *argv1, char *str)
{
	ft_putstr_fd("minishell: exit: ", STDERR_FILENO);
	// ft_putstr_fd("exit: ", STDERR_FILENO);
	if (argv1 != NULL)
	{
		ft_putstr_fd(argv1, STDERR_FILENO);
		ft_putstr_fd(": ", STDERR_FILENO);
	}
	ft_putendl_fd(str, STDERR_FILENO);
	// ft_putstr_fd("\n", STDERR_FILENO);
	if (argv1 != NULL)
	{
		shlvl_down(mini);
		g_exit_status = 255;
		exit(255);
	}
	else
		return (1);
}

/**
 * @brief 64-bit signed integer. 2⁶³−1 : 9223372036854775807 llong_max
 * 
 * @param mini 
 * @param str 
 * @return unsigned char 
 */
static unsigned char	exit_numeric(t_book *mini, char *str)
{
	int				negative;
	int				i;
	long long int	convert;

	negative = 1;
	i = 0;
	convert = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			negative = -negative;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		convert = convert * 10 + (str[i++] - '0');
	}
	if ((uint64_t)convert > LLONG_MAX && negative == 1)
		exit_error(mini, str, "numeric argument required");
	if ((uint64_t)convert -1 > LLONG_MAX && negative == -1)
		exit_error(mini, str, "numeric argument required");
	return (convert * negative);
}

int	isdigit_str(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (str[i])
	{
		if (!(str[i] >= '0' && str[i] <= '9'))
			return (1);
		i++;
	}
	return (0);
}

// int	exit_error(t_book *mini, char *argv1, char *str)
// {
// 	ft_putstr_fd("minishell: ", STDERR_FILENO);
// 	ft_putstr_fd("exit: ", STDERR_FILENO);
// 	if (argv1 != NULL)
// 	{
// 		ft_putstr_fd(argv1, STDERR_FILENO);
// 		ft_putstr_fd(": ", STDERR_FILENO);
// 	}
// 	ft_putstr_fd(str, STDERR_FILENO);
// 	ft_putstr_fd("\n", STDERR_FILENO);
// 	if (argv1 != NULL)
// 	{
// 		shlvl_down(mini);
// 		g_exit_status = 255;
// 		exit(255);
// 	}
// 	else
// 		return (1);
// }

int	ms_exit(t_book *mini, char **argv)
{
	int	len;

	len = ft_arrind(argv);
	if (len == 1)
	{
		shlvl_down(mini);
		exit(g_exit_status);
	}
	if (isdigit_str(argv[1]))
		return (exit_error(mini, argv[1], "numeric argument required"));
	if (len > 2)
		return (exit_error(mini, NULL, "too many arguments"));
	if (len == 2)
	{
		g_exit_status = exit_numeric(mini, argv[1]);
		shlvl_down(mini);
		exit(g_exit_status);
	}
	return (0);
}