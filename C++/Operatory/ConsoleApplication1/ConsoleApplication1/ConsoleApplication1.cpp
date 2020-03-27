

#include <iostream>
#include <cstdlib>

using namespace std;

class Zespolona {
private:
	int rzecz, uroj;
public:
	Zespolona(int r, int u ) : rzecz(r),uroj(u) {}
		
	
	int getrzecz() const
	{
		return rzecz;
	}
	int geturoj() const
	{
		return uroj;
	}
	void SetZesp(int r, int u) {
		rzecz = r;
		uroj = u;
	}

Zespolona& operator =(const Zespolona& z1)
{
	if (this != &z1) {
		rzecz = z1.rzecz;
	}
	if (this != &z1) {
		uroj = z1.uroj;
	}
	return *this;
}
Zespolona& operator++() {
	++rzecz;
	++uroj;
	return *this;
}
};
Zespolona operator+(const Zespolona& z1, const Zespolona& z2) {
	return Zespolona(z1.getrzecz() + z2.getrzecz(), z1.geturoj() + z2.geturoj());
}
istream& operator>>(istream& in, Zespolona& z1) {
	int v,k;
	cin >> v;
	cin >> k;
	z1.SetZesp(v, k);
	return in;
}
ostream& operator<<(ostream& out,const Zespolona& z1) {
	out << z1.getrzecz() << " " << z1.geturoj()<<endl;
	return out;
}

int main()
{
	Zespolona z1(1, 1);
	Zespolona z2(1, 1);
	Zespolona z3 = z1 + z2;
	cout << z3.getrzecz() << "   "<< z3.geturoj()<<endl;
	
	++z3;
	cout << z3.getrzecz() << "   " << z3.geturoj()<<endl;
	cin >> z3;
	cout << z3;
	
	
	
	
	
	system("pause");
	
		return 0;
}

