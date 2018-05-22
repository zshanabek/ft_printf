#include "ft_printf.h"

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
	if (c == 0)
		ft_putchar(0);
	else if (c >= 32 && c <= 126)
		ft_putchar(c);
	else
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

void	ft_analyze_ls(wchar_t *str, t_item *form, char *flags, int *count)
{
	wchar_t		*output;
	char		*padding_str;

	output = ft_strnew_w(0);
	padding_str = ft_strnew(0);	
	if (find_minus(flags))
		form->minus = true;
	if (get_precision(flags) != -1)
		output = ft_strsub_w(str, 0, get_precision(flags));
	else 
		output = ft_strdupw(str);
	form->padding = calculate_padding_ws(output, flags);
	if (form->padding > 0)
		padding_str = ft_strfill(form->padding, ' ');
	if (form->minus == false)
		ft_putstr(padding_str);
	ft_putstrw(output);		
	if (form->minus == true)
		ft_putstr(padding_str);
	*count += (ft_strlen(padding_str) + ft_strlen_w(output));
}

void	ft_analyze_s(char *str, t_item *form, char *flags, int *count)
{
	char *output;
	char *padding_str;

	output = ft_strnew(0);
	padding_str = ft_strnew(0);
	if (find_minus(flags))
		form->minus = true;
	if (str == NULL)
		output = ft_strdup("(null)");
	else if (get_precision(flags) != -1)
		output = ft_strsub(str, 0, get_precision(flags));
	else 
		output = ft_strdup(str);
	form->padding = calculate_padding_s(output, flags);
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

void	create_output_u(t_item *form)
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
	if (form->padding > 0 && form->minus == true) 
		ft_putstr(form->padding_str);
	*count += (ft_strlen(form->padding_str) + ft_strlen(form->zeros_str) + ft_strlen(output));	
}

void	ft_analyze_u(uintmax_t num, t_item *form, char *flags, int *count)
{
	char *output;

	if (find_minus(flags))
		form->minus = true;
	else if (find_zero(flags))
		form->zero = true;
	if ((find_hash(flags) || form->specifier == 'p') && num != 0)
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
	create_output_u(form);
	ft_sign_order_u(form, count);	
	make_output_u(form, output, count);
}
