/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-moue <hel-moue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 16:52:53 by hel-moue          #+#    #+#             */
/*   Updated: 2024/01/14 04:18:55 by hel-moue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*
** 1- read the file and store it in the buffer
** 2- check if the buffer contains a new line
** 3- if it does, store the line in the buffer
** 4- store the rest of the buffer in the save
** 5- return the buffer
*/

// the fonction that read the file and store it in the buffer
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

// the fonction that check if the buffer contains a new line
char	*sacond_fonction(char *save)
{
	char	*buffer;
	int		len;

	len = 0;
	if (!save || !save[len]) 
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

// the fonction that store the rest of the buffer in the save
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

// the main fonction
char	*get_next_line(int fd)
{
	static char	*save;
	char		*buffer;

	if (BUFFER_SIZE <= 0)
		return (0);
	save = (char *)first_fonction(fd, save);
	if (!save)
	{
		free(save);
		return (NULL);
	}
	buffer = sacond_fonction(save);
	save = save_fonction(save);
	return (buffer);
}
