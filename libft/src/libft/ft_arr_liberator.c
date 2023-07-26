/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arr_liberator.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yichan <yichan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 23:38:33 by yichan            #+#    #+#             */
/*   Updated: 2023/07/25 23:39:03 by yichan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	array_liberator(char **array)
{
	int	it;

	it = 0;
	while (array[it])
	{
		free(array[it]);
		array[it] = NULL;
		it++;
	}
	free(array);
	array = NULL;
}
