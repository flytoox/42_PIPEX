/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelaizi <obelaizi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 17:33:39 by obelaizi          #+#    #+#             */
/*   Updated: 2023/03/09 11:09:42 by obelaizi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	free_str(char **str)
{
	int		i;

	i = -1;
	while (str[++i])
		free(str[i]);
	free(str);
}

int	count_words(const char *str, char c)
{
	int	count;

	count = 1;
	while (*str)
	{
		if (*str == c && *(str + 1) && *(str + 1) != c)
			count++;
		str++;
	}
	return (count);
}

int	word_len(const char *str, char c)
{
	int	len;

	len = 0;
	while (*str && *str != c)
	{
		len++;
		str++;
	}
	return (len);
}

char	**fill_it(const char *str, char c, int words)
{
	char	**res;
	int		i;
	int		j;

	i = -1;
	res = malloc(sizeof(char *) * (words + 1));
	if (!res)
		return (NULL);
	while (*str)
	{
		j = 0;
		if (*str != c)
		{
			res[++i] = malloc(word_len(str, c) + 1);
			if (!res[i])
				return (free_str(res), NULL);
			while (*str && *str != c)
				res[i][j++] = *(str++);
			res[i][j] = 0;
		}
		else
			str++;
	}
	return (res[words] = NULL, res);
}

char	**ft_split(const char *str, char c)
{
	while (str && *str && *str == c)
		str++;
	if (!str ||!(*str))
		return (NULL);
	return (fill_it(str, c, count_words(str, c)));
}
