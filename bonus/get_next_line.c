/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-hss <aben-hss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 16:30:18 by aben-hss          #+#    #+#             */
/*   Updated: 2024/07/28 00:33:32 by aben-hss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "checker.h"

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 4
#endif

char	*join_strings(char *s1, char *s2)
{
	char	*data;

	if (!s1 && s2)
		return (s2);
	if (!*s2)
		return (free(s2), s1);
	data = (char *) malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!data)
		return (free(s1), free(s2), s1 = NULL, NULL);
	ft_strcpy(data, s1);
	ft_strcat(data, s2);
	free(s1);
	free(s2);
	return (data);
}

char	*extract_line(char *str)
{
	char	*line;
	int		size;
	int		i;

	size = 0;
	if (!str)
		return (NULL);
	while (str[size] && str[size] != '\n')
		size++;
	if (str[size] == '\n')
		size++;
	line = malloc(sizeof(char) * (size + 1));
	if (!line)
		return (NULL);
	i = 0;
	while (i < size && str[i])
	{
		line[i] = str[i];
		i++;
	}
	line[i] = '\0';
	if (!*line)
		return (free(line), NULL);
	return (line);
}

char	*extract_rest(char *str)
{
	int		i;
	int		j;
	char	*rest;

	i = 0;
	if (!str)
		return (NULL);
	if (!*str)
		return (free(str), str = NULL, NULL);
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i] == '\n')
		i++;
	rest = malloc(sizeof(char) * ft_strlen(str + i) + 1);
	if (!rest)
		return (free(str), str = NULL, NULL);
	j = 0;
	while (str[i])
		rest[j++] = str[i++];
	rest[j] = '\0';
	free(str);
	if (!rest[0])
		return (free(rest), NULL);
	return (rest);
}

char	*get_next_line(int fd)
{
	static char	*rest;
	char		*line;
	char		*buffer;
	ssize_t		n;

	line = NULL;
	if (BUFFER_SIZE <= 0 || fd < 0 || BUFFER_SIZE > INT_MAX)
		return (NULL);
	n = 1;
	while (n && !contains_new_line(rest))
	{
		buffer = (char *) malloc(sizeof(char) * ((size_t)BUFFER_SIZE + 1));
		if (!buffer)
			return (free(rest), rest = NULL, NULL);
		n = read(fd, buffer, BUFFER_SIZE);
		if (n < 0)
			return (free(buffer), free(rest), rest = NULL, NULL);
		buffer[n] = '\0';
		rest = join_strings(rest, buffer);
	}
	line = extract_line(rest);
	if (!line)
		return (free(rest), rest = NULL, NULL);
	rest = extract_rest(rest);
	return (line);
}
