#pragma once
#include <iostream>
#include <string>
#include <map>

/*
中介者模式定义：用一个中介对象来封装一系列的对象交互。
中介者使各对象不需要显式地相互引用，从而使其耦合松散，而且可以独立地改变它们之间的交互。

举个简单的例子，就比如大家平时喜欢用微信聊天，你发送的聊天内容需要通过微信服务器进行中间处理，
然后下发给你的好友，微信服务器就是一个中介者。

角色
Mediator: 抽象中介者
ConcreteMediator: 具体中介者
Colleague: 抽象同事类
ConcreteColleague: 具体同事类

中介者模式的两个主要作用：中转作用（结构性）：通过中介者提供的中转作用，各个同事对象就不再需要显式引用其他同事，
当需要和其他同事进行通信时，通过中介者即可。该中转作用属于中介者在结构上的支持。

协调作用（行为性）：中介者可以更进一步的对同事之间的关系进行封装，同事可以一致地和中介者进行交互，
而不需要指明中介者需要具体怎么做，中介者根据封装在自身内部的协调逻辑，对同事的请求进行进一步处理，
将同事成员之间的关系行为进行分离和封装。该协调作用属于中介者在行为上的支持。

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

