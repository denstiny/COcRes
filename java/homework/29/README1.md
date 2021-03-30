# java 程序作业

```
public class student{
    //  第一题，编写一个student类，包含name，gender，id，score属性分别为string int double属性
    student(String name,String gender,int age,int id,double score) {
		this.age = age;
		this.name = name;
		this.id = id;
		this.score = score;
		this.gender = gender;
    }
    private String name; // 名字
    private String gender; // 性别
    private int age; // 年龄
    private int id;  // id
    private double score; // 分数
	//  第二题 定义一个say类返回所有属性
    public  String say() {
		return name + gender + age + id + score;
    }
}

```



```
	// 第三题 在另一个类中的main函数方法中，创建student对象，并将say方法中的所有属性打印输出
public class TestStudent{
    public static void main(String [] args) {
		student s = new student("篱墙", "男", 13, 1, 86.1);
		System.out.println(s.say());
    }
}

```

![image-20210329205504659](/home/aero/.config/Typora/typora-user-images/image-20210329205504659.png)
