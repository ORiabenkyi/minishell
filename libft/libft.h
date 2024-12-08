/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oriabenk <oriabenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 13:19:15 by oriabenk          #+#    #+#             */
/*   Updated: 2024/11/10 17:38:14 by oriabenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <limits.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

char	*get_next_line(int fd);

int		ft_printf(const char *format, ...);
ssize_t	print_char(int fd, int c);
ssize_t	print_string(int fd, const char *str);
ssize_t	print_number(int fd, long c, const char *symbols, unsigned int base);
ssize_t	print_unumber(int fd, unsigned long num, const char *symbols,
			unsigned int base);
ssize_t	print_ptr(int fd, unsigned long p);

int		ft_isalpha(int symbol);
int		ft_isdigit(int symbol);
int		ft_isalnum(int symbol);
int		ft_isascii(int symbol);
int		ft_isprint(int symbol);
int		ft_toupper(int symbol);
int		ft_tolower(int symbol);
int		ft_strncmp(const char *str1, const char *str2, size_t size);
int		ft_memcmp(const void *str1, const void *str2, size_t size);
int		ft_atoi(const char *str);

//undere type

char	*ft_strchr(const char *str, int symbol);
char	*ft_strrchr(const char *str, int symbol);
char	*ft_strnstr(const char *where, const char *what, size_t size);
char	*ft_strdup(const char *income_str);
char	*ft_substr(char const *str, unsigned int start, size_t len);
char	*ft_strjoin(char const *str1, char const *str2);
char	*ft_strtrim(char const *str1, char const *set);
char	**ft_split(char const *str, char c);
char	*ft_itoa(int number);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));

//undere type

size_t	ft_strlen(const char *str);
size_t	ft_strlcpy(char *dest, const char *src, size_t lenght);
size_t	ft_strlcat(char *dest, const char *src, size_t size);

//undere type

void	*ft_memset(void *start, int symbol, size_t length);
void	ft_bzero(void *start, size_t length);
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	*ft_memmove(void *dest, const void *src, size_t length);
void	*ft_memchr(const void *start, int symbol, size_t size);
void	*ft_calloc(size_t count, size_t size);
void	ft_striteri(char *s, void (*f)(unsigned int, char*));
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);

//bonus function

t_list	*ft_lstnew(void *content);
void	ft_lstadd_front(t_list **lst, t_list *new);
int		ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstdelone(t_list *lst, void (*del)(void *));
void	ft_lstclear(t_list **lst, void (*del)(void *));
void	ft_lstiter(t_list *lst, void (*f)(void *));
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

#endif
