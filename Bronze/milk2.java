/*
ID: chenant1
LANG: JAVA
TASK: milk2
*/

import java.util.*;
import java.io.*;

public class milk2 {
	public static void main(String[] args) throws IOException {
		try (
				Scanner in = new Scanner(new File("milk2.in"));
				PrintWriter out = new PrintWriter("milk2.out");
		) {
			int[][] times = new int[in.nextInt()][2];
			for (int i = 0; i < times.length; i++) {
				times[i][0] = in.nextInt();
				times[i][1] = in.nextInt();
			}
			Arrays.sort(times, new TimeComparator2());
			out.println(calculate(times)[0] + " " + calculate(times)[1]);
		}
	}
	
	public static int[] calculate(int[][] array) {
		int prevCont = 0;
		int prevGap = 0;
		int prevEnd = array[0][0];
		int start = array[0][0]; 
		
		for (int i = 0; i < array.length; i++) {
			if (prevEnd >= array[i][0] && prevEnd <= array[i][1]) {
				prevEnd = array[i][1];
			}
			if (prevEnd < array[i][0] || i == array.length - 1 ) {
				int gap = array[i][0] - prevEnd;
				if (gap > prevGap) {
					prevGap = gap;
				}
				int cont = prevEnd - start;
				if (cont > prevCont) {
					prevCont = cont;
				}
				start = array[i][0];
				prevEnd = array[i][1];
			}
		}
		
		return new int[] {prevCont, prevGap};
	}
}
class TimeComparator2 implements Comparator<int[]> {
	public int compare(int[] x, int[] y) {
		return (x[0] == y[0]) ? (x[1] - y[1]) : (x[0] - y[0]);
	}
}