#include "administrator.h"
#include "staff.h"

using namespace std;

int main()
{
	Administrator menu;
	ifstream file("file.csv");//.csvΪ�ַ������ţ��ָ�ֵ
	shared_ptr<map<int, vector<string>>>pFileDetails = make_shared<map<int, vector<string>>>(menu.readFile(file));//��make_shared��������ָ�벢����ֱ�ӳ�ʼ��
	int choice = 0;
	do
	{
		menu.menu();
		cin >> choice;
		switch (choice)
		{
		//�˳�
		case 0:
			menu.Exit();
			break;
		//���
		case 1:
		{
			system("cls");
			(*pFileDetails).insert(menu.Add(pFileDetails));//��ӵ�ָ��ָ���map��
			ofstream os("file.csv");
			menu.saveFile(pFileDetails, os);
			//��ӵ��ļ�
			system("pause");
			system("cls");
			break;
		}
		//��ʾ����
		case 2:
			system("cls");
			menu.show(pFileDetails);//��ʾ�����ļ��е�����
			system("pause");
			system("cls");
			break;
		//ɾ��
		case 3:
		{
			{
				system("cls");
				//pFileDetails->erase(menu.Delete(pFileDetails));//ɾ���ļ��е�����,ʹ�õ�����
				menu.Delete(pFileDetails);
				ofstream os("file.csv");
				menu.saveFile(pFileDetails, os);
				system("pause");
				system("cls");
				break;
			}
		}
		//�޸�
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
		//����
		case 5:
		{
			system("cls");
			auto& inforIter = menu.Find(pFileDetails);
			menu.show(inforIter);
			system("pause");
			system("cls");
			break;
		}
		//��������
		default:
			system("cls");
			cout << "�����ѡ�����������룡" << endl;
			system("cls");
			break;
		}
	} while (choice != 0);
	return 0;
}