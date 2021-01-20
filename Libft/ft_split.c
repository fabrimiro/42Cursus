/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_def.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmiranda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 19:17:57 by fmiranda          #+#    #+#             */
/*   Updated: 2021/01/18 18:11:51 by fmiranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_find_char(char const *s, char c)
{
	int		i;
	int		k;

	i = 0;
	k = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
			k++;
		i++;
	}
	return (k);
}

int		ft_empty_str(char const *s, char c)
{
	int		i;
	int		k;
	int		l;

	i = 0;
	k = 0;
	l = ft_strlen(s) - 1;
	while (s[i] != '\0')
	{
		if (s[i] == c)
			k++;
		i++;
	}
	if (k == (l + 1))
		k = -1;
	return (k);
}

char	**ft_split2(char const *s, char c, char **mat, int x)
{
	int		k;
	int		y;

	y = 0;
	k = 0;
	while (s[y] != '\0')
	{
		if (s[y] != c)
		{
			mat[x][k] = s[y];
			k++;
		}
		else if (s[y] == c && s[y + 1] != c && s[y + 1] != '\0')
		{
			mat[x][k] = '\0';
			k = 0;
			x++;
		}
		else if (s[y] == c && s[y + 1] != c && s[y + 1] == '\0')
			mat[x + 1] = NULL;
		y++;
	}
	mat[x + 1] = NULL;
	return (mat);
}

char	**ft_split3(void)
{
	char **mat;

	mat = malloc(sizeof(char *) * 1);
	mat[0] = malloc(sizeof(char) * 1);
	mat[0] = NULL;
	return (mat);
}

char	**ft_split(char const *s, char c)
{
	char	**mat;
	int		k;
	int		i;
	int		y;

	i = 0;
	y = 0;
	k = ft_find_char(s, c);
	if (ft_empty_str(s, c) == -1)
		return (ft_split3());
	if (NULL == (mat = malloc(sizeof(char *) * (k + 2))))
		return (NULL);
	while (i < (k + 2))
	{
		if (NULL == (mat[i] = malloc(sizeof(char) * 100)))
			return (NULL);
		i++;
	}
	while (s[y] == c)
		y++;
	return (ft_split2(&s[y], c, mat, 0));
}
