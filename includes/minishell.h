/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etlaw <ethanlxz@gmail.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 18:17:57 by yichan            #+#    #+#             */
/*   Updated: 2023/05/24 20:18:26 by etlaw            ###   ########.fr       */
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
# define DOLLAR		3
# define NEUTRAL	0
# define EXPORT		1
# define CD			2

typedef struct s_env
{
	char			*var;
	char			*key;
	char			*value;
	struct s_env	*next;
	struct s_env	*prev;
}	t_env;

typedef struct s_token
{
	char			*entity;
	int				type;
}	t_token;

typedef struct s_book
{
	char	**env_arr;
	char	*input;
	int		anchor;
	t_list	*env;
	t_list	*token;
}	t_book;

//----utils
//ms_libft.c

//----allocate
//ms_initiate.c
void	ms_token(t_book *record);
int		ms_inputloop(t_book *record);
void	record_init(t_book *record, char **envp);
// ms_lexer.c
int		ms_lexer(t_book *record, t_token *token);

char	*var_strjoin(char const *val, char const *key);


#endif
