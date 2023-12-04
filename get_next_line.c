#ifndef BUFFER_SIZE
#define BUFFER_SIZE 1
#endif
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

char *get_next_line(int fd)
{
	int a;
	int b;
	char *buffer;
	static char *contenitore;
	char *nextline;
	char *temporaneo;

	temporaneo = NULL;
	a = 1;

	while(a != 0)
	{
		buffer = ft_calloc(BUFFER_SIZE , 1 );
		a = read (fd, buffer, BUFFER_SIZE);
		if (a == -1)
		return(NULL);

		if(contenitore)
		{
			if (temporaneo != NULL)
			free(temporaneo);
			temporaneo = ft_calloc(ft_strlen(contenitore)+ a + 1, 1);
			 ft_strlcpy(temporaneo, contenitore, ft_strlen(contenitore)+1);
			 ft_strlcat(temporaneo, buffer, a + 1);
			 free (contenitore);
		}
		else
		{
			temporaneo = ft_calloc( a + 1, 1);
			 ft_strlcpy(temporaneo, buffer, a + 1);
		}
		contenitore  = ft_calloc(ft_strlen(temporaneo)+1, 1);
		 ft_strlcpy(contenitore, temporaneo, ft_strlen(temporaneo )+ 1);
		b = newline(contenitore);
		free(buffer);
		if (b != -1 )
		{
			nextline = ft_calloc(b + 2, 1);
			 ft_strlcpy(nextline, contenitore, b +1 );
			nextline[b ] = '$';
			nextline[b + 1 ] = '\0';
			free (contenitore);
			contenitore = ft_substr(temporaneo, b +1 , ft_strlen(temporaneo) - b );
			free (temporaneo);
			return(nextline);
		}
		else if (a == 0 && *contenitore != '\0')
		{
			free (temporaneo);
		nextline = ft_calloc(ft_strlen(contenitore) + 1, 1);
		 ft_strlcpy(nextline, contenitore, ft_strlen(contenitore) +1 );
		 free (contenitore);
		 contenitore = NULL;
		 return(nextline);
		}
		}
		return(NULL);
}
