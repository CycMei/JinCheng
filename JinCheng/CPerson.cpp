#include "stdafx.h"
#include "CPerson.h"

#include<iostream>


CPerson::CPerson(int iAge, const std::string sName)
try :iAge(iAge), sName(sName){

}
catch (...) {

}

CPerson::~CPerson() {
	
}

std::string CPerson::WhoAmI() {
	return "I am a person";
}





CWorker::CWorker(int iAge, std::string sName, std::string sEmploymentStatus)
try :CPerson(iAge, sName), sEmploymentStatus(sEmploymentStatus) {

}
catch (...) {

}

CWorker::~CWorker() {

}

std::string CWorker::WhoAmI() {
	return "i am a worker";
}





CStudent::CStudent(int iAge, std::string sName, std::string sStudentIdentity)
try:CPerson(iAge,sName),sStudentIdentity(sStudentIdentity) {

}
catch (...) {

}

CStudent::~CStudent() {

}

std::string CStudent::WhoAmI() {
	return "i am a student";
}


void myPerson() {
	CPerson cperson(10, "john");
	CWorker cworker(23, "cyc", "it");
	CStudent cstudent(32, "cyx", "no");
	std::cout << cperson.WhoAmI() << std::endl;
	std::cout << cworker.WhoAmI() << std::endl;
	std::cout << cstudent.WhoAmI() << std::endl;
}