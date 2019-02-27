#pragma once
#include <iostream>
#include <string>
#include <map>

/*
享元模式（英语：Flyweight Pattern）是一种软件设计模式。
它使用共享物件，用来尽可能减少内存使用量以及分享资讯给尽可能多的相似物件；
它适合用于当大量物件只是重复因而导致无法令人接受的使用大量内存。
通常物件中的部分状态是可以分享。常见做法是把它们放在外部数据结构，
当需要使用时再将它们传递给享元。由于享元模式要求能够共享的对象必须是细粒度对象，
因此它又称为轻量级模式，它是一种对象结构型模式。

要理解享元模式，先要理解两个重要的概念：内部状态和外部状态。

内部状态存储于flyweight中，它包含了独立于flyweight场景的信息，这些信息使得flyweight可以被共享。
而外部状态取决于flyweight场景，并根据场景而变化，因此不可共享。用户对象负责在必要的时候将外部状态传递给flyweight。

角色
Flyweight： 抽象享元类
ConcreteFlyweight： 具体享元类
UnsharedConcreteFlyweight： 非共享具体享元类
FlyweightFactory： 享元工厂类

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