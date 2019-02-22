#pragma once
#include <iostream>
/*
��������(Factory Method)ģʽ�������Ƕ���һ��������Ʒ����Ĺ����ӿڣ�
��ʵ�ʴ��������Ƴٵ����൱�С����Ĺ����಻�ٸ����Ʒ�Ĵ�����
�����������Ϊһ�����󹤳���ɫ����������幤���������ʵ�ֵĽӿڣ�
������һ�����󻯵ĺô���ʹ�ù�������ģʽ����ʹϵͳ�ڲ��޸ľ��幤����ɫ������������µĲ�Ʒ��

��������ģʽ�Ǽ򵥹���ģʽ����������������򵥹���ģʽ�����⡣
������ȫʵ�֡������� ԭ�򡯣�ʵ���˿���չ��
��θ����ӵĲ�νṹ������Ӧ���ڲ�Ʒ������ӵĳ��ϡ� 

��������ģʽ�Լ򵥹���ģʽ�����˳�����һ�������Factory�ࣨ�����ǳ�����ͽӿڣ���
����ཫ���ٸ������Ĳ�Ʒ����������ֻ�ƶ�һЩ�淶�����������������������ȥ��ɡ�
�����ģʽ�У�������Ͳ�Ʒ�������������ζ�Ӧ����һ�����󹤳���Ӧһ�������Ʒ��
һ�����幤����Ӧһ�������Ʒ���������Ĺ����͸���������Ӧ�Ĳ�Ʒ��

��������ģʽ(Factory Method pattern)������͵�ģ�巽��ģʽ(Template Method pattern)Ӧ�á�

���󹤳�(Creator)��ɫ���ǹ�������ģʽ�ĺ��ģ���Ӧ�ó����޹ء��κ���ģʽ�д����Ķ���Ĺ��������ʵ������ӿڡ�
���幤��(Concrete Creator)��ɫ������ʵ�ֳ��󹤳��ӿڵľ��幤���࣬������Ӧ�ó���������ص��߼���
�����ܵ�Ӧ�ó�������Դ�����Ʒ����
�����Ʒ(Product)��ɫ����������ģʽ�������Ķ���ĳ����ͣ�Ҳ���ǲ�Ʒ����Ĺ�ͬ�����ͬӵ�еĽӿڡ�
�����Ʒ(Concrete Product)��ɫ�������ɫʵ���˳����Ʒ��ɫ������Ľӿڡ�

ĳ�����Ʒ��ר�ŵľ��幤������������֮������һһ��Ӧ��
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








