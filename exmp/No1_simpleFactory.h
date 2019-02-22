#pragma once
#include <iostream>
/*
简单工厂模式

又称为静态工厂方法(Static Factory Method)模式，它属于类创建型模式。
在简单工厂模式中，可以根据参数的不同返回不同类的实例。
简单工厂模式专门定义一个类来负责创建其他类的实例，被创建的实例通常都具有共同的父类。

角色：
Factory类：负责创建具体产品的实例
Product类：抽象产品类，定义产品子类的公共接口
ConcreteProduct 类：具体产品类，实现Product父类的接口功能，也可添加自定义的功能
*/

//算法的父类，抽象出返回结果的接口
class product
{
public:
	virtual void GetResult() = 0;
};

//算法子类，由工厂类创建，重写父类中的虚函数
class productOne : public product
{
public:
	void GetResult() {
		std::cout << "productOne" << std::endl;
	}
};

class productTwo : public product
{
public:
	void GetResult() {
		std::cout << "productTwo" << std::endl;
	}
};

//工厂类，用于生产相应的算法子类
class productFactry
{
public:
	productFactry() {}
	~productFactry() {}
public:
	static product* CreateProduct(int n)
	{
		switch (n)
		{
		case 1:
			return new productOne();
			break;
		case 2:
			return new productTwo();
			break;

		default:
			return nullptr;
		}
	}
};

void test1() {
	std::cout << "1. simple factory pattern" << std::endl;
	productFactry *prodFactory = new productFactry();
	product *prod = nullptr;
	for (int i = 1; i < 3; ++i) {
		prod = prodFactory->CreateProduct(i);
		prod->GetResult();
		delete prod;
	}
}
