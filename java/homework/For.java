package homework;

import javax.crypto.interfaces.PBEKey;

/*
 使用for 循环输出 20 × 8 的矩形
 思路 使用双循环，外循环控制转行，内循环输出单行的内容
 */


public class For {

    public static  void Print(int x,int y) {
        for(int i = 0; i < x; i++){
            for(int n = 0;n < y;n++) {
                System.out.print("*");
            }
            System.out.println();
        }

    }
    public static void main(String[] args) {
        Print(20,8) ;
    }
    
}
