public class helo {
    // 第一题
    public static void main(String [] args) {
        char a[] = new char[26];
        for(int i = 0,s = 65;i < 26;i++ ,s++) {
           a[i]  = (char)s;
           System.out.print(a[i] + "  ");
        }
    }
}
