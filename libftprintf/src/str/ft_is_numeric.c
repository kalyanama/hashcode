#include "str.h"

bool ft_is_numeric(const char *str)
{
	int sign;

	PROTECT(str)
	sign = 0;
	while (*str)
	{
		if (*str == '+' || *str == '-')
		{
			++sign;
			if (sign > 1)
				return (false);
			str++;
		}
		if (!ft_isdigit(*str))
			return (false);
		str++;
	}
	return (true);
}