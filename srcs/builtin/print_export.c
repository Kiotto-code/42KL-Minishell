/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_export.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etlaw <ethanlxz@gmail.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 17:53:04 by etlaw             #+#    #+#             */
/*   Updated: 2023/08/05 17:57:49 by etlaw            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// sorts the env by ascii order

void	sort_env(char **env)
{
	int		sorted;
	int		i;
	char	*tmp;
	int		env_len;

	env_len = ft_arrlen(env);
	sorted = 0;
	while (env && sorted == 0)
	{
		sorted = 1;
		i = 0;
		while (i < env_len - 1)
		{
			if (ft_strcmp(env[i], env[i + 1]) > 0)
			{
				tmp = env[i];
				env[i] = env[i + 1];
				env[i + 1] = tmp;
				sorted = 0;
			}
			i++;
		}
	}
}

// prints out the export env

void	print_export_env(t_env **env)
{
	int		i;
	char	**res_env;
	t_env	*tmp;

	res_env = env_to_array(*env);
	sort_env(res_env);
	i = 0;
	while (res_env[i])
	{
		tmp = ms_getenv_vvar(*env, res_env[i]);
		ft_putstr_fd("declare -x ", 1);
		if (ft_strchr(tmp->var, '='))
			printf("%s=\"%s\"\n", tmp->key, tmp->value);
		else
			printf("%s\n", tmp->key);
		i++;
	}
	free_2arr(res_env);
}

/*
 useless but helpful functions
*/

// counts the length of the double array

// int	len_2arr(char **arr)
// {
// 	int	i;

// 	i = 0;
// 	while (arr[i])
// 		i++;
// 	return (i);
// }

// counts the total length of the each string of linked list
// with aditional space for demiliter

// int	str_env_len(t_env *lst)
// {
// 	int	len;

// 	len = 0;
// 	while (lst)
// 	{
// 		if (lst->var != NULL)
// 		{
// 			len += ft_strlen(lst->var);
// 			len++;
// 		}
// 		lst = lst->next;
// 	}
// 	return (len);
// }

//  converts env linked list into a single string
// the string will be later be split into a double array with
// the delimiter being '\n'

// char	*env_to_str(t_env *env)
// {
// 	char	*res;
// 	int		i;
// 	int		j;

// 	env = malloc(sizeof(char) * str_env_len(env) + 1);
// 	if (!env)
// 		return (NULL);
// 	i = 0;
// 	while (env)
// 	{
// 		j = 0;
// 		while (env->var[j] != NULL)
// 		{
// 			res[i] = env->var[j];
// 			i++;
// 			j++;
// 		}
// 		if (env->next->next != NULL)
// 			res[i++] = '\n';
// 		env = env->next;
// 	}
// 	res[i] = '\0';
// 	return (env);
// }