/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yichan <yichan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 16:23:47 by etlaw             #+#    #+#             */
/*   Updated: 2023/07/24 13:46:51 by yichan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// strjoin for env var

char	*var_strjoin(char const *key, char const *val)
{
	char	*res;
	char	*ptr;
	int		i;

	i = ft_strlen(key);
	if (!key || !val)
		return (NULL);
	res = malloc(sizeof(char) * (ft_strlen(val) + ft_strlen(key) + 2));
	if (!res)
		return (NULL);
	ptr = res;
	while (*key)
		*res++ = *key++;
	res[i] = '=';
	(*res)++;
	while (*val)
		*res++ = *val++;
	*res = '\0';
	return (ptr);
}

/* error message for builtins
   1 = export error
   2 = cd error
   3 = unset error
*/

void	ft_errormessage(char *str, int format)
{
	if (format == 1)
	{
		ft_putstr_fd("bash: export: '", 2);
		ft_putstr_fd(str, 2);
		ft_putstr_fd("': not a valid identifier\n", 2);
	}
	if (format == 2)
	{
		ft_putstr_fd("bash: cd: '", 2);
		ft_putstr_fd(str, 2);
		ft_putstr_fd("': No such directory is found\n", 2);
	}
	if (format == 3)
	{
		ft_putstr_fd("bash: unset: '", 2);
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
	if (!(ft_isalpha(str[0] && str[0] == '_')))
	{
		ft_errormessage(str, format);
		return (1);
	}
	while (str[++i])
	{
		if (!(ft_isalnum(str[i]) && str[i] == '_'))
		{
			ft_errormessage(str, format);
			return (1);
		}
		if (str[i] == '=')
			return (2);
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
		free(arr[i]);
		i++;
	}
}