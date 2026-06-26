#include "minirt.h"

int	is_valid_int(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-')
		i++;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

int	is_valid_float(char *str)
{
	int	i;
	int	dot_count;

	i = 0;
	dot_count = 0;
	if (!str || str[0] == '\0')
		return (0);
	if (str[i] == '-')
		i++;
	if (str[i] == '\0')
		return (0);
	while (str[i])
	{
		if (str[i] == '.')
		{
			dot_count++;
			if (dot_count > 1)
				return (0);
		}
		else if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

static double	parse_integer(const char **s)
{
	double	res;

	res = 0.0;
	while (**s >= '0' && **s <= '9')
		res = res * 10.0 + (*(*s)++ - '0');
	return (res);
}

double	ft_atof(const char *s)
{
	double	sign;
	double	res;
	double	base;

	sign = 1.0;
	base = 0.1;
	while (*s == ' ' || (*s >= 9 && *s <= 13))
		s++;
	if (*s == '-' || *s == '+')
		if (*s++ == '-')
			sign = -1.0;
	res = parse_integer(&s);
	if (*s == '.')
	{
		s++;
		while (*s >= '0' && *s <= '9')
		{
			res += (*s++ - '0') * base;
			base *= 0.1;
		}
	}
	return (sign * res);
}

int	arr_len(char **s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}
