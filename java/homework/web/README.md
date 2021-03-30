# java 作业

作业

## one
```java
package web;

import javax.crypto.interfaces.PBEKey;

public class one {
	public static void main(String[] args) {
	    for(int i  = 0 ; i <= Integer.parseInt(args[0]) && i <= 100;i++) {
		System.out.println(i);
	    }
	}

}

```
> 运行结果
![20210328202013](https://i.loli.net/2021/03/28/t3Wf6x4jX5vYcBR.png)


## tow

``` java 

package web;

import javax.crypto.interfaces.PBEKey;

public class tow {
	public static void main(String[] args) {
		int len = 0;
		boolean v = true;
		for (int a = 2; a < 200; a++) {
			for (int i = 2; i < a; i++) {
				if (a % i == 0) {
					v = false;
				}
			}
			if (v){
				System.out.print(a);
				System.out.print(" ");
				len++;
			}
			if(len == 5)
			    {
					System.out.println();
					len = 0;
			    }
				v = true;
		}
	}
}

``` 

> 运行结果
![20210328203820](https://i.loli.net/2021/03/28/WLx7VipjfruHECq.png)

## three
```java

package web;

import javax.crypto.interfaces.PBEKey;

public class three {
	public static void main(String[] args) {
		int len = 0;
	    for(int i  = 0 ; i < 100 ; ++i){
		if(i % 13 == 0){
			continue;
		}
		len++;
		System.out.print(i + " ");
		if(len == 5) {
			len = 0;
			System.out.println();
		}
	    }
	}
}

```
> 运行结果
![20210328204322](https://i.loli.net/2021/03/28/FfrkDIwOHvm4ePp.png)
