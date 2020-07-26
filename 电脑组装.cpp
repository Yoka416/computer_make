#include<iostream>//��׼��
using namespace std; //��׼�����
#include<string>//�ַ�����



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

//ǰ�������൱�ڸ��࣡�Ƚϼ�
//����������Ǹó���ĺ��ģ���Ҫ�����ǣ������ٵ�ָ������ĸ�����ָ����պ�
//ʹ��Щָ��ָ������ĺ���ʹ���������
//ע�⣺���յ�ʱ����ù��캯�����������ຯ����ʱ��һ��Ҫ�ó�Ա����

class computer
{
public:

	//���캯���ĺ�����һ��Ҫ��������ͬ��
	 computer(cpu *cpu, videocard *vc, memory *mem)//ע�⣬�����ǹ��캯��������Ҫ��void
	{
		m_cpu=cpu;
		m_vc=vc;
		m_mem=mem;
	}
	

	void work()  //������ǹ��캯��������ǳ�Ա������������Ҫ��void
	{
		//������������������ýӿ�
		m_cpu->caculate();
		m_vc->display();
		m_mem->storage();	

		/*delete m_cpu;
		delete m_vc;
		delete m_vc;ע�ⲻ���������ͷŶ�����һ��Ҫ�������������ͷţ�������*/
	}
	~computer()//��������������
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

private:  //�����������������Ҫ��private��	
	cpu *m_cpu;
	videocard *m_vc;
	memory *m_mem;

		
	
};

//�����������
//Ӣ�ض�����
class InterCPU : public cpu
{
public:
	virtual void caculate()//��������Ҳ���Լ�virtual,ÿһ����ֻҪ�ǵü���public����
	{
		cout<<"Inter��cpu��ʼ�����ˣ�"<<endl;
	}
};
class InterVideoCard : public videocard
{
public:
	virtual void  display()
	{
		cout<<"Inter���Կ���ʼ��ʾ�ˣ�"<<endl;
	}
};

class InterMemory : public memory
{
public:
	virtual void storage()
	{
		cout<<"Inter���ڴ濪ʼ�洢�ˣ�"<<endl;
	}
};


//Lenovo����
class LenovoCPU : public cpu
{
public:
	virtual void caculate()
	{
		cout<<"Lenovo��cpu��ʼ������!"<<endl;
	}
};
class LenovoVideoCard : public videocard
{
public:
	virtual void  display()
	{
		cout<<"Lenovo���Կ���ʼ��ʾ��!"<<endl;
	}
};

class LenovoMemory : public memory
{
public:
	virtual void storage()
	{
		cout<<"Lenovo���ڴ濪ʼ�洢��!"<<endl;
	}
};

void test01()
{
	//���ٵ�ָ������ĸ�����ָ��
	cpu *inter_cpu = new InterCPU;
	videocard *inter_vc= new InterVideoCard;
	memory *inter_mem= new InterMemory;

	//���ģ�
	//������������ˣ�����ֱ���ں��������Ŵ��͹��캯����Ҫ��ָ��
	computer *inter = new computer(inter_cpu,inter_vc,inter_mem);
	//��ǿ��һ�飺���캯��������һ��Ҫ�����������ͬ���ܴ�ָ��

	inter->work();//��ʼ����
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

