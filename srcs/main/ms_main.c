/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yichan <yichan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 18:16:14 by yichan            #+#    #+#             */
/*   Updated: 2023/04/09 21:10:21 by yichan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(int ac, char **av, char **env)
{
	t_book	record;

	(void) ac;
	(void) av;
	exit_status = 0;
	// t_token	token;

	// (void)av;
	// int	i = 0;
	// int len = ft_arrind(env);
	// while (i < len)
	// 	printf("%s\n", env[i++]);
	if (ac != 1)
	{
		ft_putstr_fd("Minishell Initiate cannot have argument \n", 1);
		return (EXIT_FAILURE);
	}
	record_init(&record, env);
	ms_inputloop(&record);
	// ms_lexer(&record);
	// record.input = readline("./minishell> ");
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
