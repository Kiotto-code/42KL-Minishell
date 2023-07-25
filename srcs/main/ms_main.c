/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yichan <yichan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 18:16:14 by yichan            #+#    #+#             */
/*   Updated: 2023/07/25 03:19:41 by yichan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(int ac, char **av, char **env)
{
	t_book	record;

	(void) ac;
	(void) av;
	g_exit_status = 0;
	if (ac != 1)
	{
		ft_putstr_fd("Minishell Initiate cannot have argument \n", 1);
		return (EXIT_FAILURE);
	}
	record_init(&record, env);
	shlvl_up(&record);
	ms_inputloop(&record);
	system("leaks -q minishell");
	return (0);
}

// int	main(void)
// {
// 	char	*str;

// 	while (1)
// 	{
// 		str = readline("read> ");
// 		if (str == NULL)
// 			break ;
// 		printf("str: [%s]\n", str);
// 		free(str);
// 	}
// }
