## 第一题
```java

public class computer {
    public computer() {
        System.out.println("create computer");
        fstab = "";
        cpu  = "";
        neicun  = "";
    }
    private String fstab;
    private String cpu;
    private String neicun;
    void SetFstab(String fstab) {
        this.fstab = fstab;
    }
    void SetCpu(String cpu) {
        this.cpu = cpu;
    }
    void SetNeicun(String neicun) {
        this.neicun = neicun;
    }

    String Getdetails() {
        return fstab+cpu+neicun;
    }
    String GetCpu() {return this.cpu;};
    String GetNeicun() {return this.neicun;};
    String GetFstab() {return this.fstab;};
}
```
```java

public class Notepad  extends computer{
    String Note;
    public Notepad(String Note,String fstab,String cpu,String neicun) {
        super();
        System.out.println("create Notepad ");
        super.SetFstab(fstab);
        super.SetCpu(fstab);
        super.SetNeicun(neicun);
        this.Note = Note;
    }
    @Override
    String Getdetails() {
        return super.GetCpu()+super.GetFstab()+super.GetNeicun()+this.Note;
    }
}
```
```java

public class pc extends computer {
    public pc(String name,String fstab,String cpu,String neicun)  {
        super();
        super.SetFstab(fstab);
        super.SetCpu(fstab);
        super.SetNeicun(neicun);
        this.name = name;
        System.out.println("create pc ");
    }

    public String name;

    @Override
    String Getdetails() {
        return name+super.GetCpu()+super.GetFstab()+super.GetNeicun();
    }
}
```
```java

public class App {
    public static void main(String[] args) throws Exception {
        computer PC = new pc("戴尔","固态","8核","100G");
        System.out.println(PC.Getdetails());
        computer NOTEPAD = new Notepad("苹果","机械","4核","50G");
        System.out.println(NOTEPAD.Getdetails());
    }
}
```

## 第二题
```java

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
```
```java

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
```