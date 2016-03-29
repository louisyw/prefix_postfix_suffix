#include <stdio.h>
#include "calc.h"

#define MAXOP 100

int main()
{
	char str[MAXOP];
	int type;
	double op2;
	
	while((type = getop(str)) != EOF){
		switch(type){
			case NUMBER:
				push(atof(str));
				break;
			case '+':
				push(pop() + pop());
				break;
			case '*':
				push(pop() * pop());
				break;
			case '-':
				op2 = pop();
				push(pop() - op2);
				break;
			case '/':
				op2 = pop();
				if (op2 != 0.0)
					push(pop()/op2);
				else
					printf("error: zero divisior\n");
				break;
			case '\n':
				printf("the result is:");
				printf("\t %.8g\n", pop());
				break;
			default:
				printf("error: unknown command %s\n", str);
				break;
		}
	}
	return 0;
}
