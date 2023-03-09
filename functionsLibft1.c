/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functionsLibft1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelaizi <obelaizi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 11:21:56 by obelaizi          #+#    #+#             */
/*   Updated: 2023/03/09 11:33:09 by obelaizi         ###   ########.fr       */
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
