/*
 *leetcode 224:base calculator
 *给定基本算式，只有加减法
 */

#include <stack>
#include <cstdio>
#include <cctype>
#include <string>
using namespace std;

int calculate(string s)
{
	stack<int> sign;
	sign.push(1);
	sign.push(1);

	int ret = 0;
	
	for(size_t i = 0; i < s.size(); ++i){
		int num = 0;
		if(isdigit(s[i])){
			num =  s[i] -'0';										                
			
			while(i+1 < s.size() && isdigit(s[i+1])){
				num = num * 10 + s[i+1] - '0';
				++i;
			}
			ret += sign.top()*num;
			sign.pop();
		}else if(s[i] == '+' || s[i] == '('){
			sign.push(1 * sign.top());
		}else if(s[i] == '-'){
			sign.push(-1 * sign.top());
		}else if(s[i] == ' ' || s[i] == '\t'){
			continue;
		}else{
			sign.pop();
		}
	}
	return ret;
}


int main()
{
	string str= "12+(3-4+5)-(6-7+8)";

	int res = calculate(str);

	printf("%d\n", res);

	return 0;
}
