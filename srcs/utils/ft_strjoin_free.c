/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_free.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 22:26:06 by adelille          #+#    #+#             */
/*   Updated: 2021/12/02 22:29:54 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/bsq.h"

static int	ft_strcpy(char *dst, const char *src)
{
	int	i;
	int	size;

	i = 0;
	size = ft_strlen(src);
	while (i < size && src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (i);
}

char	*ft_strjoin_free(char *s1, char *s2, bool const f1, bool const f2)
{
	char	*res;

	res = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!res)
		return (NULL);
	ft_strcpy(res, s1);
	ft_strcpy(&res[ft_strlen(s1)], s2);
	if (f1 == true)
		free(s1);
	if (f2 == true)
		free(s2);
	return (res);
}
