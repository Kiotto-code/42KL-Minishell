/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_inputloop.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yichan <yichan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 23:03:16 by yichan            #+#    #+#             */
/*   Updated: 2023/08/04 22:06:45 by yichan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	check_xclm(t_book *record, char **str)
{
	char	*av;
	int		status;
	char	*mainkey;
	int		i;
	int		print;

	print = 0;
	av = ft_strdup(*str);
	i = -1;
	status = NEUTRAL;
	while (av[++i])
	{
		if (av[i] == '\'' && status != DQUOTE)
			status ^= SQUOTE;
		if (av[i] == '\"' && status != SQUOTE)
			status ^= DQUOTE;
		if (av[i] == '!' && status != SQUOTE && av[i+1] != ' ')
		{
			mainkey = ft_substr(*str, i, 2);
			if (mainkey[1] == '!')
				ft_replace(str, mainkey, record->history, i);
			check_xclm(record, str);
			print = 1;
			break ;
		}
	}
	if(print == 1)
	{
		printf("%s\n", *str);
		print = 0;
	}
	ft_free(av);
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
			exit(g_exit_status);
		check_xclm(record, &record->input);
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
