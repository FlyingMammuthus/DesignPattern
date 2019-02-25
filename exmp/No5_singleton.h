#pragma once
#include <iostream>

/*
单例模式，也叫单子模式，是一种常用的软件设计模式。在应用这个模式时，单例对象的类必须保证只有一个实例存在。
许多时候整个系统只需要拥有一个的全局对象，这样有利于我们协调系统整体的行为。

实现单例模式的思路是：一个类能返回对象一个引用(永远是同一个)和一个获得该实例的方法
（必须是静态方法，通常使用getInstance这个名称）；当我们调用这个方法时，如果类持有的引用不为空就返回这个引用，
如果类保持的引用为空就创建该类的实例并将实例的引用赋予该类保持的引用；
同时我们还将该类的构造函数定义为私有方法，这样其他处的代码就无法通过调用该类的构造函数来实例化该类的对象，
只有通过该类提供的静态方法来得到该类的唯一实例。

*/
using namespace std;
class singleton {
public:
	static singleton* getInstance() {
		if (instance == nullptr)
			instance = new singleton();
		return instance;

		/* 多线程版本
		if (instance == NULL)        
		{
		lock();                    //防止同时创建
		if (instance == NULL)      //再加一重锁防止同时创建
		{
		instance = new Singleton();
		}
		unlock();
		}

		return instance;
		*/
	}

private:
	singleton() {}

	singleton(const singleton&) {}

	singleton& operator=(const singleton&) {}

	static singleton* instance;
};

singleton* singleton::instance = nullptr;

void test5() {
	singleton *s1 = singleton::getInstance(),
		*s2 = singleton::getInstance();
	if (s1 == s2) {
		cout << "s1 is the same as s2." << endl;
	}
	else {
		cout << "s1 is different from s2." << endl;
	}
}
