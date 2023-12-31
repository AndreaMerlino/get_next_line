/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andreamerlino <andreamerlino@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 10:51:06 by andreamerli       #+#    #+#             */
/*   Updated: 2023/12/14 14:26:59 by andreamerli      ###   ########.fr       */
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
	*contenitore = ft_calloc(ft_strlen(temp) + 1, 1);
	ft_strlcpy(*contenitore, temp, ft_strlen(temp) + 1);
	free (*buffer);
	return (temp);
}

char	*subline(char ***c, char ***t, char ***nextline, int b)
{
	if (b != -1)
	{
		**nextline = ft_calloc(b + 2, 1);
		ft_strlcpy(**nextline, **c, b + 1);
		(**nextline)[b] = '\n';
		(**nextline)[b +1] = '\0';
		free (**c);
		**c = ft_substr(**t, b + 1, ft_strlen(**t) - b);
		free (**t);
		return (**nextline);
	}
	**nextline = ft_calloc(ft_strlen(**c) + 1, 1);
	ft_strlcpy(**nextline, **c, ft_strlen(**c) + 1);
	free (**c);
	**c = NULL;
	return (**nextline);
}

char	*line(char **c, char **t, char **nextline, int a)
{
	int		b;

	b = newline(*c);
	if (b != -1)
	{
		*nextline = subline(&c, &t, &nextline, b);
		return (*nextline);
	}
	else if (a == 0 && **c != '\0')
	{
		free (*t);
		*nextline = subline(&c, &t, &nextline, b);
		return (*nextline);
	}
	if (*t != NULL)
	{
		free(*t);
		*t = NULL;
	}
	if (a == 0 && **c == '\0')
	{
		free (*c);
		*c = NULL;
	}
	return (NULL);
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
		nextline = line(&contenitore, &temporaneo, &nextline, a);
		if (nextline != NULL)
			return (nextline);
	}
	return (NULL);
}
