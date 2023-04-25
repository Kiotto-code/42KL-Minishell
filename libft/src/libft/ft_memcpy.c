/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yichan <yichan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 19:12:59 by yichan            #+#    #+#             */
/*   Updated: 2023/04/25 18:30:30 by yichan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// void	*ft_memcpy(void *dest, const void *src, size_t n)
// {
// 	unsigned int	i;

// 	i = 0;
// 	if (dest == NULL && src == NULL)
// 		return (NULL);
// 	while (i < n)
// 	{
// 		((unsigned char *)dest)[i] = ((unsigned char *)src)[i];
// 		i++;
// 	}
// 	return (dest);
// }

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char		*dst_cpy;
	const char	*src_cpy;

	dst_cpy = dst;
	src_cpy = src;
	if (dst_cpy == NULL && src_cpy == NULL)
		return (NULL);
	while (n--)
		*dst_cpy++ = *src_cpy++;
	return (dst);
}