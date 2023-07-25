/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dollar_processing.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yichan <yichan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 17:23:00 by yichan            #+#    #+#             */
/*   Updated: 2023/07/25 11:05:00 by yichan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	key_checker(char c)
{
	if (c == '_' || ft_isalnum(c))
		return (1);
	return (0);
}

void	expnd_cmd_symbol_check(char *input)
{
	int	i;

	i = -1;
	while (input[++i])
	{
		if (ft_strchr("<|>", input[i]))
		{
			printf("./minishell>$ ");
			printf(" %c: No such file or directory", input[i]);
		}
	}
}

//expander && concatenate
char	*key_handler(char *input, int begin, int end, t_env *env)
{
	char	*key;
	char	*tmp_1;
	char	*tmp_2;
	char	*tmp_3;

	key = ft_substr(input, begin + 1, end - begin - 1);
	tmp_1 = ft_substr(input, 0, begin);
	tmp_3 = ft_strdup(input + end);
	tmp_2 = ft_strdup(check_envvar(env, key));
	free(input);
	input = NULL;
	if (tmp_2 == NULL)
		input = ft_strjoin(tmp_1, tmp_3);
	else
		input = ft_strjoin_con(tmp_1, tmp_2, tmp_3);
	free(key);
	free(tmp_1);
	free(tmp_2);
	free(tmp_3);
	expnd_cmd_symbol_check(input);
	return (input);
}

/**
 * @brief Handle echo $?
 * 
 * @param input the input string
 * @param begin 
 * @param it 
 * @return char* 
 */
char	*question_handle(char *input, int begin, int *it)
{
	char	*line_new;
	char	*tmp_1;
	char	*tmp_2;
	char	*nbr_val;
	char	*tail;

	nbr_val = ft_itoa(g_exit_status);
	tmp_1 = ft_substr(input, 0, begin);
	tmp_2 = ft_strjoin(tmp_1, nbr_val);
	tail = ft_strdup(&input[*it]);
	line_new = ft_strjoin(tmp_2, tail);
	free(nbr_val);
	free(tmp_1);
	free(tmp_2);
	free(tail);
	free(input);
	g_exit_status = 0;
	return (line_new);
}

/**
 * @brief key_handler == expander
 * 
 * @param input 
 * @param it 
 * @param env 
 * @return char* 
 */
char	*is_dollar(char *input, int *it, t_env *env)
{
	int		begin;

	begin = *it;
	if (ft_strlead("?", &input[begin + 1]))
	{
		*it += 2;
		return (question_handle(input, begin, it));
	}
	while (input[++(*it)])
	{
		if (!key_checker(input[*it]))
			break ;
	}
	if (*it == begin + 1)
		return (input);
	input = key_handler(input, begin, *it, env);
	return (input);
}
