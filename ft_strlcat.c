/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamartin <pamartin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/31 19:39:40 by pamartin          #+#    #+#             */
/*   Updated: 2021/12/31 19:39:41 by pamartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	len(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	len_dst;
	size_t	len_src;
	size_t	i;
	size_t	rslt;
	size_t	y;

	len_dst = len(dst);
	len_src = len(src);
	rslt = 0;
	i = 0;
	if (dstsize > len_dst)
		rslt = len_src + len_dst;
	else
		rslt = len_src + dstsize;
	y = len_dst;
	while (src[i] && (y + 1) < dstsize)
	{
		dst[y] = src[i];
		i++;
		y++;
	}
	dst[y] = '\0';
	return (rslt);
}
/*
#include <stdio.h>

int main(int argc, char **argv)
{
    argc++;
    printf("my strlcat   : %lu \n", ft_strlcat(argv[1], argv[2], atoi(argv[3])));
    printf("real strlcat : %lu \n", strlcat(argv[1], argv[2], atoi(argv[3])));
}*/
