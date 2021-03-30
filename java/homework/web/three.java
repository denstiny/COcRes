package web;

import javax.crypto.interfaces.PBEKey;

public class three {
	public static void main(String[] args) {
		int len = 0;
	    for(int i  = 0 ; i < 100 ; ++i){
		if(i % 13 == 0){
			continue;
		}
		len++;
		System.out.print(i + " ");
		if(len == 5) {
			len = 0;
			System.out.println();
		}
	    }
	}
}
