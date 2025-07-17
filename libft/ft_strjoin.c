/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taewonki <@student.42gyeongsan.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 12:22:45 by taewonki          #+#    #+#             */
/*   Updated: 2025/04/12 15:53:22 by taewonki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	nstr_len;
	size_t	i;
	char	*nstr;
	char	*result;

	i = 0;
	if (!s1 || !s2)
		return (NULL);
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
