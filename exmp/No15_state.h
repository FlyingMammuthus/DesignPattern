#pragma once
#include <iostream>
/*
״̬ģʽ
״̬ģʽ������һ�����������ڲ�״̬�ı�ʱ�ı�������Ϊ�����������ƺ��޸��������ࡣ
�����Ϊ״̬����(Objects for States)��״̬ģʽ��һ�ֶ�����Ϊ��ģʽ��
��ʱ��һ���������Ϊ����һ��������������Ա仯���仯������������Ҳ����״̬�������ĵĶ���Ҳ������״̬�Ķ���

��ɫ
Context: �����࣬ά��һ��ConcreteState�����ʵ�������ʵ�����嵱ǰ״̬��
State: ����״̬�࣬����һ���ӿ��Է�װ��Context��һ���ض�״̬��ص���Ϊ��
ConcreteState: ����״̬�࣬ÿһ������ʵ��һ����Context��һ��״̬��ص���Ϊ��
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