/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
<<<<<<< HEAD
/*   By: taewonki <@student.42gyeongsan.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 15:43:25 by taewonki          #+#    #+#             */
/*   Updated: 2025/04/17 10:11:33 by taewonki         ###   ########.fr       */
=======
/*   By: taewonki <taewonki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 15:43:25 by taewonki          #+#    #+#             */
/*   Updated: 2025/06/05 12:46:20 by taewonki         ###   ########.fr       */
>>>>>>> 64d55ee6a554b27d829ee9f5920984fc9fac63f4
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

<<<<<<< HEAD
static size_t	word_num(char *str, char c)
{
	size_t	i;
	size_t	word;
	size_t	str_len;

	i = 0;
	word = 0;
	str_len = ft_strlen(str);
	while (str[i] != 0 && i + 1 < str_len)
	{
		if (str[i] == c && str[i + 1] != c)
			word++;
		i++;
	}
	if (str[0] != c && str[0] != '\0')
		word++;
	return (word);
}

=======
static size_t word_num(char *str, char c)
{
	size_t	i;
	size_t	word;
	int		in_word;

	i = 0;
	word = 0;
	in_word = 0;
	while (str[i])
	{
		if (str[i] != c && in_word == 0)
		{
			in_word = 1;
			word++;
		}
		else if (str[i] == c)
		{
			in_word = 0;
		}
		i++;
	}
	return word;
}


>>>>>>> 64d55ee6a554b27d829ee9f5920984fc9fac63f4
static void	arr_free(char **nstr_arr, size_t i)
{
	while (i--)
		free(nstr_arr[i]);
	free(nstr_arr);
}

static size_t	get_len(char *ptr, char c)
{
	char	*end;

	end = ft_strchr(ptr, c);
	if (end)
		return (end - ptr);
	else
		return (ft_strlen(ptr));
}

<<<<<<< HEAD
static void	assign_val(char **nstr_arr, char *s, size_t word, char c)
=======
static int	assign_val(char **nstr_arr, char *s, size_t word, char c)
>>>>>>> 64d55ee6a554b27d829ee9f5920984fc9fac63f4
{
	char	*start;
	size_t	len;
	size_t	i;

	start = s;
	i = 0;
	while (*start && i < word)
	{
		while (*start == c)
			start++;
		len = get_len(start, c);
		nstr_arr[i] = malloc(len + 1);
		if (nstr_arr[i] == NULL)
<<<<<<< HEAD
			arr_free(nstr_arr, i);
		if (nstr_arr[i] == NULL)
			return ;
=======
		{
			arr_free(nstr_arr, i);
			return (1);
		}
>>>>>>> 64d55ee6a554b27d829ee9f5920984fc9fac63f4
		ft_strlcpy(nstr_arr[i], start, len + 1);
		start += len;
		i++;
	}
<<<<<<< HEAD
=======
	return (0);
>>>>>>> 64d55ee6a554b27d829ee9f5920984fc9fac63f4
}

char	**ft_split(char const *s, char c)
{
	char	*temp;
	char	**nstr_arr;
	size_t	word;

	if (s == NULL)
		return (NULL);
	temp = (char *)s;
<<<<<<< HEAD
	while (*temp == c)
=======
	while (*temp && *temp == c)
>>>>>>> 64d55ee6a554b27d829ee9f5920984fc9fac63f4
		temp++;
	word = word_num(temp, c);
	nstr_arr = malloc((word + 1) * sizeof(char *));
	if (nstr_arr == NULL)
		return (NULL);
<<<<<<< HEAD
	assign_val(nstr_arr, temp, word, c);
=======
	if (assign_val(nstr_arr, temp, word, c))
		return (NULL);
>>>>>>> 64d55ee6a554b27d829ee9f5920984fc9fac63f4
	nstr_arr[word] = NULL;
	return (nstr_arr);
}
