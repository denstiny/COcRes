package homework;

/*
使用for循环 判断其中13的倍数
思路： 使用for循环进行遍历，并进行取余判断是否被13整除
*/


public class for13 {
    public static void main(String[] args) {
        for(int i = 1; i < 100; i++) {
            if(i%13==0)
                System.out.println("13的倍数: "+i);
        }
    }
    
}
