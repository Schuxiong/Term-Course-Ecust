public class  Calculator
{
	public static void main(String[] args) 
	{   byte a=106;
	    byte b=(byte)~a;
		System.out.println("b: "+b);

		byte c=10;
		byte d=(byte)(c<<1);
		System.out.println("d: "+d);

		byte e=-50;   
		/* -50 ������: 11001110 */
		byte f=(byte)(e<<3);
		/* f ������:   00111000 */
		System.out.println("f: "+f);

        
		byte g=7;   
		/* -50 ������: 00000111 */
		byte h=(byte)(g<<6);
	/* h �����Ʋ���(������ڲ���ʾ��: 1011 1111 */
	/* h ������ԭ��:   1100 0000: -64 */
		System.out.println("h: "+h);

	}
}
