/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_replace.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yichan <yichan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 21:50:01 by yichan            #+#    #+#             */
/*   Updated: 2023/05/26 17:37:49 by yichan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// int	ft_strlead(const char *s1, const char *s2)
// {
// 	size_t	it;

// 	it = 0;
// 	while (s1[it] && (s1[it] == s2[it] && s2[it]))
// 		it++;
// 	if (s2[it] == '\0')
// 		return (0);
// 	return ((unsigned char)s1[it] - (unsigned char)s2[it]);
// }


// char *ft_strstr(const char *haystack, const char *needle)
// {
// 	size_t	i;
// 	size_t	j;

// 	j = 0;
// 	if (!needle[0])
// 		return ((char *)haystack);
// 	while (haystack[j])
// 	{
// 		i = 0;
// 		while (needle[i] == haystack[i + j])
// 		{
// 			if (!needle[i +1])
// 				return ((char *)haystack + j);
// 			i++;
// 		}
// 		j++;
// 	}
// 	return (NULL);
// }

// char	*ft_replace(char *str, char *old, char *new)
// {
// 	char	*initial;
// 	char	*itr;
// 	int		i;
// 	char	*res;

// 	res = 0;
// 	initial = ft_strdup(str);
// 	itr = (char *)ft_calloc(sizeof(char) * (ft_strlen(initial) \
// 		+ ft_strlen(new) - ft_strlen(old) +1));
// 	if (!itr)
// 		return (NULL);
// 	i = -1;
// 	while (initial[++i])
// 	{
// 		if (ft_strlead(initial + i, old))
// 		{
// 			printf("itr : %s\n", itr);
// 			printf("new: %s\n", new);
// 			res = ft_strjoin(itr, new);
// 			printf("str after join: %s\n", str);
// 			break ;
// 		}
// 		itr[i] = initial[i];
// 	}
// 	res = ft_strjoinf(res, initial + i + ft_strlen(old));
// 	printf("str: %s\n", str);
// 	return (free(str), free(initial), free(itr), res);
// }


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
// 	free(str);
// 	*str = res;
// }

// void	ft_replace(char *str, char *old, char *new)
// {
// 	int		old_len;
// 	int		new_len;
// 	char	*pos;

// 	old_len = ft_strlen(old);
// 	new_len = ft_strlen(new);
// 	pos = str;
// 	while ((pos = ft_strstr(pos, old)) != NULL)
// 	{
// 		ft_memmove(pos + new_len, pos + old_len, ft_strlen(pos + old_len) + 1);
// 		ft_memcpy(pos, new, new_len);
// 		pos += new_len;
// 	}
// }


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

// 	printf("str: %s|old: %s|new: %s\n", str, old, new);
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



/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yichan <yichan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 22:30:55 by yichan            #+#    #+#             */
/*   Updated: 2023/05/25 16:13:27 by yichan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// char	*ft_strjoin(char const *s1, char const *s2)
// {
// 	size_t	len;
// 	char	*s;

// 	if (!s1 || !s2)
// 		return (NULL);
// 	len = ft_strlen(s1) + ft_strlen(s2);
// 	s = (char*)malloc(sizeof(char) * (len + 1));
// 	if (s == NULL)
// 		return (NULL);
// 	ft_strcpy(s, (char*)s1);
// 	ft_strcpy(s+ft_strlen(s), (char*)s2);
// 	return (s);
// }


 void   ft_replace(char **s, const char *old, const char *new)
 {
    int i;
    char    *str;
    char    *temp;
    char    *first;
    char    *third;

    i = 0;
    str = *s;
    while (strcmp(str+i, old))
        i++;
    first = ft_substr(str, 0, i);
    third = ft_substr(str, ft_strlen(old)+i, ft_strlen(str) - i - ft_strlen(old));
    temp = ft_strjoin(first, new);
    free(str);
    str = ft_strjoin(temp, third);
 }


//  int main()
//  {
//     char *str = strdup("hello world whatever");
//     repalce(str);
//     printf("%s\n", str);
//  }