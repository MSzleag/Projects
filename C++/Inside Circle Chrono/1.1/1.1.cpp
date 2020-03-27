

#include <iostream>
#include <cstdlib>
#include <time.h>
#include <random>
#include <chrono>
using namespace std;

class Point2D {
private:
	float m_x, m_y;
public:
	Point2D(float x = 0, float y = 0) :m_x{ x }, m_y{ y }
	{}
	float get_x() {
		return m_x;
	}
	float get_y() {
		return m_y;
	}
	void set_x(float x) {
		m_x = x;
	}
	void set_y(float y)
	{
		m_y = y;
	}

};
class Circle {
private:
	float m_x, m_y, m_r;
public:
	Circle(float x = 0, float y = 0, float r = 1) : m_x{ x }, m_y{ y }, m_r{ r }
	{}

	bool is_inside(Point2D p)
	{
		
		if ((p.get_x() - m_x) * (p.get_x() - m_x) + (p.get_y() - m_y) * (p.get_y() - m_y) <= (m_r) * (m_r))
		{
			
			return true;
		}
		else {
			return false;
		}
	}
};
float n = 1000000;
float ni=0;
int main()
{
	Circle k;
	Point2D c;
	mt19937 gen(chrono::system_clock::now().time_since_epoch().count());
	uniform_real_distribution<float> distribution{ -1.0,1.0 };
	for (int i = 0; i < n; i++)
	{
		c.set_x(distribution(gen));
		c.set_y(distribution(gen));
		
		if (k.is_inside(c)) {
			ni++;
		}
	}
	 float g = ni/n;
	 cout << g*4 <<endl;
	system("pause");
}

