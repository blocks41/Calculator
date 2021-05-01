#include <iostream>
#include <stack>

using namespace std;

double inStack();   //���ĺ��������������������ջ���㣬 ��󷵻ؽ��
void calculate(stack<char>& Ope, stack<double>& Num);  //��������Ӽ��˳�, �����������ջ��
int priority(char ope_);   //������������������ȼ�

int main() {
	double result;   //���Ľ��

	cout << "�����룺\n";
	result = inStack();   //���������Ĳ�����������ѹ��ջ 

	cout <<"����ǣ�\n"<< result;

	return 0;
}

double inStack() {
	stack<char> Ope;
	stack<double> Num;
	double num_;
	char ope_;

	while (1) {
		cin >> num_ >> ope_;   //�������ŵļ��㣬����������Ǽ�����е�
		Num.push(num_);   //����ֱ����ջ

		if (ope_ == '=') {
			while (!Ope.empty()) calculate(Ope, Num); //�������ջ���գ���һֱ����
			return Num.top();  //����ǵȺ��ҷ���ջ��Ϊ�գ��ͷ�������ջ��Ԫ��
		}
		else if (Ope.empty()) Ope.push(ope_);    //ѹ�����
		else if (priority(Ope.top()) >= priority(ope_)) {  //���ջ�����ŵ����ȼ����ڵ��ڵ�ǰ
			calculate(Ope, Num);   //������ѹ������ջ,ȡ����ǰջ��
			Ope.push(ope_);  //ѹ�뵱ǰ����
		}
		else Ope.push(ope_);  //�����ѹ�����ջ
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