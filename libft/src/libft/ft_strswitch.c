/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strswitch.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yichan <yichan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 04:53:42 by yichan            #+#    #+#             */
/*   Updated: 2023/07/29 05:40:38 by yichan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "libft.h"

void	ft_strswitch(char **old, char *new)
{
	if (!old || !new || !*old)
		return ;
	if (*old)
		free(*old);
	*old = ft_strdup(new);
	if (new)
		free(new);
}