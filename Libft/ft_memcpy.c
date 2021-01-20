/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmiranda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 11:03:30 by fmiranda          #+#    #+#             */
/*   Updated: 2021/01/20 11:03:32 by fmiranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t				x;
	unsigned char		*y;
	unsigned const char	*z;

	x = 0;
	y = dest;
	z = src;
	if (dest == NULL && src == NULL)
		return (NULL);
	while (n > 0)
	{
		y[x] = z[x];
		x++;
		n--;
	}
	return (dest);
}
