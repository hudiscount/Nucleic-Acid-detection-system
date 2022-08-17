#pragma once
#include"Queue_Information.h"
#include"LinkQueue.h"
#include"Tube.h"
#include<vector>
#include"Person_Information.h"
#include<string>
#include<map>


class Nucleic_acid_check_system
{
public:
	Nucleic_acid_check_system();
	~Nucleic_acid_check_system();
	string Get_Single_tube_number();                           //得到单管的序号
	string Get_Mixed_tube_number();							   //得到混管的序号
	map<string, Person_Information>::iterator Find_through_personcode(string s);               //通过人员代码查询状态
	void Show_STATUS(string STATUS);                            //展示某种状态的人
	void Line_up_in_file();										//排队登记(文件）
	void Nucleic_acid_detection_in_file();						//检测核酸(文件）
	void Line_up();												//排队登记
	void Nucleic_acid_detection();								//检测核酸
	void Show_que();
	void Rejister_result();										//登记检测结果
	void Status_query();										//各类人员查询
	void Construct_ALL_Information();						   //构建全员信息大表
	void Show_map();										   //显示全员信息大表
private:
	LinkQueue<Queue_Information> Mix_que;                 //排队队列
	LinkQueue<Queue_Information> Single_que;              //排队队列
	vector<Single_tube> Single;                           //单人测试管vector容器
	vector<Mixed_tube> Mix;						          //混合测试管vector容器
	map<string,Person_Information>  All_information;      //全员信息大表
	int single_tube_number = 0;							  //控制单管流水号
	int mixed_tube_number = 0;							  //控制混管流水号
	int count1 = 0;                                       //控制混检10人一组编号；
	string Current_Mix_number;				//记录当前分配的混检试管号
	string Current_Single_number;			//记录当前分配的单管号
	int count = 0;                          //控制混检核酸管的人员代码（10人一组）
};

Nucleic_acid_check_system::Nucleic_acid_check_system()
{	
}

Nucleic_acid_check_system::~Nucleic_acid_check_system()
{
}
string Nucleic_acid_check_system::Get_Single_tube_number() 
{
	string temp= to_string(single_tube_number);
	while (temp.size() < 4)
	{
		temp = '0' + temp;
	}
	single_tube_number++;
	temp = '1' + temp;
	return temp;
}

string Nucleic_acid_check_system::Get_Mixed_tube_number()
{
	if (count1 < 10)
	{
		string temp = to_string(mixed_tube_number);
		while (temp.size() < 4)
		{
			temp = '0' + temp;
		}
		temp = '0' + temp;
		count1++;
		return temp;
	}
	else
	{
		count1 = 0;
		mixed_tube_number++;
		string temp = to_string(mixed_tube_number);
		while (temp.size() < 4)
		{
			temp = '0' + temp;
		}

		temp = '0' + temp;
		count1++;
		return temp;
		/*string temp = to_string(mixed_tube_number);
		while (temp.size() < 5)
		{
			temp = '0' + temp;
		}
		mixed_tube_number++;
		temp = '0' + temp;
		return temp;*/
	}
}

void Nucleic_acid_check_system::Construct_ALL_Information()
{
	
	for (int i = 1; i < 61; i++)
	{
		for (int j = 1; j < 13; j++)
		{
			for (int k = 1; k < 5; k++)
			{
				for (int z = 1; z < 5; z++)
				{
					
					string temp = to_string(z);
					
					string temp1 = to_string(k);
					temp = '0' + temp1 + temp;
					if (j < 10)
					{
						string temp3 = to_string(j);
						temp = '0' + temp3+temp;
					}
					else if (j >= 10)
					{
						string temp3 = to_string(j);
						temp = temp3+temp;
					}
					if (i < 10)
					{
						string temp4 = to_string(i);
						temp = "00"+ temp4 + temp;
					}
					else if (i >= 10)
					{
						string temp4 = to_string(i);
						temp = '0' + temp4 + temp;
					}
					//得到了全部的人员代码
					Person_Information e;
					All_information.insert(pair<string, Person_Information>(temp, e));
				}
			}
		}
	}

}

map<string, Person_Information>::iterator Nucleic_acid_check_system::Find_through_personcode(string s)
{
	// find 返回迭代器指向当前查找元素的位置否则返回map::end()位置
	map<string, Person_Information>::iterator iter;
	iter = All_information.find(s);

	if (iter != All_information.end())
		cout << "Find, the value is" <<"\t" << iter->second << endl;
	
	else
		cout << "Do not Find" << endl;
	return iter;
}
void Nucleic_acid_check_system::Show_map()
{
	map<string, Person_Information>::iterator it = All_information.begin();
	while (it != All_information.end()) {
		cout << it->first << " " << it->second << endl;
		it++;
	}
	cout << "人员代码" <<"  " << "检测试管号"<<" " << "状态1"<<"\t" << "状态2" << endl;
}

void Nucleic_acid_check_system::Show_STATUS(string STATUS)
{
	int flag = 0;
	if (STATUS == "Wait_for_upload_result"||STATUS=="In_Line")
	{
		flag = 1;
	}
	if (flag == 1)
	{
		for (int i = 1; i < 61; i++)
		{
			for (int j = 1; j < 13; j++)
			{
				for (int k = 1; k < 5; k++)
				{
					for (int z = 1; z < 5; z++)
					{

						string temp = to_string(z);

						string temp1 = to_string(k);
						temp = '0' + temp1 + temp;
						if (j < 10)
						{
							string temp3 = to_string(j);
							temp = '0' + temp3 + temp;
						}
						else if (j >= 10)
						{
							string temp3 = to_string(j);
							temp = temp3 + temp;
						}
						if (i < 10)
						{
							string temp4 = to_string(i);
							temp = "00" + temp4 + temp;
						}
						else if (i >= 10)
						{
							string temp4 = to_string(i);
							temp = '0' + temp4 + temp;
						}
						//得到了全部的人员代码
						Person_Information e;
						if (All_information[temp].Get_s1() == STATUS)
							cout << All_information[temp] << endl;
					}
				}
			}
		}
	}
	else
	{
		for (int i = 1; i < 61; i++)
		{
			for (int j = 1; j < 13; j++)
			{
				for (int k = 1; k < 5; k++)
				{
					for (int z = 1; z < 5; z++)
					{

						string temp = to_string(z);

						string temp1 = to_string(k);
						temp = '0' + temp1 + temp;
						if (j < 10)
						{
							string temp3 = to_string(j);
							temp = '0' + temp3 + temp;
						}
						else if (j >= 10)
						{
							string temp3 = to_string(j);
							temp = temp3 + temp;
						}
						if (i < 10)
						{
							string temp4 = to_string(i);
							temp = "00" + temp4 + temp;
						}
						else if (i >= 10)
						{
							string temp4 = to_string(i);
							temp = '0' + temp4 + temp;
						}
						//得到了全部的人员代码
						Person_Information e;
						if (All_information[temp].Get_s2() == STATUS)
							cout << temp<<"\t" << All_information[temp] << endl;
					}
				}
			}
		}
	}
	
}

inline void Nucleic_acid_check_system::Line_up_in_file()
{
	string person_code;
	string tube_number;
	fstream f;
	f.open("line_up.in", ios::in);
	//一直读到文件末尾
	int Mixnum, Singlenum, flag;
	f >> Mixnum;
	f >> Singlenum;
	for (int i = 0; i < Mixnum; i++)
	{
		f >> person_code;
		flag = 0;
		Queue_Information  temp(person_code, flag);
		Mix_que.EnQueue(temp);                   //排队登记成功
		Person_Information temp1(person_code, "In_Line");
		All_information[person_code] = temp1;             //改动全员大表的状态信息，修改为In_Lin
	}
	for (int i = 0; i < Singlenum; i++)
	{
		f >> person_code;
		flag = 1;
		Queue_Information  temp(person_code, flag);
		Single_que.EnQueue(temp);                   //排队登记成功
		All_information[person_code].Modify_s1("In_Line");        //改动全员大表的状态信息，修改为In_Lin
	}

	f.close();
	cout << "排队读取成功" << endl;
}

inline void Nucleic_acid_check_system::Nucleic_acid_detection_in_file()
{
	/*cout << "请输入要检测的混合核酸人数" << endl;
			int Mixed_num;
			cin >> Mixed_num;
			cout << "请输入要检测的单管核酸人数" << endl;
			int Single_num;
			cin >> Single_num;*/


	fstream f;
	f.open("nucleic_acid_test.in", ios::in);
	//一直读到文件末尾
	int Mixed_num, Single_num;
	f >> Mixed_num;
	f >> Single_num;
	f.close();
	Queue_Information temp;
	string Mixed_tube_number_flag;
	string PerSON_CODE[10];                 //初始管子所需的10个人员代码

	for (int i = 0; i < Mixed_num; i++)
	{
		Mix_que.DelQueue(temp);                             //检测核酸即可以出队，并在大表中赋核酸管号

		if (count < 10)
		{
			PerSON_CODE[count] = temp.Get_Person_code();
			count++;
			if (count == 10)
			{
				Mixed_tube tep(Mixed_tube_number_flag, PerSON_CODE);  //10次记录后初始化管子，然后入混检管子队；
				Mix.push_back(tep);
				count = 0;
			}
		}


		Mixed_tube_number_flag = Get_Mixed_tube_number();
		Current_Mix_number = Mixed_tube_number_flag;
		Person_Information temp1(Mixed_tube_number_flag, "Wait_for_upload_result");
		string temp2 = temp.Get_Person_code();
		All_information[temp2] = temp1;               //每个人都更新大表状态





		//改动全员大表的状态信息，更新为待检测

	}
	for (int i = 0; i < Single_num; i++)
	{
		Single_que.DelQueue(temp);
		string temp_Tube_number = Get_Single_tube_number();
		Current_Single_number = temp_Tube_number;
		Person_Information temp1(temp_Tube_number, "Wait_for_upload_result");
		string temp2 = temp.Get_Person_code();
		All_information[temp2] = temp1;
		Single_tube a(temp_Tube_number, temp2);
		Single.push_back(a);
	}
}

inline void Nucleic_acid_check_system::Line_up()
{
	string person_code;
	string tube_number;
	cout << "请输入人员代码" << endl;
	cin >> person_code;
	cout << "请问要做单管核酸，还是混合核酸？混合核酸:0   单管核酸:1" << endl;
	int flag = 0;
	cin >> flag;
	if (flag == 0)
	{
		Queue_Information  temp(person_code, flag);
		Mix_que.EnQueue(temp);                   //排队登记成功				
		All_information[person_code].Modify_s1("In_Line");             //改动全员大表的状态信息，修改为In_Lin
	}
	else
	{
		Queue_Information  temp(person_code, flag);
		Single_que.EnQueue(temp);                   //排队登记成功
		All_information[person_code].Modify_s1("In_Line");        //改动全员大表的状态信息，修改为In_Lin
	}



	//Queue_Information  temp(person_code, flag);
	//que.EnQueue(temp);                   //排队登记成功
	//Person_Information temp1("In_Line");
	//All_information[person_code] = temp1;             //改动全员大表的状态信息，修改为In_Line     


	//Multi.Traverse(Write < Queue_Information>);
	cout << "单人排队完毕！" << endl;
}

inline void Nucleic_acid_check_system::Nucleic_acid_detection()
{
	int Mixed_num, Single_num;
	cout << "请输入要检测的混合核酸人数" << endl;
	cin >> Mixed_num;
	cout << "请输入要检测的单管核酸人数" << endl;
	cin >> Single_num;
	if (Mixed_num > Mix_que.GetLength())
	{
		cout << "混合检测人数要小于对应排队的人数" << endl;
		return;
	}
	if (Single_num > Single_que.GetLength())
	{
		cout << "单管检测人数要小于对应排队的人数" << endl;
		return;
	}
	Queue_Information temp;
	string Mixed_tube_number_flag;
	string PerSON_CODE[10];                 //初始管子所需的10个人员代码

	for (int i = 0; i < Mixed_num; i++)
	{
		Mix_que.DelQueue(temp);                             //检测核酸即可以出队，并在大表中赋核酸管号

		if (count < 10)
		{
			PerSON_CODE[count] = temp.Get_Person_code();
			count++;
			if (count == 10)
			{
				Mixed_tube tep(Mixed_tube_number_flag, PerSON_CODE);  //10次记录后初始化管子，然后入混检管子队；
				Mix.push_back(tep);
				count = 0;
			}
		}

		Mixed_tube_number_flag = Get_Mixed_tube_number();
		Current_Mix_number = Mixed_tube_number_flag;
		Person_Information temp1(Mixed_tube_number_flag, "Wait_for_upload_result");
		string temp2 = temp.Get_Person_code();
		All_information[temp2] = temp1;               //每个人都更新大表状态





		//改动全员大表的状态信息，更新为待检测

	}
	for (int i = 0; i < Single_num; i++)
	{
		Single_que.DelQueue(temp);
		string temp_Tube_number = Get_Single_tube_number();
		Current_Single_number = temp_Tube_number;
		Person_Information temp1(temp_Tube_number, "Wait_for_upload_result");
		string temp2 = temp.Get_Person_code();
		All_information[temp2] = temp1;
		Single_tube a(temp_Tube_number, temp2);
		Single.push_back(a);
	}
}

inline void Nucleic_acid_check_system::Show_que()
{
	cout << "查看排队情况" << endl;
	cout << " 混管排队情况" << endl;
	Mix_que.Traverse(Write < Queue_Information>);
	cout << " 单管排队情况" << endl;
	Single_que.Traverse(Write < Queue_Information>);
}

inline void Nucleic_acid_check_system::Rejister_result()
{
	cout << "登记检测结果" << endl;
	cout << "输入测试管编号" << endl;
	string Tube_num_temp;
	cin >> Tube_num_temp;
	cout << "输入测试管结果" << endl;
	string Result_temp;
	cin >> Result_temp;
	int flag;
	int panduan = stoi(Tube_num_temp.substr(0, 1));
	flag = panduan;
	//cout << flag << endl;
	if (Result_temp == "Negative")
	{
		if (flag == 1)
		{
			for (int i = 0; i < Single.size(); i++)
			{
				if (Tube_num_temp == Single[i].Get_tube_number())
				{
					string tempPerCode = Single[i].Get_personcode();
					string tempTube = Single[i].Get_tube_number();
					Person_Information  p = All_information[tempPerCode];
					string temps1 = p.Get_s1();
					Person_Information temp1(tempTube, "null", Result_temp);
					All_information[tempPerCode] = temp1;               //单管登记	
					cout << "登记成功！" << endl;
					break;
				}

			}

		}
		if (flag == 0)
		{
			for (int i = 0; i < Mix.size(); i++)
			{
				if (Tube_num_temp == Mix[i].Get_tube_number())
				{
					for (int j = 0; j < 10; j++)
					{
						string tempPerCode = Mix[i].Get_personcode()[j];
						string tempTube = Mix[i].Get_tube_number();
						Person_Information  p = All_information[tempPerCode];
						string temps1 = p.Get_s1();
						Person_Information temp1(tempTube, "null", Result_temp);
						All_information[tempPerCode] = temp1;               //混管登记
					}
					cout << "登记成功！" << endl;
					break;
				}
			}
		}
	}
	if (Result_temp == "Diagnosis")                     //如果时单管确诊，直接标记单个人员的状态
	{
		//cout << "w我进来了" << endl;
		if (flag == 1)
		{
			int itemp;
			for (int i = 0; i < Single.size(); i++)
			{
				if (Tube_num_temp == Single[i].Get_tube_number())
				{
					itemp = i;
					cout << "管子" << Single[i].Get_tube_number() << endl;
					string tempPerCode = Single[i].Get_personcode();
					string tempTube = Single[i].Get_tube_number();
					Person_Information  p = All_information[tempPerCode];
					//string temps1 = p.Get_s1();
					Person_Information temp1(tempTube, "null", Result_temp);
					cout << Result_temp << endl;
					All_information[tempPerCode] = temp1;               //完成对单管确诊的登记	



					tempPerCode = Single[i].Get_personcode();
					for (int k = 1; k < 13; k++)
					{
						for (int y = 1; y < 5; y++)
						{
							for (int z = 1; z < 5; z++)
							{
								string temp = tempPerCode.substr(0, 3);
								string temp1 = to_string(k);
								string temp2 = to_string(y);
								string temp3 = to_string(z);
								if (k < 10)
								{
									temp = temp + '0' + temp1 + '0' + temp2 + temp3;
								}
								else if (k >= 10)
								{
									temp = temp + temp1 + '0' + temp2 + temp3;
								}
								if (All_information[temp].Get_s2() != "Diagnosis" && All_information[temp].Get_s2() != "Suspicious")
								{
									All_information[temp].Modify_s2("Contact");			//完成对同一栋楼的密接标记
								}


							}
						}
					}


					All_information[tempPerCode].Modify_s2(Result_temp);
					cout << tempPerCode << endl;

					if ((i - 10) >= 0)
					{
						for (int j = i - 10; j < i; j++)
						{
							string tempPerCode = Single[j].Get_personcode();
							string tempTube = Single[j].Get_tube_number();
							Person_Information  p = All_information[tempPerCode];
							//string temps1 = p.Get_s1();
							Person_Information temp11(tempTube, "null", "Contact");
							All_information[tempPerCode] = temp11;               //前面10人密接


							for (int k = 1; k < 13; k++)								 //标记排队的前面10人的密接楼栋为次密接
							{
								for (int y = 1; y < 5; y++)
								{
									for (int z = 1; z < 5; z++)
									{
										string temp = tempPerCode.substr(0, 3);
										string temp1 = to_string(k);
										string temp2 = to_string(y);
										string temp3 = to_string(z);
										if (k < 10)
										{
											temp = temp + '0' + temp1 + '0' + temp2 + temp3;
										}
										else if (k >= 10)
										{
											temp = temp + temp1 + '0' + temp2 + temp3;
										}
										if (All_information[temp].Get_s2() != "Diagnosis" && All_information[temp].Get_s2() != "Suspicious" && All_information[temp].Get_s2() != "Contact")
										{
											All_information[temp].Modify_s2("Sub_Contact");
										}


									}
								}
							}
						}
						int kk = i+1;
						if (kk < Single.size())
						{
							string tempPerCode = Single[kk].Get_personcode();
							string tempTube = Single[kk].Get_tube_number();
							Person_Information  p = All_information[tempPerCode];
							//string temps1 = p.Get_s1();
							Person_Information temp1(tempTube, "null", "Contact");
							All_information[tempPerCode] = temp1;               //后面一个人密接

							for (int k = 1; k < 13; k++)                                    //标记排队的后面一位的密接同栋楼为次密接
							{
								for (int y = 1; y < 5; y++)
								{
									for (int z = 1; z < 5; z++)
									{
										string temp = tempPerCode.substr(0, 3);
										string temp1 = to_string(k);
										string temp2 = to_string(y);
										string temp3 = to_string(z);
										if (k < 10)
										{
											temp = temp + '0' + temp1 + '0' + temp2 + temp3;
										}
										else if (k >= 10)
										{
											temp = temp + temp1 + '0' + temp2 + temp3;
										}
										if (All_information[temp].Get_s2() != "Diagnosis" && All_information[temp].Get_s2() != "Suspicious" && All_information[temp].Get_s2() != "Contact")
										{
											All_information[temp].Modify_s2("Sub_Contact");
										}
									}
								}
							}
						}
					}


					if ((i - 10) < 0)
					{
						for (int j = 0; j < i; j++)
						{
							string tempPerCode = Single[j].Get_personcode();
							string tempTube = Single[j].Get_tube_number();
							Person_Information  p = All_information[tempPerCode];
							if (All_information[tempPerCode].Get_s2() != "Diagnosis" && All_information[tempPerCode].Get_s2() != "Suspicious")
							{
								All_information[tempPerCode].Modify_s2("Contact");
							}//string temps1 = p.Get_s1();
							          //前面10人密接


							for (int k = 1; k < 13; k++)								 //标记排队的前面10人的密接为次密接
							{
								for (int y = 1; y < 5; y++)
								{
									for (int z = 1; z < 5; z++)
									{
										string temp = tempPerCode.substr(0, 3);
										string temp1 = to_string(k);
										string temp2 = to_string(y);
										string temp3 = to_string(z);
										if (k < 10)
										{
											temp = temp + '0' + temp1 + '0' + temp2 + temp3;
										}
										else if (k >= 10)
										{
											temp = temp + temp1 + '0' + temp2 + temp3;
										}
										if (All_information[temp].Get_s2() != "Diagnosis" && All_information[temp].Get_s2() != "Suspicious" && All_information[temp].Get_s2() != "Contact")
										{
											All_information[temp].Modify_s2("Sub_Contact");
										}


									}
								}
							}
						}
						int mm = i + 1;
						if (mm < Single.size())
						{
							string tempPerCode = Single[mm].Get_personcode();
							string tempTube = Single[mm].Get_tube_number();
							Person_Information  p = All_information[tempPerCode];
							//string temps1 = p.Get_s1();
							if (All_information[tempPerCode].Get_s2() != "Diagnosis" && All_information[tempPerCode].Get_s2() != "Suspicious")
							{
								All_information[tempPerCode].Modify_s2("Contact");
							}              //后面一个人密接

							for (int k = 1; k < 13; k++)                                    //标记排队的后面一位的密接同栋楼为次密接
							{
								for (int y = 1; y < 5; y++)
								{
									for (int z = 1; z < 5; z++)
									{
										string temp = tempPerCode.substr(0, 3);
										string temp1 = to_string(k);
										string temp2 = to_string(y);
										string temp3 = to_string(z);
										if (k < 10)
										{
											temp = temp + '0' + temp1 + '0' + temp2 + temp3;
										}
										else if (k >= 10)
										{
											temp = temp + temp1 + '0' + temp2 + temp3;
										}
										if (All_information[temp].Get_s2() != "Diagnosis" && All_information[temp].Get_s2() != "Suspicious" && All_information[temp].Get_s2() != "Contact")
										{
											All_information[temp].Modify_s2("Sub_Contact");
										}
									}
								}
							}
						}
					}
					break;
				}

			}


		}
		if (flag == 0)
		{
			//cout << Mix.size() << endl;
			for (int i = 0; i < Mix.size(); i++)
			{
				cout << Mix[i].Get_tube_number() << endl;
				if (Tube_num_temp == Mix[i].Get_tube_number())
				{

					
						for (int j = 0; j < 10; j++)
						{
							string tempPerCode = Mix[i].Get_personcode()[j];
							All_information[tempPerCode].Modify_s1("null");
							All_information[tempPerCode].Modify_s2("Suspicious");           //混管登记
						}
						cout << "登记Suspicious成功！" << endl;
					

				}
			}
		}
	}
}

inline void Nucleic_acid_check_system::Status_query()
{
	cout << "请输入想要查询的状态" << endl;
	cout << "1.阴性 2.确诊 3.可疑 4.密接 5.次密接 6.待上传结果 7.在排队8." << endl;
	int i;
	cin >> i;
	if (i == 1)
	{
		Show_STATUS("Negative");
	}
	else if (i == 2)
	{
		Show_STATUS("Diagnosis");
	}
	else if (i == 3)
	{
		Show_STATUS("Suspicious");
	}
	else if (i == 4)
	{
		Show_STATUS("Contact");
	}
	else if (i == 5)
	{
		Show_STATUS("Sub_Contact");
	}
	else if (i == 6)
	{
		Show_STATUS("Wait_for_upload_result");
	}
	else if (i == 7)
	{
		Show_STATUS("Diagnosis");
	}
	else
	{
		cout << "请输入有效选项" << endl;
		return;
	}
}

