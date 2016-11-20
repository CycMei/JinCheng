#include "stdafx.h"
#include<iostream>



struct ComplexTwo {
	double dReal;
	double dImg;
};

ComplexTwo ComplexAdd(ComplexTwo c1, ComplexTwo c2) {
	ComplexTwo c;
	c.dReal = c1.dReal + c2.dReal;
	c.dImg = c1.dImg + c2.dImg;
	return c;
}

double Rand(double dMin, double dMax);
void MyComplexTwo() {
	ComplexTwo c1;
	c1.dImg = ::Rand(-10, 10);
	c1.dReal = ::Rand(-10, 10);

	ComplexTwo c2;
	c2.dImg = ::Rand(-10, 10);
	c2.dReal = ::Rand(-10, 10);

	ComplexTwo c = ComplexAdd(c1, c2);
	std::cout << c.dReal << " + " << c.dImg << "  . " << std::endl;

}