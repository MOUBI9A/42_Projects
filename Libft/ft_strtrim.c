/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-moue <hel-moue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 18:32:59 by hel-moue          #+#    #+#             */
/*   Updated: 2023/04/09 02:46:03 by hel-moue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	int		first;
	int		last;

	last = 0;
	first = 0;
	if (!s1 || (s1[0] == '\0' && !set))
		return (NULL);
	while (s1[first] && ft_strchr(set, s1[first]))
		first++;
	last = (int)ft_strlen(s1);
	while (ft_strchr(set, s1[last]) && last > 0)
		last--;
	return (ft_substr(s1, first, (last - first) + 1));
}
