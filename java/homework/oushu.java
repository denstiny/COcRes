package homework;

import javax.security.auth.x500.X500Principal;


/*

    使用for 循环计算100 - 200 之间的偶数
    思路：
    使用循环遍历100 - 200 之间的数，使用取余检查是否被2整除
 */
public class oushu {

    public static void Print(int L_num,int N_num){
		int s = 0;
        for(int i = L_num; i < N_num; i++) {
            if(i%2 == 0) {
                System.out.print("偶数: "+i + "  ");
				s++;
				if(s == 5){
					System.out.println();
					s=0;
				}

            }

				
        }
    }
    public static void main(String[] args) {
    Print(100,200);

    }
    
}
