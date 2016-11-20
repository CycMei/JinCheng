// JinCheng.cpp : 定义控制台应用程序的入口点。
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
	clist.Remove(32);
	clist.Insert(32);
}

int _tmain(int argc, TCHAR *argv[]) {
	test4();
}

