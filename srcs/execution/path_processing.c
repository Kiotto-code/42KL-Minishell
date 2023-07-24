/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_processing.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yichan <yichan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 16:13:11 by yichan            #+#    #+#             */
/*   Updated: 2023/07/23 03:13:13 by yichan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	executable_path(char *line)
{
	int	it;

	it = 0;
	while (line != NULL && line[it] && !ft_isalnum(line[it]))
	{
		if (line[it] == '/')
			return (1);
		it++;
	}
	return (0);
}

char	**get_paths(t_book *mini)
{
	char	*path_value;
	char	**paths;

	path_value = check_envvar(mini->env, "PATH");
	if (!path_value)
		return (NULL);
	paths = ft_split(path_value, ':');
	return (paths);
}

char	*path_processing(t_book *mini, char *line)
{
	int		it;
	char	*path;
	char	**paths;

	it = 0;
	if (executable_path(line))
		return (line);
	paths = get_paths(mini);
	if (!paths)
		return (NULL);
	while (paths[it])
	{
		path = ft_strjoin_con(paths[it], "/", line);
		// printf("check: path%s\n", path);
		if (access(path, F_OK | X_OK) == 0)
		{
			array_liberator(paths);
			// printf("%s: command not found\n", line);
			// printf(RED"checking wrong path");
			return (path);
		}
		free(path);
		it++;
	}
	array_liberator(paths);
	return (NULL);
}
