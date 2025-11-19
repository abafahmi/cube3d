/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abafahmi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 13:51:31 by abafahmi          #+#    #+#             */
/*   Updated: 2024/11/10 14:55:02 by abafahmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	slen;
	size_t	dlen;
	size_t	s;
	size_t	d;

	slen = ft_strlen(src);
	if (dst == NULL && size == 0)
		return (slen);
	dlen = ft_strlen(dst);
	if (dlen >= size)
		return (size + slen);
	d = dlen;
	s = 0;
	while (src[s] && d + 1 < size)
	{
		dst[d] = src[s];
		s++;
		d++;
	}
	dst[d] = '\0';
	return (dlen + slen);
}
/*
int	main()
{
	char src[] = "abdelilah";
	char dst[5];
	size_t n = ft_strlcat(dst, src, 0);
	printf("n %zu\n", n);
	// printf("dst %s\n", dst);
	// printf("src %s\n", src);
}*/
