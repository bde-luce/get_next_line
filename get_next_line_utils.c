/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-luce <bde-luce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 16:14:08 by bde-luce          #+#    #+#             */
/*   Updated: 2024/06/26 13:20:27 by bde-luce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	check_nl(char *buf)
{
	int	i;

	i = 0;
	if (!buf)
		return (0);
	while (buf[i])
	{
		if (buf[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

size_t	str_len(char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

char	*join_buf(char *rest, char *buf)
{
	char	*str;
	size_t		i;
	size_t		j;

	if (!rest)
	{
		rest = malloc(sizeof(char) * 1);
		if (!rest)
			return (NULL);
		rest[0] = '\0';
	}
	if (!buf)
		return (NULL);
	str = malloc(sizeof(char) * (str_len(rest) + str_len(buf) + 1));
	if (!str)
		return (NULL);
	i = -1;
	while (rest[++i])
		str[i] = rest[i];
	j = 0;
	while (buf[j])
		str[i++] = buf[j++];
	str[i] = '\0';
	free(rest);
	return (str);
}

char	*get_line(char *rest)
{
	int		i;
	int		b;
	char	*str;

	i = 0;
	if (!rest[i])
		return (NULL);
	while (rest[i] && rest[i] != '\n')
		i++;
	b = 1;
	if (rest[i] == '\n')
		b = 2;
	str = malloc(sizeof(char) * (i + b));
	if (!str)
		return (NULL);
	i = 0;
	while (rest[i] && rest[i] != '\n')
	{
		str[i] = rest[i];
		i++;
	}
	if (rest[i] == '\n')
		str[i++] = '\n';
	str[i] = '\0';
	return (str);
}

char	*get_rest(char *rest)
{
	int		i;
	int		j;
	char	*new_rest;

	i = 0;
	while (rest[i])
		i++;
	j = 0;
	while (rest[j] && rest[j] != '\n')
		j++;
	if (rest[j] == '\n')
		j++;
	new_rest = malloc(sizeof(char) * (i - j + 1));
	if (!new_rest)
		return (NULL);
	i = 0;
	while (rest[j])
		new_rest[i++] = rest[j++];
	new_rest[i] = '\0';
	free(rest);
	return (new_rest);
}
