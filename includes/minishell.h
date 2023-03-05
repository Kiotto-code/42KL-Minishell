/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yichan <yichan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 18:17:57 by yichan            #+#    #+#             */
/*   Updated: 2023/03/05 23:11:42 by yichan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <unistd.h>
# include <stdlib.h>
# include <readline/history.h>
# include <readline/readline.h>
# include "../libft/includes/libft.h"

# define DEFAULT	"\033[0m"
# define CYAN		"\033[0;36m"
# define RED		"\033[0;31m"
# define SQUOTE		1
# define DQUOTE		2
# define NEUTRAL	0

typedef struct s_env
{
	char			*var;
	char			*key;
	char			*value;
	struct s_env	*prev;
	struct s_env	*next;
}	t_env;

typedef struct s_token
{
	int				anchor;
	int				dollar;
	t_list			*entity;
	// t_list direct;
	// t_list dquote;
	// t_list squote;
	struct s_token	*next;
	struct s_token	*prev;
}	t_token;

typedef struct s_book
{
	char	**env_arr;
	char	*input;
	t_list	*env;
	t_list	*token;
}	t_book;

//----utils
//ms_libft.c

//----allocate
//ms_initiate.c
void	ms_token(t_token *token, t_book *record);
int		ms_inputloop(t_book *record);
void	record_init(t_book *record, char **envp);

#endif
