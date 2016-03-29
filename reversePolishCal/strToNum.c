#include <ctype.h>
#include "calc.h"

double atof(char s[])
{
	double val, power;

	int i, sign;

	//跳过字符串前的空格符
	for(i = 0; isspace(s[i]); ++i)
		;

	sign = (s[i] == '-') ? -1 : 1;

	//如果有正负号
	if (s[i] == '+'|| s[i] == '-')
		i++;

	for(val = 0.0; isdigit(s[i]); ++i)
		val = 10.0 * val + (s[i] - '0');
	
	if (s[i] == '.')
		i++;
	
	for(power = 1.0; isdigit(s[i]); i++){
		val = val *10.0 + (s[i] -'0');
		power *= 10.0;
	}

	return sign*val/power;
}
