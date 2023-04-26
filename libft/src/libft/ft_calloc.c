/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yichan <yichan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 12:40:38 by yichan            #+#    #+#             */
/*   Updated: 2023/04/26 22:55:03 by yichan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count)
{
	void			*ptr;

	if (count >= SIZE_MAX)
		return (NULL);
	ptr = (void *)malloc(count);
	if (!ptr)
		return (NULL);
	ft_bzero (ptr, count);
	return (ptr);
}
