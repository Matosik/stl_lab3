#include "polynominal.h"



void main() {
	Polynominal<int> a(3);
	for (int i = 0; i < 3; i++) {
		a.set_coef(2, i);
	}
	for (int i = 0; i < 3; i++) {
		cout << a[i] << " ";
	}
	
}