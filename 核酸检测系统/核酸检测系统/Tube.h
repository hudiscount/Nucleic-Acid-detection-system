#pragma once
#include<iostream>
using namespace std;
class Single_tube
{
public:
	Single_tube(string Number, string Personcode);
	string Get_personcode();
	string Get_tube_number();
	~Single_tube();

private:
	string tube_number;
	string personcode;
};

Single_tube::Single_tube(string Number ,string Personcode)
{
	tube_number = Number;
	personcode = Personcode;
}

inline string Single_tube::Get_personcode()
{
	
	return personcode;
}

inline string Single_tube::Get_tube_number()
{
	return tube_number;
}

Single_tube::~Single_tube()
{

}


class Mixed_tube
{
public:
	Mixed_tube(string number, string* personcode1);
	~Mixed_tube();
	string* Get_personcode();
	string Get_tube_number();
private:
	string personcode[10];
	string tube_number;
};

Mixed_tube::Mixed_tube(string number, string* personcode1)
{
	for (int i = 0; i < 10; i++)
	{
		personcode[i]=personcode1[i];
	}
	tube_number = number;
}

Mixed_tube::~Mixed_tube()
{
	
}
inline string* Mixed_tube::Get_personcode()
{
	return personcode;
}
inline string Mixed_tube::Get_tube_number()
{
	return tube_number;
}
//if (flag == 0)
//{
//	int tube0temp = tube0 / 10;
//	tube0++;
//	string temp;
//	stringstream ss;
//	ss << tube0temp;
//	ss >> temp;                //string 
//	int n = 0;
//
//	for (int i = temp.size(); temp.size() < 5; i++)
//	{
//		temp = '0' + temp;
//	}
//	tube_number = '0' + temp;
//	Queue_Information person(person_code, flag);
//	Shanghai.Multi.InsertElem(person);
//
//}
//else if (flag == 1)
//{
//	int tube1temp = tube1;
//	tube1++;
//	string temp;
//	stringstream ss;
//	ss << tube1temp;
//	ss >> temp;                //string 
//	int n = 0;
//
//	for (int i = temp.size(); temp.size() < 4; i++)
//	{
//		temp = '0' + temp;
//	}
//	tube_number = '1' + temp;
//	Queue_Information person(person_code, flag);
//	Shanghai.Single.InsertElem(person);
//}
//else {
//	cout << "请输入正确的格式（0/1）" << endl;
//}