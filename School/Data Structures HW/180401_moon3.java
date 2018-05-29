import java.io.*;
import java.util.Vector;
import java.util.Stack;

public class CalculatorTest
{
	//TODO : 0^3 , 3%0 , 3/0 에러 처리
	static public Vector<Integer> relations;
	static public Stack<Character> ops;
	
	public static void main(String args[])
	{
		//System.out.println((long)2%0);
		relations = new Vector<Integer>();
		ops = new Stack<Character>();
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

		while (true)
		{
			try
			{
				String input = br.readLine();
				if (input.compareTo("q") == 0)
					break;

				command(input);
			}
			catch (Exception e)
			{
				System.out.println("입력이 잘못되었습니다. 오류 : " + e.toString());
			}
		}
	}
	
	
	static int getpriority(char s)
	{
		switch(s) {
		case '^':
			return 6;
		case '~':
			return 5;
		case '*':
			return 4;
		case '/':
			return 4;
		case '%':
			return 4;
		case '+':
			return 3;
		case '-':
			return 3;
		case '(':
			return 2;
		}
		return -1;
	}
	
	private static void command(String input) 
	{
		// parse input
		String processed = process(input);
		if(processed.equals("ERROR")) {
			System.out.println("ERROR");
			return;
		}
		// make postfix
		String post = postfix(processed);
		System.out.println(post);
		// calculate result
		long result = calculate(post);
		if(result==-12121000003L) {
			System.out.println("ERROR");
		}else {
		System.out.println(result);
		}
	}
	
	static String process(String input) {
		input = input.replaceAll("\\s+","");
		StringBuilder sb = new StringBuilder(input);
		//System.out.println(sb.toString());
		// TODO : determine unary operators and change them to ~
		// TODO : check equation validity
		// ERRORS : no operator between or too many
		int count = 0;
		for(int j = 0 ; j < sb.length();j++) {
			if(sb.charAt(j)=='(') {
				count++;
			}else if(sb.charAt(j)==')'){
						count--;
			}
		}
		if(count!=0) return "ERROR";
		int i = 1;
		// check first index
		if(sb.charAt(0)=='('||(sb.charAt(0)>='0'&&sb.charAt(0)<='9')) {
			// OK
		}else if(sb.charAt(0)=='-') {
			i = 0;
			//System.out.println("set0");
			sb.setCharAt(0, '~');
		}else {
			//System.out.println("debug0");
			return "ERROR";
		}
		// check last index
		if(sb.charAt(sb.length()-1)==')'||(sb.charAt(sb.length()-1)>='0'&&sb.charAt(sb.length()-1)<='9')) {
			// :)
		}else {
			//System.out.println("debug1");
			return "ERROR";
		}
		// check rest
		for( ; i < sb.length()-1;i++) {
			if(sb.charAt(i)=='(') {
				if(!(sb.charAt(i-1)=='('||sb.charAt(i-1)=='+'||sb.charAt(i-1)=='*'||sb.charAt(i-1)=='~'||sb.charAt(i-1)=='-'||sb.charAt(i-1)=='^'||sb.charAt(i-1)=='/'||sb.charAt(i-1)=='%')) {
					//System.out.println("debug2");
					return "ERROR";
				}else {
					if(sb.charAt(i+1)=='('||sb.charAt(i+1)==')'||(sb.charAt(i+1)>='0'&&sb.charAt(i+1)<='9')) {
						
					}else if(sb.charAt(i+1)=='-') {
						//System.out.println("set1");
						sb.setCharAt(i+1, '~');
					}else{
						//System.out.println("debug3");
						return "ERROR";
					}
				}
			}else if(sb.charAt(i)==')') {
				if(!(sb.charAt(i+1)==')'||sb.charAt(i+1)=='+'||sb.charAt(i+1)=='*'||sb.charAt(i+1)=='-'||sb.charAt(i+1)=='^'||sb.charAt(i+1)=='/'||sb.charAt(i+1)=='%')) {
					//System.out.println("debug4");
					return "ERROR";
				}else {
					if(sb.charAt(i-1)=='('||sb.charAt(i-1)==')'||(sb.charAt(i-1)>='0'&&sb.charAt(i-1)<='9')) {
						
					}else{
						//System.out.println("debug5");
						return "ERROR";
					}
				}
			}else if(sb.charAt(i)=='+'||sb.charAt(i)=='*'||sb.charAt(i)=='^'||sb.charAt(i)=='/'||sb.charAt(i)=='%') {
				if(sb.charAt(i)=='^'&&sb.charAt(i+1)=='-') {
					//System.out.println("debug6");
					return "ERROR";
				}
				if(sb.charAt(i-1)==')'||(sb.charAt(i-1)>='0'&&sb.charAt(i-1)<='9')) {
					// :)
					if(sb.charAt(i+1)=='('||(sb.charAt(i+1)>='0'&&sb.charAt(i+1)<='9')) {
						
					}else if(sb.charAt(i+1)=='-') {
						//System.out.println("set2");
						sb.setCharAt(i+1,'~');
					}else {
						//System.out.println("debug7");
						return "ERROR";
					}
				}else {
					//System.out.println("debug8");
					return "ERROR";
				}
			}else if(sb.charAt(i)=='-') {
				if(sb.charAt(i+1)=='('||(sb.charAt(i+1)>='0'&&sb.charAt(i+1)<='9')) {
					// ok
				}else if(sb.charAt(i+1)=='-') {
					//System.out.println("set3");
					sb.setCharAt(i+1, '~');
					//System.out.println(sb.toString());
				}else {
					//System.out.println("debug9");
					return "ERROR";
				}
			}else if(sb.charAt(i)=='~') {
				if(sb.charAt(i+1)=='('||(sb.charAt(i+1)>='0'&&sb.charAt(i+1)<='9')) {
					// ok
				}else if(sb.charAt(i+1)=='-') {
					//System.out.println("okk");
					//System.out.println("set4");
					sb.setCharAt(i+1, '~');
				}else {
					//System.out.println("debug10");
					return "ERROR";
				}
			}else {
				// numbers
			}
		}
		//System.out.println(sb.toString());
		return sb.toString();
		}
	
	static String postfix(String input) {
		StringBuffer sb = new StringBuffer();
		for(int i = 0 ; i <input.length();) {
			// reading numbers as a whole and referencing with letters
			if(input.charAt(i)>='0'&&input.charAt(i)<='9') {
				sb.append(input.charAt(i));
				int count = input.charAt(i)-'0';
				i++;
				while(i<input.length()&&input.charAt(i)>='0'&&input.charAt(i)<='9') {
					//count*=10;
					//count+=input.charAt(i)-'0';
					sb.append(input.charAt(i));
					i++;
				}
				sb.append(' ');
				//relations.addElement(count);
				//sb.append((char)(relations.size()+'A'-1));
			}else if(input.charAt(i)=='(') {
				ops.push(input.charAt(i));
				i++;
			}else if(input.charAt(i)==')') {
				char toptoken = ops.pop();
				while(toptoken!='(') {
					sb.append(toptoken);
					sb.append(' ');
					toptoken = ops.pop();
				}
				i++;
			}else {
				while(!ops.isEmpty()&&(getpriority(ops.peek())>=getpriority(input.charAt(i)))){
					sb.append(ops.pop());
					sb.append(' ');
				}
				ops.push(input.charAt(i));
				i++;
			}
		}
		while(!ops.isEmpty()) {
			sb.append(ops.pop());
			sb.append(' ');
		}
		return sb.toString();
	}
	
	static long calculate(String input) {
		Stack<Long> nums = new Stack<Long>();
		for(int i = 0 ; i < input.length();) {
			if(input.charAt(i)>='0'&&input.charAt(i)<='9') {
				long num = input.charAt(i)-'0';
				i++;
				while(i<input.length()&&input.charAt(i)>='0'&&input.charAt(i)<='9') {
					num*=10;
					num+=input.charAt(i)-'0';
					i++;
				}
				nums.push(num);
			}else if(input.charAt(i)=='~') {
				long tmp = nums.pop();
				tmp = (-1)*tmp;
				nums.push(tmp);
				i++;
			}else if(input.charAt(i)=='-') {
				long tmp = nums.pop();
				long tmp2 = nums.pop();
				nums.push(tmp2-tmp);i++;
			}else if(input.charAt(i)=='*') {
				long tmp = nums.pop();
				long tmp2 = nums.pop();
				nums.push(tmp2*tmp);i++;
			}
			else if(input.charAt(i)=='+') {
				long tmp = nums.pop();
				long tmp2 = nums.pop();
				nums.push(tmp2+tmp);i++;
			}
			else if(input.charAt(i)=='/') {
				long tmp = nums.pop();
				long tmp2 = nums.pop();
				if(tmp==0L) {
					return -12121000003L;
				}else {
					nums.push(tmp2/tmp);i++;
				}
			}else if(input.charAt(i)=='^') {
				long tmp = nums.pop();
				long tmp2 = nums.pop();
				try {
					if(tmp2==0L) {
						return -12121000003L;
					}else{
						long tm2p = (long)Math.pow(tmp2, tmp);
						nums.push(tm2p);
						i++;
					}
				}catch(Exception e) {
					return -12121000003L;
				}
			}else if(input.charAt(i)=='%') {
				long tmp = nums.pop();
				long tmp2 = nums.pop();
				if(tmp==0L) {
					return -12121000003L;
				}else {
					nums.push(tmp2%tmp);i++;
				}
			}else {
				i++;
			}
		}
		if (nums.size()!=0)
		return nums.pop();
		else
		return -123456781234L;
	}
	
	
}









