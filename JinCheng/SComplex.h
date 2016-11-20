#ifndef SCOMPLEX_H
#define SCOMPLEX_H

#include<iostream>
class SComplex {
public:
	SComplex();
	SComplex(double dReal, double dImg);
	friend SComplex operator+(const SComplex&, const SComplex&);
	friend std::ostream &operator<<(std::ostream&, const SComplex&);
	void add();
private:
	double dReal;
	double dImg;
};
#endif // !SCOMPLEX_H
