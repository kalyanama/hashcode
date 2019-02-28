#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include "parsing.h"


bool get_layout(char c)
{
	return (c == 'H');
}

size_t next_len(const char *line)
{
	size_t i;

	i = 0;
	while (line[i])
	{
		if (line[i] == ' ')
			return i;
		i++;
	}
	return (i);
}

char **get_tags(size_t tag_amount, char *line)
{
	char **res;
	int i;

	res = malloc(sizeof(char *) * tag_amount);
	i = 0;
	line = strchr(line, ' ') + 1;
	size_t len;
	while (i < tag_amount)
	{
		len = next_len(line);
		res[i] = ft_strsub(line, 0, len);
		line += len + 1;
		i++;
	}
	return (res);
}

void parse_one_photo(t_parsed *set, char *line)
{
	set->horizontal = get_layout(*line);
	line = strchr(line, ' ') + 1;
	set->tags_amount = (size_t) ft_atoi(line);
	set->tags = get_tags(set->tags_amount, line);

}

t_parsed **parse_input(char *argv, size_t *photos_amount)
{
	char *line = NULL;
	t_parsed **data_set;
	int fd;
	int i;

	fd = open(argv, O_RDONLY);
	get_next_line(fd, &line);
	*photos_amount = (size_t) ft_atoi(line);
	ft_strdel(&line);
	data_set = malloc(sizeof(data_set) * (*photos_amount + 1));
	i = 0;
	while (get_next_line(fd, &line))
	{
		data_set[i] = malloc(sizeof(t_parsed));
		parse_one_photo(data_set[i++], line);
		ft_strdel(&line);
	}

	close(fd);
	return (data_set);
}
