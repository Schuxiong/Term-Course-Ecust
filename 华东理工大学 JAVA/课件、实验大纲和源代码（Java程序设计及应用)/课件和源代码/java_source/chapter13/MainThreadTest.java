class MainThreadTest
{
	public static void main(String[] args) 
	{
		Thread t=Thread.currentThread();	//ͨ��currentThread()����������߳�
		System.out.println("current Thread: "+t.getName());
		t.setName("zhang");    //�ı��̵߳�����       
        System.out.println("after name changed: "+t.getName());
		try{
			for(int i=0;i<=5;i++){
              System.out.println(i);     
			  Thread.sleep(1000);//һ����
			}
		  }catch(InterruptedException e){
             System.out.println("main thread interrupted");     
		   }
	}
}
