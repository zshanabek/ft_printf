#include "libft.h"

int			ft_wstrlen(wchar_t *str)
{
	int len;
	int i;

	i = 0;
	len = 0;
	while (str[i] && (MB_CUR_MAX != 1))
	{
		len += ft_charlen(str[i]);
		i++;
	}
	return (len);
}
