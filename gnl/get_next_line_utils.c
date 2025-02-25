/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablrome <pablrome@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 14:03:57 by pablrome          #+#    #+#             */
/*   Updated: 2025/02/25 16:53:55 by pablrome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char		*d;
	const char	*s;

	d = dst;
	s = src;
	while (n--)
		*d++ = *s++;
	return (dst);
}

#include <stdlib.h>

// Calcula la longitud de una cadena
size_t ft_strlen(const char *str) {
    size_t len = 0;
    while (str[len]) len++;
    return len;
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	s_len;
	char	*sub;

	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	if (start >= s_len)
		return (ft_strdup(""));
	if (len > s_len - start)
		len = s_len - start;
	sub = ft_calloc(sizeof(char), len + 1);
	if (!sub)
		return (NULL);
	ft_memcpy(sub, s + start, len);
	sub[len] = '\0';
	return (sub);
}

// Duplica una cadena
char *ft_strdup(const char *str) {
    size_t len = ft_strlen(str);
    char *dup = ft_calloc(sizeof(char), len + 1);
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
char *ft_strjoin(char *s1, char *s2) {
    if (!s1)
        return ft_strdup(s2);
    if (!s2)
        return ft_strdup(s1);

    size_t len1 = ft_strlen(s1);
    size_t len2 = ft_strlen(s2);
    char *result = ft_calloc(sizeof(char), len1 + len2 + 1);
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

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;
	size_t	i;

	if (nmemb != 0 && (nmemb * size) / nmemb != size)
		return (NULL);
	ptr = (void *)malloc(size * nmemb);
	if (!ptr)
		return (NULL);
	if (size == 0)
		return (ptr);
	i = 0;
	while (i < (nmemb * size))
	{
		((unsigned char *)ptr)[i] = 0;
		i++;
	}
	return (ptr);
}