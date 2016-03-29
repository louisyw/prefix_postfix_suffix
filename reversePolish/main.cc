/*
 *change the infix to suffix(reverse Polish Expression)
 *
 */


#include <string>
#include <stack>
#include <iostream>
#include <cstdio>
#include <queue>
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


string reversePolishNotation(string &s)
{
	queue<char> mainStack;
	stack<char> operatorStack;
	int i;

	for(i = 0; i < s.size(); ++i){
		if(s[i] == '('){
			operatorStack.push(s[i]);
		}else if(s[i] == ' '|| s[i] == '\t'){
			continue;
		}else if(isdigit(s[i])){
			mainStack.push(s[i]);

			while(i + 1 < s.size() && isdigit(s[i+1])){
				mainStack.push(s[i+1]);
				++i;
			}

			mainStack.push(' ');
		}else if(isOperator(s[i])){
			if(operatorStack.empty() || operatorStack.top() == '(' || priority(s[i]) > operatorStack.top()){
				operatorStack.push(s[i]);
			}else{      //此处需要特别注意，可读性太差

				//这种情况一定是发生在符号栈非空
				/*while
				 (priority(operatorStack.top()) > priority(s[i])){
					char c = operatorStack.top();  operatorStack.pop();
					mainStack.push(c);
					mainStack.push(' ');
				}*/

				while(!operatorStack.empty()){
					if(priority(operatorStack.top()) >= priority(s[i])){
						char c = operatorStack.top();  operatorStack.pop();
						mainStack.push(c);
						mainStack.push(' ');
					}else
						break;
				}
				operatorStack.push(s[i]);
			}
		}else if(s[i] == ')'){
			while(operatorStack.top() != '('){
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
		ret += mainStack.front();
		mainStack.pop();
	}

	return ret;
}

int main()
{
	string str = "  1 +2    *   (3- 4)-5*6";

	string polish = reversePolishNotation(str);
	cout<<"The infix is:"<<endl;
	cout<<str<<endl<<endl;
	cout<<"The suffix is:"<<endl;
	cout<<polish<<endl;

	return 0;
}
