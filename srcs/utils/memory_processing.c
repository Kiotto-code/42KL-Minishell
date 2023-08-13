/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory_processing.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yichan <yichan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 22:30:19 by yichan            #+#    #+#             */
/*   Updated: 2023/08/13 15:50:41 by yichan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	cleaner(t_book *mini)
{
	args_destroy(&mini->args);
	cmds_destroy(&mini->cmds);
}

// void	*allocator(size_t size)
// {
// 	void	*ptr;

// 	ptr = malloc(size);
// 	if (!ptr)
// 	{
// 		perror("Could not malloc");
// 		exit(EXIT_FAILURE);
// 	}
// 	return (ptr);
// }

// void	initializator(t_book *mini)
// {
// 	mini->input = NULL;
// 	mini->env = NULL;
// 	mini->cmds = NULL;
// 	mini->args = NULL;
// }

// void	array_liberator(char **array)
// {
// 	int	it;

// 	it = 0;
// 	while (array[it])
// 	{
// 		ft_free(array[it]);
// 		array[it] = NULL;
// 		it++;
// 	}
// 	ft_free(array);
// 	array = NULL;
// }
