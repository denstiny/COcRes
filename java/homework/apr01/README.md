
<!-- vim-markdown-toc GFM -->

* [java apr 01 作业](#java-apr-01-作业)
	* [第一题](#第一题)
	* [第二题](#第二题)
	* [第三题](#第三题)
	* [第四题](#第四题)

<!-- vim-markdown-toc -->
## java apr 01 作业

### 第一题
```java

public class helo {
    // 第一题
    public static void main(String [] args) {
        char a[] = new char[26];
        for(int i = 0,s = 65;i < 26;i++ ,s++) {
           a[i]  = (char)s;
           System.out.println(a[i] + "  ");
        }
    }
}

```
> 运行截图
![20210401203303](https://i.loli.net/2021/04/01/QugqvDFBtmEir1P.png)

### 第二题
```java

public class tow {
    public static void main(String[] args) {
        char[] str = new char[36];
        int i = 0;
        for(int st = 'A';i <= 'Z'-'A';i++,st++) {
            str[i] = (char)st;
            System.out.print(str[i] + " ");
        }
        for(int ss = 0,st = '0';ss < 10;i++,ss++,st++) {
            str[i] = (char)st;
            System.out.print(str[i] + " ");
        }

    }
}
```
> 运行截图
![20210401203435](https://i.loli.net/2021/04/01/JqeiyTfr1BSKLtR.png)

### 第三题
```java

public class three {
    public static void main(String[] args) {
        char [] as = new char[]{'a','c','e','h','c','j','q','w','x','z'};
        for(char i : as) {
            System.out.println(i);
        }
    }
}
```
> 运行截图
![20210401204309](https://i.loli.net/2021/04/01/72C3BUn5pswYRvF.png)

### 第四题
```java

public class four {
    // 创建 intArray 方法
    public static  void intArray(int [] array) {
        // 存放数据
        for(int i = 2,n = 0;n < 20;n++) {
            while(i % 2 != 0 && ++i != 0);
            array[n] = i++;
        }
    }

    public static void main(String[] args) {
        int [] array = new int[20];
        intArray(array);
        // 打印数组数据
        for(int n : array)
            System.out.print(n + "  ");
    }
}
```
> 运行截图

![20210401204201](https://i.loli.net/2021/04/01/vhLFS41kjRCM9Qq.png)
