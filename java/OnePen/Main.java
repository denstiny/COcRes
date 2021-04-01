import java.util.Scanner;
public class Main{
    public static void main(String[] args) {

        Scanner scanf = new Scanner(System.in);

        student s  = new student("liming",10);
        student sd = s;
        String nae = scanf.nextLine();
        studet ns = new student(nae,10);
        System.out.println(sd.id  + " " + sd.name);
        System.out.println(ns.id  + " " + ns.name);

        
    }
}