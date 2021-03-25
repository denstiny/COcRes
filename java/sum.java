public class sum {
    public static void main(String [] args) {
        //int result = 9/9;
		//int b = 10;
		//int c = 20;

		int a = 100;
        System.out.println((a=11));
		a=100;

		//if(1 > 0 && 1==(a=10));

		//boolean s  = (boolean)12;  // int 不能直接或隐示转换成bool
		//System.out.println(a);
		//System.out.println((a=b));
	

		while( (a < 10 ) && a != ( a+=10 ) || ( ( a > 10 ) && a != ( a-=10 ) ) ); // (a=b) 语句返回a本身的值 

        System.out.println( "a ==> "+a );
		
		a = 100;
		//if( (a < 10 ) && a!=(a+=10) || ( ( a > 10 ) && a!=(a-=10)) ); // 转化成实际使用代码
		do{
			if( a < 10 )
				a+=10;
			else if( a > 10 )
				a-=10;
		}while( a != 10 );
		System.out.println( "a ==> "+a );


	}
}
