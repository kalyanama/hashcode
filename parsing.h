#ifndef PARSING_H
# define PARSING_H

#include <stdbool.h>
typedef struct
{
	bool	horizontal;
	size_t	tags_amount;
	char	**tags;
}			t_parsed;

#endif