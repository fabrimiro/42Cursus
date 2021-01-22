/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmiranda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/22 11:09:07 by fmiranda          #+#    #+#             */
/*   Updated: 2021/01/22 11:09:35 by fmiranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_free_mat(char **mat, int size)
{
	while (size--)
		free(mat[size]);
	return (0);
}

int		ft_count_words(const char *s, char c)
{
	int	i;
	int	numwords;

	numwords = 0;
	i = 0;
	while (s[i] != '\0')
	{
		if ((s[i + 1] == c || s[i + 1] == '\0') == 1
				&& (s[i] == c || s[i] == '\0') == 0)
			numwords++;
		i++;
	}
	return (numwords);
}

void	write_word(char *s1, const char *s2, char c)
{
	int	i;

	i = 0;
	while ((s2[i] == c || s2[i] == '\0') == 0)
	{
		s1[i] = s2[i];
		i++;
	}
	s1[i] = '\0';
}

int		ft_split2(char **split, const char *s, char c)
{
	int		i;
	int		j;
	int		word;

	word = 0;
	i = 0;
	while (s[i] != '\0')
	{
		if ((s[i] == c || s[i] == '\0') == 1)
			i++;
		else
		{
			j = 0;
			while ((s[i + j] == c || s[i + j] == '\0') == 0)
				j++;
			if ((split[word] = (char*)malloc(sizeof(char) * (j + 1))) == NULL)
				return (ft_free_mat(split, word - 1));
			write_word(split[word], s + i, c);
			i += j;
			word++;
		}
	}
	return (0);
}

char	**ft_split(const char *s, char c)
{
	char	**mat;
	int		numwords;

	numwords = ft_count_words(s, c);
	if ((mat = (char**)malloc(sizeof(char*) * (numwords + 1))) == NULL)
		return (NULL);
	mat[numwords] = 0;
	if (ft_split2(mat, s, c) == -1)
		return (NULL);
	return (mat);
}
