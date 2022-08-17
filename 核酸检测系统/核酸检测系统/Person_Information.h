#ifndef __PERSON_INFORMATION_H__
#define __PERSON_INFORMATION_H__
#pragma once

#include"Assistance.h"
#include<iostream>
using namespace std;
class Person_Information                       //人员信息大表中的个人信息
{
public:
	Person_Information();

	Person_Information(string status);

	Person_Information(string number,string status);   //覆盖第一类状态
	Person_Information(string number, string status, string status2);     //覆盖第二类状态
	string Get_s1();
	string Get_s2();
	void Modify_s1(string a);
	void Modify_s2(string a);
	
	~Person_Information();
	friend ostream& operator<<(ostream& out, const Person_Information& d)
	{
		out << d.tube_number << "\t";
		out << d.s1;
		out << "\t";
		out << d.s2 << endl;
		return out;
	}

private:
	
	string tube_number="null";
	string s1 = "Undetected";;                                  //人员状态   等待上传	在排队	  未检测
	string s2="null";							//确诊		可疑	  密接		次密接		阴性
	
};

Person_Information::Person_Information()
{
	tube_number = "null";
	
}


Person_Information::Person_Information(string number, string status)					//调整第一个状态
{
	tube_number = number;
	s1 = status;
}

Person_Information::Person_Information(string number, string status, string status2)    //调整第二个状态
{
	tube_number = number;
	s1 = status;
	s2 = status2;
}

Person_Information::~Person_Information()
{

}

string Person_Information::Get_s1()
{
	return s1;
}

string Person_Information::Get_s2()
{
	return s2;
}

void Person_Information::Modify_s2(string a)
{
	s2 = a;
}
void Person_Information::Modify_s1(string a)
{
	s1 = a;
}

#endif