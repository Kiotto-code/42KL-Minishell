/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_token.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yichan <yichan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 19:19:09 by yichan            #+#    #+#             */
/*   Updated: 2023/08/13 15:54:20 by yichan           ###   ########.fr       */
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

	if (end <= start)
		return (NULL);
	new = ft_calloc(sizeof(t_token));
	if (!new)
		return (0);
	new->entity = ft_substr(av, start, end - start);
	return (new);
}

int	check_dredirection(t_book *record, char *av, int *start)
{
	while (av[*start] == ' ')
		(*start)++;
	if (av[*start] == '\0' || av == NULL)
	{
		return (0);
	}
	if (ft_strchr("<>", av[*start]) && (av[*start] != av[*start +1]))
	{
		ms_tokenladd_back(&record->args,
			(ms_newtoken(av, *start, (*start) + 1)));
		(*start) += 1;
		return (1);
	}
	else if (ft_strchr("<>", av[*start]) && (av[*start] == av[*start +1]))
	{
		ms_tokenladd_back(&record->args,
			(ms_newtoken(av, *start, (*start) + 2)));
		(*start) += 2;
		return (1);
	}
	return (0);
}

void	ms_tokenrec(char *av, int *start, int *end, t_book *record)
{
	if (av[*end])
	{
		ms_tokenladd_back(&record->args,
			(ms_newtoken(av, *start, *end)));
		(*start) = (*end);
		(*start) = pass_whitespaces(av, *start);
		(*end) = (*start);
		if (av[*start] && ft_strchr(" <|>", av[*start]))
		{
			ms_record(av, start, end, record);
		}
	}
}

/**
 * @brief It is to record a token based on spaces
 * 			other than those within quotaion.
 * 
 * @param record	The t_book struct which contain the
 * 					token t_list and anchor required.
 */
void	ms_quotesplit(t_book *record, int start, int end, char *av)
{
	int	status;

	av = ft_strjoin(record->input, " ");
	expandenv(record, &av);
	start = pass_whitespaces(av, 0);
	end = start;
	while (av[end])
	{
		if ((av[end] == '\'' || av[end] == '\"'))
		{
			status = av[end++];
			while (av[end] != status && av[end +1])
				end ++;
			end++;
			continue ;
		}
		if (av[end +1] && !ft_strchr("<|> ", av[end]))
		{
			while (av[end] && !ft_strchr("<|>\'\" ", av[end]))
				end++;
			continue ;
		}
		ms_tokenrec(av, &start, &end, record);
	}
	ft_free(av);
}

// /**
//  * @brief Split the input into 
//  * 
//  * @param record 
//  * @return int 
//  */
// void	ms_token(t_book *record)
// {
// 	if (*record->input == '#')
// 		return ;
// 	ms_quotesplit(record, 0, 0, NULL);
// 	set_redirect(record->args);
// 	if (record->args == NULL)
// 	{
// 		ft_free(record->input);
// 		record->input = NULL;
// 	}
// }

void	ms_record(char *av, int *start, int *end, t_book *record)
{
	if (av[*start] && ft_strchr(" <|>", av[*start]))
	{
		if (ft_strchr("<>", av[*end]) && \
			check_dredirection(record, av, start))
		{
			(*end) = (*start);
			return ;
		}
		if (ft_strchr(("|"), av[*start]))
		{
			ms_tokenladd_back(&record->args,
				(ms_newtoken(av, *start, (*start) + 1)));
			(*start) += 1;
			(*end) = (*start);
			return ;
		}
		if (av[*end] == '\0')
		{
			ms_tokenladd_back(&record->args,
				(ms_newtoken(av, *start, *end)));
			*start = *end;
			return ;
		}
	}
}
