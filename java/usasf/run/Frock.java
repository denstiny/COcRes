/*
	Frock 类
*/
public class Frock {
	static long INCREMENT = 100;
	private static long currentNum = 10000;
	public static long getNextNum() {
		return currentNum+=INCREMENT;
	}

	public Frock() {
	}
}
