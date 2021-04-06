/*
    使用do - while 判断 1 - 100 中 13的倍数
    思路，使用do  - while 进行遍历，并使用取余判断是否被13整除
*/

public class home {
    public static void main(String[] args) {
        int i = 1;
        do{
            if(i%13 == 0){
                System.out.println("13的倍数是： "+i);
            }
        }while(++i <= 100);

    }
    
}
