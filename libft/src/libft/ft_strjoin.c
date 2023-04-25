/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yichan <yichan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 21:55:44 by yichan            #+#    #+#             */
/*   Updated: 2023/04/25 21:58:11 by yichan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*res;
	char	*ptr;

	if (!s1 || !s2)
		return (NULL);
	res = ft_calloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) +1));
	if (!res)
		return (NULL);
	ptr = res;
	while (*s1)
		*res++ = *s1++;
	while (*s2)
		*res++ = *s2++;
	*res = '\0';
	return (ptr);
}
