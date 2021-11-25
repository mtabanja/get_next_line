#include "get_next_line.h"

int	_free(char **save)
{
	if (!*save)
	{
		free(*save);
		return (-1);
	}
	return (1);
}

static int	split_and_update(char **save, char **line)
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
			return (!_free(save));
		}
		else if (save[0][i + 1] == '\0')
		{
			*line = *save;
			*save = 0;
			free(*save);
			return (1);
		}
		i++;
	}
	return (1);
}

static int	save_buff_in_save(char **save, char *buff)
{
	char	*tmp;
	int		i;

	i = 0;
	if (!*save)
	{
		*save = ft_strdup(buff);
		if (!_free(save))
			return (-1);
	}
	else
	{
		tmp = ft_strjoin(*save, buff);
		free(*save);
		*save = ft_strdup(tmp);
		free(tmp);
		if (!_free(save))
			return (-1);
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
	int			fail_check;

	rd = 1;
	line = 0;
	buff = malloc((BUFFER_SIZE + 1) * sizeof(char));
	while (rd > 0)
	{
		rd = read(fd, buff, BUFFER_SIZE);
		if (rd <= 0)
			break ;
		buff[rd] = '\0';
		fail_check = save_buff_in_save(&save[fd], buff);
		if (fail_check == 1 || fail_check == -1)
			break ;
	}
	if (rd >= 0 && save[fd] && fail_check >= 0)
		fail_check = split_and_update(&save[fd], &line);
	if (fail_check == -1)
		line = 0;
	free(buff);
	return (line);
}
