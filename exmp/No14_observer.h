#pragma once
#include <iostream>
#include <string>

/*
在此种模式中，一个目标对象管理所有相依于它的观察者对象，并且在它本身的状态改变时主动发出通知。
这通常透过呼叫各观察者所提供的方法来实现。此种模式通常被用来实时事件处理系统。
观察者模式又叫做发布-订阅（Publish/Subscribe）模式、模型-视图（Model/View）模式、
源-监听器（Source/Listener）模式或从属者（Dependents）模式。

角色
Subject: 抽象目标类，一般至少提供三个接口：
添附(Attach)：新增观察者到串炼内，以追踪目标对象的变化。
解附(Detach)：将已经存在的观察者从串炼中移除。
通知(Notify)：利用观察者所提供的更新函式来通知此目标已经产生变化。

ConcreteSubject: 具体目标，提供了观察者欲追踪的状态，也可设置目标状态

Observer: 抽象观察者，定义观察者的更新操作接口

ConcreteObserver: 具体观察者，实现抽象观察者的接口，做出自己的更新操作
*/

class obSubject;
class observer;

typedef map<int, observer*> observerMap;

class observer {
public:
	observer(int id_in) : id(id_in) {}

	virtual void update(obSubject *sub) = 0;

	int getId() {
		return id;
	}

protected:
	int id;
};

class obSubject {
public:
	void attach(observer *obsrv_in) {
		observerMap::iterator iter = obsrvs->find(obsrv_in->getId());
		if (iter == obsrvs->end()) {
			obsrvs->insert(observerMap::value_type(obsrv_in->getId(), obsrv_in));
		}
	}

	void deattach(observer *obsrv_in) {
		observerMap::iterator iter = obsrvs->find(obsrv_in->getId());
		if (iter != obsrvs->end()) {
			obsrvs->erase(iter);
		}
	}

	virtual void setState(int state) = 0;

	virtual int getState() = 0;

	virtual void notify() {
		observerMap::iterator iter = obsrvs->begin();
		while (iter != obsrvs->end()) {
			iter->second->update(this);
			iter++;
		}
	}

protected:
	static observerMap *obsrvs;
};

observerMap* obSubject::obsrvs = new observerMap();

class mySubject : public obSubject {
public:
	void setState(int state_in) {
		state = state_in;
	}

	int getState() {
		return state;
	}

protected:
	int state;
};

class myObserver : public observer {
public:

	myObserver(int Id, string name_in) : observer(Id) {
		obName = name_in;
	}

	void update(obSubject* sub) {
		cout << "Update Obeserver[" << obName << "] State: " << sub->getState() << endl;
	}

protected:
	string obName;
};

void test14() {
	obSubject *sub = new mySubject();
	myObserver *one = new myObserver(1, string("one")),
		*two = new myObserver(2, string("two"));

	sub->attach(one);
	sub->attach(two);
	sub->setState(1);
	sub->notify();

	sub->setState(2);
	sub->deattach(two);
	sub->notify();
}