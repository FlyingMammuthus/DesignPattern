#pragma once
#include <iostream>

/*
代理模式
所谓的代理者是指一个类别可以作为其它东西的接口。
代理者可以作任何东西的接口：网络连接、内存中的大对象、文件或其它昂贵或无法复制的资源。
代理对象可以在客户端和目标对象之间起到中介的作用，
并且可以通过代理对象去掉客户不能看到的内容和服务或者添加客户需要的额外服务。
可能大家听得最多且最常用的就是VPN网络代理，或者代理服务器等。

角色
Subject: 抽象主题角色
Proxy: 代理主题角色
RealSubject: 真实主题角色
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