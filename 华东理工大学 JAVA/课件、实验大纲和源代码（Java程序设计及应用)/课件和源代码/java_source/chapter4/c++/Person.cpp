 
#include <string>
#include <iostream>
using namespace std;
class Person
{ 
	//��������Ϊ���Բ���
    public:
		string name;//����
	    string Id; //���֤ 

	private:
		int   age;  //���� ��˽������
    
	//���²���Ϊ��������
	public:
		Person(){	}
	    Person(string name,string Id, int age){	
	       this->name=name; this->Id=Id;  this->age=age;
	    } 
	    void setName(string name){ this->name=name;}
	    string getName(){return name;}

	    void setId(string Id){ this->Id=Id;}
	    string getId(){return Id;} 
	   
		void setAge(int age){ this->age=age;}
	    int getAge(){return age;} 

	    string toString(){return "Person��";}

};

int main(int argc, char *argv[])
{
	Person p;
	cout<<p.toString();
	 
	return 0;
}
