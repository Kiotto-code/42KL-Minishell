/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_token.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yichan <yichan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 19:19:09 by yichan            #+#    #+#             */
/*   Updated: 2023/06/26 17:53:04 by yichan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/**
 * @brief record token into a string and lexer its type(havent done).
 * @param av (the whole argument from readline output)
 * @param start (Where to begin)
 * @param end (Where to end)
 * @return t_token* 
 */

t_token	*ms_newtoken(char *av, int start, int end)
{
	t_token	*new;

	new = ft_calloc(sizeof(t_token));
	// if (end <= start)
	// 	return (NULL);
	if (!new)
		return (0);
	new->entity = ft_substr(av, start, end - start);
	// printf("newtoken: %s\n", new->entity);
	new->type = 0;
	return (new);
}

int check_dredirection(t_book *record, char *av, int *i)
{
	// if (ft_strchr(">", av[*i]) && ft_strchr(">", av[*i +1]))
	// {
	// 	ms_tokenladd_back(&record->token,
	// 		(ms_newtoken(av, *i, (*i +2))));
	// 	*i += 2;
	// 	return (1);
	// }
	// if (ft_strchr("<", av[*i]) && ft_strchr("<", av[*i +1]))
	// {
	// 	ms_tokenladd_back(&record->token,
	// 		(ms_newtoken(av, *i, (*i +2))));
	// 	*i += 2;
	// 	return (1);
	// }
	// return (0);
	if (!ft_strchr("<>", av[*i]) || (av[*i] != av[*i +1]))
		return (0);
	else
	{
		ms_tokenladd_back(&record->args,
			(ms_newtoken(av, *i, (*i +2))));
		*i += 2;
		return (1);
	}
}


void	ms_tokenrec(char *av, int start, int end, t_book *record)
{
	int		i;

	i = start;
	while (i < end)
	{
		while (!ft_strchr("|?<>", av[i]) && i < end)
			i++;
		if (i <= end && i != start)
			ms_tokenladd_back(&record->args,
				(ms_newtoken(av, start, i)));
		while (ft_strchr("|?<>", av[i]))
		{
			if (check_dredirection(record, av, &i))
				continue ;
			ms_tokenladd_back(&record->args,
				(ms_newtoken(av, i, (i +1))));
			i++;
		}
		start = i;
		// if (ft_strchr("|?$<>", av[i]))
		// 	i++;
	}
	return ;
}


void	check_anchor(char c, t_book *record)
{
	if (c == '\'' && record->anchor == NEUTRAL)
		record->anchor = SQUOTE;
	else if (c == '\'' && record->anchor == SQUOTE)
		record->anchor = NEUTRAL;
	else if (c == '\"' && record->anchor == NEUTRAL)
		record->anchor = DQUOTE;
	else if (c == '\"' && record->anchor == DQUOTE)
		record->anchor = NEUTRAL;
}

/**
 * @brief It is to record a token based on spaces other than those within quotaion.
 * 
 * @param record The t_book struct which contain the token t_list and anchor required.
 */
void	ms_quotesplit(t_book *record)
{
	int				start;
	int				end;
	char			*av;

	start = 0;
	av = ft_strjoin(record->input, " ");//remove sapce
	end = start;
	while (av[end])
	{
		// while (ft_strchr(" '\"", av[end]) == NULL && av[end])
		// 	end++;
		if ((av[end] == ' ' && av[end -1] != ' ' && \
			record->anchor == NEUTRAL) || av[end +1] == 0)
		{
			while (av[start] == ' ')
				start++;
			ms_tokenrec(av, start, end, record);
			start = end;
		}
		check_anchor(av[end], record);
		end++;
	}
}

/**
 * @brief Split the input into 
 * 
 * @param record 
 * @return int 
 */
void	ms_token(t_book *record)
{
	ms_quotesplit(record);
	set_redirect(record->args);
	if (record->args == NULL)
	{
		free(record->input);
		record->input = NULL;
	}
}