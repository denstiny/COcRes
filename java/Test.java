public class Test {
    public static void main(String[] args) {
        long startTime1 = System.nanoTime();
        for (int i = 0; i < 1000000; i++) {

        }
        System.out.println("i++ time(ms):" + Long.toString((System.nanoTime() - startTime1) / 1000));
        System.out.println("i++ time(s):" + Long.toString((System.nanoTime() - startTime1) / 1000 / 1000));

        long startTime2 = System.nanoTime();
        for (int i = 0; i < 1000000; ++i) {

        }
        System.out.println("++i time(ms):" + Long.toString((System.nanoTime() - startTime2) / 1000));
        System.out.println("++i time(s):" + Long.toString((System.nanoTime() - startTime2) / 1000 / 1000));
    }
}

