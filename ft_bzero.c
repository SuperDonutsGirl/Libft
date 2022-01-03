/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamartin <pamartin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 22:01:33 by pamartin          #+#    #+#             */
/*   Updated: 2021/12/17 22:01:39 by pamartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t			i;
	unsigned char	*str;

	i = 0;
	str = (unsigned char *)s;
	while (i < n)
	{
		str[i] = 0;
		i++;
	}
}

/*   MAIN NON FONCTIONNEL
#include <stdio.h>
#include <string.h>
#include "libft.h"


int main()
{
    void *s = "bonjour";
	size_t n = 4;

	const char *a = ft_bzero(s, n);
	const char *c = bzero(s, n);

    printf("my   bzero --> %d \n", a);
	printf("real bzero --> %d \n", c);
}*/