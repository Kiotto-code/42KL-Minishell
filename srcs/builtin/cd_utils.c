/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etlaw <ethanlxz@gmail.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 18:14:12 by etlaw             #+#    #+#             */
/*   Updated: 2023/08/05 18:14:27 by etlaw            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// if path is "~", go to root dir
char	*go_root(t_env *env)
{
	while (env)
	{
		if (ft_strcmp(env->key, "HOME") == 0)
			return (env->value);
		env = env->next;
	}
	printf("bash : cd: HOME not set\n");
	return (0);
}
