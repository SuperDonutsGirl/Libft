/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamartin <pamartin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/31 16:35:26 by pamartin          #+#    #+#             */
/*   Updated: 2021/12/31 16:35:27 by pamartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *restrict dst, const void *restrict src,
int c, size_t n)
{
	unsigned char	*dst_tempo;
	unsigned char	*src_tempo;
	size_t			i;

	dst_tempo = (unsigned char *)dst;
	src_tempo = (unsigned char *)src;
	i = 0;
	while (i < n)
	{
		dst_tempo[i] = src_tempo[i];
		if (src_tempo[i] == (unsigned char)c)
			return (dst + (i + 1));
		i++;
	}
	return (NULL);
}
/*
#include <stdio.h>
#include <string.h>

int main(int argc, char **argv)
{
	argc++;
	printf("my memccpy   : %s \n", ft_memccpy(argv[1], argv[2], atoi(argv[3]),
	atoi(argv[4])));
	printf("real memccpy : %s \n", memccpy(argv[1], argv[2], atoi(argv[3]),
	atoi(argv[4])));
}*/