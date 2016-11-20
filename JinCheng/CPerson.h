#include "stdafx.h"
#pragma once

#include<string>
class CPerson {
private:
	int iAge;
	std::string sName;
public:
	CPerson(int, const std::string);
	~CPerson();
	virtual std::string WhoAmI();
};

class CWorker :public CPerson {
private:
	std::string sEmploymentStatus;
public:
	CWorker(int iAge,std::string sName,std::string sEmploymentStatus);
	~CWorker();
	std::string WhoAmI() override;
};


class CStudent :public CPerson {
private:
	std::string sStudentIdentity;
public:
	CStudent(int iAge, std::string sName, std::string sStudentIdentity);
	~CStudent();
	std::string WhoAmI() override;
};