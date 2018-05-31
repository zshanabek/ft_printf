#include "libft.h"

int	ft_charlen(wchar_t c)
{
	int		size;

	size = 0;
	if (c <= 127)
		size = 1;
	else if (c <= 2047)
		size = 2;
	else if (c <= 65535)
		size = 3;
	else
		size = 4;
	return (size);
}