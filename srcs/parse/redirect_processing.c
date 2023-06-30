/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect_processing.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yichan <yichan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 17:23:16 by yichan            #+#    #+#             */
/*   Updated: 2023/04/18 21:12:47 by yichan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	redir_lstadd_back(t_redir **list, t_redir *new)
{
	t_redir	*last;

	if (!list || !new)
		exit(EXIT_FAILURE);
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

t_redir	*redir_lstnew(char *type, char *name)
{
	t_redir	*element;

	element = (t_redir *)malloc(sizeof(t_redir));
	if (!element)
		return (NULL);
	element->type = ft_strdup(type);
	element->name = ft_strdup(name);
	element->next = NULL;
	return (element);
}

int	first_redirect(t_token **args, t_redir **rdr)
{
	while (*args)
	{
		if ((*args)->redirect == 1)
		{
			redir_lstadd_back(rdr, redir_lstnew((*args)->entity, \
			(*args)->next->entity));
			if (!(*args)->next->next)
			{
				(*args) = (*args)->next->next;
				return (1);
			}
			(*args) = (*args)->next->next;
		}
		if ((*args)->redirect == 0)
			break ;
	}
	return (0);
}

t_redir	*redirect_processing(t_token **args)
{
	t_redir	*rdr;
	t_token	*tmp;

	if (!args || !(*args))
		return (NULL);
	rdr = NULL;
	if (first_redirect(args, &rdr) == 1)
		return (rdr);
	tmp = *args;
	while (tmp->next)
	{
		if (ft_strcmp(tmp->entity, "|") == 0)
			break ;
		if (tmp->next->redirect == 1)
		{
			redir_lstadd_back(&rdr, redir_lstnew(tmp->next->entity, \
			tmp->next->next->entity));
			args_lstdelnode(&tmp->next);
			args_lstdelnode(&tmp->next);
		}
		if (tmp->next && tmp->next->redirect != 1)
			tmp = tmp->next;
	}
	return (rdr);
}
