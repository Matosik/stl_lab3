#pragma once
#include <iostream>
#include <math.h>
#include <complex>
#include <list>
#include <iostream>
#include <math.h>
using namespace std;

template<typename T>
T maximum(T a, T b) {
	if (a > b) { return a; }
	return b;
}
template<typename T>
struct Coef {
	int Mystep;
	T value;
	Coef(T value, int Mystep) {
		this->value = value;
		this->Mystep = Mystep;
	}
};

template <typename T>
class Polynominal {
private:
	list <Coef<T>> data;
	int step;
	auto begin() {
		return data.begin();
	}
	auto end() {
		return data.end();
	}
public:
	auto cbegin() const { return data.cbegin(); }

	auto cend() const { return data.cend(); }

	auto crbegin() const { return data.crbegin(); }

	auto crend() const { return data.crend(); }
	Polynominal(int step);

	Polynominal(Polynominal& other) const = default;
	~Polynominal() = default;
	void set_coef(T value, int i);
	Polynominal operator +(Polynominal<T>& other)const;
	Polynominal operator -(Polynominal<T>& other)const;
	Polynominal operator *(T multiplier) const;
	T valueX(T x)const;
	T operator[](int i)const; 
	int equation_roots(T*& arr) const;
	friend ostream& operator << (ostream& os, const Polynominal<T> poly) {
		;
		for (auto iter = poly.cbegin(); iter != poly.cend(); ++iter) {
			Coef<T> tmp = *iter;
			if ((tmp.Mystep < poly.step) && (tmp.Mystep == 0)) {
				os << tmp.value << " + ";
			}
			else if (tmp.Mystep < poly.step) {
				os << tmp.value << "x^" << tmp.Mystep << " + ";
			}
			else {
				os << tmp.value << "x^" << tmp.Mystep;
			}
		}
		return os;
	}
};