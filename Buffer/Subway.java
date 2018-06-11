
import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStreamReader;

public class Subway {
	
	public static MyGraph graph = new MyGraph();

	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(new FileInputStream(args[0]),"UTF-8"));
		
		
		String input;
		while(true){
			try {
				input = br.readLine();
				if(input.equals("")) break;
				graph.insert(input.split(" ")[0],input.split(" ")[1],input.split(" ")[2]);
			}
			catch (IOException e)
			{
				System.out.println("입력이 잘못되었습니다. 오류 : " + e.toString());
			}
		}
		
		while(true){
			try {
				input = br.readLine();
				if(input==null) break;
				graph.insertEdge(input.split(" ")[0],input.split(" ")[1],Integer.parseInt(input.split(" ")[2]));
			}
			catch (IOException e)
			{
				System.out.println("입력이 잘못되었습니다. 오류 : " + e.toString());
			}
		}
		
		br = new BufferedReader(new InputStreamReader(System.in, "UTF-8"));
		
		while(true){
			try {
				input = br.readLine();
				if(input.equals("QUIT")) break;
				if(input.split(" ").length==2) graph.path(input.split(" ")[0],input.split(" ")[1], true);
				else graph.path(input.split(" ")[0],input.split(" ")[1], false);
			}
			catch (IOException e)
			{
				System.out.println("입력이 잘못되었습니다. 오류 : " + e.toString());
			}
		}
	}
}