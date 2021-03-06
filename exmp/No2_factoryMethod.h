#pragma once
#include <iostream>
/*
工厂方法(Factory Method)模式的意义是定义一个创建产品对象的工厂接口，
将实际创建工作推迟到子类当中。核心工厂类不再负责产品的创建，
这样核心类成为一个抽象工厂角色，仅负责具体工厂子类必须实现的接口，
这样进一步抽象化的好处是使得工厂方法模式可以使系统在不修改具体工厂角色的情况下引进新的产品。

工厂方法模式是简单工厂模式的衍生，解决了许多简单工厂模式的问题。
首先完全实现‘开－闭 原则’，实现了可扩展。
其次更复杂的层次结构，可以应用于产品结果复杂的场合。 

工厂方法模式对简单工厂模式进行了抽象。有一个抽象的Factory类（可以是抽象类和接口），
这个类将不再负责具体的产品生产，而是只制定一些规范，具体的生产工作由其子类去完成。
在这个模式中，工厂类和产品类往往可以依次对应。即一个抽象工厂对应一个抽象产品，
一个具体工厂对应一个具体产品，这个具体的工厂就负责生产对应的产品。

工厂方法模式(Factory Method pattern)是最典型的模板方法模式(Template Method pattern)应用。

抽象工厂(Creator)角色：是工厂方法模式的核心，与应用程序无关。任何在模式中创建的对象的工厂类必须实现这个接口。
具体工厂(Concrete Creator)角色：这是实现抽象工厂接口的具体工厂类，包含与应用程序密切相关的逻辑，
并且受到应用程序调用以创建产品对象。
抽象产品(Product)角色：工厂方法模式所创建的对象的超类型，也就是产品对象的共同父类或共同拥有的接口。
具体产品(Concrete Product)角色：这个角色实现了抽象产品角色所定义的接口。

某具体产品有专门的具体工厂创建，它们之间往往一一对应。
*/

class fMproduct {
public:
	virtual void GetResult() = 0;
};

class fMfactory {
public:
	virtual fMproduct* CreateProduct() = 0;
};

class fMproductOne : public fMproduct
{
public:
	void GetResult() {
		std::cout << "factory method pattern productOne" << std::endl;
	}
};

class fMfactoryOne : public fMfactory
{
public:
	static fMproductOne* CreateProduct() {
		return new fMproductOne();
	}
};

class fMproductTwo : public fMproduct
{
public:
	void GetResult() {
		std::cout << "factory method pattern productTwo" << std::endl;
	}
};

class fMfactoryTwo : public fMfactory
{
public:
	static fMproductTwo* CreateProduct() {
		return new fMproductTwo();
	}
};

void test2() {
	std::cout << "2. factory method pattern" << std::endl;
	fMproduct *prod = nullptr;
	prod = fMfactoryOne::CreateProduct();
	prod->GetResult();
	delete prod;
	prod = fMfactoryTwo::CreateProduct();
	prod->GetResult();
	delete prod;
}








