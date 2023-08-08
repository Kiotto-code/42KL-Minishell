/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yichan <yichan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 20:29:21 by etlaw             #+#    #+#             */
/*   Updated: 2023/08/07 00:17:24 by yichan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// env function
int	ms_env(t_env *env)
{
	if (*check_envvar(env, "PATH") == 0)
	{
		ft_putstr_fd("minishell: ", 2);
		ft_putstr_fd("env", 2);
		ft_putstr_fd(": No such file or directoryy\n", 2);
		g_exit_status = 127;
		return (g_exit_status);
	}
	while (env)
	{
		printf("%s\n", env->var);
		env = env->next;
	}
	return (0);
}
