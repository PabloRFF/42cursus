/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablrome <pablrome@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 14:03:57 by pablrome          #+#    #+#             */
/*   Updated: 2025/02/13 14:36:16 by pablrome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// static size_t	ft_strlen(const char *s)
// {
// 	size_t	len;

// 	len = 0;
// 	while (s[len])
// 		len++;
// 	return (len);
// }

// char	*ft_strchr(char *s, int c)
// {
// 	while (*s)
// 	{
// 		if (*s == (char)c)
// 			return ((char *)s);
// 		s++;
// 	}
// 	if (c == '\0')
// 		return ((char *)s);
// 	else
// 		return (NULL);
// }

// void	*ft_memcpy(void *dst, const void *src, size_t n)
// {
// 	char		*d;
// 	const char	*s;

// 	d = dst;
// 	s = src;
// 	while (n--)
// 		*d++ = *s++;
// 	return (dst);
// }

// char	*ft_strdup(const char *s1)
// {
// 	size_t	len;
// 	char	*copy;

// 	len = ft_strlen(s1) + 1;
// 	copy = malloc(len);
// 	if (!copy)
// 		return (NULL);
// 	ft_memcpy(copy, s1, len);
// 	return (copy);
// }

// char	*ft_strjoin(char const *s1, char const *s2)
// {
// 	size_t	len1;
// 	size_t	len2;
// 	char	*result;

// 	if (!s1 || !s2)
// 		return (NULL);
// 	len1 = ft_strlen(s1);
// 	len2 = ft_strlen(s2);
// 	result = malloc(len1 + len2 + 1);
// 	if (!result)
// 		return (NULL);
// 	ft_memcpy(result, s1, len1);
// 	ft_memcpy(result + len1, s2, len2 + 1);
// 	return (result);
// }

// char	*ft_substr(char const *s, unsigned int start, size_t len)
// {
// 	size_t	s_len;
// 	char	*sub;

// 	if (!s)
// 		return (NULL);
// 	s_len = ft_strlen(s);
// 	if (start >= s_len)
// 		return (ft_strdup(""));
// 	if (len > s_len - start)
// 		len = s_len - start;
// 	sub = malloc(len + 1);
// 	if (!sub)
// 		return (NULL);
// 	ft_memcpy(sub, s + start, len);
// 	sub[len] = '\0';
// 	return (sub);
// }

#include <stdlib.h>

// Calcula la longitud de una cadena
size_t ft_strlen(const char *str) {
    size_t len = 0;
    while (str[len]) len++;
    return len;
}

// Duplica una cadena
char *ft_strdup(const char *str) {
    size_t len = ft_strlen(str);
    char *dup = malloc(len + 1);
    if (!dup) return NULL;
    for (size_t i = 0; i <= len; i++) dup[i] = str[i];
    return dup;
}

// Busca un carácter en una cadena
char	*ft_strchr(const char *str, int c)
{
    while (*str) {
        if (*str == (char)c) return (char *)str;
        str++;
    }
    return NULL;
}

// Concatena dos cadenas
char *ft_strjoin(char const *s1, char const *s2) {
    if (!s1)
        return ft_strdup(s2);
    if (!s2)
        return ft_strdup(s1);

    size_t len1 = ft_strlen(s1);
    size_t len2 = ft_strlen(s2);
    char *result = malloc(len1 + len2 + 1);
    if (!result)
        return NULL;
    
    size_t i = 0;
    while (i < len1) {
        result[i] = s1[i];
        i++;
    }
    size_t j = 0;
    while (j < len2) {
        result[i + j] = s2[j];
        j++;
    }
    result[i + j] = '\0';
    return result;
}

// Copia una cadena en otra
void ft_strcpy(char *dest, const char *src) {
    while (*src) *dest++ = *src++;
    *dest = '\0';
}