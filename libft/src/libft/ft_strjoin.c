/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yichan <yichan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 21:55:44 by yichan            #+#    #+#             */
/*   Updated: 2023/04/26 23:06:39 by yichan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// char	*ft_strjoin(char const *s1, char const *s2)
// {
// 	char	*res;
// 	char	*ptr;

// 	if (!s1 || !s2 || !*s1 || !*s2)
// 		return (NULL);
// 	res = ft_calloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) +1));
// 	if (!res)
// 		return (NULL);
// 	ptr = res;
// 	while (*s1)
// 		*res++ = *s1++;
// 	while (*s2)
// 		*res++ = *s2++;
// 	*res = '\0';
// 	return (ptr);
// }

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*res;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!s1 || !s2 )
		return (NULL);
	res = ft_calloc(sizeof(char ) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!res)
		return (NULL);
	while (s1[i])
		res[i++] = s1[j++];
	j = 0;
	while (s2[j])
		res[i++] = s2[j++];
	res[i] = '\0';
	// free (s1);
	return (res);
}
