#include "ft_printf.h"

int get_width(char *flags)
{
	int k;
	int len;
	int num;
	int i;

	num = 0;
	i = 0;
	while (flags[i] && !(ft_isdigit(flags[i])))
		i++;
	k = i;
	len = 0;
	while (ft_isdigit(flags[i]))
	{
		len++;
		i++;
	}
	num = ft_atoi(ft_strsub(flags, k, len));
	return (num);
}

int get_precision(char *flags)
{
	int len;
	int num;
	int k;
	int i;

	i = 0;
	num = 0;
	while (flags[i] && flags[i] != '.')
		i++;
	if (flags[i] == '.')
	{
		i++;
		k = i;		
		len = 0;
		while (flags[i] && ft_isdigit(flags[i]))
		{
			len++;
			i++;
		}
		num = ft_atoi(ft_strsub(flags, k, len));
		return (num);		
	}
	else 
		return (-1);
}