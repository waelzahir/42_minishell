/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-kham <sel-kham@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 19:16:44 by sel-kham          #+#    #+#             */
/*   Updated: 2022/07/03 01:43:57 by sel-kham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

typedef struct s_token
{
	enum {
		SINGLE_QUOTE,
		DOUBLE_QUOTE,
		INPUT_REDIRECTION,
		OUTPUT_REDIRECTION,
		OUTPUT_REDIRECTION_APPEND,
		HEREDOC,
		STRING,
		PIPE,
		VAR,
		AND_IF,
		OR_IF,
		OPEN_PARENTHESIS,
		CLOSE_PARENTHESIS,
		WILD_CARD,
		EOL
	}	e_type;
	char	*content;
}	t_token;
