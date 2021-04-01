public class tow {
    public static void main(String[] args) {
        char[] str = new char[36];
        int i = 0;
        for(int st = 'A';i <= 'Z'-'A';i++,st++) {
            str[i] = (char)st;
            System.out.print(str[i] + " ");
        }
        for(int ss = 0,st = '0';ss < 10;i++,ss++,st++) {
            str[i] = (char)st;
            System.out.print(str[i] + " ");
        }

    }
}
