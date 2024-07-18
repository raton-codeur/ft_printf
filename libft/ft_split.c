/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhauuy <qhauuy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 18:46:46 by qhauuy            #+#    #+#             */
/*   Updated: 2023/11/30 03:15:32 by qhauuy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned int	ft_length(const char *s, char c)
{
	unsigned int	result;
	int				condition;

	result = 0;
	condition = (*s == c);
	while (*s && ((*s == c) == condition))
	{
		result++;
		s++;
	}
	return (result);
}

static unsigned int	ft_count_words(char const *s, char c)
{
	unsigned int	result;

	result = 0;
	if (*s == c)
		s += ft_length(s, c);
	while (*s)
	{
		s += ft_length(s, c);
		s += ft_length(s, c);
		result++;
	}
	return (result);
}

static char	**ft_free(char **result, unsigned int i)
{
	unsigned int	j;

	j = 0;
	while (j < i)
		free(result[j++]);
	free(result);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char			**result;
	unsigned int	i;

	if (s == NULL)
		return (NULL);
	result = malloc(sizeof(char *) * (ft_count_words(s, c) + 1));
	if (result == NULL)
		return (NULL);
	if (*s == c)
		s += ft_length(s, c);
	i = 0;
	while (*s)
	{
		result[i] = malloc(sizeof(char) * (ft_length(s, c) + 1));
		if (result[i] == NULL)
			return (ft_free(result, i));
		ft_strlcpy(result[i++], s, ft_length(s, c) + 1);
		s += ft_length(s, c);
		s += ft_length(s, c);
	}
	result[i] = NULL;
	return (result);
}
