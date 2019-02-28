#include "parsing.h"
void	free_tags(char **tags, size_t count)
{
	for (int i = 0; i < count; ++i)
	{
		ft_strdel(&tags[i]);
	}
}
void free_dataset(t_parsed **dataset, size_t count)
{
	for (int i = 0; i < count; ++i)
	{
		free_tags(dataset[i]->tags, dataset[i]->tags_amount);
		free(dataset[i]->tags);
		free(dataset[i]);
	}
	free(dataset);
}