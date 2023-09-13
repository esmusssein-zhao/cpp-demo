#include <iostream>
#include <list>
#include <map>
using namespace std;
//��������ʽ
class SINGLETON_LAZY
{
private:
	SINGLETON_LAZY() = default;
	static SINGLETON_LAZY* lazy_p;
public:
	static SINGLETON_LAZY* getInstance()
	{
		if (lazy_p == nullptr)
			lazy_p = new SINGLETON_LAZY;
		return lazy_p;
	}
};
SINGLETON_LAZY* SINGLETON_LAZY::lazy_p = nullptr;
//��������ʽ
class SINGLETON_HUNGRY
{
private:
	SINGLETON_HUNGRY() = default;
	static SINGLETON_HUNGRY* hungry_p;
public:
	static SINGLETON_HUNGRY* getInstance()
	{
		return hungry_p;
	}
};
SINGLETON_HUNGRY* SINGLETON_HUNGRY::hungry_p = new SINGLETON_HUNGRY;

//�򵥹���
class fruit//������  ���ڴ�����ϸˮ��
{
public:
	virtual void fruit_name() = 0;
};
class apple:public fruit
{
public:
	virtual void fruit_name() override{ cout << "this is a apple"; }
};
class pear :public fruit
{
public:
	virtual void fruit_name() override { cout << "this is a pear"; }
};
class peach :public fruit
{
public:
	virtual void fruit_name() override { cout << "this is a peach"; }
};
class fruit_factory//ˮ��������ֱ�����ɶ�Ӧ���͵�ˮ��
{
public:
	static fruit* make_fruit(string name)
	{
		if (name == "apple")
			return new apple;
		if (name == "pear")
			return new pear;
		if (name == "peach")
			return new peach;
		else
			return nullptr;
	}
};

//��������
class abstruct_factory//�����  ��Ӧ������һ���͵�����
{
public:
	virtual fruit* produce() = 0;
};
class apple_factory :public abstruct_factory
{
public:
	virtual fruit* produce() override{ return new apple; }
};
class pear_factory :public abstruct_factory
{
public:
	virtual fruit* produce() override { return new pear; }
};
class peach_factory :public abstruct_factory
{
public:
	virtual fruit* produce() override { return new peach; }
};

//���󹤳�
class abstructSingleCore //���󵥺� 
{
public:
	virtual void print1() = 0;
};
class A_SingleCore :public abstructSingleCore//a���ĵ���
{
public:
	virtual void print1() override { cout << "SingleCore from A factory" << endl; }
};
class B_SingleCore :public  abstructSingleCore//b���ĵ���
{
public:
	virtual void print1() override  { cout << "SingleCore from B factory" << endl; }
};
class abstructMulticore//������
{
public:
	virtual void print2() = 0;
};
class A_Multicore :public abstructMulticore//a���Ķ��
{
public:
	virtual void print2() override { cout << "Multicore from A factory" << endl; }
};
class B_Multicore :public  abstructMulticore//b���Ķ��
{
public:
	virtual void print2() override { cout << "Multicore from B factory" << endl; }
};
class abstructFactory//���󹤳�
{
public:
	virtual abstructMulticore* createMulticore() = 0;//���ж��
	virtual abstructSingleCore* createSingleCore() = 0;//���е���
};
class A_factory :public abstructFactory//����a
{
public:
	virtual abstructMulticore* createMulticore() override
	{
		return new A_Multicore;
	}
	virtual abstructSingleCore* createSingleCore() override
	{
		return new A_SingleCore;
	}
};
class B_factory :public abstructFactory//����b
{
public:
	virtual abstructMulticore* createMulticore() override
	{
		return new B_Multicore;
	}
	virtual abstructSingleCore* createSingleCore() override
	{
		return new B_SingleCore;
	}
};

//����ģʽ
class abstructWeb//�����Ҫʹ�õĹ���
{
public:
	virtual void show() = 0;
};
class YouTube :public abstructWeb//�޷�ֱ�ӷ��ʵ���վ
{
public:
	virtual void show()override
	{
		cout << "web opening..." << endl;
	}
};
class VPN :public abstructWeb//ͨ���������� �޷����ʵ���վ���з���
{
private:
	abstructWeb* web;
public:
	virtual void show()override
	{
		if (web == nullptr)
			web = new YouTube;
		web->show();
	}
};

//��Ԫģʽ  
enum COLOUR
{
	BLACK,
	YELLOW,
	GREEN
};
class Front
{
private:
	COLOUR c=BLACK;
	int size=10;
	string style="Roman";
public:
	Front() = default;
	void doSomeThing() { cout << "using front" << endl; }
};
class ComputerFront
{
private:
	map<string, Front*> frontLibrary;
public:
	Front* pFront(string name)
	{
		auto p = frontLibrary.find(name);
		if (p == frontLibrary.end())
		{
			Front* pfront = new Front;
			frontLibrary.insert({ name, pfront });
			return pfront;
		}
		else
			return p->second;
	}
	~ComputerFront()
	{
		for (auto& everyPair : frontLibrary)
		{
			cout << everyPair.first << " is free" << endl;
			delete everyPair.second;//��Ӧ������ָ�벻��Ҫ�ֶ��ͷ�
		}
	}
};

//�۲���ģʽ
class Observer
{
public:
	Observer() {}
	virtual ~Observer() {}
	virtual void Update() {}
};  
class Blog
{
public:
	Blog() {}
	virtual ~Blog() {}
	void Attach(Observer* observer) { m_observers.push_back(observer); }     //��ӹ۲���  
	void Remove(Observer* observer) { m_observers.remove(observer); }        //�Ƴ��۲���  
	void Notify() //֪ͨ�۲���  
	{
		list<Observer*>::iterator iter = m_observers.begin();
		for (; iter != m_observers.end(); iter++)
			(*iter)->Update();
	}
	virtual void SetStatus(string s) { m_status = s; } //����״̬  
	virtual string GetStatus() { return m_status; }    //���״̬  
private:
	list<Observer* > m_observers; //�۲�������  
protected:
	string m_status; //״̬  
}; 
class BlogCSDN : public Blog
{
private:
	string m_name; //��������  
public:
	BlogCSDN(string name) : m_name(name) {}
	~BlogCSDN() {}
	void SetStatus(string s) { m_status = "CSDN֪ͨ : " + m_name + s; } //��������״̬��Ϣ  
	string GetStatus() { return m_status; }
}; 
class ObserverBlog : public Observer
{
private:
	string m_name;  //�۲�������  
	Blog* m_blog;   //�۲�Ĳ��ͣ���Ȼ��������ʽ���ã��Ϳ��Թ۲�������  
public:
	ObserverBlog(string name, Blog* blog) : m_name(name), m_blog(blog) {}
	~ObserverBlog() {}
	void Update()  //��ø���״̬  
	{
		string status = m_blog->GetStatus();
		cout << m_name << "-------" << status << endl;
	}
};

int main()
{
#if 0 //��ֻ֤��һ������  �����̲߳���ȫ��ʹ��atomic����lock_gard��  �����̰߳�ȫ
	SINGLETON_LAZY* p = SINGLETON_LAZY::getInstance();
	SINGLETON_LAZY* p1 = SINGLETON_LAZY::getInstance();
	if (p == p1)
		cout << "lazy" << endl;
	SINGLETON_HUNGRY* a = SINGLETON_HUNGRY::getInstance();
	SINGLETON_HUNGRY* a1 = SINGLETON_HUNGRY::getInstance();
	if (a == a1)
		cout << "hungry" << endl;
	delete p;
	delete a;
#endif // ����
#if 0 //ʹ�ù���������������֪������Ĵ������� �����Ͽ���ԭ�� 
	fruit_factory* f1 = new fruit_factory;
	fruit* ap = f1->make_fruit("apple");
	fruit* pe = f1->make_fruit("pear");
	ap->fruit_name();
	pe->fruit_name();
	delete f1;
	delete ap;
	delete pe;
#endif // �򵥹���
#if 0  //ÿ������һ�����������Ͽ���ԭ�� ���ᵼ����Խ��Խ��
	abstruct_factory* f = new apple_factory;
	fruit* ap=f->produce();
	ap->fruit_name();
	delete f;
	delete ap;
#endif // ��������
#if 0  //ÿ���������ж�Ӧ���ƵĲ�Ʒ�����󴴽���Ӧ�Ĳ�Ʒ�������󴴽���Ӧ�Ĺ�����ÿ�������������еĲ�Ʒ
	//����A
	abstructFactory* a = new A_factory;
	abstructMulticore* a_one = a->createMulticore();
	a_one->print2();
	abstructSingleCore* a_double = a->createSingleCore();
	a_double->print1();
	delete a;
	delete a_one;
	delete a_double;
	//����B
	abstructFactory* b = new B_factory;
	abstructMulticore* b_one = b->createMulticore();
	b_one->print2();
	abstructSingleCore* b_double = b->createSingleCore();
	b_double->print1();
	delete b;
	delete b_one;
	delete b_double;
#endif //���󹤳�
#if 0 //��ֱ�ӷ�������Ҫ�Ķ���ͨ�����һ��������ʵ�ֶԶ���ķ���
	abstructWeb* Internet = new VPN;
	Internet->show();
	delete Internet;
#endif //����ģʽ
#if 0 //����������Ĵ�������  ���ö����������������ϵͳ�ж���ĸ������Ӷ�����ϸ���ȶ����ϵͳ�������ڴ�ѹ��      ����������Ǻܺã�����ʹ��Χ��İ�����ֻ��Ҫ������Ӧ���������ӣ��������д��λ����Ϣ������  ����
	ComputerFront* cf = new ComputerFront;
	auto puseFront1 = cf->pFront("s1");
	auto puseFront2 = cf->pFront("s2");
	auto puseFront3 = cf->pFront("s1");
	if (puseFront1 == puseFront3)
		cout << "same ptr" << endl;
	else
		cout << "different ptr" << endl;
	delete cf;
#endif //��Ԫģʽ
#if 0 //һ�����д��й۲���ָ�룬�����е���Ϣ�ı䣬֪ͨ�۲���
	Blog* blog = new BlogCSDN("zz");
	Observer* observer1 = new ObserverBlog("tutupig", blog);
	blog->Attach(observer1);
	blog->SetStatus("�۲���ģʽ");
	blog->Notify();
	delete blog; delete observer1;
#endif //�۲���ģʽ

	
	return 0;
}