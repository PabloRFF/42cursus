/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablrome <pablrome@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 18:22:52 by pablrome          #+#    #+#             */
/*   Updated: 2025/01/22 20:02:47 by pablrome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int	ft_atoi(const char *str);
int	ft_isalnum(int c);
int	ft_isalpha(int c);
int	ft_isascii(int c);
int	ft_isdigit(int c);
int	ft_isprint(int c);
int	ft_strlen(const char *str);
int ft_tolower(int c);
int ft_toupper(int c);
void	*ft_bzero(void *str, size_t n);
void	*ft_memset(void *str, int c, size_t n);
size_t  ft_strlcpy(char *dest, const char *src, size_t n);
void	*ft_memmove(void *dest, const void *src, size_t n);
void	*ft_memcpy(void *dest_str, const void *src_str, size_t n);
void	*ft_memchr(const void *s, int c, size_t n);
void    *ft_calloc(size_t nitems, size_t size);
char    *ft_itoa(int n);
char    *ft_strdup(const char *s);
char    *ft_strmapi(char const *s, char (*f)(unsigned int, char));
char	*ft_strchr(const char *str, int c);
char    *ft_strtrim(char const *s1, char const *set);
char    *ft_substr(char const *s, unsigned int start, size_t len);
char    **ft_split(char const *s, char c);
void    ft_striteri(char *s, void (*f)(unsigned int, char*));
void	ft_putstr_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
void	ft_putchar_fd(char c, int fd);
void	ft_putendl_fd(char *s, int fd);

#endif