#include "head.h"
using namespace std;
int main()
{
	//�ļ�����ȡ
	ifstream ifs("addressBook.txt");
	//vector<Person>addressBook = readFile(ifs);//��Ϊʹ������ָ��
	// vector<Person>news=addressBook;
	//shared_ptr<vector<Person>> book_ptr = make_shared<vector<Person>>(addressBook);//book_ptrָ��ĺ�addressBook��ͬ
	auto book_ptr = make_shared<vector<Person>>(readFile(ifs));

menu:
	//�˵�ѡ��
	int choice = menu();
	system("cls");
	//���
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
	//��ʾ
	if (choice == 2)
	{
		//show(addressBook);
		//show(book_ptr);
		cout << book_ptr;
		system("pause");
		system("cls");
		goto menu;
	}
	//ɾ��(����)
	if (choice == 3)
	{
		delMember(book_ptr);
		system("pause");
		system("cls");
		goto menu;
	}
	//����(����)
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
	//�޸�(����)
	if (choice == 5)
	{
		changeMember(book_ptr);
		system("pause");
		system("cls");
		goto menu;
	}
	//���
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
			book_ptr->clear();//�����������
			cout << "accomplish!" << endl;
			system("pause");
			system("cls");
		}
		goto menu;
	}
	//�˳�������
	if (choice == 7)
	{
		save(book_ptr);
		return 0;
	}
}