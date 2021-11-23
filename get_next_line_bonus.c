#include "get_next_line.h"

static void	split_and_update(char **save, char **line)
{
	int		i;
	char	*tmp;

	i = 0;
	while (save[0][i])
	{
		if (save[0][i] == '\n' && save[0][i + 1])
		{
			*line = ft_substr(*save, 0, i + 1);
			tmp = ft_strdup(&save[0][i + 1]);
			free(*save);
			*save = ft_strdup(tmp);
			free(tmp);
			return ;
		}
		else if (save[0][i + 1] == '\0')
		{
			*line = *save;
			*save = 0;
			return ;
		}
		i++;
	}
}

static int	save_buff_in_save(char **save, char *buff)
{
	char	*tmp;
	int		i;

	i = 0;
	if (!*save)
	{
		*save = ft_strdup(buff);
		if (!*save)
		{
			free(*save);
			exit(0);
		}
	}
	else
	{
		tmp = ft_strjoin(*save, buff);
		free(*save);
		*save = ft_strdup(tmp);
		free(tmp);
	}
	while (save[0][i] && save[0][i] != '\n')
		i++;
	if (save[0][i] == '\n')
		return (1);
	return (0);
}

char	*get_next_line(int fd)
{
	static char	*save[4100];
	char		*buff;
	char		*line;
	int			rd;

	rd = 1;
	line = 0;
	buff = malloc(BUFFER_SIZE * sizeof(char));
	while (rd > 0)
	{
		rd = read(fd, buff, BUFFER_SIZE);
		if (rd <= 0)
			break ;
		buff[rd] = '\0';
		if (save_buff_in_save(&save[fd], buff))
			break ;
	}
	if (save[fd] && rd >= 0)
		split_and_update(&save[fd], &line);
	free(buff);
	return (line);
}
