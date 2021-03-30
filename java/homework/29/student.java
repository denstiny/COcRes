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
    public  String say() {
	return name + gender + age + id + score;
    }
}
