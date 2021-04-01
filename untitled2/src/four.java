public class four {
    // 创建 intArray 方法
    public static  void intArray(int [] array) {
        // 存放数据
        for(int i = 2,n = 0;n < 20;n++) {
            while(i % 2 != 0 && ++i != 0);
            array[n] = i++;
        }
    }

    public static void main(String[] args) {
        int [] array = new int[20];
        intArray(array);
        // 打印数组数据
        for(int n : array)
            System.out.print(n + "  ");
    }
}
