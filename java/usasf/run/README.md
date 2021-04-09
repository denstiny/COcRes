# java 作业

> 创建 Frock 类



```java
/*
	Frock 类
*/
public class Frock {
	static long INCREMENT = 100;
	private static long currentNum = 10000;
	public static long getNextNum() {
		return currentNum+=INCREMENT;
	}

	public Frock() {
	}
}
```
> TestFrock 类
```java
/*
	TestFrock 类
*/
public class TestFrock {
	public static void main(String[] args) {
		Frock p = new Frock();
		System.out.println(p.getNextNum());
		System.out.println(p.getNextNum());
	}
}

```
![20210409195205](https://i.loli.net/2021/04/09/xDYrupBqCmRdn5y.png)
