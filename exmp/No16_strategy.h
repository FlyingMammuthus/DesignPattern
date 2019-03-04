#pragma once
#include <iostream>

/*
����ģʽ(Strategy Pattern)������һϵ���㷨����ÿһ���㷨��װ�������������ǿ����໥�滻������ģʽ���㷨������ʹ�����Ŀͻ����仯��Ҳ��Ϊ����ģʽ(Policy)��

����ʾ���������������㷨�п�������ð�����򣬹鲢����ѡ������ȣ����������Ҫ��һ���㷨�����ṩ��Щ�㷨��һ�������Ľ���������������ж�����������ÿ����������һ�־���������㷨��Ȼ��ʹ�� if...else...ȥ�жϵ����������㷨������ֱ�ӵ���ĳ�����巽�������ַ����ǽ��㷨��ʵ��Ӳ���뵽���У����������ı׶˾����㷨����ǳ�ӷ�ף����ҵ���Ҫ���ӻ��߸���һ���µ����򷽷�ʱ����Ҫ�޸��㷨��Ĵ��룬ͬʱҲ��Ҫ�޸Ŀͻ��˵��ô��Ĵ��롣����ģʽ����Ϊ�˽�������������Ƶġ�

��ɫ

Context: �����࣬ʹ��һ��ConcreteStrategy���������ã�ά��һ����Stategy��������ã�ͬʱ�����Զ���һ���ӿ�����Stategy�����������ݡ�

Strategy: ��������࣬��������֧�ֵ��㷨�Ĺ����ӿڡ�Contextʹ������ӿ�������ĳConcreteStrategy������㷨��

ConcreteStrategy: ��������࣬ʵ�� Strategy �ӿڵľ����㷨��
*/
using namespace std;

class strategy {
public:
	virtual void use() = 0;
};

class strategyA : public strategy {
public:
	void use() {
		cout << "Using strategy A..." << endl;
	}
};

class strategyB : public strategy {
public:
	void use() {
		cout << "Using strategy B..." << endl;
	}
};

class strcontext {
public:
	void setStrategy(strategy *strtg_in) {
		strtg = strtg_in;
	}

	void use() {
		strtg->use();
	}

protected:
	strategy * strtg;
};

void test16() {
	strcontext* cont = new strcontext();
	strategyA* strtgA = new strategyA();
	strategyB* strtgB = new strategyB();
	cont->setStrategy(strtgA);
	cont->use();

	cont->setStrategy(strtgB);
	cont->use();

	delete strtgA;
	delete strtgB;
	delete cont;
}