//֧�ִ����ŵı��ʽ,֧��+-*/��^(ָ��)��ȡ����!(�׳�)
#include <iostream>
#include <stack>
#include <math.h>

using namespace std;

double inStack();   //���ĺ��������������������ջ���㣬 ��󷵻ؽ��
void calculate(stack<char>& Ope, stack<double>& Num);  //��������Ӽ��˳�, �����������ջ��
void factorial(stack<double>& Num);   //��������׳�
int priority(char ope_);   //������������������ȼ�

int main() {
	double result;   //���Ľ��

	cout << "�����룺\n";
	result = inStack();   //���������Ĳ�����������ѹ��ջ 

	cout << "����ǣ�\n" << result;

	return 0;
}

double inStack() {
	stack<char> Ope;
	stack<double> Num;
	char ope_;
	double num_;

	while (1) {
		if (cin.peek() >= '0' && cin.peek() <= '9') {  //�ж���һ���Ƿ�������
			cin >> num_;
			Num.push(num_);   //����ֱ����ջ
		}
		else {
			cin >> ope_;
			if (ope_ == '=') {
				while (!Ope.empty()) calculate(Ope, Num); //�������ջ���գ���һֱ����
				return Num.top();  //����ǵȺ��ҷ���ջ��Ϊ�գ��ͷ�������ջ��Ԫ��
			}
			else if (ope_ == '!') factorial(Num);  //����ǣ��ͽ׳�
			else if (ope_ == '(' ||Ope.empty()) Ope.push(ope_);    //��������������Ż����ջΪ��ֱ��ѹ��
			else if (ope_ == ')') {  //�����������
				while (Ope.top() != '(') calculate(Ope, Num); //һֱ�������������
				Ope.pop();  //�����ų�ջ
			}
			else if (priority(Ope.top()) >= priority(ope_)) {  //���ջ�����ŵ����ȼ����ڵ��ڵ�ǰ
				calculate(Ope, Num);   //������ѹ������ջ,ȡ����ǰջ��
				Ope.push(ope_);  //ѹ�뵱ǰ����
			}
			else Ope.push(ope_);  //�����ѹ�����ջ
		}
	}
}

void calculate(stack<char>& Ope, stack<double>& Num) {
	double a, b;

	if (Ope.top() == '-') {
		a = Num.top(); Num.pop();
		Ope.pop();   //ȡ������
		Num.push(-a);  //ѹ�븺ֵ
		if (!Num.empty()) {
			if(Ope.empty() || Ope.top() != '(')
				Ope.push('+');  //���ǰ�滹�����֣���ѹ��+������ɼӸ�ֵ
		}
	}
	else {
		a = Num.top(); Num.pop();
		b = Num.top(); Num.pop();

		if (Ope.top() == '+') Num.push(b + a);
		else if (Ope.top() == '*') Num.push(b * a);
		else if (Ope.top() == '/') Num.push(b / a);
		else if (Ope.top() == '^') Num.push(pow(b, a));

		Ope.pop();
	}
}

void factorial(stack<double>& Num) {
	int a = static_cast<int>(Num.top());
	int result=1;

	for (int i = 1; i <= a; i++) result *= i;

	Num.push(static_cast<double>(result));
}

int priority(char ope_) {
	if (ope_ == '(') return 0;
	else if (ope_ == '+' || ope_ == '-') return 1;
	else if (ope_ == '*' || ope_ == '/') return 2;
	else if (ope_ == '^') return 3;
}