/*
ID: chenant1
LANG: JAVA
TASK: friday
*/

import java.util.*;
import java.io.*;

public class friday {
	public static void main(String[] args) throws IOException {
		try (
				Scanner in = new Scanner(new File("friday.in"));
				PrintWriter out = new PrintWriter(new FileWriter("friday.out"));
		) {
			
			int N = in.nextInt();
			
			int[] monthDays = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
			int[] frequencies = new int[7];
			
			int day = 0;
			
			for (int i = 1900; i < 1900 + N; i++) {
				monthDays[1] = 28;
				day %= 7;
				if ((i % 4 == 0 && i % 100 != 0) || i % 1000 == 0) {
					monthDays[1]++;
				}
				
				for (int j = 0; j < 12; j++) {
					day += 12;
					frequencies[(day + 2) % 7]++;
					
					day += monthDays[j] - 12;
				}
			}
			
			for (int i = 0; i < frequencies.length; i++) {
				out.print(frequencies[i]);
				if (i != frequencies.length - 1) {
					out.print(" ");
				}
				else {
					out.print("\n");
				}
			}
		}
	}
}