/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   postparser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yichan <yichan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 17:23:05 by yichan            #+#    #+#             */
/*   Updated: 2023/07/22 20:04:36 by yichan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*is_slash(char *input, int *it)
{
	char	*tmp_1;
	char	*tmp_2;

	tmp_1 = ft_substr(input, 0, *it);
	tmp_2 = ft_strdup(input + *it + 1);
	free(input);
	input = NULL;
	input = ft_strjoin(tmp_1, tmp_2);
	free(tmp_1);
	free(tmp_2);
	(*it)++;
	return (input);
}

/**
 * @brief Handle all the quote(removal) and do the expander(is_dollar/key_handler)
 * 
 * @param input 
 * @param env 
 * @return char* 
 */
char	* postparser(char *input, t_env *env) // "", '', \, $, ;, |, >, >>, <, ' *space* '
{
	int		i;
	int		j;
	char	*ret;

	i = 0;
	j = 0;
	(void)env;
	ret = ft_calloc(sizeof(char) * (ft_strlen(input) +1));
	printf("check: input post: %s\n", input);
	while (input[i])
	{
		if (input[i] && input[i] == '\'')
		{
			i++;
			while (input[i] && input[i] != '\'' )
				ret[j++] = input[i++];
			i++;
		}
		else if (input[i] && input[i] == '\"')
		{
			i++;
			while (input[i] && input[i] != '\"')
				ret[j++] = input[i++];
			i++;
		}
		else if (input[i] && !ft_strchr("\'\"", input[i]))
			ret[j++] = input[i++];
	}
	printf("check: input post22as2: %s\n", ret);
	free(input);
	return (ret);
}
