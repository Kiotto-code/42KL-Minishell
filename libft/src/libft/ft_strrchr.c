/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yichan <yichan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 16:03:35 by yichan            #+#    #+#             */
/*   Updated: 2023/04/28 18:57:14 by yichan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//Check if the character c (converted to an unsigned char) occurs anywhere in the string s.

char	*ft_strrchr(const char *s, int c)
{
	int	len;

	len = ft_strlen(s);
	while (len >= 0)
	{
		if (*(s + len) == (unsigned char)c)
			return ((char *)(s + len));
		len --;
	}
	return (NULL);
}
