#ifndef __QUEUE_INFORMATION_H__
#define __QUEUE_INFORMATION_H__
#pragma once
#include<iostream>
using namespace std;
class Queue_Information							//�Ŷӽڵ���Ϣ
{
public:
	Queue_Information();
	Queue_Information(string person_code, int flag1);
	~Queue_Information();

	string Get_Person_code();

	int  Get_flag();
	
	Queue_Information& operator =(Queue_Information q);

	friend ostream& operator<<(ostream& out, const Queue_Information& d)
	{
		out<< "��Ա����" << d.Person_code <<" " << d.flag << endl;
		return out;
	}
	friend istream& operator>>(istream& in, Queue_Information& d)
	{

	}
private:
	string Person_code;							//��Ա����
	int flag ;										//0:��ʾĬ�ϻ�ϼ��
	//int tag[7] = { 0,0,0,0,0,0,0};
};


Queue_Information::Queue_Information()
{

}

Queue_Information::Queue_Information(string person_code, int flag1)
{
	Person_code = person_code;
	flag = flag1;

}

Queue_Information::~Queue_Information()
{
}

string Queue_Information::Get_Person_code()
{
	string temp = Person_code;
	return temp;
}

 int Queue_Information::Get_flag()
{
	 int temp = flag;
	 return temp;
}



Queue_Information& Queue_Information::operator =(Queue_Information q)
{
	Person_code = q.Get_Person_code();
	flag = q.Get_flag();
	return *this;
}
#endif

