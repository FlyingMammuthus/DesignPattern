#pragma once
#include <iostream>
#include <string>

/*
�ڴ���ģʽ�У�һ��Ŀ���������������������Ĺ۲��߶��󣬲������������״̬�ı�ʱ��������֪ͨ��
��ͨ��͸�����и��۲������ṩ�ķ�����ʵ�֡�����ģʽͨ��������ʵʱ�¼�����ϵͳ��
�۲���ģʽ�ֽ�������-���ģ�Publish/Subscribe��ģʽ��ģ��-��ͼ��Model/View��ģʽ��
Դ-��������Source/Listener��ģʽ������ߣ�Dependents��ģʽ��

��ɫ
Subject: ����Ŀ���࣬һ�������ṩ�����ӿڣ�
��(Attach)�������۲��ߵ������ڣ���׷��Ŀ�����ı仯��
�⸽(Detach)�����Ѿ����ڵĹ۲��ߴӴ������Ƴ���
֪ͨ(Notify)�����ù۲������ṩ�ĸ��º�ʽ��֪ͨ��Ŀ���Ѿ������仯��

ConcreteSubject: ����Ŀ�꣬�ṩ�˹۲�����׷�ٵ�״̬��Ҳ������Ŀ��״̬

Observer: ����۲��ߣ�����۲��ߵĸ��²����ӿ�

ConcreteObserver: ����۲��ߣ�ʵ�ֳ���۲��ߵĽӿڣ������Լ��ĸ��²���
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