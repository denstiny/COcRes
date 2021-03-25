package homework;

import javax.crypto.interfaces.PBEKey;

/*题目1：输出20 × 8 的矩形
  题目2 ： 输出 10 × 5 的矩形 
  思路，创建一个函数，给定参数行和列，放入指定大小进行打印
  */


public class asdf {

    public static void Myprint(int x,int y ) {
        int This_x = 0;
        int This_y = 0;
        do{
           while(++This_y <= y) 
                System.out.print('*');
            System.out.print("\n");
        }while(++This_x < x && 0 == (This_y = 0));
    }
    public static void main(String[] args) {
        /*
        打印 矩形
        */ 
        // 第一
		System.out.println("第一题");
        Myprint(20,8);

        // 第二
		System.out.println("第二题");
        Myprint(10,5);
    }
    
}
