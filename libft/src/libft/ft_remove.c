/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_remove.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yichan <yichan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 01:57:51 by yichan            #+#    #+#             */
/*   Updated: 2023/07/12 02:11:45 by yichan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include"libft.h"

static size_t	count_words(char const *s, char c)
{
	size_t	i;
	size_t	count;

	i = -1;
	count = 0;
	while (s[++i] != '\0')
	{
		if(s[i] == c)
			count++;
	}
	return (count);
}

char *ft_remove(char *input, char c)
{
	int		i;
	int		remain_size;
	char	*ret;

	remain_size = count_words(input, c);
	ret = ft_calloc(sizeof(char) * remain_size);
	i = 0;
	while (input[++i])
	{
		if (input[i] != c)
			ret[i] = input[i];
	}
	free(input);
	return (ret);
}