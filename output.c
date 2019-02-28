
#include "output.h"
#include <string.h>
#include <photo.h>
#include <libftprintf/inc/libft.h>

size_t	print_photo_amount(size_t len, int *path)
{
	size_t i;

	i = 0;
	while (i < len)
	{
		if (path[i] == -1)
			break;
		i++;
	}
	return i;
}

void	print_slide(t_photo photos){
	ft_dprintf(STDOUT_FILENO, "%d", photos.first_num);
	if (photos.second_num != -1)
		ft_dprintf(STDOUT_FILENO, " %d", photos.second_num);
	ft_dprintf(STDOUT_FILENO, "\n");
}

void	print_output(size_t len, int *path, t_photo *photos)
{
	size_t amount;

	amount = print_photo_amount(len, path);
	for (int i = 0; i < amount; ++i)
	{
		print_slide(photos[path[i]]);
	}
}