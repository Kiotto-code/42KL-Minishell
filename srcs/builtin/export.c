/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etlaw <ethanlxz@gmail.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 18:03:30 by etlaw             #+#    #+#             */
/*   Updated: 2023/06/05 23:43:57 by etlaw            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

// copies the name of the variable of the env

char	*get_env_name(char *str)
{
	char	*res;
	int		i;

	i = 0;
	while (str[i] && str[i] != '=')
		i++;
	res = ft_substr(str, 0, i + 1);
	return (res);
}

void	change_value(t_env *env, char *tkn)
{
	int	i;
	int	j;

	i = 0;
	free(env->value);
	env->value = ft_strdup(tkn);
	while (tkn[i] != '=')
	{
		i++;
	}
	j = i;
	while (tkn[i])
	{
		i++;
	}
	free(env->var);
	env->var = ft_substr(tkn, j, i);
}

/*
	compares the env value one by one
	and changes the value if found 
*/
int	is_in_env(t_env *env, char *tkn)
{
	char	*var_name;
	char	*env_name;

	var_name = get_env_name(tkn);
	while (env)
	{
		if (ft_strcmp(var_name, env->key) == 0)
		{
			change_value(env, tkn);
		}
	}
	free(var_name);
}

int	ms_export(t_env **env, t_env **export, char **tkn)
{
	int	new_env;
	int	error_ret;

	new_env = 0;
	if (!tkn[1])
	{
		print_export_env(*env);
		return (0);
	}
	else
	{
		error_ret = is_iden(tkn[1]);
		if (error_ret == 1)
			return (1);
		else if (error_ret == 2)
			is_in_env(*env, tkn[1]);
		
		
		
	}
	return (0);

}
