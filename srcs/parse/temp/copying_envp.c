/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copying_envp.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yichan <yichan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 17:22:55 by yichan            #+#    #+#             */
/*   Updated: 2023/04/18 22:18:02 by yichan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*copy_value(char *env_part)
{
	int		it;
	char	*value;

	it = 0;
	while (env_part[it] != '=' && env_part[it] != '\0')
		it++;
	if (env_part[it] == '\0')
		value = NULL;
	else
		value = ft_strdup(&env_part[it + 1]);
	return (value);
}

char	*copy_key(char *env_part)
{
	int		it;
	char	*key;

	it = 0;
	while (env_part[it] != '=' && env_part[it] != '\0')
		it++;
	key = ft_substr(env_part, 0, it);
	return (key);
}

t_env	*envl_lstnew(char *env_str)
{
	t_env	*element;

	element = (t_env *)malloc(sizeof(t_env));
	if (!element)
		return (NULL);
	element->line = ft_strdup(env_str);
	element->key = copy_key(env_str);
	if (ft_strcmp(element->key, "OLDPWD") == 0)
		element->value = NULL;
	else
		element->value = copy_value(env_str);
	element->next = NULL;
	return (element);
}

void	envl_lstadd_back(t_env	**list, t_env *new)
{
	t_env	*last;

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

t_env	*copying_envp(char **envp)
{
	t_env	*envp_copy;
	int		it;

	it = 0;
	envp_copy = NULL;
	while (envp[it])
	{
		envl_lstadd_back(&envp_copy, envl_lstnew(envp[it]));
		it++;
	}
	return (envp_copy);
}
