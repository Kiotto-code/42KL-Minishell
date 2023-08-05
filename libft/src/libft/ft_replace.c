/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_replace.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yichan <yichan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 21:50:01 by yichan            #+#    #+#             */
/*   Updated: 2023/08/05 23:09:09 by yichan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_replace(char **s, const char *old, const char *new, int start)
{
	int		i;
	char	*str;
	char	*temp;
	char	*first;
	char	*third;

	if (old == NULL || new == NULL || s == NULL \
		|| ft_strlen(*s) < (size_t)start)
		return ;
	i = start;
	str = *s;
	while (str[i] && !ft_strlead(str + i, old))
		i++;
	first = ft_substr(str, 0, i);
	third = ft_substr(str, ft_strlen(old)+i, \
		ft_strlen(str) - i - ft_strlen(old));
	temp = ft_strjoin(first, new);
	ft_free(*s);
	*s = ft_strjoin(temp, third);
	ft_free(temp);
	ft_free(third);
}
