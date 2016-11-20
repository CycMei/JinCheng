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
	//���׹�ʽ����Ϊ�������εİ��ܳ��ֱ��ȥ�����������߳����õ������������, �õ��ĳ˻���
	//���������εİ��ܳ�, ���ý��������ƽ���� ���������ε����.�ù�ʽ��ʾΪ��
	//S�� = �̡� p*(p - a)*(p - b)*(p - c) ��
	//����a, b, c �ֱ��ʾ�����ε������߳�,
	//p��ʾ�����εİ��ܳ�, �� p = (a + b + c) / 2
	//����� C ��ʾ�����ε��ܳ�, ��ʽ����д�ɣ�
	//S�� = �̡�C / 2 * (C / 2 - a) * (C / 2 - b) * (C / 2 - c)��
	//����a, b, c ��ʾ�����ε������߳�
	//C��ʾ�����ε��ܳ�, �� C = a + b + c

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
