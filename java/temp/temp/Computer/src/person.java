public class person {
    private String name;
    private int age;
    public person(String name,int age) {
        this.name  = name;
        this.age = age;
    }
    public String say() {
        return "姓名: " + name + "年龄: " + age;
    }

}
