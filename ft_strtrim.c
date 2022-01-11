/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 14:43:03 by pamartin          #+#    #+#             */
/*   Updated: 2022/01/11 14:43:05 by pamartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_char_is_charset(char c, const char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	if (str[i] == c)
		return (1);
	return (0);
}

static size_t	ft_start(const char *str, const char *trim)
{
	size_t	i;

	i = 0;
	while (ft_char_is_charset(str[i], trim) == 1)
		i++;
	return (i);
}

static size_t	ft_end(const char *str, const char *trim)
{
	size_t	i;

	i = ft_strlen(str) - 1;
	while (ft_char_is_charset(str[i], trim) == 1)
		i--;
	return (i);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t		start;
	size_t		end;
	char		*trim;

	if (!s1 || !set)
		return (0);
	start = ft_start(s1, set);
	end = ft_end(s1, set);
	if (end < start)
		return (ft_strdup(""));
	trim = ft_substr(s1, start, (end - start) + 1);
	return (trim);
}
/*
#include <stdio.h>

int main(void)
{
	char *str = "zzzz bonjour zzzz";
    char *set = "z ";
	printf("%s \n", ft_strtrim(str, set));
}*/