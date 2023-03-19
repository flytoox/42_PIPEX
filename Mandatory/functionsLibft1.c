/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functionsLibft1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelaizi <obelaizi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 11:21:56 by obelaizi          #+#    #+#             */
/*   Updated: 2023/03/09 16:29:16 by obelaizi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

size_t	ft_strlen(const char *s)
{
	size_t	count;

	count = 0;
	while (s[count])
		count++;
	return (count);
}

int	ft_strncmp(const char *s1, const char *s2, size_t size)
{
	unsigned char	*str1;
	unsigned char	*str2;

	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	if (!size)
		return (0);
	if (!*str1 || !*str2)
		return (*str1 - *str2);
	while (size-- && (*str1 || *str2))
	{
		if (*str1 != *str2)
			return (*str1 - *str2);
		str1++;
		str2++;
	}
	return (0);
}

void	ft_print(const char *s, int fd)
{
	if (!s)
		return ;
	write(fd, s, ft_strlen(s));
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*result;
	size_t	size;
	size_t	i;
	int		j;

	if (!s1 || !s2)
		return (0);
	i = 0;
	j = 0;
	size = ft_strlen(s1) + ft_strlen(s2);
	result = malloc(size + 1);
	if (!result)
		return (0);
	while (i < size)
	{
		while (i < ft_strlen(s1))
		{
			result[i] = s1[i];
			i++;
		}
		if (!(*s2))
			break ;
		result[i++] = s2[j++];
	}
	return (result[i] = 0, result);
}
