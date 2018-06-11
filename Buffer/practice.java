import java.io.*;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.*;

public class practice {
	public static void main(String args[]) throws Exception{
		File input = new File("C:\\Users\\hp\\Desktop\\Subway\\src\\inst.txt");
		File out = new File("C:\\Users\\hp\\Desktop\\Subway\\src\\out.txt");
		File result = new File("C:\\Users\\hp\\Desktop\\Subway\\src\\result.txt");
		
		File compare = new File("C:\\Users\\hp\\Desktop\\Subway\\src\\비교1.txt");
		BufferedWriter br = new BufferedWriter(new OutputStreamWriter(new FileOutputStream(compare),"UTF-8"));
		
		BufferedReader br1 = new BufferedReader(new FileReader(input));
		BufferedReader br2 = new BufferedReader(new FileReader(out));
		BufferedReader br3 = new BufferedReader(new FileReader(result));
		
		ArrayList<String> inputList = new ArrayList<>();
		ArrayList<String> outList = new ArrayList<>();
		ArrayList<String> resultList = new ArrayList<>();
		
		while(br1.ready()) {
			inputList.add(br1.readLine());
			outList.add(br2.readLine());
			resultList.add(br3.readLine());
		}
		
		String[] inputArray = inputList.toArray(new String[inputList.size()]);
		String[] outArray = outList.toArray(new String[inputList.size()]);
		String[] resultArray = resultList.toArray(new String[inputList.size()]);

		int i = 0;
		
		while(i<resultArray.length-1) {
			
			String outString = outArray[i];
			String resultString = resultArray[i];
			
			if(!resultString.equals(outString) && i%2 == 0) {
								
				br.write(inputArray[i/2]);
				br.newLine();
				br.write("진혁");
				br.newLine();
				br.write(outString);
				br.newLine();
				br.write(outArray[i+1]);
				br.newLine();
				br.write("지용");
				br.newLine();
				br.write(resultString);
				br.newLine();
				br.write(resultArray[i+1]);
				br.newLine();
				br.write("");
				br.newLine();	
			}
			
			i++;
		}
		
		br.close();
		br1.close();
		br2.close();
		br3.close();
	}

}
