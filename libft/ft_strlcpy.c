/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abafahmi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 14:53:18 by abafahmi          #+#    #+#             */
/*   Updated: 2024/11/03 20:12:33 by abafahmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;
	int		s;

	i = 0;
	s = ft_strlen(src);
	if (size != 0)
	{
		while (src[i] && i < size - 1)
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (s);
}
/*
int	main()
{
	char src[] = "abdelilah";
	char dst[10] = "afahmi";
	
	size_t	b = strlcpy(dst, src, 5);
	printf("b %zu\n", b);
	printf("asrc %s\n", src);
	printf("adst %s\n", dst);
	int     n = ft_strlcpy(dst, src, 5);
	printf("%d\n", n);
	printf("src %s\n", src);
	printf("dst %s\n", dst);
}*/
