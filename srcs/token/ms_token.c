/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_token.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yichan <yichan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 19:19:09 by yichan            #+#    #+#             */
/*   Updated: 2023/04/27 04:06:52 by yichan           ###   ########.fr       */
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
	char *temp;
	char *env = ft_strdup("$USER");
	char *user = ft_strdup("yichan");

	new = ft_calloc(sizeof(t_token));
	// if (end <= start)
	// 	return (NULL);
	if (!new)
		return (0);
	temp = ft_substr(av, start, end - start);
	printf("new->entity: %s\n", temp);
	ft_replace(temp, env, user);
	// ms_expander
	// printf("newtoken: %s\n", temp);
	exit(0);
	new->entity = temp;
	new->type = 0;
	new->next = NULL;
	new->prev = NULL;
	return (new);
}

int check_dredirection(t_book *record, char *av, int *i)
{
	// if (ft_strchr(">", av[*i]) && ft_strchr(">", av[*i +1]))
	// {
	// 	ft_lstadd_back(&record->token,
	// 		ft_lstnew(ms_newtoken(av, *i, (*i +2))));
	// 	*i += 2;
	// 	return (1);
	// }
	// if (ft_strchr("<", av[*i]) && ft_strchr("<", av[*i +1]))
	// {
	// 	ft_lstadd_back(&record->token,
	// 		ft_lstnew(ms_newtoken(av, *i, (*i +2))));
	// 	*i += 2;
	// 	return (1);
	// }
	// return (0);
	if (!ft_strchr("<>", av[*i]) || (av[*i] != av[*i +1]))
		return (0);
	else
	{
		ms_tokenladd_back(&record->token,
			(ms_newtoken(av, *i, (*i +2))));
		*i += 2;
		return (1);
	}
}

// t_token	*ms_newtoken(char *av, int start, int end)
// {
// 	t_token	*new;

// 	new = ft_calloc(sizeof(t_token));
// 	// if (end <= start)
// 	// 	return (NULL);
// 	if (!new)
// 		return (0);
// 	new->entity = ft_substr(av, start, end - start);
// 	// printf("newtoken: %s\n", new->entity);
// 	new->type = 0;
// 	return (new);
// }

void	ms_tokenrec(char *av, int start, int end, t_book *record)
{
	int		i;

	i = start;
	while (i < end)
	{
		while (!ft_strchr("|?<>", av[i]) && i < end)
			i++;
		if (i <= end && i != start)
			ms_tokenladd_back(&record->token,
				(ms_newtoken(av, start, i)));
		while (ft_strchr("|?<>", av[i]))
		{
			if (check_dredirection(record, av, &i))
				continue ;
			// if (ft_strchr(">", av[i]))
			// if (ft_strchr("<", av[i]))
			ms_tokenladd_back(&record->token,
				ms_newtoken(av, i, (i +1)));
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
	av = ft_strjoin(record->input, " ");
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
	// t_list	*itr;
	char *trim;

	trim = ft_strtrim(record->input, " ");
	free(record->input);
	if (*trim == '\0')
	{
		free(trim);
		exit(0) ;
	}
	record->input = trim;
	ms_quotesplit(record);
	// ms_expander(record);
	// printf("sdad");
	// itr = (t_list *)(record->token);
	// while (itr)
	// {
	// 	printf("str: %s| \n", ((t_token *)itr->content)->entity);
	// 	itr = itr->next;
	// }
}
