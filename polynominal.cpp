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
template <typename T>
int Polynominal<T>::equation_roots(T*& arr)const {
	auto iter = this->cbegin();
	Coef<T> tmp;
	if (this->step == 2)
	{
		T coef_s0 = T(0);
		T coef_s1 = T(0);
		T coef_s2 = T(0);
		while (iter != cend()) {
			tmp = *iter;
			if (tmp.Mystep == 0) {
				coef_s0 = tmp.value;
			}
			else if (tmp.Mystep == 1) {
				coef_s1 = tmp.value;
			}
			else if (tmp.Mystep == 2) {
				coef_s2 = tmp.value;
			}
			++iter;
		}
		T disc;
		T x1;
		T x2;
		disc = pow(coef_s1, T(2)) - T(4) * coef_s2 * coef_s0;
		if (disc > T(0))
		{
			x1 = (-coef_s1 + sqrt(coef_s1)) / (T(2) * coef_s2);
			x2 = (-coef_s1 - sqrt(coef_s1)) / (T(2) * coef_s2);
			arr[0] = x1;
			arr[1] = x2;
			return 2;
		}
		else if (disc == T(0))
		{
			x1 = (-coef_s1 / (T(2) * coef_s2));
			arr[0] = x1;
			return 1;
		}
		else if (disc < T(0))
		{
			string error = "действительных корней нет :(";
			throw error;
		}
	}
	else if (this->step == 1)
	{
		T coef_s0 = T(0);
		T coef_s1 = T(0);
		while (iter != cend()) {
			tmp = *iter;
			if (tmp.Mystep == 0) {
				coef_s0 = tmp.value;
			}
			else if (tmp.Mystep == 1) {
				coef_s1 = tmp.value;
			}
		}
		if ((coef_s0 == T(0)) && (coef_s1 == T(0)))
		{
			string error = "(- ; +)";
			throw error;
		}
		else if ((coef_s0 == T(0)) && (coef_s1 == T(0)))
		{
			arr[0] = 0;
			return 1;
		}
		else if ((coef_s0 != T(0)) && (coef_s1 == T(0)))
		{
			string error = "Корней нет!!!! у нас уравнение вида 0*x = 'value' ";
			throw error;
		}
	}
	else if (this->step > 2)
	{
		string error = "Я не умею решать уровнения больше второй степени -_- ";
		throw error;
	}
}
template class Polynominal<int>;
template class Polynominal<float>;
template class Polynominal<double>;
//template class Polynominal<complex<float>>;
//template class Polynominal<complex<double>>;

