/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expandenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etlaw <ethanlxz@gmail.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 19:34:24 by yichan            #+#    #+#             */
/*   Updated: 2023/08/12 23:23:07 by etlaw            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"


void	check_dollar(t_book *record, char **str, int i)
{
	int		start;
	char	*mainkey;
	char	*newval;

	start = i;
	if (ft_isalpha(str[0][i +1]) == 0)
		i += 2;
	else
	{
		while (str[0][i++])
		{
			if (!ft_isalnum(str[0][i]))
				break ;
		}
	}
	mainkey = ft_substr(*str, start, i - start);
	if (mainkey[1] == '?')
		newval = ft_itoa(g_exit_status);
	else if (mainkey[1] == '$')
		newval = ft_itoa(21225);
	else if (ft_strchr("-", mainkey[1]))
		newval = ft_strdup("himBH");
	else
		newval = ft_strdup(check_envvar(record->env, mainkey +1));
	ft_replace(str, mainkey, newval, start);
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
		if (av[i] == '$' && status != SQUOTE && av[i +1] != ' ')
		{
			check_dollar(record, str, i);
			expandenv(record, str);
			break ;
		}
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
		if (av[i] == '$' && av[i +1] != '\0')
		{
			check_dollar(record, str, i);
			here_xpnd(record, str);
			break ;
		}
	}
	return (*str);
}

// void	check_xclm(t_book *record, char **str, int i)
// {
// 	char	*mainkey;

// 	mainkey = ft_substr(*str, i, 2);
// 	if (mainkey[1] == '!')
// 		ft_replace(str, mainkey, record->history);
// }

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
