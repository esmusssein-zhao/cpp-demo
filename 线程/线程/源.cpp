/*
#include <iostream>
#include <thread>

using namespace std;

//class THREAD
//{
//public:
//	//�º�����ʽ
//	void operator()()//����()    ����Ϊpublic
//	{
//		cout << "�̴߳���" << endl;
//	}
//};
void print(string& s)
{
	cout << s << endl;
}
int main()
{
	//THREAD t;
	//thread b(t);
	//b.join();
	////������THREAD()���һ�����ţ����ⱻʶ��Ϊһ������  THREAD()��ʶ��Ϊһ���������
	//thread a( (THREAD()) );
	//a.join();
	thread a([]() {cout << "���߳�����....." << endl; });
	a.join();
	cout << "���߳�����...." << endl;
	string s("���߳�");
	thread child(print, std::ref(s));
	child.join();
	//return 0;
}
*/
#include<iostream>
#include<thread>
#include<mutex>
#include<queue>
#include<condition_variable>


using namespace std;

//�������洢���������� 
struct CacheData
{
	//��Ʒid 
	int id;
	//��Ʒ���� 
	string data;
};

queue<CacheData> Q;
//���������ռ� 
const int MAX_CACHEDATA_LENGTH = 10;
//��������������֮�䣬������֮�䣬�����ߺ�������֮�䣬ͬʱ��ֻ��һ���̷߳��ʻ����� 
mutex m;
condition_variable condConsumer;
condition_variable condProducer;
//ȫ����Ʒid 
int ID = 1;

//�����߶��� 
void ConsumerActor()
{
	unique_lock<mutex> lockerConsumer(m);
	cout << "[" << this_thread::get_id() << "] ��ȡ����" << endl;
	while (Q.empty())
	{
		cout << "��Ϊ����Ϊ�գ�����������Sleep" << endl;
		cout << "[" << this_thread::get_id() << "] ���ٳ�����" << endl;
		//���пգ� ������ֹͣ���ȴ������߻��� 
		condConsumer.wait(lockerConsumer);
		cout << "[" << this_thread::get_id() << "] Weak, ���»�ȡ����" << endl;
	}
	cout << "[" << this_thread::get_id() << "] ";
	CacheData temp = Q.front();
	cout << "- ID:" << temp.id << " Data:" << temp.data << endl;
	Q.pop();
	condProducer.notify_one();
	cout << "[" << this_thread::get_id() << "] �ͷ�����" << endl;
}

//�����߶��� 
void ProducerActor()
{
	unique_lock<mutex> lockerProducer(m);
	cout << "[" << this_thread::get_id() << "] ��ȡ����" << endl;
	while (Q.size() > MAX_CACHEDATA_LENGTH)
	{
		cout << "��Ϊ����Ϊ��������������Sleep" << endl;
		cout << "[" << this_thread::get_id() << "] ���ٳ�����" << endl;
		//��������������ֹͣ���ȴ������߻��� 
		condProducer.wait(lockerProducer);
		cout << "[" << this_thread::get_id() << "] Weak, ���»�ȡ����" << endl;
	}
	cout << "[" << this_thread::get_id() << "] ";
	CacheData temp;
	temp.id = ID++;
	temp.data = "*****";
	cout << "+ ID:" << temp.id << " Data:" << temp.data << endl;
	Q.push(temp);
	condConsumer.notify_one();
	cout << "[" << this_thread::get_id() << "] �ͷ�����" << endl;
}

//������ 
void ConsumerTask()
{
	while (1)
	{
		ConsumerActor();
	}
}

//������ 
void ProducerTask()
{
	while (1)
	{
		ProducerActor();
	}
}

//�����̵߳ĺ��� 
void Dispatch(int ConsumerNum, int ProducerNum)
{
	vector<thread> thsC;
	for (int i = 0; i < ConsumerNum; ++i)
	{
		thsC.push_back(thread(ConsumerTask));
	}

	vector<thread> thsP;
	for (int j = 0; j < ProducerNum; ++j)
	{
		thsP.push_back(thread(ProducerTask));
	}

	for (int i = 0; i < ConsumerNum; ++i)
	{
		if (thsC[i].joinable())
		{
			thsC[i].join();
		}
	}

	for (int j = 0; j < ProducerNum; ++j)
	{
		if (thsP[j].joinable())
		{
			thsP[j].join();
		}
	}
}

int main()
{
	//һ���������̣߳�5���������̣߳��������߾���Ҫ�ȴ������� 
	Dispatch(1, 5);
	return 0;
}