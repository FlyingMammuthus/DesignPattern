#pragma once
#include <iostream>

/*
����ģʽ������������������У�һ�ֶ�̬����һ����������µ���Ϊ�����ģʽ��
�͹��ܶ��ԣ�����ģʽ������������Ϊ���������Ը�ĳ��������������������һЩ���ܡ�

һ����˵����һ�����������������Ϊ�ķ�ʽ���������֣�

�̳л��ƣ�ʹ�ü̳л����Ǹ���������ӹ��ܵ�һ����Ч;����ͨ���̳�һ�����������ʹ��������ӵ����������ͬʱ��ӵ�и���ķ�����
�������ַ����Ǿ�̬�ģ��û����ܿ���������Ϊ�ķ�ʽ��ʱ����

�������ƣ�����һ����Ķ���Ƕ����һ�������У�����һ�������������Ƿ����Ƕ��������Ϊ�Ա���չ�Լ�����Ϊ��
���ǳ����Ƕ��Ķ���Ϊװ����(Decorator)

ͨ��ʹ������ģʽ������������ʱ����һ����Ĺ��ܡ�ԭ���ǣ�����һ�����������ԭ�����࣬
�����ķ�ʽһ����ͨ���ڽ�ԭ���Ķ�����Ϊ������Ĺ��캯���Ĳ�����װ����ʵ���µĹ��ܣ�
���ǣ��ڲ���Ҫ�õ��¹��ܵĵط���������ֱ�ӵ���ԭ�������еķ���������������ԭ����������ͬ�Ľӿڡ�

����ģʽ����̳е�����һ��ѡ����̳��ڱ���ʱ��������Ϊ����װ��ģʽ��������ʱ������Ϊ��

��ɫ
Component: ���󹹼�
ConcreteComponent: ���幹��
Decorator: ����װ����
ConcreteDecorator: ����װ����
*/
using namespace std;
class component {
public:
	virtual void operation() = 0;
};

class MyComponent : public component {
public:
	void operation() {
		cout << "This is the normal component operation." << endl;
	}
};

class decorator : public component {
public:
	decorator(component * comp_in):comp(comp_in) {}

	void operation() {
		comp->operation();
	}

protected:
	component * comp;
};

class MyDecorator : public decorator {
public:
	MyDecorator(component *comp_in):decorator(comp_in) {}

	void addMethod() {
		cout << "This is the added method of decorator." << endl;
	}

	void operation() {
		addMethod();
		decorator::operation();  //���ø��෽��
	}
};

void test8() {
	component *comp = new MyComponent();
	decorator *decrt = new MyDecorator(comp);
	decrt->operation();
	delete decrt;
	delete comp;
}
