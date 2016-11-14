/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_and_copy.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchartie <pchartie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/18 14:20:13 by pchartie          #+#    #+#             */
/*   Updated: 2016/02/18 15:11:42 by pchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	check_line(char *line)
{
	int i;

	i = 0;
	while (line[i] != '\0')
	{
		if (line[i] != ' ' && line[i] != '-' && (line[i] < 48 || line[i] > 57))
			return (-1);
		if (line[i] == '-' && i != 0 && (line[i - 1] != ' '
			|| (line[i + 1] < 48 && line[i + 1] > 57)))
			return (-1);
		i++;
	}
	return (1);
}

static int	ft_nbr_lines(char *file)
{
	char	*line;
	int		nbr_lines;
	int		fd;

	nbr_lines = 0;
	fd = open(file, O_RDONLY);
	if (fd <= 0)
		ft_error(3);
	while (get_next_line(fd, &line))
		nbr_lines++;
	close(fd);
	return (nbr_lines);
}

static int	ft_size_line(char *line)
{
	int i;
	int size_line;

	i = 0;
	size_line = 0;
	while (line[i] != '\0')
	{
		if (line[i] >= 48 && line[i] <= 57
			&& (line[i - 1] == ' ' || line[i + 1] == ' '
				|| line[i + 1] == '\0'))
		{
			while (line[i] >= 48 && line[i] <= 57)
				i++;
			size_line++;
		}
		i++;
	}
	return (size_line);
}

t_param		*check_file(char *file)
{
	char		*line;
	int			fd;
	t_param		*p;

	p = (t_param*)malloc(sizeof(t_param));
	p->size_line = 0;
	p->nbr_lines = ft_nbr_lines(file);
	fd = open(file, O_RDONLY);
	while (get_next_line(fd, &line))
	{
		if ((p->size_line > 0) &&
			(p->size_line != ft_size_line(line) || check_line(line) < 0))
			ft_error(4);
		p->size_line = ft_size_line(line);
	}
	close(fd);
	if (p->size_line <= 0)
		ft_error(2);
	return (p);
}

int			**tab_points(char *file, t_param *p)
{
	char	**tab_split;
	char	*line;
	int		i;
	int		k;
	int		fd;

	i = 0;
	k = 0;
	fd = open(file, O_RDONLY);
	p->tab = (int **)malloc(sizeof(int *) * p->nbr_lines);
	while (i < p->nbr_lines)
	{
		get_next_line(fd, &line);
		p->tab[i] = (int *)malloc(sizeof(int) * p->size_line);
		tab_split = ft_strsplit(line, ' ');
		while (tab_split[k])
		{
			p->tab[i][k] = ft_atoi(tab_split[k]);
			k++;
		}
		k = 0;
		i++;
	}
	close(fd);
	return (p->tab);
}
