#pragma once
#include <iostream>

/*
�Ž�ģʽ��������ģʽ����ӵ�ģʽ֮һ���������������������Ϊ�������������뿪����ʹ���ǿ��Ը��Զ����ı仯��
����������һ������ĸ���硰Բ�Ρ����������Ρ����ڳ���ġ���״��֮�£�������Բ����
�������ǡ�����ʵ����Ϊ�ġ���ͼ����֮�£�Ȼ���ɡ���״�����á���ͼ����

����Ž�ģʽ���ص���Ҫ�����ν�����(Abstraction)��ʵ�ֻ�(Implementation)���
ʹ�ö��߿��Զ����ر仯���Ž�ģʽ�����ϵͳ�Ŀ������ԣ�
�������仯ά����������չһ��ά�ȣ�������Ҫ�޸�ԭ��ϵͳ��

��ɫ��
Abstraction���������Ľӿڣ��ýӿڰ���ʵ�־�����Ϊ������������Implementor�ӿ�
Refined Abstraction������ӿ�Abstraction�����࣬������һ�������������
Implementor�����������Ϊ������������Ӧ�ýӿ�
ConcreteImplementor��ʵ��Implementor�ӿ�

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
