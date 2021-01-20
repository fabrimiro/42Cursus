/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmiranda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 11:07:53 by fmiranda          #+#    #+#             */
/*   Updated: 2021/01/20 11:07:55 by fmiranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	s1;
	size_t	s2;
	size_t	x;
	size_t	y;

	s1 = ft_strlen(dst);
	s2 = ft_strlen(src);
	x = s1;
	y = 0;
	if (s1 < dstsize - 1 && dstsize > 0)
	{
		while (src[y] != '\0' && (s1 + y) < (dstsize - 1))
		{
			dst[x] = src[y];
			x++;
			y++;
		}
		dst[x] = '\0';
	}
	if (s1 >= dstsize)
		s1 = dstsize;
	return (s1 + s2);
}
