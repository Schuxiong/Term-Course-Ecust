#include <stdio.h>
class Parent{
	public : 
	   virtual  void toString(){  printf("Parent toString() \n" );		}  //��̬��
	   void prn(){ 			printf("Parent  prn()\n" );		}//��̬��
		 
}; 
class Child:public Parent{
	public :
		void toString(){ 	 printf("Child   toString() \n" );	}
		void prn(){ 		 printf("Child  prn()\n" );		}
  };
int main(int argc, char *argv[]){
	Parent p1,*p2;
	Child c1; 
	p1.toString();
	c1.toString();
	//p2->toString();   //���г���
    printf("--------------------------\n" );	

	p1.prn();
	c1.prn();
	p2->prn();

	printf("--------------------------\n" );
	p2=&c1;
    p2->toString();
	p2->prn();

    printf("--------------------------\n" );
	p1= c1;
    p1.toString(); //����������̬��
    p1.prn();
	return 0;
}
