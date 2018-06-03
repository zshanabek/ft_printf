#include "ft_printf.h"

int 	color_len(char *color, char *conv)
{
	ft_putstr(conv);
	return (ft_strlen(color));
}

int		identify_color(const char *restrict s, int i)
{
	char *color;
	int len;

	if (ft_strstr(s + i, "{red}"))
		len = color_len("{red}", "\x1b[31m");
	else if (ft_strstr(s + i, "{eoc}"))
		len = color_len("{eoc}", "\x1b[0m");
	return (i+len);
}




// else if (ft_strstr(s, "{green}"))
// 	ft_printf("\x1b[32m");
// else if (ft_strstr(s, "{yellow}"))
// 	ft_printf("\x1b[33m");
// else if (ft_strstr(s, "{blue}"))
// 	ft_printf("\x1b[34m");
// else if (ft_strstr(s, "{magenta}"))
// 	ft_printf("\x1b[35");
// else if (ft_strstr(s, "{cyan}"))
// 	ft_printf("\x1b[36m");