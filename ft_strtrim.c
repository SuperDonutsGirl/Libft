/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamartin <pamartin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/23 16:30:59 by pamartin          #+#    #+#             */
/*   Updated: 2021/12/23 16:31:00 by pamartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_char_is_charset(const char *str, char c)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

static int	ft_start(const char *str, const char *trim)
{
	int	i;

	i = 0;
	while (str[i] && ft_char_is_charset(trim, str[i]) == 1)
		i++;
	return (i);
}

static int	ft_end(const char *str, const char *trim)
{
	size_t	i;

	i = ft_strlen(str) - 1;
	while (str[i] && ft_char_is_charset(trim, str[i]) == 1)
		i--;
	return (i);
}

static size_t	ft_white_space(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] == '\t' || str[i] == '\n' || str[i] == '\v' || str[i] == '\f'
		|| str[i] == '\r' || str[i] == ' ')
		i++;
	return (i);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		start;
	int		end;
	int		i;
	char	*trim;

	if (!s1 || !set)
		return (0);
	start = ft_start(s1, set);
	end = ft_end(s1, set);
	if (ft_strlen(s1) == ft_white_space(s1)
		&& ft_strlen(set) == ft_white_space(set))
	{
		trim = "\0";
		return (trim);
	}
	trim = (char *)malloc(sizeof(char) * (end - start + 1) + 1);
	if (!trim)
		return (0);
	i = 0;
	while (start <= end)
		trim[i++] = s1[start++];
	trim[i] = '\0';
	return (trim);
}

/*#include <stdio.h>

int main(int argc, char **argv)
{
	argc++;
	printf("%s \n", ft_strtrim(argv[1], argv[2]));
}*/