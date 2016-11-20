#include "stdafx.h"
#include "SComplex.h"

#include<exception>


double Rand(double, double);

SComplex::SComplex()try:dReal(Rand(-10, 10)), dImg(Rand(-10, 10)) {

}
catch (...) {

}

SComplex::SComplex(double dReal, double dImg) try:dReal(dReal), dImg(dImg) {

}
catch (...) {

}


inline SComplex operator+(const SComplex &c1, const SComplex &c2) {
	SComplex c(c1.dReal + c2.dReal, c2.dImg + c2.dImg);
	return c;
}

inline std::ostream &operator<<(std::ostream &os, const SComplex &c) {
	return os << c.dReal << "+" << c.dImg << "i" << std::endl;
}

void SComplex::add() {
	SComplex c1;
	SComplex c2(-2.3, 0.9);
	SComplex c = c1 + c2;
	std::cout << c << std::endl;
}