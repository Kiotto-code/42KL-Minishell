/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yichan <yichan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 18:23:46 by etlaw             #+#    #+#             */
/*   Updated: 2023/07/31 18:39:05 by yichan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// pwd function
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
