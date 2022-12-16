#pragma once
#include <iostream>
#include <math.h>
#include <complex>
#include <list>
#include <iostream>
using namespace std;

template<typename T>
struct Coef {
	T value;
	int Mystep;
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
	Polynominal(int step);
	//Polynominal(Polynominal& other) const;
	~Polynominal();
	void set_coef(T value, int i);
	//Polynominal operator +(Polynominal& other)const;
	//Polynominal operator -(Polynominal& other)const;
	T operator[](int i)const;

};