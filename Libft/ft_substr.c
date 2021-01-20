/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmiranda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 11:11:31 by fmiranda          #+#    #+#             */
/*   Updated: 2021/01/20 11:11:32 by fmiranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*final;
	size_t			x;
	size_t			y;

	x = 0;
	y = 0;
	if (!(final = (char *)malloc(sizeof(char) * len + 1)))
		return (NULL);
	while (s[x])
	{
		if (x >= start && y < len)
		{
			final[y] = s[x];
			y++;
		}
		x++;
	}
	final[y] = '\0';
	return (final);
}
