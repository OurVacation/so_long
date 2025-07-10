/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_util.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taewonki <taewonki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 09:27:13 by taewonki          #+#    #+#             */
/*   Updated: 2025/05/27 14:25:37 by taewonki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strdup(const char *s)
{
	char	*dup;
	char	*result;

	dup = malloc(ft_strlen(s) + 1);
	result = dup;
	if (dup == NULL)
		return (NULL);
	while (*s != 0)
		*dup++ = *s++;
	*dup = '\0';
	return (result);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	nstr_len;
	char	*nstr;
	char	*result;

	if (!s1)
		return (ft_strdup(s2));
	if (!s2)
		return (ft_strdup(s1));
	nstr_len = ft_strlen(s1) + ft_strlen(s2);
	nstr = malloc(nstr_len + 1);
	if (nstr == NULL)
		return (NULL);
	result = nstr;
	while (*s1)
		*nstr++ = *s1++;
	while (*s2)
		*nstr++ = *s2++;
	*nstr = '\0';
	return (result);
}

char	*ft_strchr(const char *str, int c)
{
	unsigned char	search;

	search = (unsigned char)c;
	while (*str != 0)
	{
		if (*str == search)
			return ((char *)str);
		str++;
	}
	if (search == '\0')
		return ((char *)str);
	return (NULL);
}

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	char			*substr;
	unsigned int	s_len;
	unsigned int	substr_len;
	unsigned int	i;

	s_len = (unsigned int)ft_strlen(s);
	if (s_len <= start)
	{
		substr = malloc(1);
		substr[0] = '\0';
		return (substr);
	}
	if ((s_len - start) >= (unsigned int)len)
		substr_len = (unsigned int)len;
	else
		substr_len = s_len - start;
	substr = malloc(substr_len + 1);
	if (substr == NULL)
		return (NULL);
	i = 0;
	while (s[start] != 0 && substr_len > i)
		substr[i++] = s[start++];
	substr[i] = '\0';
	return (substr);
}

size_t	ft_strlen(const char *str)
{
	size_t	count;

	count = 0;
	while (str[count] != 0)
		count++;
	return (count);
}
