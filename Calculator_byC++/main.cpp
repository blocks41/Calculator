#include <iostream>
#include <stack>

using namespace std;

void inStack(stack<char>& Ope, stack<double>& Num);
double calculate(stack<char>& Ope, stack<double>& Num);

int main() {
	stack<char> Ope;
	stack<double> Num;
	double result;

	cout << "�����룺\n";
	inStack(Ope, Num);   //���������Ĳ�����������ѹ��ջ 

	result=calculate(Ope, Num);   //������
	cout <<"����ǣ�"<< result;

	return 0;
}

void inStack(stack<char>& Ope, stack<double>& Num) {

}

double calculate(stack<char>& Ope, stack<double>& Num) {

}