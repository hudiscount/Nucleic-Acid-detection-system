#include<cstdlib>
#include<sstream>
#include<string>
#include"Nucleic_acid_check_system.h"
using namespace std;
int main()
{
	Nucleic_acid_check_system Shanghai;
	char c = '*';
	while (c != '0')
	{
		cout << "*****������ϵͳ*****" << endl;
		cout << endl << "a. �ŶӵǼ�.���ļ���";                 //¼����Ա���룬����Ϊ�Ŷ�״̬
		cout << endl << "b. ������.���ļ���";					//¼�����ܺ�,ֻ¼�����ǰ���һ���֣�Ϊ���Ƿ���ܣ�����״̬
		cout << endl << "1. �ŶӵǼ�.";
		cout << endl << "2. ������.";
		cout << endl << "3. �鿴�Ŷ����.";               
		cout << endl << "4. �ǼǼ����.";
		cout << endl << "5. ������Ա��ѯ.";
		cout << endl << "6. ���˲�ѯ.";
		cout << endl << "7. ����ȫԱ��Ϣ��.";
		cout << endl << "8. ��ʾȫԱ��Ϣ��.";
		cout << endl << "0. �˳�";
		cout << endl << "ѡ����(0~8):" << endl;
		cin >> c;
		switch (c)
		{
		case 'a':
		{
			Shanghai.Line_up_in_file();
			break;
		}
		case 'b':
		{
			Shanghai.Nucleic_acid_detection_in_file();
			break;
		}
		case '1':
		{
			Shanghai.Line_up();
			break;
		}
		case '2':
		{
			Shanghai.Nucleic_acid_detection();
			break;
		}
		case '3':
		{
			Shanghai.Show_que();
			break;
		}
		case '4':
		{
			Shanghai.Rejister_result();
			break;
		}
		case'5':
		{
			Shanghai.Status_query();
			break;
		}
		case '6':
		{
			cout << "��������Ա����" << endl;
			string temp;
			cin >> temp;
			Shanghai.Find_through_personcode(temp);
		}
		case '7':
		{
			Shanghai.Construct_ALL_Information();

			break;
		}
		case '8':
		{
			Shanghai.Show_map();
			break;
		}
		
		case '0':
			break;
		}

		}
	system("pause");        // ���ÿ⺯��system()

	return 0;
}