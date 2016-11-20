#include "stdafx.h"
#include "CFigure.h"

#include<vector>
#include<iostream>

CTriangle::CTriangle() try:a(0),b(0),c(0) {

}
catch (const std::exception&) {

}

CTriangle::CTriangle(double a, double b, double c)
try:a(a),b(b),c(c) {

}
catch (const std::exception&) {

}

std::string CTriangle::FigureType() const {
	return "Triangle";
}

double CTriangle::Circumference() {
	return a + b + c;
}
double CTriangle::Area() {
	//海伦公式描述为：三角形的半周长分别减去三角形三条边长所得到的三个数相乘, 得到的乘积再
	//乘以三角形的半周长, 所得结果的算术平方根 就是三角形的面积.用公式表示为：
	//S△ = √【 p*(p - a)*(p - b)*(p - c) 】
	//其中a, b, c 分别表示三角形的三条边长,
	//p表示三角形的半周长, 即 p = (a + b + c) / 2
	//如果用 C 表示三角形的周长, 则公式还可写成：
	//S△ = √【C / 2 * (C / 2 - a) * (C / 2 - b) * (C / 2 - c)】
	//其中a, b, c 表示三角形的三条边长
	//C表示三角形的周长, 即 C = a + b + c

	double s = Circumference() / 2;
	return std::sqrt(s*(s - a)*(s - b)*(s - c));
}




CSquare::CSquare() try:a(0),b(a) {

}
catch (...) {

}

CSquare::CSquare(double a, double b) try :a(a), b(b){

}
catch (...) {

}

CSquare::~CSquare() {

}

std::string CSquare::FigureType() const {
	return "squre";
}

double CSquare::Circumference() {
	return 2 * (a + b);
}

double CSquare::Area() {
	return a*b;
}






CCircle::CCircle() try :r(0) {

}
catch (...) {

}

CCircle::CCircle(double r) try:r(r) {

}
catch (...) {

}

CCircle::~CCircle() {

}

std::string CCircle::FigureType() const {
	return "circle";
}

double CCircle::Circumference() {
	return 2 * r*pir;
}

double CCircle::Area() {
	return pir*r*r;
}

const double CCircle::pir = 3.14;

void myFigure() {
	std::vector<CFigure*> CFigureVec{nullptr, nullptr, nullptr};
	CFigureVec[0] = new CTriangle(2.1, 3.2, 4.3);
	CFigureVec[1] = new CSquare(5.4, 6.5);
	CFigureVec[2] = new CCircle(8.8);

	for (CFigure *c : CFigureVec) {
		std::cout << "type: " << c->FigureType() 
			<< "  c: " << c->Circumference() 
			<< " s: " << c->Area() << std::endl;
		if (c) {
			delete c;
			c = nullptr;
		}
	}
}
