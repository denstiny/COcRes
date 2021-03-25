public class Main {

	public static void main(String [] args) { // java 注释
		byte b1 = 100;
		//short b2 = b1;
		//int  b3 = b2;
		long b4 = 10000000000l;
		b1 =(byte) b4;
		String str1 = "1+";
		String str2 = "2+";
		String str3 = "3+";
		System.out.println(str1+str2+str3);
		System.out.println(b4);
		System.out.println(b1);
	}
}
