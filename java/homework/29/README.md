# java 作业

```java

public class one{


    // 第一题 1
    public static void method(){
        for(int i = 0 ; i < 10; i++) {
            for(int s = 0 ; s < 8 ; s++){
                System.out.print('*');
            }
            System.out.println();
        }
    }
    // 第一题 2
    public static int method(int p) {
        for(int i = 0; i < 10 ;i++) {
            for(int s = 0 ; s < 8; s++){
                System.out.print('*');
            }
            System.out.println();
        }
        return 10*8;
    }
    public static void main(String [] args) {
        method();
        System.out.println("分割线 ___________________________________________");
        int i = 0;
        // 第二题
        System.out.println(" 面积为 ==> " + method(i));
    }
}

```
> 运行截图

![20210329172312](https://i.loli.net/2021/03/29/9QJvBW6U8FeHTgx.png)
