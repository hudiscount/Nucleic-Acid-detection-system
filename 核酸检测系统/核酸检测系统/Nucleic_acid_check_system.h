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
	string Get_Single_tube_number();                           //�õ����ܵ����
	string Get_Mixed_tube_number();							   //�õ���ܵ����
	map<string, Person_Information>::iterator Find_through_personcode(string s);               //ͨ����Ա�����ѯ״̬
	void Show_STATUS(string STATUS);                            //չʾĳ��״̬����
	void Line_up_in_file();										//�ŶӵǼ�(�ļ���
	void Nucleic_acid_detection_in_file();						//������(�ļ���
	void Line_up();												//�ŶӵǼ�
	void Nucleic_acid_detection();								//������
	void Show_que();
	void Rejister_result();										//�ǼǼ����
	void Status_query();										//������Ա��ѯ
	void Construct_ALL_Information();						   //����ȫԱ��Ϣ���
	void Show_map();										   //��ʾȫԱ��Ϣ���
private:
	LinkQueue<Queue_Information> Mix_que;                 //�ŶӶ���
	LinkQueue<Queue_Information> Single_que;              //�ŶӶ���
	vector<Single_tube> Single;                           //���˲��Թ�vector����
	vector<Mixed_tube> Mix;						          //��ϲ��Թ�vector����
	map<string,Person_Information>  All_information;      //ȫԱ��Ϣ���
	int single_tube_number = 0;							  //���Ƶ�����ˮ��
	int mixed_tube_number = 0;							  //���ƻ����ˮ��
	int count1 = 0;                                       //���ƻ��10��һ���ţ�
	string Current_Mix_number;				//��¼��ǰ����Ļ���Թܺ�
	string Current_Single_number;			//��¼��ǰ����ĵ��ܺ�
	int count = 0;                          //���ƻ�����ܵ���Ա���루10��һ�飩
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
					//�õ���ȫ������Ա����
					Person_Information e;
					All_information.insert(pair<string, Person_Information>(temp, e));
				}
			}
		}
	}

}

map<string, Person_Information>::iterator Nucleic_acid_check_system::Find_through_personcode(string s)
{
	// find ���ص�����ָ��ǰ����Ԫ�ص�λ�÷��򷵻�map::end()λ��
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
	cout << "��Ա����" <<"  " << "����Թܺ�"<<" " << "״̬1"<<"\t" << "״̬2" << endl;
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
						//�õ���ȫ������Ա����
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
						//�õ���ȫ������Ա����
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
	//һֱ�����ļ�ĩβ
	int Mixnum, Singlenum, flag;
	f >> Mixnum;
	f >> Singlenum;
	for (int i = 0; i < Mixnum; i++)
	{
		f >> person_code;
		flag = 0;
		Queue_Information  temp(person_code, flag);
		Mix_que.EnQueue(temp);                   //�ŶӵǼǳɹ�
		Person_Information temp1(person_code, "In_Line");
		All_information[person_code] = temp1;             //�Ķ�ȫԱ����״̬��Ϣ���޸�ΪIn_Lin
	}
	for (int i = 0; i < Singlenum; i++)
	{
		f >> person_code;
		flag = 1;
		Queue_Information  temp(person_code, flag);
		Single_que.EnQueue(temp);                   //�ŶӵǼǳɹ�
		All_information[person_code].Modify_s1("In_Line");        //�Ķ�ȫԱ����״̬��Ϣ���޸�ΪIn_Lin
	}

	f.close();
	cout << "�ŶӶ�ȡ�ɹ�" << endl;
}

inline void Nucleic_acid_check_system::Nucleic_acid_detection_in_file()
{
	/*cout << "������Ҫ���Ļ�Ϻ�������" << endl;
			int Mixed_num;
			cin >> Mixed_num;
			cout << "������Ҫ���ĵ��ܺ�������" << endl;
			int Single_num;
			cin >> Single_num;*/


	fstream f;
	f.open("nucleic_acid_test.in", ios::in);
	//һֱ�����ļ�ĩβ
	int Mixed_num, Single_num;
	f >> Mixed_num;
	f >> Single_num;
	f.close();
	Queue_Information temp;
	string Mixed_tube_number_flag;
	string PerSON_CODE[10];                 //��ʼ���������10����Ա����

	for (int i = 0; i < Mixed_num; i++)
	{
		Mix_que.DelQueue(temp);                             //�����ἴ���Գ��ӣ����ڴ���и�����ܺ�

		if (count < 10)
		{
			PerSON_CODE[count] = temp.Get_Person_code();
			count++;
			if (count == 10)
			{
				Mixed_tube tep(Mixed_tube_number_flag, PerSON_CODE);  //10�μ�¼���ʼ�����ӣ�Ȼ��������Ӷӣ�
				Mix.push_back(tep);
				count = 0;
			}
		}


		Mixed_tube_number_flag = Get_Mixed_tube_number();
		Current_Mix_number = Mixed_tube_number_flag;
		Person_Information temp1(Mixed_tube_number_flag, "Wait_for_upload_result");
		string temp2 = temp.Get_Person_code();
		All_information[temp2] = temp1;               //ÿ���˶����´��״̬





		//�Ķ�ȫԱ����״̬��Ϣ������Ϊ�����

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
	cout << "��������Ա����" << endl;
	cin >> person_code;
	cout << "����Ҫ�����ܺ��ᣬ���ǻ�Ϻ��᣿��Ϻ���:0   ���ܺ���:1" << endl;
	int flag = 0;
	cin >> flag;
	if (flag == 0)
	{
		Queue_Information  temp(person_code, flag);
		Mix_que.EnQueue(temp);                   //�ŶӵǼǳɹ�				
		All_information[person_code].Modify_s1("In_Line");             //�Ķ�ȫԱ����״̬��Ϣ���޸�ΪIn_Lin
	}
	else
	{
		Queue_Information  temp(person_code, flag);
		Single_que.EnQueue(temp);                   //�ŶӵǼǳɹ�
		All_information[person_code].Modify_s1("In_Line");        //�Ķ�ȫԱ����״̬��Ϣ���޸�ΪIn_Lin
	}



	//Queue_Information  temp(person_code, flag);
	//que.EnQueue(temp);                   //�ŶӵǼǳɹ�
	//Person_Information temp1("In_Line");
	//All_information[person_code] = temp1;             //�Ķ�ȫԱ����״̬��Ϣ���޸�ΪIn_Line     


	//Multi.Traverse(Write < Queue_Information>);
	cout << "�����Ŷ���ϣ�" << endl;
}

inline void Nucleic_acid_check_system::Nucleic_acid_detection()
{
	int Mixed_num, Single_num;
	cout << "������Ҫ���Ļ�Ϻ�������" << endl;
	cin >> Mixed_num;
	cout << "������Ҫ���ĵ��ܺ�������" << endl;
	cin >> Single_num;
	if (Mixed_num > Mix_que.GetLength())
	{
		cout << "��ϼ������ҪС�ڶ�Ӧ�Ŷӵ�����" << endl;
		return;
	}
	if (Single_num > Single_que.GetLength())
	{
		cout << "���ܼ������ҪС�ڶ�Ӧ�Ŷӵ�����" << endl;
		return;
	}
	Queue_Information temp;
	string Mixed_tube_number_flag;
	string PerSON_CODE[10];                 //��ʼ���������10����Ա����

	for (int i = 0; i < Mixed_num; i++)
	{
		Mix_que.DelQueue(temp);                             //�����ἴ���Գ��ӣ����ڴ���и�����ܺ�

		if (count < 10)
		{
			PerSON_CODE[count] = temp.Get_Person_code();
			count++;
			if (count == 10)
			{
				Mixed_tube tep(Mixed_tube_number_flag, PerSON_CODE);  //10�μ�¼���ʼ�����ӣ�Ȼ��������Ӷӣ�
				Mix.push_back(tep);
				count = 0;
			}
		}

		Mixed_tube_number_flag = Get_Mixed_tube_number();
		Current_Mix_number = Mixed_tube_number_flag;
		Person_Information temp1(Mixed_tube_number_flag, "Wait_for_upload_result");
		string temp2 = temp.Get_Person_code();
		All_information[temp2] = temp1;               //ÿ���˶����´��״̬





		//�Ķ�ȫԱ����״̬��Ϣ������Ϊ�����

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
	cout << "�鿴�Ŷ����" << endl;
	cout << " ����Ŷ����" << endl;
	Mix_que.Traverse(Write < Queue_Information>);
	cout << " �����Ŷ����" << endl;
	Single_que.Traverse(Write < Queue_Information>);
}

inline void Nucleic_acid_check_system::Rejister_result()
{
	cout << "�ǼǼ����" << endl;
	cout << "������Թܱ��" << endl;
	string Tube_num_temp;
	cin >> Tube_num_temp;
	cout << "������Թܽ��" << endl;
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
					All_information[tempPerCode] = temp1;               //���ܵǼ�	
					cout << "�Ǽǳɹ���" << endl;
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
						All_information[tempPerCode] = temp1;               //��ܵǼ�
					}
					cout << "�Ǽǳɹ���" << endl;
					break;
				}
			}
		}
	}
	if (Result_temp == "Diagnosis")                     //���ʱ����ȷ�ֱ�ӱ�ǵ�����Ա��״̬
	{
		//cout << "w�ҽ�����" << endl;
		if (flag == 1)
		{
			int itemp;
			for (int i = 0; i < Single.size(); i++)
			{
				if (Tube_num_temp == Single[i].Get_tube_number())
				{
					itemp = i;
					cout << "����" << Single[i].Get_tube_number() << endl;
					string tempPerCode = Single[i].Get_personcode();
					string tempTube = Single[i].Get_tube_number();
					Person_Information  p = All_information[tempPerCode];
					//string temps1 = p.Get_s1();
					Person_Information temp1(tempTube, "null", Result_temp);
					cout << Result_temp << endl;
					All_information[tempPerCode] = temp1;               //��ɶԵ���ȷ��ĵǼ�	



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
									All_information[temp].Modify_s2("Contact");			//��ɶ�ͬһ��¥���ܽӱ��
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
							All_information[tempPerCode] = temp11;               //ǰ��10���ܽ�


							for (int k = 1; k < 13; k++)								 //����Ŷӵ�ǰ��10�˵��ܽ�¥��Ϊ���ܽ�
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
							All_information[tempPerCode] = temp1;               //����һ�����ܽ�

							for (int k = 1; k < 13; k++)                                    //����Ŷӵĺ���һλ���ܽ�ͬ��¥Ϊ���ܽ�
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
							          //ǰ��10���ܽ�


							for (int k = 1; k < 13; k++)								 //����Ŷӵ�ǰ��10�˵��ܽ�Ϊ���ܽ�
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
							}              //����һ�����ܽ�

							for (int k = 1; k < 13; k++)                                    //����Ŷӵĺ���һλ���ܽ�ͬ��¥Ϊ���ܽ�
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
							All_information[tempPerCode].Modify_s2("Suspicious");           //��ܵǼ�
						}
						cout << "�Ǽ�Suspicious�ɹ���" << endl;
					

				}
			}
		}
	}
}

inline void Nucleic_acid_check_system::Status_query()
{
	cout << "��������Ҫ��ѯ��״̬" << endl;
	cout << "1.���� 2.ȷ�� 3.���� 4.�ܽ� 5.���ܽ� 6.���ϴ���� 7.���Ŷ�8." << endl;
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
		cout << "��������Чѡ��" << endl;
		return;
	}
}

