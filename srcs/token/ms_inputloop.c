/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_inputloop.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yichan <yichan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 23:03:16 by yichan            #+#    #+#             */
/*   Updated: 2023/08/13 18:27:48 by yichan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	check_xclm(t_book *record, char **str)
{
	const char	*av = ft_strdup(*str);
	int			status;
	char		*mainkey;
	int			i;
	int			print;

	print = 0;
	i = -1;
	status = NEUTRAL;
	mainkey = NULL;
	while (av[++i])
	{
		if (av[i] == '\'' && status != DQUOTE)
			status ^= SQUOTE;
		if (av[i] == '\"' && status != SQUOTE)
			status ^= DQUOTE;
		if (av[i] == '!' && status != SQUOTE && av[i +1] != ' ')
		{
			mainkey = ft_substr(*str, i, 2);
			if (mainkey[0] && mainkey[1] == '!')
				ft_replace(str, mainkey, record->history, i);
			print = 1;
		}
	}
	return (ft_free((char *)av), ft_free(mainkey), print);
}

int	ms_history(t_book *record)
{
	if (*record->input)
	{
		add_history(record->input);
		ft_strcpy(record->history, record->input);
		return (1);
	}
	return (0);
}

int	ms_inputloop(t_book *record)
{
	while (1)
	{
		sigs_interactive_shell(&record->termios_current);
		record->input = readline("minishell>$ ");
		if (record->input == NULL)
			break ;
		if (check_xclm(record, &record->input))
			printf("%s\n", record->input);
		ms_history(record);
		if (validator(record->input) == 0)
		{
			ms_token(record);
			ms_cmds(record);
		}
		ft_free(record->input);
		record->input = NULL;
		sigs_non_interactive_shell();
		if (record->cmds)
			execute_cmds(record, record->cmds);
		ft_free(record->input);
		record->input = 0;
		cleaner(record);
	}
	cleaner(record);
	return (0);
}
