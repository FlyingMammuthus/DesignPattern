#pragma once
#include <iostream>
#include <string>

/*
又名：生成器模式，是一种对象构建模式。它可以将复杂对象的建造过程抽象出来（抽象类别），
使这个抽象过程的不同实现方法可以构造出不同表现（属性）的对象。

建造者模式是一步一步创建一个复杂的对象，它允许用户只通过指定复杂对象的类型和内容就可以构建它们，
用户不需要知道内部的具体构建细节。例如，一辆汽车由轮子，发动机以及其他零件组成，对于普通人而言，我们使用的只是一辆完整的车，这时，我们需要加入一个构造者，让他帮我们把这些组件按序组装成为一辆完整的车。

角色：
Builder：抽象构造者类，为创建一个Product对象的各个部件指定抽象接口。
ConcreteBuilder：具体构造者类，实现Builder的接口以构造和装配该产品的各个部件。定义并明确它所创建的表示。提供一个检索产品的接口
Director：指挥者，构造一个使用Builder接口的对象。
Product：表示被构造的复杂对象。ConcreateBuilder创建该产品的内部表示并定义它的装配过程。

包含定义组成部件的类，包括将这些部件装配成最终产品的接口。
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