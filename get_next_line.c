#include "get_next_line.h"


void    split_and_update(char **save,char **line)
{
    int i;
    char *tmp;

    i = 0;
    while (save[0][i])
    {
        if (save[0][i] == '\n' && save[0][i + 1])
        {
            *line = ft_substr(*save, 0, i + 1);
            tmp = ft_strdup(&save[0][i+1]);
            free(*save);
            save[0] = ft_strdup(tmp);
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

void    save_buff_in_save(char **save, char *buff)
{
    char *tmp;

    if(!*save)
        *save = ft_strdup(buff);
    else
    {
        tmp = ft_strjoin(*save, buff);
        free(*save);
        *save = ft_strdup(tmp);
        free(tmp);
    }
}

//=====================CHECK ABOUT SAVE SIZE LATER=====================//

char    *get_next_line(int fd)
{
    static char *save[4100];
    char *buff;
    char *line;
    int i;
    int rd;

    line = 0;
    buff = malloc(sizeof(char) * (BUFFER_SIZE + 1));
    while ((rd = read(fd,buff,BUFFER_SIZE)) > 0)
    {   
        i = 0;
        buff[rd] = '\0';
        save_buff_in_save(&save[fd], buff);
        while (save[fd][i] && save[fd][i] != '\n')           
            i++;
        if (save[fd][i] == '\n')
                break ;
    }
    if (save[fd] && rd >= 0)
        split_and_update(&save[fd],&line);
    free(buff);
    return (line);
}