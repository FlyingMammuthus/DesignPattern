#pragma once
#include <iostream>
/*
3.���󹤳�ģʽ

�ṩһ������һϵ����ػ��໥��������Ľӿڣ�������ָ�����Ǿ�����ࡣ���󹤳�ģʽ�ֳ�ΪKitģʽ�����ڶ��󴴽���ģʽ��

��ģʽ�ǶԹ�������ģʽ�Ľ�һ����չ���ڹ�������ģʽ�У�һ������Ĺ�����������һ�����Ĳ�Ʒ����һ��һ�Ĺ�ϵ��
���ǣ������Ҫһ������Ĺ����������ֲ�Ʒ������ô����Ҫ�õ����󹤳�ģʽ�ˡ�

Ϊ�˱�������ģʽ����������������

��Ʒ�ȼ��ṹ����Ʒ�ȼ��ṹ����Ʒ�ļ̳нṹ����һ���������ǵ��ӻ����������к������ӻ������ŵ��ӻ���TCL���ӻ���
�������ӻ������Ʒ�Ƶĵ��ӻ�֮�乹����һ����Ʒ�ȼ��ṹ��������ӻ��Ǹ��࣬������Ʒ�Ƶĵ��ӻ��������ࡣ

��Ʒ�� ���ڳ��󹤳�ģʽ�У���Ʒ����ָ��ͬһ�����������ģ�λ�ڲ�ͬ��Ʒ�ȼ��ṹ�е�һ���Ʒ��
�纣���������������ĺ������ӻ�����������䣬�������ӻ�λ�ڵ��ӻ���Ʒ�ȼ��ṹ�У����������λ�ڵ�����Ʒ�ȼ��ṹ�С�

��ɫ��
���󹤳���AbstractFactory�������������ɫ���ǳ��󹤳�ģʽ�ĺ��ģ�����Ӧ��ϵͳ����ҵ�߼��޹صġ�
���幤����Factory���������ɫֱ���ڿͻ��˵ĵ����´�����Ʒ��ʵ���������ɫ����ѡ����ʵĲ�Ʒ������߼���������߼�����Ӧ��ϵͳ��ҵ�߼�������صġ�
�����Ʒ��AbstractProduct�������������ɫ�����ǳ��󹤳�ģʽ�������Ķ���ĸ��࣬�����ǹ�ͬӵ�еĽӿ�
�����Ʒ��Product�������󹤳�ģʽ���������κβ�Ʒ������һ������Ĳ�Ʒ���ʵ����
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
