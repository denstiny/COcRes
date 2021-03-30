package web;

import javax.crypto.interfaces.PBEKey;

public class tow {
	public static void main(String[] args) {
		int len = 0;
		boolean v = true;
		for (int a = 2; a < 200; a++) {
			for (int i = 2; i < a; i++) {
				if (a % i == 0) {
					v = false;
				}
			}
			if (v){
				System.out.print(a);
				System.out.print(" ");
				len++;
			}
			if(len == 5)
			    {
					System.out.println();
					len = 0;
			    }
				v = true;
		}
	}
}
