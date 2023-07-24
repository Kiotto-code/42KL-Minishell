/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etlaw <ethanlxz@gmail.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 18:03:30 by etlaw             #+#    #+#             */
/*   Updated: 2023/06/08 18:40:21 by etlaw            ###   ########.fr       */
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

// changes the value of the node wiith the new token
void	change_value(t_env *env, char *tkn)
{
	int		i;
	int		j;

	i = 0;
	free(env->value);
	env->value = ft_strdup(tkn);
	while (tkn[i] != '=')
	{
		i++;
	}
	env->key = ft_substr(tkn, 0, i);
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
	and changes the value if found.


	if no env value is found,
	a new node will be added to the env lst.
*/
int	update_lst(t_env **lst, char *tkn)
{
	t_env	*tmp;
	char	*var_name;
	char	*env_name;

	tmp = *lst;
	var_name = get_env_name(tkn);
	while (tmp)
	{
		if (ft_strcmp(var_name, tmp->key) == 0)
		{
			change_value(tmp, tkn);
			return (0);
		}
		tmp = tmp->next;
	}
	ms_envladd_back(&tmp, (newenvl(tkn)));
	free(var_name);
	return (0);
}

/* export function

	If there is no token , it will print out the export list

	If there is a token, is_den will return int res value :
						1 means invalid identifier
						2 means it will either change both
								env and export list values
						3 means it will only change export
								list
*/
int	ms_export(t_env **env, t_env **export, char **tkn)
{
	int	new_env;
	int	res;

	new_env = 0;
	if (!tkn[1])
	{
		print_export_env(export);
		return (0);
	}
	else
	{
		res = is_iden(tkn[1], 1);
		if (res == 1)
			return (1);
		else if (res == 2)
		{
			update_lst(env, tkn[1]);
			update_lst(export, tkn[1]);
		}
		else if (res == 3)
			update_lst(export, tkn[1]);
	}
	return (0);
}
