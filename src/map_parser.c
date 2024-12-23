/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asene <asene@student.42perpignan.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 20:56:44 by asene             #+#    #+#             */
/*   Updated: 2024/12/23 01:32:17 by asene            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

t_list	*parse_line(char *line, int y)
{
	int		i;
	char	**split;
	t_list	*p_list;

	line[ft_strlen(line) - 1] = '\0';
	split = ft_split(line, ' ');
	i = 0;
	p_list = NULL;
	while (split[i])
	{
		ft_lstadd_back(&p_list, ft_lstnew(new_point(i, y, ft_atoi(split[i]))));
		i++;
	}
	free_split(split);
	return (p_list);
}

t_grid	*parse_map(int fd)
{
	int		line_id;
	char	*line;
	t_list	*p_list;
	t_grid	*grid;

	line_id = 0;
	p_list = NULL;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		ft_lstadd_back(&p_list, parse_line(line, line_id++));
		free(line);
	}
	grid = init_grid(p_list, line_id);
	ft_lstclear(&p_list, NULL);
	return (grid);
}
