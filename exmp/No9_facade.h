#pragma once
#include <iostream>

/*
���ģʽ(Facade Pattern)���ⲿ��һ����ϵͳ��ͨ�ű���ͨ��һ��ͳһ����۶�����У�
Ϊ��ϵͳ�е�һ��ӿ��ṩһ��һ�µĽ��棬���ģʽ������һ���߲�ӿڣ�����ӿ�ʹ����һ��ϵͳ��������ʹ�á�
���ģʽ�ֳ�Ϊ����ģʽ������һ�ֶ���ṹ��ģʽ��

��һ���򵥵����ӣ����Ŵ�Ҷ�ʹ�ù� C++ ���ԣ�����һ�ű��������ԣ�д�����֮��
������Ҫ��������֮��������У���IDE�У�����һ�� Build �İ�ť�������������ɱ�����̣�
������һ���򵥵Ķ�������ȴ��һϵ�и��Ӳ�����Э����ϣ����ٰ����ʷ��������﷨�����������м���룬
���ɻ������Լ����ӵȲ�������Ϊ��ͨ������Ա�����ǲ���������Щ�����������ɵģ�ֻ��Ҫ���Build��ť��
IDE�ͻ��Զ���������ɱ���Ĺ�������ô���Build��ť����IDEΪ�����ṩ�ĸ߼��ӿڣ�
ͨ��������ɸ�����ϵͳ��Э��������

��ɫ��

Facade����۽�ɫ���ṩ�߼��ӿ�

SubSystem����ϵͳ��ɫ��������ԵĹ���ʵ��
*/
using namespace std;
class systemA {
public: 
	void operationA() {
		cout << "OperationA" << endl;
	}
};

class systemB {
public:
	void operationB() {
		cout << "OperationB" << endl;
	}
};

class systemC {
public:
	void operationC() {
		cout << "OperationC" << endl;
	}
};

class facade {
public:
	facade() {
		sysA = new systemA();
		sysB = new systemB();
		sysC = new systemC();
	}

	~facade() {
		delete sysA;
		delete sysB;
		delete sysC;
	}

	void operation() {
		sysA->operationA();
		sysB->operationB();
		sysC->operationC();
	}

protected:
	systemA * sysA;
	systemB * sysB;
	systemC * sysC;
};


void test9() {
	facade *f = new facade();
	f->operation();
	delete f;
}