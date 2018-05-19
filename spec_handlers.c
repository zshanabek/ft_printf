#include "ft_printf.h"

void ft_putsymbol(wchar_t c)
{
	char	*s;
	int		len;

	setlocale(LC_ALL, "");
	s = ft_itoa_base(c, 2);
	len = ft_strlen(s);
	if (MB_CUR_MAX != 1)
	{
		if (len <= 7)
			ft_putchar(c);
		else if (len <= 11)
		{
			ft_putchar((c >> 6) + 0b11000000);
			ft_putchar((c & 0b111111) + 0b10000000);
		}
		else if (len <= 16)
		{
			ft_putchar((c >> 12) + 0b11100000);
			ft_putchar(((c >> 6) & 0b111111) + 0b10000000);		
			ft_putchar((c & 0b111111) + 0b10000000);
		}
		else
		{
			ft_putchar((c >> 18) + 0b11110000);		
			ft_putchar(((c >> 12) & 0b111111) + 0b10000000);
			ft_putchar(((c >> 6) & 0b111111) + 0b10000000);		
			ft_putchar((c & 0b111111) + 0b10000000);
		}
	}
}

void	ft_analyze_c(wint_t c, t_item *form, char *flags, int *count)
{
	char *padding_str;

	padding_str = ft_strnew(0);	
	if (find_minus(flags))
		form->minus = true;
	else if (find_zero(flags))
		form->zero = true;
	form->padding = get_width(flags) - 1;
	if (form->padding > 0 && form->zero)
		padding_str = ft_strfill(form->padding, '0');
	else if (form->padding > 0)
		padding_str = ft_strfill(form->padding, ' ');
	if (form->minus == false)
		ft_putstr(padding_str);
	ft_putsymbol(c);
	if (form->minus == true)
		ft_putstr(padding_str);
	*count += (ft_strlen(padding_str) + 1);		
}

void	ft_analyze_percent(t_item *form, char *flags, int *count)
{
	char *padding_str;

	padding_str = ft_strnew(0);	
	if (find_minus(flags))
		form->minus = true;
	else if (find_zero(flags))
		form->zero = true;
	form->padding = get_width(flags) - 1;
	if (form->padding > 0 && form->zero)
		padding_str = ft_strfill(form->padding, '0');
	else if (form->padding > 0)
		padding_str = ft_strfill(form->padding, ' ');
	if (form->minus == false)
		ft_putstr(padding_str);
	ft_putchar('%');
	if (form->minus == true)
		ft_putstr(padding_str);
	*count += (ft_strlen(padding_str) + 1);	
}

void	ft_analyze_s(char *str, t_item *form, char *flags, int *count)
{
	char *output;
	char *padding_str;

	output = ft_strnew(0);
	padding_str = ft_strnew(0);	
	if (find_minus(flags))
		form->minus = true;
	output = ft_strsub(str, 0, get_precision(flags));
	form->padding = calculate_padding_s(output, form, flags);
	if (form->padding > 0)
		padding_str = ft_strfill(form->padding, ' ');
	if (form->minus == false)
		ft_putstr(padding_str);
	ft_putstr(output);	
	if (form->minus == true)
		ft_putstr(padding_str);
	*count += (ft_strlen(padding_str) + ft_strlen(output));
}

void ft_sign_order_u(t_item *form, int *count)
{
	if (form->hash && form->specifier == 'o')
	{
		form->hex_sign = "0";		
		(*count) += 1;
	}
	else if (form->hash && form->specifier == 'x' )
	{
		form->hex_sign = "0x";		
		(*count) += 2;
	}
	else if (form->hash && form->specifier == 'X')
	{
		form->hex_sign = "0X";		
		(*count) += 2;
	}	
	if (form->hash)
	{		
		if ((ft_strlen(form->padding_str) <= 0 && ft_strlen(form->zeros_str) <= 0) || (ft_strlen(form->padding_str) > 0 && ft_strlen(form->zeros_str) <= 0 && form->zero == true) 
		|| (ft_strlen(form->zeros_str) > ft_strlen(form->padding_str)))
			form->order = 1;
		else if (ft_strlen(form->padding_str) > 0 && ft_strlen(form->zeros_str) > 0)	
			form->order = 2;
		else if (ft_strlen(form->padding_str) > 0 && ft_strlen(form->zeros_str) <= 0)		
			form->order = 3;
	}
}

void	create_output_u(t_item *form, char *output, int *count)
{
	form->zeros_str = ft_strnew(0);
	form->padding_str = ft_strnew(0);	
	if (form->precision > 0)
		form->zeros_str = ft_strfill(form->precision, '0');
	if (form->padding > 0 && form->zero == true)
		form->padding_str = ft_strfill(form->padding , '0');
	else if (form->padding > 0 && form->zero == false)
		form->padding_str = ft_strfill(form->padding, ' ');
}


void	make_output_u(t_item *form, char *output, int *count)
{	
	if (form->order == 1)
		ft_putstr(form->hex_sign);
	if (ft_strlen(form->padding_str) > 0 && form->minus == false)
		ft_putstr(form->padding_str);
	if (form->order == 2)
		ft_putstr(form->hex_sign);
	if (ft_strlen(form->zeros_str) > 0)
		ft_putstr(form->zeros_str);
	if (form->order == 3)
		ft_putstr(form->hex_sign);
	ft_putstr(output);
	if (form->padding_str > 0 && form->minus == true) 
		ft_putstr(form->padding_str);
	*count += (ft_strlen(form->padding_str) + ft_strlen(form->zeros_str) + ft_strlen(output));	
}

void	ft_analyze_u(uint64_t num, t_item *form, char *flags, int *count)
{
	char *output;
	if (find_minus(flags))
		form->minus = true;
	if (find_zero(flags))
		form->zero = true;
	if (find_hash(flags) || form->specifier == 'p')
		form->hash = true;
	
	if (form->specifier == 'o')
		output = ft_itoa_base_u(num, 8);
	else if (form->specifier == 'X' || form->specifier == 'x' || form->specifier == 'p' )
		output = ft_itoa_base_u(num, 16);		
	else
		output = ft_itoa_base_u(num, 10);
	if (form->specifier == 'X')
		ft_strupcase(output);
	form->precision  = calculate_zeros_u(ft_strlen(output), flags);
	form->padding = calculate_padding_u(ft_strlen(output), form, flags);
	create_output_u(form, output, count);
	ft_sign_order_u(form, count);	
	make_output_u(form, output, count);
}