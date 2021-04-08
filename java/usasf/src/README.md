# java 作业

> 创建 Person父类
``` java

public class Person {
    public String name;
    public int age;

    String say() {
        return "名字: " + name + "年龄: " + age;
    }
    public  Person() {

    }

    public Person(String name, int age) {
        this.name = name;
        this.age = age;

    }
}
```

> 创建 Teacher 子类
```java
public class Teacher extends Person {
    public Teacher(String name, int age) {
        super(name, age);
    }
}

```
> 创建 Student 子类
```java
public class Student extends Person {
    public Student(String name, int age) {
        super(name, age);
    }
}

```
> test 代码
```java

public class test {
	public static  void main(String[]args) {
		Person people   = new Person("liwei",12);
		Teacher people1 = new Teacher("liqiang",13);
		Teacher people2 = new Teacher("weiqiao",15);
		Student people3 = new Student("wanfei",18);
		Student people4 = new Student("wrold",11);
		Person[] people5 = new Person[]{people1,people2,people3,people4,people};



		System.out.println("排序前");
		for(int i = 0;i < people5.length;i++) {
			System.out.printf("%s \n",people5[i].say());
		}



		for(int i = 0;i < people5.length;i++) {
			people5[i] = (Person)people5[i];
			for(int j = i+1;j < people5.length; j++) {
					if(!(people5[j] instanceof Person) )
							people5[j] = (Person)people5[j];

				if(people5[j].age < people5[i].age)  {
					Person tempPeople = people5[i];
					people5[i] = people5[j];
					people5[j] = tempPeople;
				}

			}
		}


		System.out.println("排序后");
		for(int i = 0;i < people5.length;i++) {
			System.out.printf("%2s \n",people5[i].say());
		}
	}
}

```

> 运行截图

![20210408192730](https://i.loli.net/2021/04/08/GKybMq3ieCVDNpI.png)
