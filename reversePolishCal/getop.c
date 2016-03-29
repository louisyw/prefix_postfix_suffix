#include <stdio.h>
#include <ctype.h>
#include "calc.h"


//此函数用来从标准输入中读运算符，数字(数字的开头均有空白符)
int getop(char s[])
{
	int i, c;
	
	//跳过多个空白符，只保留一个
	while((s[0] = c = getch()) == ' ' || c == '\t')
		;
	s[1] = '\0';
	
	//输入的字符为非数字，则返回该字符
	if (!isdigit(c) && c != '.')
		return c;

	i = 0;

	if(isdigit(c))
		while(isdigit( s[++i] = c = getch() ) )
			;

	if(c == '.')
		while(isdigit( s[++i] = c = getch() ) )
			;
	
	s[i] = '\0';

	if(c != EOF)
		ungetch(c);

	return NUMBER;
}
