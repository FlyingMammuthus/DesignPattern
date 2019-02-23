#pragma once
#include <iostream>
/*
3.抽象工厂模式

提供一个创建一系列相关或相互依赖对象的接口，而无须指定它们具体的类。抽象工厂模式又称为Kit模式，属于对象创建型模式。

此模式是对工厂方法模式的进一步扩展。在工厂方法模式中，一个具体的工厂负责生产一类具体的产品，即一对一的关系，
但是，如果需要一个具体的工厂生产多种产品对象，那么就需要用到抽象工厂模式了。

为了便于理解此模式，这里介绍两个概念：

产品等级结构：产品等级结构即产品的继承结构，如一个抽象类是电视机，其子类有海尔电视机、海信电视机、TCL电视机，
则抽象电视机与具体品牌的电视机之间构成了一个产品等级结构，抽象电视机是父类，而具体品牌的电视机是其子类。

产品族 ：在抽象工厂模式中，产品族是指由同一个工厂生产的，位于不同产品等级结构中的一组产品，
如海尔电器工厂生产的海尔电视机、海尔电冰箱，海尔电视机位于电视机产品等级结构中，海尔电冰箱位于电冰箱产品等级结构中。

角色：
抽象工厂（AbstractFactory）：担任这个角色的是抽象工厂模式的核心，是与应用系统的商业逻辑无关的。
具体工厂（Factory）：这个角色直接在客户端的调用下创建产品的实例，这个角色含有选择合适的产品对象的逻辑，而这个逻辑是与应用系统商业逻辑紧密相关的。
抽象产品（AbstractProduct）：担任这个角色的类是抽象工厂模式所创建的对象的父类，或它们共同拥有的接口
具体产品（Product）：抽象工厂模式所创建的任何产品对象都是一个具体的产品类的实例。
*/

class aFproductA {
public:
	virtual void GetResult() = 0;
};

class aFproductB {
public:
	virtual void GetResult() = 0;
};

class aFfactory {
public:
	virtual aFproductA* CreateProductA() = 0;

	virtual aFproductB* CreateProductB() = 0;
};

class aFproductA1 : public aFproductA
{
public:
	void GetResult() {
		std::cout << "abstract factory pattern product A1" << std::endl;
	}
};

class aFproductB1 : public aFproductB
{
public:
	void GetResult() {
		std::cout << "abstract factory pattern product B1" << std::endl;
	}
};

class aFfactoryOne : public aFfactory
{
public:
	static aFproductA1* CreateProductA() {
		return new aFproductA1();
	}

	static aFproductB1* CreateProductB() {
		return new aFproductB1();
	}
};

void test3() {
	std::cout << "3. abstract factory pattern" << std::endl;
	aFproductA *prodA = nullptr;
	aFproductB *prodB = nullptr;
	prodA = aFfactoryOne::CreateProductA();
	prodA->GetResult();
	delete prodA;
	prodB = aFfactoryOne::CreateProductB();
	prodB->GetResult();
	delete prodB;
}
