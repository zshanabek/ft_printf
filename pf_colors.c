#include "ft_printf.h"

void	color_len(char *color)
{
	if (ft_strequ(color, "red"))
		ft_putstr("\x1b[31m");
	else if (ft_strequ(color, "green"))
		ft_putstr("\x1b[32m");
	else if (ft_strequ(color, "yellow"))
		ft_putstr("\x1b[33m");
	else if (ft_strequ(color, "blue"))
		ft_putstr("\x1b[34m");
	else if (ft_strequ(color, "magenta"))
		ft_putstr("\x1b[35m");
	else if (ft_strequ(color, "cyan"))
		ft_putstr("\x1b[36m");
	else if (ft_strequ(color, "eoc"))
		ft_putstr("\x1b[0m");
}

int		identify_color(const char *restrict s, int i)
{	
	int		len;
	int		k;
	char	*color;

	len = 0;
	k = i;
	while (s[i] != '}')
	{
		i++;
		len++;
	}
	color = ft_strsub(s, k + 1, len - 1);
	color_len(color);
	free(color);
	return (i);
}
