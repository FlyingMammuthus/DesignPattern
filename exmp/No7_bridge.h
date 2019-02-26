#pragma once
#include <iostream>

/*
桥接模式是软件设计模式中最复杂的模式之一，它把事物对象和其具体行为、具体特征分离开来，使它们可以各自独立的变化。
事物对象仅是一个抽象的概念。如“圆形”、“三角形”归于抽象的“形状”之下，而“画圆”、
“画三角”归于实现行为的“画图”类之下，然后由“形状”调用“画图”。

理解桥接模式，重点需要理解如何将抽象化(Abstraction)与实现化(Implementation)脱耦，
使得二者可以独立地变化。桥接模式提高了系统的可扩充性，
在两个变化维度中任意扩展一个维度，都不需要修改原有系统。

角色：
Abstraction：定义抽象的接口，该接口包含实现具体行为、具体特征的Implementor接口
Refined Abstraction：抽象接口Abstraction的子类，依旧是一个抽象的事物名
Implementor：定义具体行为、具体特征的应用接口
ConcreteImplementor：实现Implementor接口

*/
using namespace std;
class drawingAPI {
public:
	virtual void drawCircle(int x, int y, int r) = 0;
};

class drawingAPI1 : public drawingAPI {
public:
	void drawCircle(int x, int y, int r) {
		if (r > 0) {
			int xo = r+1, yo = r+1;
			int xdis = 0, j;
			for (int yi = 1; yi <= 2*r+1; ++yi) {
				xdis = (int) (sqrt(r*r - (yi - yo)*(yi - yo)) + 0.5);
				for (j = 1; j < r + 1 - xdis; ++j) {
					cout << ' ';
				}
				cout << '.';
				for (++j; j < r + 1 + xdis; ++j) {
					cout << ' ';
				}
				cout << '.' << endl;
			}
		}
	}
};

class shape {
public:
	virtual void draw() = 0;

	virtual void resize(int r_in) = 0;
};

class circle : shape {
public:

	circle(int x_in, int y_in, int r_in, drawingAPI *drapi_in): x(x_in), y(y_in), r(r_in), dr_api(drapi_in){}

	void draw() {
		dr_api->drawCircle(x, y, r);
	}

	void resize(int r_in) {
		r = r_in;
	}

private:
	int x, y, r;
	drawingAPI *dr_api;
};

void test7() {
	circle *crcl = new circle(10, 10, 12, new drawingAPI1());
	crcl->draw();
}
