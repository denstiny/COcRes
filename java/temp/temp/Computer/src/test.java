public class test {
    public static void main(String [] args)  {
        person perso = new person("张三",30);
        System.out.println(perso.say());

        student sutden = new student("李四",120);
        System.out.println(sutden.say());
    }
}
