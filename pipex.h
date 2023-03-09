/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelaizi <obelaizi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 16:55:36 by obelaizi          #+#    #+#             */
/*   Updated: 2023/03/09 11:33:17 by obelaizi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H


# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>

int		ft_strncmp(const char *s1, const char *s2, size_t size);
char	**ft_split(const char *str, char c);
size_t	ft_strlen(const char *s);
void	ft_print(const char *s, int fd);


char	*get_path(char **env);
int		handle_parsing(char **argv, int argc);

#endif