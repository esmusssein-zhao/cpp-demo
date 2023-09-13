#include "administrator.h"
#include "staff.h"

using namespace std;

int main()
{
	Administrator menu;
	ifstream file("file.csv");//.csv为字符（逗号）分隔值
	shared_ptr<map<int, vector<string>>>pFileDetails = make_shared<map<int, vector<string>>>(menu.readFile(file));//用make_shared创建智能指针并进行直接初始化
	int choice = 0;
	do
	{
		menu.menu();
		cin >> choice;
		switch (choice)
		{
		//退出
		case 0:
			menu.Exit();
			break;
		//添加
		case 1:
		{
			system("cls");
			(*pFileDetails).insert(menu.Add(pFileDetails));//添加到指针指向的map中
			ofstream os("file.csv");
			menu.saveFile(pFileDetails, os);
			//添加到文件
			system("pause");
			system("cls");
			break;
		}
		//显示所有
		case 2:
			system("cls");
			menu.show(pFileDetails);//显示的是文件中的内容
			system("pause");
			system("cls");
			break;
		//删除
		case 3:
		{
			{
				system("cls");
				//pFileDetails->erase(menu.Delete(pFileDetails));//删除文件中的内容,使用迭代器
				menu.Delete(pFileDetails);
				ofstream os("file.csv");
				menu.saveFile(pFileDetails, os);
				system("pause");
				system("cls");
				break;
			}
		}
		//修改
		case 4:
		{
			system("cls");
			pFileDetails->insert(menu.Change(menu.Find(pFileDetails)));
			ofstream os("file.csv");
			menu.saveFile(pFileDetails, os);
			system("pause");
			system("cls");
			break;
		}
		//查找
		case 5:
		{
			system("cls");
			auto& inforIter = menu.Find(pFileDetails);
			menu.show(inforIter);
			system("pause");
			system("cls");
			break;
		}
		//错误输入
		default:
			system("cls");
			cout << "错误的选择，请重新输入！" << endl;
			system("cls");
			break;
		}
	} while (choice != 0);
	return 0;
}