/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andreamerlino <andreamerlino@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 10:51:06 by andreamerli       #+#    #+#             */
/*   Updated: 2023/12/15 16:41:04 by andreamerli      ###   ########.fr       */
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

char	*temp(char **contenitore, char **buffer, int a, int fd)
{
	char	*temp;

	temp = NULL;
	if (contenitore[fd])
	{
		temp = ft_calloc(ft_strlen(contenitore[fd]) + a + 1, 1);
		ft_strlcpy(temp, contenitore[fd], ft_strlen(contenitore[fd]) + 1);
		ft_strlcat(temp, *buffer, a + 1);
		free (contenitore[fd]);
	}
	else
	{
		temp = ft_calloc(a + 1, 1);
		ft_strlcpy(temp, *buffer, a + 1);
	}
	contenitore[fd] = ft_calloc(ft_strlen(temp) + 1, 1);
	ft_strlcpy(contenitore[fd], temp, ft_strlen(temp) + 1);
	free (*buffer);
	return (temp);
}

char	*subline(char **c, char **t, char **nextline, int fd)
{
	int		b;

	b = newline(c[fd]);
	if (b != -1)
	{
		*nextline = ft_calloc(b + 2, 1);
		ft_strlcpy(*nextline, c[fd], b + 1);
		(*nextline)[b] = '\n';
		(*nextline)[b +1] = '\0';
		free (c[fd]);
		c[fd] = ft_substr(*t, b + 1, ft_strlen(*t) - b);
		free (*t);
		return (*nextline);
	}
	return (NULL);
}

char	*line(char **c, char **t, char **nextline, int a, int fd)
{
	if (a == 0 && *c[fd] != '\0')
	{
	*nextline = ft_calloc(ft_strlen(c[fd]) + 1, 1);
	ft_strlcpy(*nextline, c[fd], ft_strlen(c[fd]) + 1);
	free (c[fd]);
	c[fd] = NULL;
	return (*nextline);
	}
	if (*t != NULL)
	{
		free(*t);
		*t = NULL;
	}
	if (a == 0 && *c[fd] == '\0')
	{
		free (c[fd]);
		c[fd] = NULL;
	}
	return (NULL);
}

char	*get_next_line(int fd)
{
	int			a;
	char		*buffer;
	static char	*contenitore[4096];
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
		temporaneo = temp(&contenitore[fd], &buffer, a, fd);
		nextline = subline(&contenitore[fd], &temporaneo, &nextline, fd);
		if (nextline != NULL)
			return (nextline);
		nextline = line(&contenitore[fd], &temporaneo, &nextline, a, fd);
		if (nextline != NULL)
			return (nextline);
	}
	return (NULL);
}
