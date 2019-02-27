#pragma once
#include <iostream>

/*
外观模式(Facade Pattern)：外部与一个子系统的通信必须通过一个统一的外观对象进行，
为子系统中的一组接口提供一个一致的界面，外观模式定义了一个高层接口，这个接口使得这一子系统更加容易使用。
外观模式又称为门面模式，它是一种对象结构型模式。

举一个简单的例子，相信大家都使用过 C++ 语言，他是一门编译型语言，写完代码之后，
我们需要经过编译之后才能运行，在IDE中，会有一个 Build 的按钮，点击它即可完成编译过程，
但是这一个简单的动作背后，却是一系列复杂操作的协调配合，至少包括词法分析，语法分析，生成中间代码，
生成汇编代码以及链接等操作，作为普通开发人员，我们不必在意这些过程是如何完成的，只需要点击Build按钮，
IDE就会自动帮我们完成背后的工作。那么这个Build按钮就是IDE为我们提供的高级接口，
通过他来完成各种子系统的协调工作。

角色：

Facade：外观角色，提供高级接口

SubSystem：子系统角色，负责各自的功能实现
*/
using namespace std;
class systemA {
public: 
	void operationA() {
		cout << "OperationA" << endl;
	}
};

class systemB {
public:
	void operationB() {
		cout << "OperationB" << endl;
	}
};

class systemC {
public:
	void operationC() {
		cout << "OperationC" << endl;
	}
};

class facade {
public:
	facade() {
		sysA = new systemA();
		sysB = new systemB();
		sysC = new systemC();
	}

	~facade() {
		delete sysA;
		delete sysB;
		delete sysC;
	}

	void operation() {
		sysA->operationA();
		sysB->operationB();
		sysC->operationC();
	}

protected:
	systemA * sysA;
	systemB * sysB;
	systemC * sysC;
};


void test9() {
	facade *f = new facade();
	f->operation();
	delete f;
}