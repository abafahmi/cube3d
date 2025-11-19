/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abafahmi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 21:19:40 by abafahmi          #+#    #+#             */
/*   Updated: 2024/11/08 20:13:32 by abafahmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	slen;

	slen = ft_strlen(s);
	while (slen > 0)
	{
		if (s[slen] == (char)c)
			return ((char *)&s[slen]);
		slen--;
	}
	if (s[slen] == (char)c)
		return ((char *)&s[slen]);
	return (NULL);
}
/*
int	main()
{
	char c = 'v';
	const char s[] = "abvshudbdvdjjdj";
	char *v = ft_strrchr(s, c);
	printf("%s\n", v);
}*/
