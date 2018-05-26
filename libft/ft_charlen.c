#include "libft.h"

int	ft_charlen(wchar_t c)
{
	int		len;	
	int		size;
	char	*s;

	size = 0;
	s = ft_itoa_base(c, 2);
	len = ft_strlen(s);
	ft_strdel(&s);
	if (len <= 7)
		size = 1;
	else if (len <= 11)
		size = 2;
	else if (len <= 16)
		size = 3;
	else
		size = 4;
	return (size);
}