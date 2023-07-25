/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expandenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yichan <yichan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 19:34:24 by yichan            #+#    #+#             */
/*   Updated: 2023/07/25 11:05:17 by yichan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	check_dollar(t_book *record, char **str, int i)
{
	int		start;
	char	*mainkey;
	char	*newval;

	start = i;
	while (str[i++])
	{
		if (ft_isdigit(str[0][i]) || str[0][i] == '?')
		{
			i ++;
			break ;
		}
		if (!ft_isalpha(str[0][i]))
			break ;
	}
	mainkey = ft_substr(*str, start, i - start);
	if (mainkey[1] == '?')
		newval = ft_itoa(g_exit_status);
	else
		newval = ft_strdup(check_envvar(record->env, mainkey +1));
	ft_replace(str, mainkey, newval);
}

char	*expandenv(t_book *record, char **str)
{
	char	*av;
	int		status;
	int		i;

	av = *str;
	i = -1;
	status = NEUTRAL;
	while (av[++i])
	{
		if (av[i] == '\'' && status != DQUOTE)
			status ^= SQUOTE;
		if (av[i] == '\"' && status != SQUOTE)
			status ^= DQUOTE;
		if (av[i] == '$' && status != SQUOTE)
			check_dollar(record, str, i);
	}
	return (*str);
}

char	*here_xpnd(t_book *record, char **str)
{
	char	*av;
	int		i;

	av = *str;
	i = -1;
	while (av[++i])
	{
		if (av[i] == '$')
			check_dollar(record, str, i);
	}
	return (*str);
}
// char	*expandenv(t_book *record, char **str)
// {
// 	char	*av;
// 	int		status;
// 	int		i;

// 	av = *str;
// 	i = -1;
// 	status = NEUTRAL;
// 	while (av[++i])
// 	{
// 		if (av[i] == '\'' && status != DQUOTE)
// 			status ^= SQUOTE;
// 		if (av[i] == '\"' && status != SQUOTE)
// 			status ^= DQUOTE;
// 		if (av[i] == '$' && status != SQUOTE)
// 			check_dollar(record, str, i );
// 	}
// 	return (*str);
// }
