/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_replace.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yichan <yichan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 21:50:01 by yichan            #+#    #+#             */
/*   Updated: 2023/07/25 23:41:32 by yichan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_replace(char **s, char *old, char *new)
{
	int		i;
	char	*str;
	char	*temp;
	char	*first;
	char	*third;

	i = 0;
	str = *s;
	while (str[i] && !ft_strlead(str + i, old))
		i++;
	first = ft_substr(str, 0, i);
	third = ft_substr(str, ft_strlen(old)+i, \
		ft_strlen(str) - i - ft_strlen(old));
	temp = ft_strjoin(first, new);
	free(*s);
	*s = ft_strjoin(temp, third);
	free(temp);
	free(third);
}
