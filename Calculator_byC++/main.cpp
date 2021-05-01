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

	cout <<"结果是：\n"<< result;

	return 0;
}

double inStack() {
	stack<char> Ope;
	stack<double> Num;
	double num_;
	char ope_;

	while (1) {
		cin >> num_ >> ope_;   //不带括号的计算，数字与符号是间隔排列的
		Num.push(num_);   //数字直接入栈

		if (ope_ == '=') {
			while (!Ope.empty()) calculate(Ope, Num); //如果符号栈不空，就一直计算
			return Num.top();  //如果是等号且符号栈顶为空，就返回数字栈顶元素
		}
		else if (Ope.empty()) Ope.push(ope_);    //压入符号
		else if (priority(Ope.top()) >= priority(ope_)) {  //如果栈顶符号的优先级大于等于当前
			calculate(Ope, Num);   //计算结果压入数字栈,取出当前栈顶
			Ope.push(ope_);  //压入当前符号
		}
		else Ope.push(ope_);  //否则就压入符号栈
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
	if (ope_ == '+' || ope_ == '-') return 1;
	else if (ope_ == '*' || ope_ == '/') return 2;
}