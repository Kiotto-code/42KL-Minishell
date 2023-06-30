/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yichan <yichan@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 15:34:33 by yichan            #+#    #+#             */
/*   Updated: 2022/07/06 15:48:38 by yichan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	int		a;
	int		b;
	char	*res;

	a = ft_strlen(s1);
	b = 0;
	res = (char *)malloc (a + 1);
	if (res == NULL)
		return (NULL);
	while (b < a)
	{
		res[b] = s1[b];
		b++;
	}
	res[b] = '\0';
	return (res);
}
