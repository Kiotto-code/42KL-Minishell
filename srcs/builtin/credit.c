/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   credit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etlaw <ethanlxz@gmail.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 21:53:34 by etlaw             #+#    #+#             */
/*   Updated: 2023/08/13 22:53:43 by etlaw            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	shell1(void)
{
	printf("\t\t\t\t                                               \n");
	printf("\t\t\t\t                                               \n");
	printf("\t\t\t\t                  ████████                     \n");
	printf("\t\t\t\t              ▓▓▓▓▒▒▒▒▒▒▒▒▓▓▓▓                 \n");
	printf("\t\t\t\t          ████▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒████             \n");
	printf("\t\t\t\t        ██▒▒██▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒██▒▒██           \n");
	printf("\t\t\t\t      ██▒▒▒▒▒▒██▒▒▒▒▒▒▒▒▒▒▒▒██▒▒▒▒▒▒██         \n");
	printf("\t\t\t\t      ██▒▒▒▒▒▒░░████████████▒▒▒▒▒▒▒▒██         \n");
	printf("\t\t\t\t    ██▒▒▒▒▒▒▒▒██░░░░░░░░▒▒▒▒██▒▒▒▒▒▒▒▒██       \n");
	printf("\t\t\t\t    ██▒▒▒▒▒▒██░░░░░░░░░░▒▒▒▒▒▒██▒▒▒▒▒▒██       \n");
	printf("\t\t\t\t    ██▒▒▒▒██░░░░░░░░░░░░▒▒▒▒▒▒░░▓▓▒▒▒▒██       \n");
	printf("\t\t\t\t  ██▒▒▒▒██░░▒▒░░░░░░░░░░▒▒▒▒▒▒▒▒░░██▒▒▒▒██     \n");
	printf("\t\t\t\t  ██▒▒▓▓▒▒▓▓▒▒▒▒░░░░░░▒▒▒▒▒▒▒▒▒▒▓▓▒▒██▒▒██     \n");
	printf("\t\t\t\t  ████░░░░▒▒██▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▓▓▒▒░░░░████     \n");
	printf("\t\t\t\t ███▒▒▒▒▒▒▒▒▒▒██▒▒▒▒▒▒▒▒▒▒▒▒██▒▒▒▒▒▒▒▒▒▒████   \n");
	printf("\t\t\t\t █░░██▒▒▒▒▒▒▒▒▒▒████████████░░▒▒▒▒▒▒▒▒██░░██   \n");
}

void	shell(void)
{
	shell1();
	printf("\t\t\t\t █░░░░████▒▒██▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒██▒▒████░░░░██   \n");
	printf("\t\t\t\t  ██░░░░░░▓▓██▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒██▓▓░░░░░░██     \n");
	printf("\t\t\t\t  ██░░░░░░░░░░████████████████░░░░░░░░░░██     \n");
	printf("\t\t\t\t    ██░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░██       \n");
	printf("\t\t\t\t      ██▓▓░░░░░░░░░░░░░░░░░░░░░░░░████         \n");
	printf("\t\t\t\t          ████████████████████████             \n");
	printf("\t\t\t\t                                               \n");
	printf("\t\t\t\t                                               \n");
}

int	credit(void)
{
	shell();
	printf("\n");
	printf("\n");
	printf("%s\t\t\t\t\tminishell made by :\n", GREEN);
	printf("\n");
	printf("\n");
	printf("\n");
	printf("\n");
	printf("%s\t\t\t\t\tyichan - craving 4 more caffeine\n", CYAN);
	printf("\n");
	printf("\n");
	printf("%s\t\t\t\t\tetlaw  - what the shell ?\n", MAGENTA);
	printf("\n");
	printf("\n");
	printf("\n");
	printf("\n");
	printf("\n");
	printf("%s\t\t\t\t\t       :::      ::::::::\n", GREEN);
	printf("\t\t\t\t\t     :+:      :+:    :+:\n");
	printf("\t\t\t\t\t    +:+ +:+         +:+ \n");
	printf("\t\t\t\t\t   +#+  +:+       +#+   \n");
	printf("\t\t\t\t\t+#+#+#+#+#+   +#+       \n");
	printf("\t\t\t\t\t     #+#    #+#         \n");
	printf("\t\t\t\t\t    ###   ########.kl   %s\n", DEFAULT);
	return (69);
}
