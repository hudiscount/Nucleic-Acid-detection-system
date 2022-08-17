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
		cout << "*****核酸检测系统*****" << endl;
		cout << endl << "a. 排队登记.（文件）";                 //录入人员代码，更新为排队状态
		cout << endl << "b. 检测核酸.（文件）";					//录入分配管号,只录入队列前面的一部分，为他们分配管，更新状态
		cout << endl << "1. 排队登记.";
		cout << endl << "2. 检测核酸.";
		cout << endl << "3. 查看排队情况.";               
		cout << endl << "4. 登记检测结果.";
		cout << endl << "5. 各类人员查询.";
		cout << endl << "6. 个人查询.";
		cout << endl << "7. 构造全员信息表.";
		cout << endl << "8. 显示全员信息表.";
		cout << endl << "0. 退出";
		cout << endl << "选择功能(0~8):" << endl;
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
			cout << "请输入人员代码" << endl;
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
	system("pause");        // 调用库函数system()

	return 0;
}