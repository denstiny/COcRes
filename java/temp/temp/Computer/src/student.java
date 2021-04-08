public class student extends  person{
    private  int id;
    private  double score;
    public student(String name,int id)  {
        this(name,20,id,100.0);
    } public student(String name,int age ,int id ,double score) {
        super(name,age);
        this.id = id;
        this.score = score;
    }
    public String say() {
        return super.say()+"学号" + id + "分数" + score;
    }

}
