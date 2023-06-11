#pragma once
#include <iostream>
#include <vector>
#include "Header.h"
#include <sstream>
using namespace std;

class Kukish 
{
private:
	int a;
	int b;


public:
	Kukish();
	Kukish(int newA, int newB);

	friend istream& operator>>(istream& in, Kukish& a);
	friend ostream& operator<<(ostream& out, Kukish a);
	friend Kukish operator +(Kukish a, Kukish b);
	Kukish operator -(Kukish c) {
		Kukish result;
		result.a = a * c.b - c.a * b;
		result.b = b * c.b;
		int e = NOD(result.a, result.b);
		result.a /= e;
		result.b /= e;
		return result;
	}
	Kukish operator *(Kukish c) {
		Kukish result;
		result.a = a * c.a;
		result.b = b * c.b;
		int e = NOD(result.a, result.b);
		result.a /= e;
		result.b /= e;
		return result;
	}
	Kukish operator /(Kukish c) {
		Kukish result;
		result.a = a * c.b;
		result.b = b * c.a;
		int e = NOD(result.a, result.b);
		result.a /= e;
		result.b /= e;
		return result;
	}
	Kukish operator +(int d) {
		Kukish result;
		Kukish c(d,1);
		result.a = a * c.b + c.a * b;
		result.b = b * c.b;
		int e = NOD(result.a, result.b);
		result.a /= e;
		result.b /= e;
		return result;
	}
	Kukish operator -(int d) {
		Kukish result;
		Kukish c(d, 1);
		result.a = a * c.b - c.a * b;
		result.b = b * c.b;
		int e = NOD(result.a, result.b);
		result.a /= e;
		result.b /= e;
		return result;
	}
	Kukish operator *(int d) {
		Kukish result;
		Kukish c(d, 1);
		result.a = a * c.a;
		result.b = b * c.b;
		int e = NOD(result.a, result.b);
		result.a /= e;
		result.b /= e;
		return result;
	}
	Kukish operator /(int d) {
		Kukish result;
		Kukish c(d, 1);
		result.a = a * c.b;
		result.b = b * c.a;
		int e = NOD(result.a, result.b);
		result.a /= e;
		result.b /= e;
		return result;
	}
	int NOD(int a, int b) {
		while (b %= a) swap(a, b);
		return a;
	}
};