 
 #include <iostream>
 using namespace std; 
 
 class A{ 
    public: 
       virtual void show(){cout<<"�����show()"<<endl;} 
       void get(){cout<<"�����get()"<<endl;} 
};

class B:public A{ 
       public: 
      virtual void show(){cout<<"�������show()"<<endl; }
	  void get(){cout<<"�������get()"<<endl;}

}; 

int main(int argc, char *argv[])
{
   A a; 
   B b; 
   A *c=&b; 
   c->show();//show�������麯�������Ҵ�ʱʹ��������Ķ���ȥ��ʼ����������ã������˶�̬�󶨣����õ���ʵ���ࡡ����������������B��show()----"�������show"
   c->get();//��ʱ�����㶯̬�󶨵�������c�Ǿ�̬���ͣ������-------�����get()
	
	return 0;
}
