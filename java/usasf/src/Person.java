public class Person {
    Person people   = new Person("liwei",12);
    Teacher people1 = new Teacher("liqiang",13);
    Teacher people2 = new Teacher("weiqiao",15);
    Student people3 = new Student("wanfei",18);
    Student people4 = new Student("wrold",11);
    Person[] people5 = new Person[]{people1,people2,people3,people4,people};
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
