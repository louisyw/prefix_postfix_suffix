/*
 *change infix expression to prefix expression(polish expression)
 * 
 */


#include <stack>
#include <cstdio>
#include <string>
#include <cctype>
#include <iostream>

using namespace std;

static int priority(char op)
{
	if (op == '+' || op == '-'){
		return 1;
	}else if(op == '*' || op == '/'){
		return 2;
	}else{
		return 0;
	}
}

static bool isOperator(char op)                //判断输入串中的字符是不是操作符，如果是返回true  
{
	return (op=='+' || op=='-' || op=='*' || op=='/');  
}  


string polishNotation(string &s)
{
	stack<char> mainStack;
	stack<char> operatorStack;
	int i;

	for(i = s.size() -1; i>= 0; --i){
		if(s[i] == ')'){
			operatorStack.push(s[i]);
		}else if(s[i] == ' '|| s[i] == '\t'){
			continue;
		}else if(isdigit(s[i])){
			mainStack.push(s[i]);

			while(i - 1 >= 0 && isdigit(s[i-1])){
				mainStack.push(s[i-1]);
				--i;
			}

			mainStack.push(' ');
		}else if(isOperator(s[i])){
			//当操作符栈为空，或者栈顶的元素为')'，或者要压入的操作符的优先级大于等于栈顶操作符的优先级时
			if(operatorStack.empty() || operatorStack.top() == ')' || priority(s[i]) >= operatorStack.top()){
				operatorStack.push(s[i]);
			}else{      //此处需要特别注意，可读性太差

				//这种情况一定是发生在符号栈非空
				/*while
				 (priority(operatorStack.top()) > priority(s[i])){
					char c = operatorStack.top();  operatorStack.pop();
					mainStack.push(c);
					mainStack.push(' ');
				}*/
				//否则就将操作符栈的操作符依次出栈，知道栈顶的元素的优先级大于等于要压入的操作符
				while(!operatorStack.empty()){
					if(priority(operatorStack.top()) > priority(s[i])){
						char c = operatorStack.top();  operatorStack.pop();
						mainStack.push(c);
						mainStack.push(' ');
					}else
						break;
				}
				operatorStack.push(s[i]);
			}
		}else if(s[i] == '('){                 //遇到左括号，依次出栈，知道栈顶的元素为‘)’
			while(operatorStack.top() != ')'){
				char c = operatorStack.top();    operatorStack.pop();
				mainStack.push(c);
				mainStack.push(' ');
			}
			operatorStack.pop();
		}else{
			printf("unknown operator, %c \n", s[i]);
		}
	}

	while(! operatorStack.empty()){
		char c = operatorStack.top();    operatorStack.pop();
		mainStack.push(c);
		mainStack.push(' ');
	}

	string ret;
	while(!mainStack.empty()){
		ret += mainStack.top();
		mainStack.pop();
	}

	return ret;
}

int main()
{
	string str = "1+2-3*(4-5)";

	string polish = polishNotation(str);
	cout<<"The infix is:"<<endl;
	cout<<str<<endl<<endl;
	cout<<"The prefix is:"<<endl;
	cout<<polish<<endl;

	return 0;
}
