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
