#pragma once
#include <iostream>

/*
�����ģʽ�У�������ģʽ��Ӣ�adapter pattern����ʱ��Ҳ�ư�װ��ʽ���߰�װ(wrapper)��
��һ����)�Ľӿ�ת�ӳ��û����ڴ��ġ�һ������ʹ����ӿڲ����ݶ�������һ�������๤����һ��
�����ǽ����Լ��Ľӿڰ�����һ���Ѵ��ڵ����С�

����˼�壬��ģʽ��Դ�������ڵ�Դ����������ƺͱ��뼼�ɡ�����������һЩ�࣬�ṩһЩ���õĽӿڣ�
���ǿ��ܿͻ�����Ϊ�����ݵ�ԭ�򣬲���ֱ�ӵ�����Щ���еĽӿڣ���ʱ����Ҫһ������������Ϊ��תվ��
��������������û��ṩ���õĽӿڣ����ڲ����յ�������ת��Ϊ�������߶�Ӧ�ӿڵ���������
�Ӷ�ʵ�ֶԲ����ݵ���ĸ��á�

�ŵ㣺��Ŀ���������������ͨ������һ�������������������е��������࣬�������޸�ԭ�д��롣
���������͸���Ժ͸����ԣ��������ʵ�ַ�װ�����������У����ڿͻ�������˵��͸���ģ���������������ߵĸ����ԡ�

��ɫ��
Target��Ŀ�������
Adapter����������
Adaptee����������
Client���ͻ���
*/

using namespace std;

class adaptee {
public:
	void realRequest() {
		cout << "This is the real request" << endl;
	}
};

class target {
public:
	virtual void request() = 0;
};

class adapter : target {
public:
	adapter(adaptee *adpee_in) : adpee(adpee_in) {}

	void request() {
		adpee->realRequest();
	}

protected:
	adaptee * adpee;
};

void test6() {
	adaptee *adpee = new adaptee();
	adapter *trgt = new adapter(adpee);
	trgt->request();
	delete trgt;
	delete adpee;
}

