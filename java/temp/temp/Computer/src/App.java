public class App {
    public static void main(String[] args) throws Exception {        
        computer PC = new pc("戴尔","固态","8核","100G");
        System.out.println(PC.Getdetails());
        computer NOTEPAD = new Notepad("苹果","机械","4核","50G");
        System.out.println(NOTEPAD.Getdetails());
    }
}
