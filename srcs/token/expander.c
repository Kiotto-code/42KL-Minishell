/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yichan <yichan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 01:27:44 by yichan            #+#    #+#             */
/*   Updated: 2023/04/25 01:42:41 by yichan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// char		*expand(char *str, t_env *env)
// {
// 	int		i;

// 	i = 0;
// 	while (str[i])
// 	{
// 		if (str[i] == '\'')
// 			i = expand_single_quote(str, &i);
// 		else if (str[i] == '\"')
// 			i = expand_double_quote(str, &i, env);
// 		else if (str[i] == '$')
// 			i = expand_dollar(&str, &i, env);
// 		else
// 			i++;
// 	}
// 	return (str);
// }

// static int	expand_dollar(char **str, int *i, t_env *env)
// {
// 	char	*key;
// 	char	*value;
// 	char	*tmp;
// 	int		j;

// 	j = *i;
// 	while ((*str)[j] && ft_isalnum((*str)[j]))
// 		j++;
// 	key = ft_substr(*str, *i + 1, j - *i - 1);
// 	value = get_env(env, key);
// 	if (!value)
// 		value = "";
// 	tmp = ft_strjoin(value, *str + j);
// 	free(*str);
// 	*str = tmp;
// 	*i = j;
// 	return (0);
// }
