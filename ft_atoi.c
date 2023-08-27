#include "minitalk.h"

#define POSITIVE (1)
#define NEGATIVE (-1)
#define OVERFLOW (1)
#define UNDERFLOW (-1)
#define OK (0)

static int	check_sign(const char **from_ascii, int sign);
static int	
	check_flow(unsigned long long dig2p, unsigned long long dig1, int sign);

int	ft_atoi(const char *from_ascii)
{
	unsigned long long	to_integer;
	unsigned long long	digit1;
	int					sign;

	while (ft_isspace(*from_ascii))
		from_ascii += 1;
	sign = check_sign(&from_ascii, POSITIVE);
	to_integer = 0;
	digit1 = 0;
	while (ft_isdigit(*from_ascii))
	{
		digit1 = *from_ascii - '0';
		if (check_flow(to_integer, digit1, sign) == OVERFLOW)
			return ((int)LONG_MAX);
		else if (check_flow(to_integer, digit1, sign) == UNDERFLOW)
			return ((int)LONG_MIN);
		to_integer = (to_integer * 10) + digit1;
		from_ascii += 1;
	}
	return ((int)to_integer * sign);	
}

static int	check_sign(const char **from_ascii, int sign)
{
	sign = POSITIVE;
	if (**from_ascii == '-' || **from_ascii == '+')
	{
		if (**from_ascii == '-')
			sign *= NEGATIVE;
		*from_ascii += 1;
	}
	return (sign);
}

static int	
	check_flow(unsigned long long dig2p, unsigned long long dig1, int sign)
{
	if (sign == POSITIVE)
	{
		if (dig2p > LONG_MAX / 10)
			return (OVERFLOW);
		else if (dig2p == (unsigned long long)LONG_MAX / 10 
			&& dig1 > (unsigned long long)LONG_MAX % 10)
			return (OVERFLOW);
	}
	else if (sign == NEGATIVE)
	{
		if (dig2p > LONG_MAX / 10)
			return (UNDERFLOW);
		else if (dig2p == (unsigned long long)LONG_MIN / 10
			&& dig1 > (unsigned long long)LONG_MIN % 10)
			return (UNDERFLOW);
	}
	return (OK);
}