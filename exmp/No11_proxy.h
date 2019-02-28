#pragma once
#include <iostream>

/*
����ģʽ
��ν�Ĵ�������ָһ����������Ϊ���������Ľӿڡ�
�����߿������κζ����Ľӿڣ��������ӡ��ڴ��еĴ�����ļ�������������޷����Ƶ���Դ��
�����������ڿͻ��˺�Ŀ�����֮�����н�����ã�
���ҿ���ͨ���������ȥ���ͻ����ܿ��������ݺͷ��������ӿͻ���Ҫ�Ķ������
���ܴ�������������õľ���VPN����������ߴ���������ȡ�

��ɫ
Subject: ���������ɫ
Proxy: ���������ɫ
RealSubject: ��ʵ�����ɫ
*/

using namespace std;

class subject {
public:
	virtual void request() = 0;
};

class realSubject : public subject {
public:
	void request() {
		cout << "realSubject::request..." << endl;
	}
};

class proxy : public subject {
public:
	proxy() {
		realsub = new realSubject();
	}

	~proxy() {
		delete realsub;
	}

	void beforeRequest() {
		cout << "proxy::beforeRequest..." << endl;
	}

	void afterRequest() {
		cout << "proxy::afterRequest..." << endl;
	}

	void request() {
		beforeRequest();
		realsub->request();
		afterRequest();
	}

protected:
	realSubject * realsub;
};

void test11() {
	proxy *prxy = new proxy();
	prxy->request();
	delete prxy;
}