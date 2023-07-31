/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_replace.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yichan <yichan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 21:50:01 by yichan            #+#    #+#             */
/*   Updated: 2023/07/31 21:26:22 by yichan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// void	ft_replace(char **s, char *old, char *new)
// {
// 	int		i;
// 	char	*str;
// 	char	*temp;
// 	char	*first;
// 	char	*third;

// 	i = 0;
// 	str = *s;
// 	if (old == NULL || new == NULL)
// 		return ;
// 	while (str[i] && !ft_strlead(str + i, old))
// 		i++;
// 	first = ft_substr(str, 0, i);
// 	third = ft_substr(str, ft_strlen(old)+i, \
// 		ft_strlen(str) - i - ft_strlen(old));
// 	temp = ft_strjoin(first, new);
// 	free(*s);
// 	*s = ft_strjoin(temp, third);
// 	free(temp);
// 	free(third);
// }

void	ft_replace(char **s, const char *old, const char *new)
{
	int		i;
	char	*str;
	char	*temp;
	char	*first;
	char	*third;

	if (old == NULL || new == NULL || s == NULL)
		return ;
	i = 0;
	str = *s;
	while (str[i] && !ft_strlead(str + i, old))
		i++;
	first = ft_substr(str, 0, i);
	third = ft_substr(str, ft_strlen(old)+i, \
		ft_strlen(str) - i - ft_strlen(old));
	temp = ft_strjoin(first, new);
	free(*s);
	*s = ft_strjoin(temp, third);
	free(temp);
	free(third);
}
