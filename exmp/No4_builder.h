#pragma once
#include <iostream>
#include <string>

/*
������������ģʽ����һ�ֶ��󹹽�ģʽ�������Խ����Ӷ���Ľ�����̳��������������𣩣�
ʹ���������̵Ĳ�ͬʵ�ַ������Թ������ͬ���֣����ԣ��Ķ���

������ģʽ��һ��һ������һ�����ӵĶ����������û�ֻͨ��ָ�����Ӷ�������ͺ����ݾͿ��Թ������ǣ�
�û�����Ҫ֪���ڲ��ľ��幹��ϸ�ڡ����磬һ�����������ӣ��������Լ����������ɣ�������ͨ�˶��ԣ�����ʹ�õ�ֻ��һ�������ĳ�����ʱ��������Ҫ����һ�������ߣ����������ǰ���Щ���������װ��Ϊһ�������ĳ���

��ɫ��
Builder�����������࣬Ϊ����һ��Product����ĸ�������ָ������ӿڡ�
ConcreteBuilder�����幹�����࣬ʵ��Builder�Ľӿ��Թ����װ��ò�Ʒ�ĸ������������岢��ȷ���������ı�ʾ���ṩһ��������Ʒ�Ľӿ�
Director��ָ���ߣ�����һ��ʹ��Builder�ӿڵĶ���
Product����ʾ������ĸ��Ӷ���ConcreateBuilder�����ò�Ʒ���ڲ���ʾ����������װ����̡�

����������ɲ������࣬��������Щ����װ������ղ�Ʒ�Ľӿڡ�
*/

using namespace std;
class bldProduct {
public:
	void setPartA(string str) {
		partA = str;
	}

	void setPartB(string str) {
		partB = str;
	}

	void setPartC(string str) {
		partC = str;
	}

	void showProduct() {
		cout << "This Product consists of " << partA << ", " << partB << " and " << partC << "." << endl;
	}

private:
	string partA, partB, partC;
};

class builder {
public:
	virtual void buildPartA() = 0;

	virtual void buildPartB() = 0;

	virtual void buildPartC() = 0;

	virtual bldProduct* getResult() = 0;


protected:
	bldProduct *prod;
};

class prodBuilderOne : public builder {
public:
	prodBuilderOne() {
		prod = new bldProduct();
		prod->setPartA("");
		prod->setPartB("");
		prod->setPartC("");
	}

	~prodBuilderOne() {
		delete prod;
		prod = nullptr;
	}

	void buildPartA() {
		prod->setPartA("partA1");
	}

	void buildPartB() {
		prod->setPartB("partB1");
	}

	void buildPartC() {
		prod->setPartC("partC1");
	}

	bldProduct* getResult() {
		return prod;
	}
};

class director {
public:
	void setBuilder(builder* setBld) {
		bld = setBld;
	}

	bldProduct* startBuild() {
		bld->buildPartA();
		bld->buildPartB();
		bld->buildPartC();
		return bld->getResult();
	}

private:
	builder* bld;
};


void test4() {
	builder* setBld;
	setBld = new prodBuilderOne();
	director* direct = new director();
	direct->setBuilder(setBld);
	(direct->startBuild())->showProduct();
	delete setBld;
}