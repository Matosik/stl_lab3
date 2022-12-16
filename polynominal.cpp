#include "polynominal.h"

template <typename T>
Polynominal<T>::Polynominal(int step) {
	this->step = step;
}

template <typename T>
void Polynominal<T>::set_coef(T value, int i) {
	if (value == T(0)) {
		if (i == step) {
			step--;
		}
		return;
	}
	Coef<T>* tmp = new Coef<T>(value, i);
	data.push_back(*tmp);
}

template <typename T>
Polynominal<T>::~Polynominal() {
	data.clear();
}

template<typename T>
T Polynominal<T>::operator[](int i) const {
	if ((i > step - 1) || (i < 0)) {
		string a = "Invalid index";
		throw a;
	}
	auto iter = cbegin();
	advance(iter, i);
	Coef<T> tmp = *iter;
	return tmp.value;

}

template <typename T>
T Polynominal<T>::valueX(int x) const {
	T answer = T(0);
	for (auto iter = cbegin(); iter != cend(); ++iter) {
		answer += *iter.value * pow(x, *iter.Mystep);
	}
	return answer;
}
template <typename T>
Polynominal<T> Polynominal<T>::operator+(Polynominal& other)const {
	auto this_it = this->cbegin();
	auto other_it = other.cbegin();
	int max = maximum(this->step, other.step);
	Polynominal tmp(max);
	while ((this_it != this->cend()) || (other_it != other_it.cend()))
	{
		if ((*this_it).Mystep == (*other_it).Mystep) {
			tmp.set_coef((*this_it).value + (*other_it).value, (*this_it).Mystep);
			++this_it;
			++other_it;
		}
		else if ((*this_it).Mystep < (*other_it).Mystep) {
			tmp.set_coef((*this_it).value, (*this_it).Mystep);
			++this_it;
		}
		else if ((*this_it).Mystep > (*other_it).Mystep) {
			tmp.set_coef((*other_it).value, (*other_it).Mystep);
			++other_it;
		}
	}
	return tmp;
}

template <typename T>
Polynominal<T> Polynominal<T>::operator-(Polynominal& other)const {
	auto this_it = this->cbegin();
	auto other_it = other.cbegin();
	int max = maximum(this->step, other.step);
	Polynominal tmp(max);
	while ((this_it != this->cend()) || (other_it != other_it.cend()))
	{
		if ((*this_it).Mystep == (*other_it).Mystep) {
			tmp.set_coef((*this_it).value - (*other_it).value, (*this_it).Mystep);
			++this_it;
			++other_it;
		}
		else if ((*this_it).Mystep < (*other_it).Mystep) {
			tmp.set_coef((*this_it).value, (*this_it).Mystep);
			++this_it;
		}
		else if ((*this_it).Mystep > (*other_it).Mystep) {
			tmp.set_coef((*other_it).value, (*other_it).Mystep);
			++other_it;
		}
	}
	return tmp;
}

template <typename T>
Polynominal<T> Polynominal<T>::operator *(T multiplier)const {
	Polynominal<T> newPoly(this->step);
	for (auto iter = cbegin(); iter != cend(); ++iter) {
		Coef<T> tmp = *iter;
		newPoly.set_coef(tmp.value * multiplier, tmp.Mystep);
	}
	return newPoly;

}
template class Polynominal<int>;
template class Polynominal<float>;
template class Polynominal<double>;
//template class Polynominal<complex<float>>;
//template class Polynominal<complex<double>>;

