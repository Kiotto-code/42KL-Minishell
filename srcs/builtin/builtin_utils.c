/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etlaw <ethanlxz@gmail.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 16:23:47 by etlaw             #+#    #+#             */
/*   Updated: 2023/08/14 00:43:59 by etlaw            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/* error message for builtins
   1 = export error
   2 = cd error
   3 = unset error
*/

void	ft_errormessage(char *str, int format)
{
	if (format == 1)
	{
		ft_putstr_fd("bash: export: `", 2);
		ft_putstr_fd(str, 2);
		ft_putstr_fd("': not a valid identifier\n", 2);
	}
	if (format == 2)
	{
		ft_putstr_fd("bash: cd: ", 2);
		ft_putstr_fd(str, 2);
		if (str)
			ft_putstr_fd(": No such file or directoryy", 2);
		ft_putstr_fd("\n", 2);
	}
	if (format == 3)
	{
		ft_putstr_fd("bash: unset: `", 2);
		ft_putstr_fd(str, 2);
		ft_putstr_fd("': not a valid identifier\n", 2);
	}
}

/* checks for any invalid identifier in the token
	(you can refer the format in ft_errormessage)
*/

int	is_iden(char *str, int format)
{
	int	i;

	i = 0;
	if (!(ft_isalpha(str[0]) || str[0] == '_'))
	{
		ft_errormessage(str, format);
		return (1);
	}
	while (str[++i])
	{
		if (!(ft_isalnum(str[i]) || str[i] == '_' || str[i] == '='))
		{
			ft_errormessage(str, format);
			return (1);
		}
		if (str[i] == '=')
		{
			return (2);
		}
	}
	return (3);
}

// frees double array

void	free_2arr(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		ft_free(arr[i]);
		i++;
	}
	ft_free(arr);
}

t_env	*newenvlist(char *content)
{
	t_env	*node;

	node = ft_calloc(sizeof(t_env));
	if (!node)
		return (0);
	if (ft_strchr(content, '=') == NULL)
	{
		node->value = 0;
		node->key = ft_strdup(content);
		node->var = ft_strdup(content);
		return (node);
	}
	else
		node->var = ft_strdup(content);
	node->value = get_env_val(content);
	node->key = ft_substr(content, 0, \
			ft_strlen(content) - ft_strlen(node->value) - 1);
	return (node);
}
