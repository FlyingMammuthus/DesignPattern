#pragma once
#include <iostream>
/*
����ģʽ
���������У����Ǿ�����Ҫ��ĳЩ���������󣬵��ǲ���֪������Ľ�������˭��Ҳ��֪��������Ĳ������ĸ���
����ֻ���ڳ�������ʱָ���������������߼��ɣ���ʱ������ʹ������ģʽ��������ƣ�
ʹ��������������������������˴�֮�����ϣ��ö���֮��ĵ��ù�ϵ������

��Ҫ�ص���ǽ�һ�������װΪһ�����󣬴Ӷ�ʹ���ǿ��ò�ͬ������Կͻ����в�������
�������Ŷӻ��߼�¼������־���Լ�֧�ֿɳ����Ĳ���������ģʽ��һ�ֶ�����Ϊ��ģʽ��
�����Ϊ����(Action)ģʽ������(Transaction)ģʽ��

��ɫ
Command: ����������
ConcreteCommand: ����������
Invoker: ������
Receiver: ������
Client:�ͻ���
*/
using namespace std;
class receiver {
public:
	void action() {
		cout << "receiver->action" << endl;
	}
};

class command {
public:
	command(receiver* rcvr_in): rcvr(rcvr_in) {}

	virtual void execute() = 0;

protected:
	receiver * rcvr;
};

class myCommand : public command {
public:
	myCommand(receiver* rcvr_in): command(rcvr_in){}

	void execute() {
		rcvr->action();
	}
};

class invoker {
public:
	invoker(command *cmd_in) : cmd(cmd_in) {}

	void invoke() {
		cmd->execute();
	}

protected:
	command * cmd;
};

void test12() {
	receiver *rcv = new receiver();
	command *cmd = new myCommand(rcv);
	invoker *invk = new invoker(cmd);
	invk->invoke();
	delete invk;
	delete cmd;
	delete rcv;

}
