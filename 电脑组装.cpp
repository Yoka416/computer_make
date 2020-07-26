#include<iostream>//标准库
using namespace std; //标准输出库
#include<string>//字符串库



class cpu
{
public:
	virtual void caculate()=0;
};
class videocard
{
public:
	virtual void display()=0;
};
class memory
{
public:
	virtual void storage()=0;
};

//前三个类相当于父类！比较简单
//下面这个类是该程序的核心，主要作用是：将开辟的指向子类的父类型指针接收后，
//使这些指针指向子类的函数使其可以运行
//注意：接收的时候得用构造函数，调用子类函数的时候一定要用成员函数

class computer
{
public:

	//构造函数的函数名一定要和类名相同！
	 computer(cpu *cpu, videocard *vc, memory *mem)//注意，这里是构造函数，不需要加void
	{
		m_cpu=cpu;
		m_vc=vc;
		m_mem=mem;
	}
	

	void work()  //这个不是构造函数，这个是成员函数，所以需要加void
	{
		//让软件工作起来，调用接口
		m_cpu->caculate();
		m_vc->display();
		m_mem->storage();	

		/*delete m_cpu;
		delete m_vc;
		delete m_vc;注意不能在这里释放堆区，一定要到析构函数里释放！！！！*/
	}
	~computer()//这里是析构函数
	{
		if(m_cpu!=NULL)
		{
			delete m_cpu;
			m_cpu=NULL;
		}
		if(m_vc!=NULL)
		{
			delete m_vc;
			m_vc=NULL;
		}
		if(m_vc!=NULL)
		{
			delete m_vc;
			m_vc=NULL;
		}
	}

private:  //多数定义类变量都是要加private的	
	cpu *m_cpu;
	videocard *m_vc;
	memory *m_mem;

		
	
};

//具体零件厂商
//英特尔厂商
class InterCPU : public cpu
{
public:
	virtual void caculate()//子类这里也可以加virtual,每一个类只要记得加上public就行
	{
		cout<<"Inter的cpu开始计算了！"<<endl;
	}
};
class InterVideoCard : public videocard
{
public:
	virtual void  display()
	{
		cout<<"Inter的显卡开始显示了！"<<endl;
	}
};

class InterMemory : public memory
{
public:
	virtual void storage()
	{
		cout<<"Inter的内存开始存储了！"<<endl;
	}
};


//Lenovo厂商
class LenovoCPU : public cpu
{
public:
	virtual void caculate()
	{
		cout<<"Lenovo的cpu开始计算了!"<<endl;
	}
};
class LenovoVideoCard : public videocard
{
public:
	virtual void  display()
	{
		cout<<"Lenovo的显卡开始显示了!"<<endl;
	}
};

class LenovoMemory : public memory
{
public:
	virtual void storage()
	{
		cout<<"Lenovo的内存开始存储了!"<<endl;
	}
};

void test01()
{
	//开辟的指向子类的父类型指针
	cpu *inter_cpu = new InterCPU;
	videocard *inter_vc= new InterVideoCard;
	memory *inter_mem= new InterMemory;

	//核心：
	//这个开辟厉害了，可以直接在后面用括号传送构造函数需要的指针
	computer *inter = new computer(inter_cpu,inter_vc,inter_mem);
	//再强调一遍：构造函数的名字一定要和类的名字相同才能传指针

	inter->work();//开始运行
	delete inter;

	cout<<"-----------------------------"<<endl;
	cpu *lenovo_cpu = new LenovoCPU;
	videocard *lenovo_vc= new LenovoVideoCard;
	memory *lenovo_mem= new LenovoMemory;

	computer *Lenovo = new computer(lenovo_cpu,lenovo_vc,lenovo_mem);

	Lenovo->work();
	delete Lenovo;
}


int main()
{
	test01();

	system("pause");
	return 0;
}

