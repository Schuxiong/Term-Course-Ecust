class  InnerClassInBlock{ 
	// InnerClass i;  ���ܷ��ʶ����ڿ��е��ڲ��ࡣ
	{
		System.out.println("  before InnerClass");
		//InnerClass inner=new InnerClass(); ������δ�����ڲ���ʱ����ʹ����
		class InnerClass{ 
			private int i=1;
			public void prtI(){
				System.out.println(i);
			}
		};

		InnerClass inner=new InnerClass();
		inner.prtI();

		System.out.println("after InnerClass ");
	}	


	public static void main(String[] args){
		new OuterClass();
	}
}
