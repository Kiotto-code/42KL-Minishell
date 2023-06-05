/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_expand.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etlaw <ethanlxz@gmail.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 20:42:04 by etlaw             #+#    #+#             */
/*   Updated: 2023/03/29 17:49:25 by etlaw            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	expand(t_list **env, t_list **tkn)
{
	int		i;
	char	*str;
	char	*expand;
	size_t	len;

	i = -1;
	len = ft_strlen(((t_token *)(*tkn)->content)->entity);
	while (((t_token *)(*tkn)->content)->entity[++i])
	{
		if (((t_token *)(*tkn)->content)->entity[i] == '$')
		{
			if (((t_token *)(*tkn)->content)->entity[1 + i] == '?')
				expand = get_exit_status();
			else
			{
				str = ft_substr(((t_token *)(*tkn)->content)->entity,
						i +1, len - i -1);
				expand = find_val(env, str);
				free(str);
			}
		}
	}
	str = ft_substr(((t_token *)(*tkn)->content)->entity, 0, i + 1);
	free (((t_token *)(*tkn)->content)->entity);
	((t_token *)(*tkn)->content)->entity = ft_strjoin(str, expand);
}

static char	*find_val(t_list **env, char *s_expand)
{
	t_list	*tmp;

	tmp = *env;
	while (*env)
	{
		if (ft_strcmp(((t_env *)(*env)->content)->key, s_expand) == 0)
			return (ft_strdup(((t_env *)(*env)->content)->value));
		else
			return (ft_strdup(""));
	}
}
