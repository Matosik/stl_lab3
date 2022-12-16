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
	auto iter = cbegin();
	advance(iter, i);
	Coef<T> tmp = *iter;
	return tmp.value;

}



template class Polynominal<int>;
template class Polynominal<float>;
template class Polynominal<double>;
template class Polynominal<complex<float>>;
template class Polynominal<complex<double>>;

