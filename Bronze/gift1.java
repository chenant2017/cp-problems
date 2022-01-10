/*
ID: chenant1
LANG: JAVA
TASK: gift1
*/

import java.util.*;
import java.io.*;

public class gift1 {
	public static void main(String[] args) throws IOException {
		try(
				Scanner in = new Scanner(new File("gift1.in"));
				PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("gift1.out")));
		) {
			int np = in.nextInt();
			in.nextLine();
			
			LinkedHashMap<String, Integer> accounts = new LinkedHashMap<>();
			
			for (int i = 0; i < np; i++) {
				String s = in.nextLine();
				accounts.put(s, 0);
			}
			
			for (int j = 0; j < np; j++) {
				String name = "";
				int amount = 0;
				int people = 0;
				try {
					 name = in.nextLine();
					 amount = in.nextInt();
					 people = in.nextInt();
					 if (people != 0) {
						 in.nextLine();
						 for (int i = 0; i < people; i++) {
							 String sendTo = in.nextLine();
							 int current = accounts.get(sendTo);
							 accounts.replace(sendTo, current + amount / people);
						 }
						 int nameCurrent = accounts.get(name);
						 accounts.replace(name, nameCurrent + (amount % people) - amount);
					}
					else {
						in.nextLine();
					}
				}
				catch (Exception ex) {
					throw new IOException("name, j, np, amount, people: " + name + " " + j + " " + np + " " + amount + " " + people);
				}
			}
			
			Set<Map.Entry<String, Integer>> entrySet = accounts.entrySet();
			for (Map.Entry<String, Integer> entry: entrySet) {
				out.println(entry.getKey() + " " + entry.getValue());
			}
		}
	}
}