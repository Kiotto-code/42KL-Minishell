/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expandenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etlaw <ethanlxz@gmail.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 19:34:24 by yichan            #+#    #+#             */
/*   Updated: 2023/08/04 02:47:17 by etlaw            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	check_dollar(t_book *record, char **str, int i)
{
	int		start;
	char	*mainkey;
	char	*newval;

	start = i;
	// if (ft_isdigit(str[0][i+1]) || str[0][i+1] == '?')
	// 	i += 2;
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
	// printf("check: str: |%s|\n", *str);
	// printf("check: mainkey: |%s|\n", mainkey);
	// printf("check: newval: |%s|\n", newval);
	
	// pause();
	// if (ft_strcmp(mainkey, "$") == 0)
	// {
	// 	ft_free(*str);
	// 	*str = ft_strdup("$");
	// 	return ;
	// }
	ft_replace(str, mainkey, newval);
	// printf("check: %s\n", str[0]);
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
		if (av[i] == '$' && status != SQUOTE && av[i+1] != ' ')
		{
			check_dollar(record, str, i);
			expandenv(record, str);
			break ;
		}
		// if (av[i] == '!' && status != SQUOTE && av[i+1] != ' ')
		// {
		// 	check_xclm(record, str, i);
		// 	break ;
		// }
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
		if (av[i] == '$' && av[i+1] != '\0')
		{
			check_dollar(record, str, i);
			here_xpnd(record, str);
			break ;
		}
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
