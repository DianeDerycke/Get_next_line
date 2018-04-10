/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: DERYCKE <DERYCKE@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 21:54:55 by dideryck          #+#    #+#             */
/*   Updated: 2018/04/10 18:34:30 by DERYCKE          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(const char *s1, const char *s2)
{
	char			*str;

	str = 0;
	if (s1 == NULL || s2 == NULL)
		return (NULL);
	str = (char*)ft_memalloc(sizeof(char) * ((ft_strlen(s1) + ft_strlen(s2) + 1)));
	if (str == NULL)
		return (NULL);
	str = ft_strcat(str, s1);
	str = ft_strcat(str, s2);
	return (str);
}
