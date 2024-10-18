/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzwart <mzwart@student.codam.nl>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/06 23:00:34 by mzwart            #+#    #+#             */
/*   Updated: 2024/10/06 23:44:33 by mzwart           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include <stdbool.h>



#include <limits.h>
#include <unistd.h>


#include <stdlib.h>

// remove eventually
#include <stdio.h>
#include <string.h>

// TODO: make it possible for heredoc to set a word as END delimiter...
enum e_identifiers
{
	END,
	WORD,
	SPACE = ' ',
	SET_ENV = '=',
	ENV_VAR = '$',
	PIPE = '|',
	REDIRECT_IN = '<',
	REDIRECT_OUT = '>',
	SINGLE_QUOTE = '\"',
	DOUBLE_QUOTE = '\'',

	// ... not sure about these yet
	NEW_LINE = '\n',
	HEREDOC_END,
};

// ASCII to identifier map...

struct s_tokenizer {
	char	*input;
};

typedef struct s_token {
	char			*text;
	ssize_t			length;
	enum e_identifiers	identifier;
}	t_token;

typedef struct s_token_node
{
	t_token			token;
	struct s_token_node	*next;
} t_token_node;

// END is also required here since array of chars needs to be null-terminated
const static char	SINGLE_CHAR_TOKENS[8] = {
	SINGLE_QUOTE, DOUBLE_QUOTE, REDIRECT_IN, REDIRECT_OUT,
	PIPE, SET_ENV, ENV_VAR, END
};

// combine?...
const static char	WORD_DELIMITERS[9] = {
	SPACE, SINGLE_QUOTE, DOUBLE_QUOTE, REDIRECT_IN, REDIRECT_OUT,
	PIPE, SET_ENV, ENV_VAR, END
};

//=============================================================================

void	init_tokenizer(struct s_tokenizer *tokenizer, char *data)
{
	tokenizer->input = data;
}

// This function returns current token and length and needs to 
t_token	tokenize_one_token(struct s_tokenizer *tokenizer)
{
	char		*str;
	t_token		token;

	if (!tokenizer->input)
		return ((t_token){.text = NULL, .length = 0, .identifier = 0});
	str = tokenizer->input;
	token.text = str;
	token.identifier = (enum e_identifiers)*str;
	token.length = 0;
	while (str[token.length] && str[token.length] == SPACE)
		++token.length;
	if (str[token.length] == END || token.length > 0)
	{
		tokenizer->input += token.length;
		return (token);
	}
	if (strchr(SINGLE_CHAR_TOKENS, token.identifier))
	{
		token.length += 1;
		tokenizer->input += 1;
		return (token);
	}
	token.identifier = WORD;
	while (strchr(WORD_DELIMITERS, str[token.length]) == NULL)
		++token.length;
	tokenizer->input += token.length;
	return (token);
}

// void	lst_add_node(t_tok_node	**head, t_token token)
// {
// 	if (*head == NULL)
// 	{
// 		*head = token;
// 		return ;
// 	}
// }

//In Zsh, the maximum length of a command line is 256 KB (262144 characters).

t_token_node	*lst_last(t_token_node *lst)
{
	if (!lst)
		return(NULL);
	while (lst->next != NULL)
		lst = lst->next;
	return (lst);
}

t_token_node	*lst_add_node(t_token_node **head, t_token token)
{
	t_token_node	*new_node;
	t_token_node	*last_node;

	new_node = (t_token_node *)malloc(sizeof(t_token_node));
	if (!new_node)
		return (NULL);
	new_node->token = token;
	new_node->next = NULL;
	if (*head == NULL)
		*head = new_node;
	else
	{
		last_node = lst_last(*head);
		last_node->next = new_node;
	}
	return (new_node);
}

t_token_node	*lst_traverse(t_token_node *lst, int	count)
{
	if (!lst || count < 0)
		return(NULL);
	while (lst->next != NULL && count > 1)
	{
		lst = lst->next;
		--count;
	}
	return (lst);

}

// TODO: Tokenize once, get the count, then malloc for that count
int main()
{
	struct s_tokenizer tokenizer;
	char	*str = "hel $lo_world$H";
	t_token		token;
	int		tokens;
	t_token_node	*head;



	init_tokenizer(&tokenizer, str);
	printf("untokenized str:%s\n", tokenizer.input);
	token.identifier = 1;
	tokens = 0;

	head = NULL;

	while (token.identifier != END)
	{
		token = tokenize_one_token(&tokenizer);
		lst_add_node(&head, token);
 		printf("[%.*s]:%zi,%i\n", (int)token.length, token.text, token.length, token.identifier);
		++tokens;
	}
	printf("%i", tokens);

	t_token	test = lst_traverse(head, 4)->token;

	printf("\ntok:%.*s", test.length, test.text);

	// NOTE:
	// argmax = 2097152
	// is this values always same for all codam computers?
	// NOTE: Is this necessary or is ARG_MAX not to big for most or this system?
	return 0;
}

//
//
//
//
//
//
// 	token.identifier = 1;
// 	while (tokenizer.input != NULL && token.identifier != END)
// 	{
// 		new_node = (t_tok_node *)malloc(sizeof(t_token));
// 		new_node->token = tokenize_one_token(&tokenizer);
// 		new_node->next = NULL;
// 		lst_add_node(&head, new_node);
//
//
// 		add_node(&head, token);
// 		printf("[%.*s]:%zi,%i", (int)token.length, token.text, token.length, token.identifier);
// 	}
// 	printf("\nhead node:%s", head.token.text);
// }

