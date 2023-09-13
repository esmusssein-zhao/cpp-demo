#include "head.h"
using namespace std;
int main()
{
	//文件流读取
	ifstream ifs("addressBook.txt");
	//vector<Person>addressBook = readFile(ifs);//改为使用智能指针
	// vector<Person>news=addressBook;
	//shared_ptr<vector<Person>> book_ptr = make_shared<vector<Person>>(addressBook);//book_ptr指向的和addressBook不同
	auto book_ptr = make_shared<vector<Person>>(readFile(ifs));

menu:
	//菜单选择
	int choice = menu();
	system("cls");
	//添加
	if (choice == 1)
	{
		Person news = addNewMm();
		//addressBook.push_back(news);
		book_ptr->push_back(news);
		cout << "Add successful!" << endl;
		system("pause");
		system("cls");
		goto menu;
	}
	//显示
	if (choice == 2)
	{
		//show(addressBook);
		//show(book_ptr);
		cout << book_ptr;
		system("pause");
		system("cls");
		goto menu;
	}
	//删除(姓名)
	if (choice == 3)
	{
		delMember(book_ptr);
		system("pause");
		system("cls");
		goto menu;
	}
	//查找(姓名)
	if (choice == 4)
	{
		string name;
		auto end = book_ptr->end();
		bool flag = false;
		do
		{
			cout << "Enter the name you want to find->";
			while (cin >> name, cin.get() != '\n') {}
			auto result = find(book_ptr, name);
			if (result != end)
			{
				print(*result);
				break;
			}
			else
			{
				cout << "There's no information on this guy! try again?(y/n)->";
				while (cin >> name, cin.get() != '\n') {}
				if (name == "Y" || name == "y" || name == "YES" || name == "yes")
					flag = true;
				else
					break;
			}
		} while (flag);
		system("pause");
		system("cls");
		goto menu;
	}
	//修改(姓名)
	if (choice == 5)
	{
		changeMember(book_ptr);
		system("pause");
		system("cls");
		goto menu;
	}
	//清空
	if (choice == 6)
	{
		string name;
		bool flag = false;
		std::cout << "Are you sure to delete everything?(y/n)->";
		while (std::cin >> name, std::cin.get() != '\n') {}
		if (name == "Y" || name == "y" || name == "YES" || name == "yes")
			flag = true;
		while (flag)
		{
			book_ptr->clear();//清除所有内容
			cout << "accomplish!" << endl;
			system("pause");
			system("cls");
		}
		goto menu;
	}
	//退出并保存
	if (choice == 7)
	{
		save(book_ptr);
		return 0;
	}
}