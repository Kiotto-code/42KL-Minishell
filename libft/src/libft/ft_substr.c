/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yichan <yichan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 18:42:50 by yichan            #+#    #+#             */
/*   Updated: 2023/03/26 01:45:51 by yichan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// char	*ft_substr(char const *s, unsigned int start, size_t len)
// {
// 	char	*substr;
// 	size_t	modlen;

// 	if (!s)
// 		return (NULL);
// 	if (ft_strlen(s) < start)
// 		return (ft_strdup(""));
// 	modlen = ft_strlen(s + start);
// 	if (modlen < len)
// 		len = modlen;
// 	substr = (char *)ft_calloc(sizeof(char) * len +1);
// 	if (!substr)
// 		return (NULL);
// 	ft_strlcpy(substr, s + start, len +1);
// 	return (substr);
// }

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	j;
	char	*output;

	i = 0;
	j = 0;
	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
		output = malloc(1);
	else if (len >= ft_strlen(s) - start)
		output = malloc(sizeof(char) * (ft_strlen(s) - start + 1));
	else
		output = malloc(sizeof(char) * (len + 1));
	if (output == NULL)
		return (NULL);
	while (i < start)
		i++;
	while (j < len && i < ft_strlen(s))
		output[j++] = s[i++];
	output[j] = '\0';
	return (output);
}