#include "stdafx.h"
#include<iostream>
void ComplexAdd(double dReal1, double dImgl, double dReal2, double dImg2, double &dReal, double &dImg) {
	dReal = dReal1 + dReal2;
	dImg = dImgl + dImg2;
}
double Rand(double dMin, double dMax) {
	double dVal = (double)rand() / RAND_MAX;
	return dMin + dVal*(dMax - dMin);
}
void ComplexOneTest() {
	double dReal1 = Rand(-10, 10);
	double dImg1 = Rand(-10, 10);
	double dReal2 = Rand(-10, 10);
	double dImg2 = Rand(-10, 10);
	double dReal = 0;
	double dImg = 0;
	ComplexAdd(dReal1, dImg1, dReal2, dImg2, dReal, dImg);
	std::cout << dReal << std::endl;
	std::cout << dImg << std::endl;
}