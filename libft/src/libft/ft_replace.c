/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_replace.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yichan <yichan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 21:50:01 by yichan            #+#    #+#             */
/*   Updated: 2023/04/25 00:19:40 by yichan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *ft_strstr(const char *haystack, const char *needle)
{
	size_t	i;
	size_t	j;

	j = 0;
	if (!needle[0])
		return ((char *)haystack);
	while (haystack[j])
	{
		i = 0;
		while (needle[i] == haystack[i + j])
		{
			if (!needle[i +1])
				return ((char *)haystack + j);
			i++;
		}
		j++;
	}
	return (NULL);
}

// void	ft_replace(char **str, char *orig, char *rep)
// {
// 	char	*res;

// 	res = (char *)malloc(sizeof(char) * (ft_strlen(*str) \
// 		+ ft_strlen(rep) - ft_strlen(orig) +1));
// 	ft_strcpy(res, *str);
// 	while (ft_strstr(res, orig))
// 	{
// 		ft_strcpy(res, ft_strstr(res, orig) + ft_strlen(orig));
// 		ft_strlcpy(res, rep, ft_strlen(rep) + 1);
// 		ft_strlcpy(res, ft_strstr(res, orig)
// 			+ ft_strlen(orig), ft_strlen(res) + 1);
// 	}
// 	*str = res;
// 	printf("%s\n", *str);
// }

void	ft_replace(char *str, char *old, char *new)
{
	int		old_len;
	int		new_len;
	char	*pos;

	old_len = ft_strlen(old);
	new_len = ft_strlen(new);
	pos = str;
	while ((pos = ft_strstr(pos, old)) != NULL)
	{
		ft_memmove(pos + new_len, pos + old_len, ft_strlen(pos + old_len) + 1);
		ft_memcpy(pos, new, new_len);
		pos += new_len;
	}
	// strcpy(str, pos);

	// pos = 0;
}


// void ft_replace(char **str, char *orig, char *rep)
// {
//     char *pos, *temp;
//     int orig_len = ft_strlen(orig);
//     int rep_len = ft_strlen(rep);
//     // int diff = rep_len - orig_len;
//     int size = ft_strlen(str) + 1;
//     int count = 0;

//     // Allocate temporary memory
//     temp = (char *) malloc(size * sizeof(char));

//     // Replace all occurrences of orig with rep
//     while ((pos = ft_strstr(str, orig)) != NULL)
//     {
//         // Copy the string before the occurrence
//         ft_strlcpy(temp + count, str, pos - str +1);
//         count += pos - str;

//         // Copy the replacement string
//         ft_strlcpy(temp + count, rep, rep_len +1);
//         count += rep_len;

//         // Move the pointer forward
//         str = pos + orig_len;
//     }

//     // Copy the remaining string
//     ft_strcpy(temp + count, str);

//     // Copy the temporary string back to the original string
//     ft_strcpy(str, temp);

//     // Free the temporary memory
//     free(temp);
// }

// void	ft_replace(char *str, char *old, char *new)
// {
//     int		old_len;
//     int		new_len;
//     char	*pos;

// 	old_len = ft_strlen(old);
// 	new_len = ft_strlen(new);
// 	pos = str;
//     while ((pos = ft_strstr(pos, old)) != NULL)
// 	{
//         ft_memmove(pos + new_len, pos + old_len, ft_strlen(pos + old_len) + 1);
//         ft_memcpy(pos, new, new_len);
//         pos += new_len;
//     }
// }

// int main() {
//     char str[] = "The quick brown fox jumps over the lazy dog";
//     char old[] = "fox";
//     char new[] = "cat";
//     ft_replace(str, old, new);
//     printf("%s\n", str);
//     return 0;
// }