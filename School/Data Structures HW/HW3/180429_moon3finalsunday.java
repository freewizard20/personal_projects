import java.io.*;
import java.util.Vector;
import java.util.Stack;

public class CalculatorTest
{
	static public Vector<Integer> relations;
	static public Stack<Character> ops;
	
	public static void main(String args[])
	{
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
	
	// priority of operators. used for stack management of postfix
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
	
	// processing console
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

		// calculate result
		long result = calculate(post);

		// print result or error
		if(result==-12121000003L) {
			System.out.println("ERROR");
		}else {
			System.out.println(post);
			System.out.println(result);
		}
	
	}
	

	// parses and validates equation for topostfix function
	static String process(String input) {
		// check for seperated numbers
		int numflag = 0;
		int spaceflag = 0;
		for(int i = 0 ; i < input.length() ; i++){
			if(input.charAt(i)>='0'&&input.charAt(i)<='9') numflag = 1;
			if(numflag==1 && (input.charAt(i)==' '|| input.charAt(i)=='\t')) spaceflag = 1;
			if(numflag==1 &&spaceflag==1 &&(input.charAt(i)>='0'&&input.charAt(i)<='9')) return "ERROR";
			if(!((input.charAt(i)>='0'&&input.charAt(i)<='9')||input.charAt(i)==' '||input.charAt(i)=='\t')){
				numflag = 0;
				spaceflag = 0;
			}
		}

		// remove spaces
		input = input.replaceAll("\\s+","");
		StringBuilder sb = new StringBuilder(input);
		if(sb.length()==0) return "ERROR";

		// check for parathensis equality
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
			// normal input
			if(sb.charAt(0)=='('&&sb.charAt(1)=='-'){
				sb.setCharAt(1,'~');
			}
		}else if(sb.charAt(0)=='-') {
			// unary - input
			i = 0;
			sb.setCharAt(0, '~');
		}else {
			// else invalid input
			return "ERROR";
		}

		// check last index
		if(sb.charAt(sb.length()-1)==')'||(sb.charAt(sb.length()-1)>='0'&&sb.charAt(sb.length()-1)<='9')) {
			// normal input
		}else {
			// else invalid input
			return "ERROR";
		}

		// check rest indexes
		for( ; i < sb.length()-1;i++) {
			if(sb.charAt(i)=='(') {
				if(!(sb.charAt(i-1)=='('||sb.charAt(i-1)=='+'||sb.charAt(i-1)=='*'||sb.charAt(i-1)=='~'||sb.charAt(i-1)=='-'||sb.charAt(i-1)=='^'||sb.charAt(i-1)=='/'||sb.charAt(i-1)=='%')) {
					// after (, these are the only elements possible
					return "ERROR";
				}else {
					if(sb.charAt(i+1)=='('||sb.charAt(i+1)==')'||(sb.charAt(i+1)>='0'&&sb.charAt(i+1)<='9')) {
						if(sb.charAt(i+1)==')') return "ERROR";
					}else if(sb.charAt(i+1)=='-') {
						// process unary operator
						sb.setCharAt(i+1, '~');
					}else{
						// not expected to reach here
						return "ERROR";
					}
				}
			}else if(sb.charAt(i)==')') {
				if(!(sb.charAt(i+1)==')'||sb.charAt(i+1)=='+'||sb.charAt(i+1)=='*'||sb.charAt(i+1)=='-'||sb.charAt(i+1)=='^'||sb.charAt(i+1)=='/'||sb.charAt(i+1)=='%')) {
					// after ), these are the only elements possible
					return "ERROR";
				}else {
					if(sb.charAt(i-1)=='('||sb.charAt(i-1)==')'||(sb.charAt(i-1)>='0'&&sb.charAt(i-1)<='9')) {
						// normal input
					}else{
						// not expected to reach here
						return "ERROR";
					}
				}
			}else if(sb.charAt(i)=='+'||sb.charAt(i)=='*'||sb.charAt(i)=='^'||sb.charAt(i)=='/'||sb.charAt(i)=='%') {
				if(sb.charAt(i)=='^'&&sb.charAt(i+1)=='-') {
					// special error case of 3^-2 ( due to operator priority conflict )
					return "ERROR";
				}
				if(sb.charAt(i-1)==')'||(sb.charAt(i-1)>='0'&&sb.charAt(i-1)<='9')) {
					if(sb.charAt(i+1)=='('||(sb.charAt(i+1)>='0'&&sb.charAt(i+1)<='9')) {
						// normal input
					}else if(sb.charAt(i+1)=='-') {
						// process unary operator
						sb.setCharAt(i+1,'~');
					}else {
						// not expected to reach here
						return "ERROR";
					}
				}else {
					// invalid elemenets after +...^ operators
					return "ERROR";
				}
			}else if(sb.charAt(i)=='-') {
				if(sb.charAt(i+1)=='('||(sb.charAt(i+1)>='0'&&sb.charAt(i+1)<='9')) {
					// normal input
				}else if(sb.charAt(i+1)=='-') {
					// process unary input
					sb.setCharAt(i+1, '~');
				}else {
					return "ERROR";
				}
			}else if(sb.charAt(i)=='~') {
				if(sb.charAt(i+1)=='('||(sb.charAt(i+1)>='0'&&sb.charAt(i+1)<='9')) {
					// normal input
				}else if(sb.charAt(i+1)=='-') {
					// process unary input
					sb.setCharAt(i+1, '~');
				}else {
					return "ERROR";
				}
			}else {
				// number inputs
			}
		}

		return sb.toString();
		}
	
	// processes valid and parsed input from process function
	static String postfix(String input) {
		StringBuffer sb = new StringBuffer();

		for(int i = 0 ; i <input.length();) {
			if(input.charAt(i)>='0'&&input.charAt(i)<='9') {
				// reading numbers as a whole and referencing with letters
				sb.append(input.charAt(i));
				int count = input.charAt(i)-'0';
				i++;
				while(i<input.length()&&input.charAt(i)>='0'&&input.charAt(i)<='9') {
					sb.append(input.charAt(i));
					i++;
				}
				sb.append(' ');
			}else if(input.charAt(i)=='(') {
				ops.push(input.charAt(i));
				i++;
			}else if(input.charAt(i)==')') {
				// pop all operators until ( met
				char toptoken = ops.pop();
				while(toptoken!='(') {
					sb.append(toptoken);
					sb.append(' ');
					toptoken = ops.pop();
				}
				i++;
			}else if(input.charAt(i)=='^'||input.charAt(i)=='~'){
				// pop all possible operators from stack
				while(!ops.isEmpty()&&(getpriority(ops.peek())>getpriority(input.charAt(i)))){
					sb.append(ops.pop());
					sb.append(' ');
				}
				ops.push(input.charAt(i));
				i++;
			}
			else {
				// pop all possible operators from stack
				while(!ops.isEmpty()&&(getpriority(ops.peek())>=getpriority(input.charAt(i)))){
					sb.append(ops.pop());
					sb.append(' ');
				}
				ops.push(input.charAt(i));
				i++;
			}
		}

		// pop all operators left from stack
		while(!ops.isEmpty()) {
			sb.append(ops.pop());
			sb.append(' ');
		}
		
		// remove tail spaces
		for(int i = sb.length()-1 ; i>=0 ; i--){
			if(sb.charAt(i)==' ') sb.deleteCharAt(i);
			else break;
		}

		return sb.toString();
	}
	

	// calculate postfix expression
	static long calculate(String input) {
		Stack<Long> nums = new Stack<Long>();
		for(int i = 0 ; i < input.length();) {
			if(input.charAt(i)>='0'&&input.charAt(i)<='9') {
				// if number detected, get whole number
				long num = input.charAt(i)-'0';
				i++;
				while(i<input.length()&&input.charAt(i)>='0'&&input.charAt(i)<='9') {
					num*=10;
					num+=input.charAt(i)-'0';
					i++;
				}
				nums.push(num);
			}else if(input.charAt(i)=='~') {
				// process unary operator directly
				long tmp = nums.pop();
				tmp = (-1)*tmp;
				nums.push(tmp);
				i++;
			
			// process operators
			}else if(input.charAt(i)=='-') {
				long tmp = nums.pop();
				long tmp2 = nums.pop();
				nums.push(tmp2-tmp);
				i++;
			}else if(input.charAt(i)=='*') {
				long tmp = nums.pop();
				long tmp2 = nums.pop();
				nums.push(tmp2*tmp);
				i++;
			}
			else if(input.charAt(i)=='+') {
				long tmp = nums.pop();
				long tmp2 = nums.pop();
				nums.push(tmp2+tmp);
				i++;
			}
			else if(input.charAt(i)=='/') {
				long tmp = nums.pop();
				long tmp2 = nums.pop();
				// exception case of 12/0
				if(tmp==0L) {
					return -12121000003L;
				}else {
					nums.push(tmp2/tmp);
					i++;
				}
			}else if(input.charAt(i)=='^') {
				long tmp = nums.pop();
				long tmp2 = nums.pop();
				// exception case of 0^3
				try {
					if(tmp2==0L&&tmp<0L) {
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
				// exception case of 12%0
				if(tmp==0L) {
					return -12121000003L;
				}else {
					nums.push(tmp2%tmp);i++;
				}
			}else {
				i++;
			}
		}

		// get calculated result
		if (nums.size()!=0)	return nums.pop();
		else return -12121000003L;
	}	

	// end of CalculatorTest
}
