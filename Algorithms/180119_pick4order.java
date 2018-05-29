package my;

public class classtest{
	public static void main(String[] args) {
		int count = 0;
		for(int i = 0 ; i < 10 ; i++) {
			for(int j = 0 ; j < 10 ; j++) {
				if(j!=i) {
					for(int k = 0 ; k < 10 ; k++) {
						if(k!=j && k!=i) {
							for(int l = 0 ; l < 10 ; l++) {
								if(l!=k && l!=j && l!=i) {
									System.out.println(i + " " + j + " " + k + " " + l);
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
