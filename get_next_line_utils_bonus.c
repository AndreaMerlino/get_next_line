/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andreamerlino <andreamerlino@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 10:59:35 by andreamerli       #+#    #+#             */
/*   Updated: 2023/12/06 11:01:46 by andreamerli      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	newline(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

int	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_substr(char *s, int start, int len)
{
	char	*new;
	int		i;
	int		finish;

	i = 0;
	if (!s)
		return (NULL);
	finish = ft_strlen(s) - start;
	if (start >= ft_strlen(s))
		len = 0;
	else if (finish < len)
		len = finish;
	new = (char *)malloc(sizeof(char) * (len + 1));
	if (!new)
		return (NULL);
	while (i < len && s[start + i])
	{
		new[i] = s[start + i];
		i++;
	}
	new[i] = '\0';
	return (new);
}

char	*ft_strlcpy(char *dst, char *src, int dstsize)
{
	char	*s;
	int		i;

	i = 0;
	s = (char *)src;
	while ((i < dstsize - 1) && (*s != '\0'))
	{
		*dst++ = *s++;
		i++;
	}
	*dst = '\0';
	return (s - i);
}

char	*ft_strlcat(char *dst, char *src, int dstsize)
{
	int	lendst;

	if (!dst && !src)
		return (0);
	lendst = ft_strlen(dst);
	dst = ft_strlcpy((dst + lendst), src, (dstsize));
	return (dst - lendst);
}
