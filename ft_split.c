/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpeyre <gpeyre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 10:53:13 by gpeyre            #+#    #+#             */
/*   Updated: 2023/10/03 10:53:13 by gpeyre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	len_tab(char const *str, char c)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	while (str[i])
	{
		if (str[i] != c)
		{
			while (str[i] && str[i] != c)
				i++;
			len++;
		}
		while (str[i] && str[i] == c)
			i++;
	}
	return (len + 1);
}

static char	*get_next_word(int *index, char const *str, char c)
{
	char	*res;
	int		len;
	int		i;

	i = 0;
	len = 0;
	while ((str[*index] == c))
		(*index)++;
	while (str[*index + len] != c && str[*index + len])
		len++;
	if (len == 0)
		return (NULL);
	res = malloc((len + 1) * sizeof(char));
	while (i < len)
	{
		res[i] = str[*index];
		i++;
		(*index)++;
	}
	res[i] = 0;
	return (res);
}

char	**ft_split(char const *s, char c)
{
	char	**res;
	int		len;
	int		i;
	int		j;

	if (!s)
		return (NULL);
	len = len_tab(s, c);
	i = 0;
	j = 0;
	if (len == 0)
		return (NULL);
	res = malloc(len * sizeof(char *));
	if (!res)
		return (NULL);
	while (i < len - 1)
	{
		res[i] = get_next_word(&j, s, c);
		i++;
	}
	res[i] = 0;
	return (res);
}
/*#include <stdio.h>
int main(void)
{
	char const str[] = "  tripouille  42  ";
	char c = ' ';
	int len = len_tab(str, c);
	int i = 0;
	char** res;

	res = ft_split(str, c);

	while (i < len - 1)
	{
		printf("%s\n", res[i]);
		i++;
	}
	i = 0;
	while (i < len - 1)
	{
		free(res[i]);
		i++;
	}
	free(res);
}*/