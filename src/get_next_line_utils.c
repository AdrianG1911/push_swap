/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrgutie <adrgutie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 16:37:02 by adrgutie          #+#    #+#             */
/*   Updated: 2024/08/31 17:24:01 by adrgutie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*free_ft_substr(char **s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	slen;

	if (!(*s))
		return (NULL);
	slen = ft_strlen(*s);
	if (slen < start)
		len = 0;
	else if (len > slen)
		len = slen;
	sub = (char *)malloc(len + 1);
	if (!sub)
		return (freeptr(s, NULL, NULL), NULL);
	if (start >= slen)
		start = slen;
	if (slen - start < len)
		len = slen - start;
	ft_strlcpy(sub, (*s) + start, len + 1);
	return (sub);
}

char	*free_ft_strjoin(char **s1, char **s2)
{
	char	*newstr;
	size_t	s1len;
	size_t	s2len;

	if (!(*s1) || !(*s2))
		return (freeptr(s1, s2, NULL), NULL);
	s1len = ft_strlen(*s1);
	s2len = ft_strlen(*s2);
	newstr = (char *)malloc(s1len + s2len + 1);
	if (!newstr)
		return (freeptr(s1, s2, NULL), NULL);
	ft_strlcpy(newstr, *s1, s1len + 1);
	ft_strlcpy(newstr + s1len, *s2, s2len + 1);
	return (freeptr(s1, s2, NULL), newstr);
}
