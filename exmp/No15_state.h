#pragma once
#include <iostream>
/*
状态模式
状态模式：允许一个对象在其内部状态改变时改变它的行为。对象看起来似乎修改了它的类。
其别名为状态对象(Objects for States)，状态模式是一种对象行为型模式。
有时，一个对象的行为受其一个或多个具体的属性变化而变化，这样的属性也叫作状态，这样的的对象也叫作有状态的对象。

角色
Context: 环境类，维护一个ConcreteState子类的实例，这个实例定义当前状态；
State: 抽象状态类，定义一个接口以封装与Context的一个特定状态相关的行为；
ConcreteState: 具体状态类，每一个子类实现一个与Context的一个状态相关的行为。
*/

using namespace std;

class context;

class stState {
public:
	virtual void handle(context *cont) = 0;
};

class stateA : public stState {
public:
	void handle(context *cont);

	static stateA* getInstance() {
		if (instance == nullptr) {
			instance = new stateA();
		}
		return instance;
	}

	static void deleteInstance() {
		if (instance != nullptr) {
			delete instance;
		}
	}

private:
	static stateA* instance;

	stateA() {}

	stateA(const stateA&) {}

	stateA& operator=(const stateA&) {}
};
stateA* stateA::instance = nullptr;

class stateB : public stState {
public:
	void handle(context *cont);

	static stateB* getInstance() {
		if (instance == nullptr) {
			instance = new stateB();
		}
		return instance;
	}

	static void deleteInstance() {
		if (instance != nullptr) {
			delete instance;
		}
	}

private:
	static stateB* instance;

	stateB() {}

	stateB(const stateB&) {}

	stateB& operator=(const stateB&) {}
};
stateB* stateB::instance = nullptr;

class context {
public:
	context() {
		state = stateA::getInstance();
	}

	void changeState(stState *state_in) {
		state = state_in;
	}

	void request() {
		state->handle(this);
	}

protected:
	stState * state;
};

void stateA::handle(context *cont) {
	cout << "Handling in state A..." << endl << "Done!!! Change state to B" << endl;
	cont->changeState(stateB::getInstance());
}

void stateB::handle(context *cont) {
	cout << "Handling in state B..." << endl << "Done!!! Change state to A" << endl;
	cont->changeState(stateA::getInstance());
}

void test15() {
	context *cont = new context();
	cont->request();
	cont->request();
	cont->request();
	cont->request();
	delete cont;
	stateA::deleteInstance();
	stateB::deleteInstance();
}