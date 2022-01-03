/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamartin <pamartin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/26 00:20:31 by pamartin          #+#    #+#             */
/*   Updated: 2021/12/26 00:20:33 by pamartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static void	*ft_free(char **split)
{
	unsigned int	i;

	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	return (NULL);
}

static char	**ft_count_words(char const *str, char c)
{
	int		count;
	int		i;
	char	**split;

	count = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] != c)
		{
			count++;
			while (str[i] && str[i] != c)
				i++;
		}
		else
			i++;
	}
	split = (char **)malloc(sizeof(char *) * (count + 1));
	return (split);
}

static int	ft_lenword(const char *str, char c)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != c)
		i++;
	return (i);
}

static int	ft_copy(char *dest, const char *str, char c, int i)
{
	int	j;

	j = 0;
	while (str[i] && str[i] != c)
	{
		dest[j] = str[i];
		i++;
		j++;
	}
	dest[j] = '\0';
	return (i);
}

char	**ft_split(char const *s, char c)
{
	char	**split;
	int		words;
	int		i;

	split = ft_count_words(s, c);
	if (!split)
		return (0);
	i = 0;
	words = 0;
	while (s[i])
	{
		if (s[i] == c)
			i++;
		else
		{
			split[words] = (char *)malloc(sizeof(char) * ft_lenword(s, c) + 1);
			if (!split[words])
				ft_free(split);
			i = ft_copy(split[words], s, c, i);
			words++;
		}
	}
	split[words] = 0;
	return (split);
}

/*#include <stdio.h>
int main(void)
{
	int i;
	char **split;
	char c;
	char	*str;

	c = 32;
	str = "1un 2deux 3trois 4quatre 5cinq";

	split = ft_split(str, c);
	i = 0;
	while (split[i])
	{
		printf("%s\n", split[i]);
		i++;
	}
}*/