#include <iostream>
#include <stack>

using namespace std;

void inStack(stack<char>& Ope, stack<double>& Num);
double calculate(stack<char>& Ope, stack<double>& Num);

int main() {
	stack<char> Ope;
	stack<double> Num;
	double result;

	cout << "请输入：\n";
	inStack(Ope, Num);   //将缓冲区的操作符和数字压入栈 

	result=calculate(Ope, Num);   //计算结果
	cout <<"结果是："<< result;

	return 0;
}

void inStack(stack<char>& Ope, stack<double>& Num) {

}

double calculate(stack<char>& Ope, stack<double>& Num) {

}