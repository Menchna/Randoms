#include "get_next_line.h"

size_t    ft_strlen(const char *s)
{
    size_t    i;

    i = 0;
    while (s[i])
        i++;
    return (i);
}

char    *ft_strchr(const char *s, int c)
{
    int    i;

    i = 0;
    while (s[i] != '\0')
    {
        if (s[i] == (char)c)
            return ((char *)s + i);
        i++;
    }
    if ((char)c == '\0')
        return ((char *)(s + i));
    return (NULL);
}

char    *ft_strjoin(char *s1, char *s2)
{
    char    *new;
    size_t    i;
    size_t    j;

    if (!s1 && !s2)
        return (NULL);
    if (!s1)
    {
        s1 = ft_strdup("");
        if (!s1)
            return (NULL);
    }
    if (!s2)
        return (s1);
    new = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
    if (!new)
    {
        if (s1 != ft_strdup(""))
            free(s1);
        return (NULL);
    }
    i = 0;
    while (s1[i])
    {
        new[i] = s1[i];
        i++;
    }
    j = 0;
    while (s2[j])
        new[i++] = s2[j++];
    new[i] = '\0';
    free(s1);
    return (new);
}

char    *ft_line(char *str)
{
    char    *line;
    int        i;

    if (!str)
        return (NULL);
    i = 0;
    while (str[i] && str[i] != '\n')
        i++;
    if (str[i] == '\n')
        i++;
    line = malloc(sizeof(char) * (i + 1));
    if (!line)
        return (NULL);
    i = 0;
    while (str[i] && str[i] != '\n')
    {
        line[i] = str[i];
        i++;
    }
    if (str[i] == '\n')
    {
        line[i] = '\n';
        i++;
    }
    line[i] = '\0';
    return (line);
}

char    *ft_next(char *str)
{
    char    *new;
    int        i;
    int        j;

    i = 0;
    while (str[i] && str[i] != '\n')
        i++;
    if (!str[i])
    {
        free(str);
        return (NULL);
    }
    new = malloc(sizeof(char) * (ft_strlen(str) - i + 1));
    if (!new)
    {
        free(str);
        return (NULL);
    }
    i++;
    j = 0;
    while (str[i])
        new[j++] = str[i++];
    new[j] = '\0';
    free(str);
    return (new);
}

char    *ft_strdup(const char *s)
{
    char    *new;
    size_t    len;
    size_t    i;

    len = ft_strlen(s);
    new = malloc(sizeof(char) * (len + 1));
    if (!new)
        return (NULL);
    i = 0;
    while (s[i])
    {
        new[i] = s[i];
        i++;
    }
    new[i] = '\0';
    return (new);
}