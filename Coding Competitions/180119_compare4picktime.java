package my;

import java.time.*;

public class classtest{
	public static void main(String[] args) {
		LocalTime startTime = LocalTime.now();
		func1();
		LocalTime endTime = LocalTime.now();
		LocalTime startTime2 = LocalTime.now();
		func2();
		LocalTime endTime2 = LocalTime.now();
		Duration du1 = Duration.between(startTime, endTime);
		Duration du2 = Duration.between(startTime2, endTime2);
		System.out.println("if 몰아서 : " + du1.getNano());
		System.out.println("if 각각 : "+ du2.getNano());
	}
	
	static void func1() {
		int count = 0;
		for(int i = 0 ; i < 10 ; i++) {
			for(int j = 0 ; j < 10 ; j ++) {
				for(int k = 0 ; k < 10 ; k ++) {
					for(int l = 0 ; l < 10 ; l++) {
						if(i!=j && j!=k && k!=l && i!=k && i!=l && j!=l) {
							//System.out.println(i + " " + j + " " + k + " " +l);
							count++;
						}
					}
				}
			}
		}
		System.out.println("total : " + count);
	}
	
	static void func2() {
		int count = 0;
		for(int i = 0 ; i < 10 ; i++) {
			for(int j = 0 ; j < 10 ; j++) {
				if(j!=i) {
					for(int k = 0 ; k < 10 ; k++) {
						if(k!=j && k!=i) {
							for(int l = 0 ; l < 10 ; l++) {
								if(l!=k && l!=j && l!=i) {
									//System.out.println(i + " " + j + " " + k + " " + l);
									count++;
								}
							}
						}
					}
				}
			}
		}
		System.out.println("total : " + count);
	}
}
