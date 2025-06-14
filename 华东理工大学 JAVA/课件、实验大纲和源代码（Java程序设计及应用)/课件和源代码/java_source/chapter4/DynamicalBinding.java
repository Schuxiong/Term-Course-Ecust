class A {
      String str="A";
      static void method1() {  System.out.println("A.method1()");       }
     void method2() {           System.out.println("A.method2()");     }
} 

 class B extends A{
	    String str="B";
        // will not override A.method1()
        static void method1() {  System.out.println("B.method1()");         }
        // will override the A. method2()
        void method2() {    System.out.println("B.method2()");       }
  }

  public class DynamicalBinding { 
        public static void main(String[] args) {
           A a = new B();       // a=(A) a;
           a.method1(); //因为A里面的method1是static,编译时就静态绑定了,所以输出 A.method1()
           a.method2(); //而method2()不是static方法,a是由B new出来的,执行的时候会执行new它的那个类的method2()方法,所以输出B.method2(),这是java的多态性
           System.out.println(a.str);
       }
}