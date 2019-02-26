#pragma once
#include <iostream>

/*
修饰模式，是面向对象编程领域中，一种动态地往一个类中添加新的行为的设计模式。
就功能而言，修饰模式相比生成子类更为灵活，这样可以给某个对象而不是整个类添加一些功能。

一般来说，给一个对象或者类增加行为的方式可以有两种：

继承机制，使用继承机制是给现有类添加功能的一种有效途径，通过继承一个现有类可以使得子类在拥有自身方法的同时还拥有父类的方法。
但是这种方法是静态的，用户不能控制增加行为的方式和时机。

关联机制，即将一个类的对象嵌入另一个对象中，由另一个对象来决定是否调用嵌入对象的行为以便扩展自己的行为，
我们称这个嵌入的对象为装饰器(Decorator)

通过使用修饰模式，可以在运行时扩充一个类的功能。原理是：增加一个修饰类包裹原来的类，
包裹的方式一般是通过在将原来的对象作为修饰类的构造函数的参数。装饰类实现新的功能，
但是，在不需要用到新功能的地方，它可以直接调用原来的类中的方法。修饰类必须和原来的类有相同的接口。

修饰模式是类继承的另外一种选择。类继承在编译时候增加行为，而装饰模式是在运行时增加行为。

角色
Component: 抽象构件
ConcreteComponent: 具体构件
Decorator: 抽象装饰类
ConcreteDecorator: 具体装饰类
*/
using namespace std;
class component {
public:
	virtual void operation() = 0;
};

class MyComponent : public component {
public:
	void operation() {
		cout << "This is the normal component operation." << endl;
	}
};

class decorator : public component {
public:
	decorator(component * comp_in):comp(comp_in) {}

	void operation() {
		comp->operation();
	}

protected:
	component * comp;
};

class MyDecorator : public decorator {
public:
	MyDecorator(component *comp_in):decorator(comp_in) {}

	void addMethod() {
		cout << "This is the added method of decorator." << endl;
	}

	void operation() {
		addMethod();
		decorator::operation();  //调用父类方法
	}
};

void test8() {
	component *comp = new MyComponent();
	decorator *decrt = new MyDecorator(comp);
	decrt->operation();
	delete decrt;
	delete comp;
}
