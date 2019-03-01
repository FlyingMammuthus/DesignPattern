#pragma once
#include <iostream>
#include <string>
#include <map>

/*
�н���ģʽ���壺��һ���н��������װһϵ�еĶ��󽻻���
�н���ʹ��������Ҫ��ʽ���໥���ã��Ӷ�ʹ�������ɢ�����ҿ��Զ����ظı�����֮��Ľ�����

�ٸ��򵥵����ӣ��ͱ�����ƽʱϲ����΢�����죬�㷢�͵�����������Ҫͨ��΢�ŷ����������м䴦��
Ȼ���·�����ĺ��ѣ�΢�ŷ���������һ���н��ߡ�

��ɫ
Mediator: �����н���
ConcreteMediator: �����н���
Colleague: ����ͬ����
ConcreteColleague: ����ͬ����

�н���ģʽ��������Ҫ���ã���ת���ã��ṹ�ԣ���ͨ���н����ṩ����ת���ã�����ͬ�¶���Ͳ�����Ҫ��ʽ��������ͬ�£�
����Ҫ������ͬ�½���ͨ��ʱ��ͨ���н��߼��ɡ�����ת���������н����ڽṹ�ϵ�֧�֡�

Э�����ã���Ϊ�ԣ����н��߿��Ը���һ���Ķ�ͬ��֮��Ĺ�ϵ���з�װ��ͬ�¿���һ�µغ��н��߽��н�����
������Ҫָ���н�����Ҫ������ô�����н��߸��ݷ�װ�������ڲ���Э���߼�����ͬ�µ�������н�һ������
��ͬ�³�Ա֮��Ĺ�ϵ��Ϊ���з���ͷ�װ����Э�����������н�������Ϊ�ϵ�֧�֡�

*/

using namespace std;

class colleague;

class mediator {
public:
	virtual void operation(int id, string message) = 0;
	virtual void medRegister(int id, colleague *clg) = 0;
};

class colleague {
public:
	virtual void sendMsg(int id, string message) = 0;

	virtual void receiveMsg(string message) = 0;

	void setMediator(mediator *mdt_in) {
		mdt = mdt_in;
	}

protected:
	mediator * mdt;
};

class colleagueA : public colleague {
public:
	void sendMsg(int id, string message) {
		cout << "Send message from colleagueA to " << id << endl;
		mdt->operation(id, message);
	}

	void receiveMsg(string message) {
		cout << "ColleagueA receive message \"" << message << "\"" << endl;
	}
};

class colleagueB : public colleague {
public:
	void sendMsg(int id, string message) {
		cout << "Send message from colleagueB to " << id << endl;
		mdt->operation(id, message);
	}

	void receiveMsg(string message) {
		cout << "ColleagueB receive message \"" << message << "\"" << endl;
	}
};

typedef map<int, colleague*> colleagueMap;
class myMediator : public mediator {
public:
	void operation(int id, string message) {
		colleagueMap::iterator it_clg = clgs->find(id);
		if (it_clg == clgs->end()) {
			cout << "Colleague not found" << endl;
		}
		else {
			it_clg->second->receiveMsg(message);
		}
	}

	void medRegister(int id, colleague *clg) {
		colleagueMap::iterator iter = clgs->find(id);
		if (iter == clgs->end()) {
			clgs->insert(colleagueMap::value_type(id, clg));
		}
		clg->setMediator(this);
	}

	static void deleteColleagueMap() {
		delete clgs;
	}

protected:
	static colleagueMap *clgs;
};

colleagueMap* myMediator::clgs = new colleagueMap();

void test13() {
	colleague *clgA = new colleagueA();
	colleague *clgB = new colleagueB();
	mediator * mdt = new myMediator();
	mdt->medRegister(1, clgA);
	mdt->medRegister(2, clgB);
	clgA->sendMsg(2, string("Hello, id 2"));
	clgB->sendMsg(1, string("Hi, id 1"));
	delete mdt;
	delete clgB;
	delete clgA;
}

