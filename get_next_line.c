#include "get_next_line.h"

static char    *ft_read(int fd, char *str)
{
    char    *buf;
    int        rd;

    if (!str)
    {
        str = ft_strdup("");
        if (!str)
            return (NULL);
    }
    buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
    if (!buf)
    {
        free(str);
        return (NULL);
    }
    rd = 1;
    while (rd > 0 && !ft_strchr(str, '\n'))
    {
        rd = read(fd, buf, BUFFER_SIZE);
        if (rd == -1)
        {
            free(buf);
            free(str);
            return (NULL);
        }
        buf[rd] = '\0';
        str = ft_strjoin(str, buf);
        if (!str)
        {
            free(buf);
            return (NULL);
        }
    }
    free(buf);
    return (str);
}

char    *get_next_line(int fd)
{
    static char    *str;
    char        *line;

    if (fd < 0 || BUFFER_SIZE <= 0)
        return (NULL);
    str = ft_read(fd, str);
    if (!str)
        return (NULL);
    if (!*str)
    {
        free(str);
        str = NULL;
        return (NULL);
    }
    line = ft_line(str);
    if (!line)
    {
        free(str);
        str = NULL;
        return (NULL);
    }
    str = ft_next(str);
    return (line);
}

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int main(void)
{
    int fd = open("test.txt", O_RDONLY);
    char *line;

    if (fd < 0)
        return (1);
    while ((line = get_next_line(fd)))
    {
        printf("%s", line);
        free(line);
    }
    close(fd);
    return (0);
} 
