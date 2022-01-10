/*
ID: chenant1
LANG: JAVA
TASK: beads
*/


import java.util.*;
import java.io.*;

public class beads {
	public static void main(String[] args) throws IOException {
		try (
				Scanner in = new Scanner(new File("beads.in"));
				PrintWriter out = new PrintWriter(new FileWriter("beads.out"));
		) {
			in.nextInt();
			in.nextLine();
			String necklace = in.nextLine();
			String loopNecklace = necklace + necklace;
			
			int max = 0;
			
			for (int i = 0; i < necklace.length(); i++) {
				String cutOrder = loopNecklace.substring(i, i + necklace.length());
				int sum = findConsecutive(cutOrder) + findConsecutive(reverse(cutOrder));
				if (sum > max) {
					max = sum;
				}
				if (max > necklace.length()) {
					max = necklace.length();
					break;
				}
			}
			out.println(max);
		}
	}
	
	public static String reverse(String s) {
		String result = "";
		
		for (int i = s.length() - 1; i >= 0; i--) {
			result += s.charAt(i);
		}
		
		return result;
	}
	
	public static int findConsecutive(String s) {
		int consecutive = 0;
		char color = 'w';
		for (int i = 0; i < s.length(); i++) {
			if (s.charAt(i) == color || color == 'w' || s.charAt(i) == 'w') {
				if (color == 'w') {
					color = s.charAt(i);
				}
				consecutive++;
			}
			
			else {
				return consecutive;
			}
		}
		return consecutive;
	}
}
