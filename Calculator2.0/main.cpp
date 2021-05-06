//支持带括号的表达式
#include <iostream>
#include <stack>

using namespace std;

double inStack();   //核心函数，将操作符有序的入栈计算， 最后返回结果
void calculate(stack<char>& Ope, stack<double>& Num);  //用来计算加减乘除, 结果放在数字栈顶
int priority(char ope_);   //用来计算操作符的优先级

int main() {
	double result;   //最后的结果

	cout << "请输入：\n";
	result = inStack();   //将缓冲区的操作符和数字压入栈 

	cout << "结果是：\n" << result;

	return 0;
}

double inStack() {
	stack<char> Ope;
	stack<double> Num;
	char ope_;
	double num_;

	while (1) {
		if (cin.peek() >= '0' && cin.peek() <= '9') {  //判断下一个是否是数字
			cin >> num_;
			Num.push(num_);   //数字直接入栈
		}
		else {
			cin >> ope_;
			if (ope_ == '=') {
				while (!Ope.empty()) calculate(Ope, Num); //如果符号栈不空，就一直计算
				return Num.top();  //如果是等号且符号栈顶为空，就返回数字栈顶元素
			}
			else if (ope_ == '(' || Ope.empty()) Ope.push(ope_);    //如果符号是左括号或符号栈为空直接压入
			else if (ope_ == ')') {  //如果是右括号
				while (Ope.top() != '(') calculate(Ope, Num); //一直计算完括号里的
				Ope.pop();  //左括号出栈
			}
			else if (priority(Ope.top()) >= priority(ope_)) {  //如果栈顶符号的优先级大于等于当前
				calculate(Ope, Num);   //计算结果压入数字栈,取出当前栈顶
				Ope.push(ope_);  //压入当前符号
			}
			else Ope.push(ope_);  //否则就压入符号栈
		}
	}
}

void calculate(stack<char>& Ope, stack<double>& Num) {
	double a, b;
	a = Num.top(); Num.pop();
	b = Num.top(); Num.pop();

	if (Ope.top() == '+') Num.push(b + a);
	else if (Ope.top() == '-') Num.push(b - a);
	else if (Ope.top() == '*') Num.push(b * a);
	else if (Ope.top() == '/') Num.push(b / a);

	Ope.pop();
}

int priority(char ope_) {
	if (ope_ == '(') return 0;
	else if (ope_ == '+' || ope_ == '-') return 1;
	else if (ope_ == '*' || ope_ == '/') return 2;
}