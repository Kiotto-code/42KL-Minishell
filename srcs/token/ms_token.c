/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_token.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yichan <yichan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 19:19:09 by yichan            #+#    #+#             */
/*   Updated: 2023/07/23 11:13:11 by yichan           ###   ########.fr       */
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
	if (end <= start)
		return (NULL);
	if (!new)
		return (0);
	new->entity = ft_substr(av, start, end - start);
	printf("newtoken: |%s|\n", new->entity);
	// new->type = 0;
	return (new);
}

int check_dredirection(t_book *record, char *av, int *start, int *i)
{
	// int start
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
	while(av[*start] == ' ')
		(*start)++;
	printf("check: dredirect here: |%c|\n\n", av[*i]);
	if (av[*start] == '\0' || av == NULL)
	{
		printf("check: dredirect here2: |%c|\n\n", av[*i]);
		return (0);
	}
	// *i = *start;
	if (ft_strchr("<>", av[*start]) && (av[*start] != av[*start +1]))
	// if (!ft_strchr("<>", av[*i]))
	{
		printf("check: dredirect here2222: |%c|\n\n", av[*i]);
		ms_tokenladd_back(&record->args,
			(ms_newtoken(av, *start, (*start) +1)));
		(*start) += 1;
		// pause();
		return (1);
	}
	else if (ft_strchr("<>", av[*start]) && (av[*start] == av[*start +1]))
	{
		printf("check: dredirect here3333\n\n\n");
		ms_tokenladd_back(&record->args,
			(ms_newtoken(av, *start, (*start) +2)));
		(*start) += 2;
		// pause();
		return (1);
	}
	// pause();
	printf("check: redirect\n");
	return (0);
}


void	ms_tokenrec(char *av, int *start, int *end, t_book *record)
{
	// int		i;
	// int		status;

	// i = *start;
	// status = NEUTRAL;
	if (av[*end])
	{
		ms_tokenladd_back(&record->args,
			(ms_newtoken(av, *start, *end)));
		(*start) = (*end);
		(*start) = pass_whitespaces(av, *start);
		(*end) = (*start);
		printf("check: pos start: %c\n", av[*start]);
		printf("check: pos end: %c\n", av[*end]);
		// (*end)++;
		if (av[*start] && ft_strchr(" <|>", av[*start]) )
		{
			if (ft_strchr("<>", av[*end]) && 
				check_dredirection(record, av, start, end))
			{
				// *start = (*end)++;
				printf("check: dredirect HERE!!\n\n\n\n");
				// *start = pass_whitespaces(av, *start);
				(*end) = (*start);
				return ;
			}
			if(ft_strchr(("|"), av[*start]))
			{
				// *start = (*end)++;
				// *end = (*start) +1;
				ms_tokenladd_back(&record->args,
					(ms_newtoken(av, *start, (*start) +1)));
				// *start = (*end);
				(*start) += 1;
				// *start = pass_whitespaces(av, *start);
				(*end) = (*start) ;
				return ;
			}
			// if(av[*end] == '\0' || av[*end] == ' ')
			if(av[*end] == '\0')
			{
				ms_tokenladd_back(&record->args,
					(ms_newtoken(av, *start, *end)));
				*start = *end;
				return ;
			}
		}
		// pause();
	}
	// *start = *end;

	return ;
}

/**
 * @brief It is to record a token based on spaces other than those within quotaion.
 * 
 * @param record The t_book struct which contain the token t_list and anchor required.
 */
void	ms_quotesplit(t_book *record)
{
	int		start;
	int		end;
	char	*av;
	char	status;

	start = 0;
	// if (ft_strcmp(record->input, "\n"))
	// 	return ;
	av = ft_strjoin(record->input, " ");
	// av = ft_strdup(record->input);
	printf("check: avb4: %s\n", av);
	expandenv(record, &av);
	printf("check: avat: %s\n", av);
	// pause();
	// status = NEUTRAL;
	end = start +1;
	// printf("check: avat av[end]: %c\n", av[end]);
	// while (av[start] && av[start] == ' ')
	// {
	// 	start++;
	// 	end = start+1;
	// }
	start = pass_whitespaces(av, start);
	end = start;
	printf("check: avat5: |%s|\n", av);
	// pause();
	while (av[end])
	{
		printf("check: qsplit1: |%s|\n", av+start);
		printf("check: qsplit1end: |%s|\n", av+end);
		if ((av[end] == '\'' || av[end] == '\"'))
		{
			status = av[end];
			end++;
			while (av[end] != status && av[end +1])
				end ++;
			end++;
			continue ;
		}
		printf("check: qsplit2: |%s|\n", av+end);
		printf("check: avat av[end]8888: |%s|\n", av+end);
		// pause();
		if (av[end +1] && !ft_strchr("<|> ", av[end]))
		{
			// if (ft_strchr("<|> ", av[end]))
			// 	continue ;
			printf("check: here 99999\n");
			while (av[end] && !ft_strchr("<|>\'\" ", av[end]))
				end++;
			// end++;
			continue ;
		}
		printf("check: avat av[end]333: |%c|\n", av[end]);

		printf("check: avat av[start]333: |%s|\n", av+start);
		printf("check: avat av[end]333: |%s|\n", av+end);
		ms_tokenrec(av, &start, &end, record );
		// pause();
		printf("check: 333\n");
		// start = end;
		printf("check: 777 %s\n", av+start);
		printf("check: 777:end %s\n", av+end);
		// pause();

		// end++;
	}
	free(av);
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