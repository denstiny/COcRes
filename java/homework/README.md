# java 作业


## 第一题
> 编写程序打印一个 10 × 5 的矩形
## 第二题
> 编写程序，使用双重循环打印20 × 8 的矩形。
```java
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
        Myprint(20,8);
        // 第二
        Myprint(10,5);
    }
    
}
```
<details>
<summary>点击查看运行结果</summary>

![20210325185047](https://i.loli.net/2021/03/25/zn2qIkhVNUZ6OW7.png)

</details>

## 第三题
> 使用do-while打印 1 - 100 之间 13的倍数
```java

package homework;

import java.util.concurrent.CountDownLatch;
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

```
<details>
<summary>点击查看运行结果</summary>

![20210325184910](https://i.loli.net/2021/03/25/iP7EcZHCjMdA5Rm.png)

</details>

## 第四题
> 使用for 循环打印 1 - 100 之间的倍数

```java
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

```
<details>
<summary>点击查看运行结果</summary>

![20210325184833](https://i.loli.net/2021/03/25/xXrqIkV7aOFH2zj.png)

</details>

## 第五题
> 编写程序使用双重循环打印 20 × 8 的矩形，使用for 循环实现
```java

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

```

<details>
<summary>点击查看运行结果</summary>

![20210325184744](https://i.loli.net/2021/03/25/aM5kOSc1BD2WR8T.png)

</details>

## 第六题
> 编写程序，打印100 - 200 之间的偶数
```java
package homework;

import javax.security.auth.x500.X500Principal;


/*

    使用for 循环计算100 - 200 之间的偶数
    思路：
    使用循环遍历100 - 200 之间的数，使用取余检查是否被2整除
 */
public class oushu {

    public static void Print(int L_num,int N_num){
        for(int i = L_num; i < N_num; i++) {
            if(i%2 == 0) {
                System.out.println("偶数: "+i);
            }
        }
    }
    public static void main(String[] args) {
    Print(100,200);

    }
    
}

```

<details>
<summary>点击查看运行结果</summary>

![20210325184614](https://i.loli.net/2021/03/25/sbM8BIxVST9udzA.png)

</details>
