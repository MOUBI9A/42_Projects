/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-moue <hel-moue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 16:52:53 by hel-moue          #+#    #+#             */
/*   Updated: 2022/12/26 19:17:37 by hel-moue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*first_fonction(int fd, char *save)
{
	char	*buffer;
	int		rdlen;

	rdlen = 1;
	buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	while (ft_strchr(save, '\n') == (-1) && rdlen != 0)
	{
		rdlen = (int)read(fd, buffer, BUFFER_SIZE);
		if (rdlen == -1)
		{
			free(save);
			free(buffer);
			return (0);
		}
		buffer[rdlen] = '\0';
		save = (char *)ft_strjoin(save, buffer);
	}
	free(buffer);
	return (save);
}

char	*sacond_fonction(char *save)
{
	char	*buffer;
	int		len;

	len = 0;
	if (!save[len])
		return (NULL);
	while (save[len] != '\0' && save[len] != '\n')
		len++;
	buffer = (char *)malloc(sizeof(char) * (len + 2));
	if (!buffer)
		return (NULL);
	len = 0;
	while (save[len] && save[len] != '\n')
	{
		buffer[len] = save[len];
		len++;
	}
	if (save[len] == '\n')
	{
		buffer[len] = save[len];
		len++;
	}
	buffer[len] = '\0';
	return (buffer);
}

char	*save_fonction(char *all)
{
	char	*save;
	int		len;
	int		j;

	len = 0;
	while (all[len] && all[len] != '\n')
		len++;
	if (!all[len])
	{
		free(all);
		return (NULL);
	}
	save = (char *)malloc(sizeof(char) * (ft_strlen(all) - len + 1));
	if (!save)
		return (NULL);
	len++;
	j = 0;
	while (all[len])
		save[j++] = all[len++];
	free(all);
	save[j] = '\0';
	return (save);
}

char	*get_next_line(int fd)
{
	static char	*save[OPEN_MAX];
	char		*buffer;

	if (BUFFER_SIZE <= 0)
		return (0);
	save[fd] = (char *)first_fonction(fd, save[fd]);
	if (!save[fd])
	{
		free(save[fd]);
		return (NULL);
	}
	buffer = sacond_fonction(save[fd]);
	save[fd] = save_fonction(save[fd]);
	return (buffer);
}
