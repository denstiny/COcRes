public class hac { 
	// 选择排序
	public static  void main(String[] args) {
		int[] age = {12,34,41,53,54,21,5,3,91};
		for(int i = 0;i < age.length; i++) {
			for(int n = i+1;n < age.length ;n++) {
				if(age[i] > age[n]) {
					age[i] = age[i] ^ age[n];
					age[n] = age[i] ^ age[n];
					age[i] = age[i] ^ age[n];
				}
			}
		}
		for(int s : age) {
			System.out.println(s);
		}
	}
}
