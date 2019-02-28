#include <stdio.h>
#include <parsing.h>

int main(int argc, char **argv)
{
	t_parsed	**data_set;
	size_t photos;

	data_set = parse_input(argv[1], &photos);
	for (int i = 0; i < photos; ++i)
	{
		printf("%zd\n", data_set[i]->tags_amount);
		for (int j = 0; j < data_set[i]->tags_amount; ++j)
		{
			printf("%s\n", data_set[i]->tags[j]);
		}
	}
	return 0;
}