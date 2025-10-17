/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abafahmi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 14:44:54 by abafahmi          #+#    #+#             */
/*   Updated: 2024/11/08 20:15:07 by abafahmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*d;

	d = (void *)malloc(nmemb * size);
	if (d == NULL)
		return (NULL);
	ft_bzero(d, (nmemb * size));
	return (d);
}
