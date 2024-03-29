/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etlaw <ethanlxz@gmail.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 18:23:46 by etlaw             #+#    #+#             */
/*   Updated: 2023/08/05 17:56:45 by etlaw            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// int	ms_pwd(t_env *env)
// {
// 	while (env)
// 	{
// 		if (ft_strcmp(env->key, "PWD") == 0)
// 		{
// 			ft_putstr_fd(env->value, 1);
// 			ft_putstr_fd("\n", 1);
// 			return (0);
// 		}
// 		env = env->next;
// 	}
// 	return (0);
// }

int	ms_pwd(t_env *env)
{
	char	cwd[100];

	getcwd(cwd, 100);
	printf("%s\n", cwd);
	(void) env;
	return (0);
}
