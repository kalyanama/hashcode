#ifndef PARSING_H
# define PARSING_H

#include <stdbool.h>
#include "libft.h"

typedef struct
{
	bool	horizontal;
	size_t	tags_amount;
	char	**tags;
}			t_parsed;

t_parsed ** parse_input(char *argv, size_t *photos_amount);
void free_dataset(t_parsed **dataset, size_t count);

#endif