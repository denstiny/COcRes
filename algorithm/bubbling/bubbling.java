public class bubbling {
    public static void main(String[] args) {
        int[] arg = { 1, 3, 4, 2, 7, 6, 8, 9, 5 };
        int b = 0;
        for (int x = 0; x < arg.length; x++) {
            for (int i = 0; i < arg.length -x-1; i++) {
                if (i + 1 < arg.length && arg[i] < arg[i + 1]) {
                    arg[i] = arg[i] ^ arg[i+1];
                    arg[i+1] = arg[i] ^ arg[i+1];
                    arg[i] = arg[i] ^ arg[i+1];
                }
                b++;
            }
        }

        for (int i = 0; i < arg.length; i++) {
            System.out.println(arg[i]);
        }
            System.out.println(b);
    }
}