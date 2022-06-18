/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_lines.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lalex <lalex@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 01:10:24 by lalex             #+#    #+#             */
/*   Updated: 2022/06/18 20:20:32 by lalex            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "so_long_map.h"
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <errno.h>

static t_list	*read_map_lines(int fd)
{
	char	*line;
	t_list	*lst;
	t_list	*new;

	line = get_next_line(fd);
	new = NULL;
	lst = NULL;
	while (line)
	{
		new = ft_lstnew(line);
		if (!new)
			break ;
		ft_lstadd_back(&lst, new);
		line = get_next_line(fd);
	}
	if (line && !new)
	{
		ft_printf("Error\n%s\n", MAP_READ_ERR);
		free(line);
		ft_lstclear(&lst, &free);
	}
	else if (!line && !lst)
		ft_printf("Error\n%s: %s\n", MAP_READ_ERR, strerror(errno));
	return (lst);
}

static void	remove_endlines(t_list *lst)
{
	size_t	len;
	char	*line;

	while (lst)
	{
		line = lst->content;
		lst = lst->next;
		len = ft_strlen(line);
		if (!len)
			continue ;
		if (line[len - 1] == '\n')
			line[len - 1] = '\0';
	}
}

t_list	*get_map_lines(const char *file)
{
	t_list	*lst;
	int		fd;

	fd = open(file, O_RDONLY);
	if (fd < 0)
	{
		ft_printf("Error\n%s: %s: %s\n", MAP_FILE_ERR, file, strerror(errno));
		return (NULL);
	}
	lst = read_map_lines(fd);
	remove_endlines(lst);
	close(fd);
	return (lst);
}
