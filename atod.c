#include <math.h>

int count_power(const char *str)
{
    int i;
    int post_comma;

    i = 0;
    post_comma = 0;
    while (str[i])
    {
        if (str[i] == '.')
        {
            while(str[i])
            {
                i++;
                post_comma++;
            }
        }
        i++;
    }
    return (pow(10, post_comma - 1));
}

double	ft_atod(const char *str)
{
	int     i;
	int     signal;
	double  result;
    int     power;

	result = 0;
	signal = 1;
	i = 0;
	if (str[i] == '-')
		signal = -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while ((str[i] >= 48 && str[i] <= 57) || str[i] == '.')
	{
		if (result >= 9223372036854775807 && signal == 1)
			return (-1);
		if (result > 9223372036854775807 && signal == -1)
			return (0);
        if (str[i] == '.')
            i++;
		result = (str[i] - 48) + (result * 10);
		i++;
	}
    power = count_power(str);
	return ((result * signal) / power);
}
