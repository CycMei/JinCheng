// JinCheng.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include<iostream>
#include<vld.h>

#include"SComplex.h"
#include"CList.h"

void ComplexOneTest();
void MyComplexTwo();
void test1() {
	SComplex sc;
	sc.add();
}

void myPerson();
void test2() {
	myPerson();
}

void myFigure();
void test3() {
	myFigure();
}

void test4() {
	CList<int> clist;
	clist.Insert(32);
	
	clist.Insert(23);
	//clist.Remove(2);
	clist.Append(50);
}

int _tmain(int argc, TCHAR *argv[]) {
	test4();
}

