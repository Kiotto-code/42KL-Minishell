/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmdl_create.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yichan <yichan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 20:01:54 by yichan            #+#    #+#             */
/*   Updated: 2023/07/27 12:37:58 by yichan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	cmdblock_counter(t_token *args)
{
	int		quantity;
	t_token	*tmp;

	if (!args)
		return (0);
	tmp = args;
	quantity = 1;
	if (ft_strcmp("|", tmp->entity) == 0)
		return (0);
	while (tmp->next)
	{
		tmp = tmp->next;
		if (ft_strcmp(tmp->entity, "|") == 0)
			return (quantity);
		quantity++;
	}
	return (quantity);
}

char	**cmdblock_to_array(t_token *args, int quantity_lists)
{
	int		it;
	char	**arg_arr;

	it = 0;
	arg_arr = malloc(sizeof(char *) * (quantity_lists + 1));
	if (!arg_arr)
		return (NULL);
	while (args && (quantity_lists != 0))
	{
		arg_arr[it] = ft_strdup(args->entity);
		it++;
		quantity_lists--;
		args = args->next;
	}
	arg_arr[it] = NULL;
	return (arg_arr);
}

t_cmdl	*cmds_lstnew(t_token *args)
{
	t_cmdl	*element;
	int		quantity_lists;

	element = (t_cmdl *)malloc(sizeof(t_cmdl));
	if (!element || !args)
		return (NULL);
	element->redir = NULL;
	element->redir = redirect_processing(&args);
	quantity_lists = cmdblock_counter(args);
	element->command = cmdblock_to_array(args, quantity_lists);
	element->in = 0;
	element->out = 1;
	element->fork = 0;
	element->pipe_fd[0] = 0;
	element->pipe_fd[1] = 0;
	element->next = NULL;
	return (element);
}

void	cmds_lstadd_back(t_cmdl	**list, t_cmdl *new)
{
	t_cmdl	*last;

	if (!list || !new)
		return ;
	if (*list)
	{
		last = *list;
		while (last->next)
			last = last->next;
		last->next = new;
	}
	else
		*list = new;
}
