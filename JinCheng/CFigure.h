#include "stdafx.h"
#pragma once
#include<string>
class CFigure {
public:
	virtual std::string FigureType() const = 0;
	virtual double Circumference() = 0;
	virtual double Area() = 0;
	virtual ~CFigure() {

	}
};


class CTriangle :public CFigure {
private:
	double a, b, c;
public:
	CTriangle();
	CTriangle(double a, double b, double c);
	std::string FigureType() const override;
	double Circumference() override;
	double Area() override;
};


class CSquare :public CFigure {
private:
	double a, b;
public:
	CSquare();
	CSquare(double a, double b);
	~CSquare();
	std::string FigureType() const override;
	double Circumference() override;
	double Area() override;
};



class CCircle :public CFigure {
private:
	double r;
	static const double pir;
public:
	CCircle();
	CCircle(double r);
	~CCircle();
	std::string FigureType() const override;
	double Circumference() override;
	double Area() override;
};