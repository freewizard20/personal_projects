package my;

public class classtest{
	public static void main(String[] args) {
		int count = 0;
		for(int i = 0 ; i < 10 ; ++i) {
			for(int j = i+1; j < 10; ++j) {
				for(int k = j+1;k<10; ++k) {
					for(int l = k + 1 ; l < 10 ; ++l) {
						System.out.println(i + " " + j + " " + k + " " + l);
						count++;
					}
				}
			}
		}
		System.out.println("total : " + count);
	}
}
