/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   get_next_line.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: tvarnier <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/06 18:16:02 by tvarnier     #+#   ##    ##    #+#       */
/*   Updated: 2018/12/03 22:34:43 by tvarnier    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

int		get_rest(int fd, t_rest **s)
{
	while (*s)
	{
		if ((*s)->fd == fd)
			return (1);
		if (!((*s)->next))
			break ;
		*s = (*s)->next;
	}
	if (!(*s))
	{
		if (!(*s = (t_rest *)malloc(sizeof(t_list))))
			return (0);
	}
	else
	{
		if (!((*s)->next = (t_rest *)malloc(sizeof(t_list))))
			return (0);
		(*s) = (*s)->next;
	}
	(*s)->rest = NULL;
	(*s)->fd = fd;
	(*s)->next = NULL;
	return (1);
}

void	ft_remove(t_rest **list, t_rest *target, t_rest *begin)
{
	t_rest		*tmp;

	*list = begin;
	if (target == begin)
	{
		tmp = (*list)->next;
		free((*list)->rest);
		free(*list);
		begin = tmp;
	}
	else
		while (*list)
		{
			if (*list == target)
			{
				tmp->next = (*list)->next;
				free((*list)->rest);
				free(*list);
				break ;
			}
			tmp = *list;
			*list = (*list)->next;
		}
	*list = begin;
}

int		ft_check_error(char **line, int fd, t_rest **s, t_rest **begin)
{
	*begin = *s;
	if (fd < 0 || !&(*line))
		return (1);
	if (!(get_rest(fd, s)))
		return (1);
	if (!((*s)->rest))
	{
		if (!((*s)->rest = ft_strnew(0)))
			return (1);
	}
	if (!(*begin))
		*begin = *s;
	*line = NULL;
	return (0);
}

int		get_next_line_next(t_rest **s, char **line, int fd, t_rest *begin)
{
	char		buf[BUFF_SIZE + 1];
	int			ret;
	char		*tmp;

	if ((ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[ret] = '\0';
		tmp = (*s)->rest;
		if (!((*s)->rest = ft_strjoin(((*s)->rest), buf)))
			return (-1);
		free(tmp);
		*s = begin;
		return (get_next_line(fd, line));
	}
	if (ft_strlen((*s)->rest) && ret >= 0)
	{
		*line = ft_strdup((*s)->rest);
		(*s)->rest = ft_strnew(0);
		*s = begin;
		return (1);
	}
	ft_remove(s, *s, begin);
	if (ret < 0)
		return (-1);
	return (0);
}

int		get_next_line(const int fd, char **line)
{
	static t_rest	*s;
	int				pos;
	char			*tmp;
	int				i;
	t_rest			*begin;

	if (ft_check_error(line, fd, &s, &begin))
		return (-1);
	pos = -1;
	i = -1;
	while (s->rest[++i] && pos == -1)
		if (s->rest[i] == '\n')
			pos = i;
	if (pos == -1)
		return (get_next_line_next(&s, line, fd, begin));
	*line = ft_strsub(s->rest, 0, pos);
	tmp = s->rest;
	if (pos + 1 < (int)ft_strlen(s->rest))
		s->rest = ft_strsub(s->rest, pos + 1, (int)ft_strlen(s->rest));
	else
		s->rest = ft_strnew(0);
	free(tmp);
	s = begin;
	return (1);
}
