package homework;

/*
使用for循环 判断其中13的倍数
思路： 使用for循环进行遍历，并进行取余判断是否被13整除评价

*/


public class for13 {
    public static void main(String[] args) {
        long stat = System.currentTimeMillis();
        System.out.println("取模方法： ==> "+ stat);
        // 取模方法
        int a = 0;
        for(int x =  0; x < 10000;x++)
        {
            for(int i = 1; i < 100; i++) {
                if(i%13==0)
                    //System.out.print("倍数==> "+i);
                    a++;
            }
        }
        System.out.println("使用时间" + (System.currentTimeMillis()-stat));
        // 乘法求值
        long stats = System.currentTimeMillis();
        System.out.println("乘法求值==> "+ stats);
        int sa = 0;
        boolean siz = false;
        for(int as = 0 ; as < 10000;as++) {
            for(int x = 0;x < 100;siz=(++x)*13 < 100 ? true:false) {
                if(siz) {
                  //  System.out.println(x*13);
                  sa ++;
                }
            }
        }
        System.out.println("使用时间" + (System.currentTimeMillis()-stats));

    }
    
}
