package homework;
public class List {
    public static void main(String[] args) {
        int [] arg = new int[10];
        arg[1] = '1';
        arg[2] = '2';
        arg[3] = '3';
        for(int i = 0;i <= 3 ; i++)
            System.out.print(arg[i]);

        System.out.println("arg"+arg.length);
        
        
        String[] strin = new String[]{"hello","world"};
        System.out.println(strin[0]+strin[1]);

    }
    
}
