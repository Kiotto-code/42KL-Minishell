/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etlaw <ethanlxz@gmail.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 22:29:38 by yichan            #+#    #+#             */
/*   Updated: 2023/08/12 23:20:41 by etlaw            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	redir_lstdelone(t_redir *lst)
{
	if (!lst)
		return ;
	ft_free(lst->type);
	lst->type = NULL;
	ft_free(lst->name);
	lst->name = NULL;
	ft_free(lst);
	lst = NULL;
}

void	redir_destroy(t_redir **lst)
{
	t_redir	*tmp;

	if (!lst)
		return ;
	while (*lst)
	{
		tmp = (*lst)->next;
		redir_lstdelone(*lst);
		*lst = tmp;
	}
	*lst = NULL;
}

void	cmds_lstdelone(t_cmdl *lst)
{
	int		it;
	t_redir	*tmp;

	it = 0;
	if (!lst)
		return ;
	while (lst->command[it])
	{
		if (lst->command == NULL)
			break ;
		ft_free(lst->command[it]);
		lst->command[it] = NULL;
		it++;
	}
	ft_free(lst->command);
	lst->command = NULL;
	tmp = (t_redir *) lst->redir;
	redir_destroy(&tmp);
	ft_free(lst);
	lst = NULL;
}

void	cmds_destroy(t_cmdl **lst)
{
	t_cmdl	*tmp;

	if (!lst)
		return ;
	while (*lst)
	{
		tmp = (*lst)->next;
		cmds_lstdelone(*lst);
		*lst = tmp;
	}
	*lst = NULL;
}

// int	cmds_lstsize(t_cmdl *cmds)
// {
// 	int	count;

// 	if (!cmds)
// 		return (0);
// 	count = 0;
// 	while (cmds)
// 	{
// 		cmds = cmds->next;
// 		count++;
// 	}
// 	return (count);
// }
