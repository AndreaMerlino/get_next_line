/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andreamerlino <andreamerlino@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 10:51:06 by andreamerli       #+#    #+#             */
/*   Updated: 2023/12/06 20:52:33 by andreamerli      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_calloc(size_t count, size_t size)
{
	void		*ptr;
	size_t		bytes;

	bytes = count * size;
	ptr = malloc(bytes);
	if (!ptr)
		return (NULL);
	while (bytes--)
		((char *)ptr)[bytes] = 0;
	return (ptr);
}

char	*temp(char **contenitore, char **buffer, int a)
{
	char	*temp;

	if (*contenitore)
	{
		temp = ft_calloc(ft_strlen(*contenitore) + a + 1, 1);
		ft_strlcpy(temp, *contenitore, ft_strlen(*contenitore) + 1);
		ft_strlcat(temp, *buffer, a + 1);
		free (*contenitore);
	}
	else
	{
		temp = ft_calloc(a + 1, 1);
		ft_strlcpy(temp, *buffer, a + 1);
	}
	return (temp);
}

char	*subline(char ***c)
{
	char	*nextline;

	nextline = ft_calloc(ft_strlen(**c) + 1, 1);
	ft_strlcpy(nextline, **c, ft_strlen(**c) + 1);
	free (**c);
	**c = NULL;
	return (nextline);
}

char	*line(char **c, char **t, int a)
{
	int		b;
	char	*nextline;

	nextline = NULL;
	b = newline(*c);
	if (b != -1)
	{
		nextline = ft_calloc(b + 2, 1);
		ft_strlcpy(nextline, *c, b + 1);
		nextline[b] = '\n';
		nextline[b + 1] = '\0';
		free (*c);
		*c = ft_substr(*t, b + 1, ft_strlen(*t) - b);
		free (*t);
		return (nextline);
	}
	else if (a == 0 && **c != '\0')
	{
		free (*t);
		nextline = subline(&c);
		return (nextline);
	}
	return (nextline);
}

char	*get_next_line(int fd)
{
	int			a;
	char		*buffer;
	static char	*contenitore;
	char		*nextline;
	char		*temporaneo;

	temporaneo = NULL;
	a = 1;
	while (a != 0)
	{
		buffer = ft_calloc(BUFFER_SIZE, 1);
		a = read (fd, buffer, BUFFER_SIZE);
		if (a == -1)
		{
			free(buffer);
			return (NULL);
		}
		if (temporaneo != NULL)
			free (temporaneo);
		temporaneo = temp(&contenitore, &buffer, a);
		contenitore = ft_calloc(ft_strlen(temporaneo) + 1, 1);
		ft_strlcpy(contenitore, temporaneo, ft_strlen(temporaneo) + 1);
		free (buffer);
		nextline = line(&contenitore, &temporaneo, a);
		if (nextline != NULL)
			return (nextline);
	}

	return (NULL);
}
