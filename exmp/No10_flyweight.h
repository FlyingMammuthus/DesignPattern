#pragma once
#include <iostream>
#include <string>
#include <map>

/*
��Ԫģʽ��Ӣ�Flyweight Pattern����һ��������ģʽ��
��ʹ�ù�����������������ܼ����ڴ�ʹ�����Լ�������Ѷ�������ܶ�����������
���ʺ����ڵ��������ֻ���ظ���������޷����˽��ܵ�ʹ�ô����ڴ档
ͨ������еĲ���״̬�ǿ��Է������������ǰ����Ƿ����ⲿ���ݽṹ��
����Ҫʹ��ʱ�ٽ����Ǵ��ݸ���Ԫ��������ԪģʽҪ���ܹ�����Ķ��������ϸ���ȶ���
������ֳ�Ϊ������ģʽ������һ�ֶ���ṹ��ģʽ��

Ҫ�����Ԫģʽ����Ҫ���������Ҫ�ĸ���ڲ�״̬���ⲿ״̬��

�ڲ�״̬�洢��flyweight�У��������˶�����flyweight��������Ϣ����Щ��Ϣʹ��flyweight���Ա�����
���ⲿ״̬ȡ����flyweight�����������ݳ������仯����˲��ɹ����û��������ڱ�Ҫ��ʱ���ⲿ״̬���ݸ�flyweight��

��ɫ
Flyweight�� ������Ԫ��
ConcreteFlyweight�� ������Ԫ��
UnsharedConcreteFlyweight�� �ǹ��������Ԫ��
FlyweightFactory�� ��Ԫ������

*/
using namespace std;

class flyweight {
public:
	virtual void operation() = 0;
};

class myflyweight : public flyweight {
public:
	myflyweight(string str_in) {
		intrinsicState = new string(str_in);
	}

	~myflyweight() {
		delete intrinsicState;
	}

	void operation() {
		cout << "MyFlyWeight[" << *intrinsicState << "] do operation." << endl;
	}

protected:
	string *intrinsicState;
};

typedef map<string, myflyweight*> flyweightPool;

class flyweightFactory {
public:
	myflyweight * getFlyweight(string str) {
		flyweightPool::iterator iter = fwPool->find(str);
		if (iter == fwPool->end()) {
			myflyweight* fw_ins = new myflyweight(str);
			fwPool->insert(flyweightPool::value_type(str, fw_ins));
			return fw_ins;
		}
		else {
			cout << "Flyweight[" << str << "] has already been in the pool. Use the existing one.";
			return iter->second;
		}
	}

	static void deletePool() {
		flyweightPool::iterator iter = fwPool->begin();
		while (iter != fwPool->end()) {
			delete iter->second;
			iter->second = nullptr;
			iter++;
		}
		fwPool->clear();
		delete fwPool;
	}
protected:
	static flyweightPool *fwPool;
};

flyweightPool * flyweightFactory::fwPool = new flyweightPool();

void test10() {
	flyweightFactory* fwFactory = new flyweightFactory();
	myflyweight *myfw;

	myfw = fwFactory->getFlyweight(string("One"));
	myfw->operation();

	myfw = fwFactory->getFlyweight(string("Two"));
	myfw->operation();

	myfw = fwFactory->getFlyweight(string("Three"));
	myfw->operation();

	flyweightFactory::deletePool();
}