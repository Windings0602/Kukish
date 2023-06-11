#include <iostream>
#include <vector>
#include "Header.h"
#include "Kukish.h"
using namespace std;

int NOD(int a, int b) {
	while (b %= a) swap(a, b);
	return a;
}

ostream& operator<<(ostream& out, vector<int> v) {
	for (int i = 0; i < v.size(); i++) {
		out << v[i] << " ";
	}
	out << '\n';
	return out;
}


vector<int> operator+(vector<int> v, vector<int> g) {
	vector<int> result(v.size());
	for (int i = 0; i < v.size(); i++) {
		result[i] = v[i] + g[i];
	}
	return result;
}

//istream& operator>>(istream& in, Kukish& a)
//{
//	in >> a.a >> a.b;
//	return in;
//}

istream& operator >>(istream& in, Kukish& a) {
	double num;
	double x;
	double y;
	in >> num;
	x = modf(num, &y);
	stringstream ss;
	ss << x;
	string z = ss.str();
	int lenght = z.size() - 2;
	if (lenght == -1) {
		a.a = y;
		a.b = 1;
		return in;
	}
	int bb = pow(10, lenght);
	int aa = y * bb + x * bb;
	a.a = aa;
	a.b = bb;
	return in;
}

ostream& operator<<(ostream& out, Kukish a)
{
	out << a.a << "/" << a.b;
	return out;
}
Kukish operator +(Kukish a, Kukish b) {
	Kukish result;
	result.a = a.a * b.b + b.a * a.b;
	result.b = a.b * b.b;
	int c = NOD(result.a, result.b);
	result.a /= c;
	result.b /= c;
	return result;
}

int main()
{
	Kukish a, b, c;

	cin >> a >> b; 
	cout << a + b << "\n";
	cout << a - b << "\n";
	cout << a * b << "\n";
	cout << a / b << "\n";
	cout << a + 5 << "\n";
	cout << a - 5 << "\n";
	cout << a * 5 << "\n";
	cout << a / 5 << "\n";


}