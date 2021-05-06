/*���Լ�������ŵı��ʽ������ֻ�ܼ���ʮ���ڵ�����*/

#include <iostream>
#include <stack>

using namespace std;

double inStack();   //���ĺ��������������������ջ���㣬 ��󷵻ؽ��
void calculate(stack<char>& Ope, stack<int>& Num);  //��������Ӽ��˳�, �����������ջ��
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
	stack<int> Num;
	char ch;

	while (1) {
		cin >> ch;   //����һ���ַ�
		if(ch>='0'&&ch<='9') Num.push(ch-'0');   //����ֱ����ջ
		else if (ch == '=') {
			while (!Ope.empty()) calculate(Ope, Num); //�������ջ���գ���һֱ����
			return Num.top();  //����ǵȺ��ҷ���ջ��Ϊ�գ��ͷ�������ջ��Ԫ��
		}
		else if (ch == '('||Ope.empty()) Ope.push(ch);    //��������������Ż����ջΪ��ֱ��ѹ��
		else if (ch == ')') {  //�����������
			while(Ope.top()!='(') calculate(Ope, Num); //һֱ�������������
			Ope.pop();  //�����ų�ջ
		}
		else if (priority(Ope.top()) >= priority(ch)) {  //���ջ�����ŵ����ȼ����ڵ��ڵ�ǰ
			calculate(Ope, Num);   //������ѹ������ջ,ȡ����ǰջ��
			Ope.push(ch);  //ѹ�뵱ǰ����
		}
		else Ope.push(ch);  //�����ѹ�����ջ
	}
}

void calculate(stack<char>& Ope, stack<int>& Num) {
	int a, b;
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