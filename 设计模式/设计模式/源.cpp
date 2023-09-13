#include <iostream>
#include <list>
#include <map>
using namespace std;
//单例懒汉式
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
//单例饿汉式
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

//简单工厂
class fruit//抽象类  由于创建详细水果
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
class fruit_factory//水果工厂，直接生成对应类型的水果
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

//工厂方法
class abstruct_factory//抽象的  对应生产单一类型的种类
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

//抽象工厂
class abstructSingleCore //抽象单核 
{
public:
	virtual void print1() = 0;
};
class A_SingleCore :public abstructSingleCore//a厂的单核
{
public:
	virtual void print1() override { cout << "SingleCore from A factory" << endl; }
};
class B_SingleCore :public  abstructSingleCore//b厂的单核
{
public:
	virtual void print1() override  { cout << "SingleCore from B factory" << endl; }
};
class abstructMulticore//抽象多核
{
public:
	virtual void print2() = 0;
};
class A_Multicore :public abstructMulticore//a厂的多核
{
public:
	virtual void print2() override { cout << "Multicore from A factory" << endl; }
};
class B_Multicore :public  abstructMulticore//b厂的多核
{
public:
	virtual void print2() override { cout << "Multicore from B factory" << endl; }
};
class abstructFactory//抽象工厂
{
public:
	virtual abstructMulticore* createMulticore() = 0;//都有多核
	virtual abstructSingleCore* createSingleCore() = 0;//都有单核
};
class A_factory :public abstructFactory//工厂a
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
class B_factory :public abstructFactory//工厂b
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

//代理模式
class abstructWeb//抽象出要使用的功能
{
public:
	virtual void show() = 0;
};
class YouTube :public abstructWeb//无法直接访问的网站
{
public:
	virtual void show()override
	{
		cout << "web opening..." << endl;
	}
};
class VPN :public abstructWeb//通过代理来对 无法访问的网站进行访问
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

//享元模式  
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
			delete everyPair.second;//对应的字体指针不需要手动释放
		}
	}
};

//观察者模式
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
	void Attach(Observer* observer) { m_observers.push_back(observer); }     //添加观察者  
	void Remove(Observer* observer) { m_observers.remove(observer); }        //移除观察者  
	void Notify() //通知观察者  
	{
		list<Observer*>::iterator iter = m_observers.begin();
		for (; iter != m_observers.end(); iter++)
			(*iter)->Update();
	}
	virtual void SetStatus(string s) { m_status = s; } //设置状态  
	virtual string GetStatus() { return m_status; }    //获得状态  
private:
	list<Observer* > m_observers; //观察者链表  
protected:
	string m_status; //状态  
}; 
class BlogCSDN : public Blog
{
private:
	string m_name; //博主名称  
public:
	BlogCSDN(string name) : m_name(name) {}
	~BlogCSDN() {}
	void SetStatus(string s) { m_status = "CSDN通知 : " + m_name + s; } //具体设置状态信息  
	string GetStatus() { return m_status; }
}; 
class ObserverBlog : public Observer
{
private:
	string m_name;  //观察者名称  
	Blog* m_blog;   //观察的博客，当然以链表形式更好，就可以观察多个博客  
public:
	ObserverBlog(string name, Blog* blog) : m_name(name), m_blog(blog) {}
	~ObserverBlog() {}
	void Update()  //获得更新状态  
	{
		string status = m_blog->GetStatus();
		cout << m_name << "-------" << status << endl;
	}
};

int main()
{
#if 0 //保证只有一个对象  懒汉线程不安全（使用atomic或者lock_gard）  饿汉线程安全
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
#endif // 单例
#if 0 //使用工厂创建对象，无需知道对象的创建过程 不符合开闭原则 
	fruit_factory* f1 = new fruit_factory;
	fruit* ap = f1->make_fruit("apple");
	fruit* pe = f1->make_fruit("pear");
	ap->fruit_name();
	pe->fruit_name();
	delete f1;
	delete ap;
	delete pe;
#endif // 简单工厂
#if 0  //每个对象，一个工厂，符合开闭原则 但会导致类越来越多
	abstruct_factory* f = new apple_factory;
	fruit* ap=f->produce();
	ap->fruit_name();
	delete f;
	delete ap;
#endif // 工厂方法
#if 0  //每个工厂都有对应类似的产品，抽象创建对应的产品，并抽象创建对应的工厂，每个工厂都有特有的产品
	//工厂A
	abstructFactory* a = new A_factory;
	abstructMulticore* a_one = a->createMulticore();
	a_one->print2();
	abstructSingleCore* a_double = a->createSingleCore();
	a_double->print1();
	delete a;
	delete a_one;
	delete a_double;
	//工厂B
	abstructFactory* b = new B_factory;
	abstructMulticore* b_one = b->createMulticore();
	b_one->print2();
	abstructSingleCore* b_double = b->createSingleCore();
	b_double->print1();
	delete b;
	delete b_one;
	delete b_double;
#endif //抽象工厂
#if 0 //不直接访问所需要的对象，通过添加一个代理来实现对对象的访问
	abstructWeb* Internet = new VPN;
	Internet->show();
	delete Internet;
#endif //代理模式
#if 0 //解决面向对象的代价问题  采用对象共享的做法来降低系统中对象的个数，从而降低细粒度对象给系统带来的内存压力      这个案例不是很好，可以使用围棋的案例，只需要创建对应的两种棋子，在棋子中存放位置信息（不对  好像）
	ComputerFront* cf = new ComputerFront;
	auto puseFront1 = cf->pFront("s1");
	auto puseFront2 = cf->pFront("s2");
	auto puseFront3 = cf->pFront("s1");
	if (puseFront1 == puseFront3)
		cout << "same ptr" << endl;
	else
		cout << "different ptr" << endl;
	delete cf;
#endif //享元模式
#if 0 //一个类中存有观察者指针，对象中的信息改变，通知观察者
	Blog* blog = new BlogCSDN("zz");
	Observer* observer1 = new ObserverBlog("tutupig", blog);
	blog->Attach(observer1);
	blog->SetStatus("观察者模式");
	blog->Notify();
	delete blog; delete observer1;
#endif //观察者模式

	
	return 0;
}