import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.regex.Matcher;
import java.util.regex.Pattern;
import java.util.Arrays;
  
public class BigInteger
{	
	public int[] data;
    public static final String QUIT_COMMAND = "quit";
    public static final String MSG_INVALID_INPUT = "입력이 잘못되었습니다.";
  
    // implement this
    public static final Pattern EXPRESSION_PATTERN = Pattern.compile("");
  
  
    public BigInteger(int i)
    {
    	data = new int[201];
    	Arrays.fill(data,9999);
    	if(i<0) data[0] = -1;
    	else data[0] = 1;
    	int count = 0;
    	if(i==0) data[200] = 0;
    	while(i!=0) {
    		data[200-count] = i%10;
    		i /= 10;
    		count++;
    	}
    }
  
    public BigInteger(int[] num1)
    {
    	data = new int[201];
    	Arrays.fill(data, 9999);
    	for(int i = num1.length-1, j = 200 ; i >=0 ; i--,j--) {
    		data[j] = num1[i];
    	}
    	data[0] = 1;
    }
  
    public BigInteger(String s)
    {
    	char[] tmp = s.toCharArray();
    	data = new int[201];
    	Arrays.fill(data, 9999);
    	if(s.length()!=0&&s.charAt(0)=='-') data[0] = -1;
    	else data[0] = 1;
    	for(int i = s.length()-1,j=200;i>=0;i--,j--) {
    		if(s.charAt(i)=='-') break;
    		data[j] = s.charAt(i)-'0';
    	}
    }
  
    public Boolean iszero() {
    	for(int i = 1 ; i < data.length ; i++) {
    		if(!(data[i]==0&&data[i]==9999)) {
    			return false;
    		}
    	}
    	return true;
    }
    
    int whatisbigger(BigInteger big1, BigInteger big2) {
    	int ret;
    	for(int i = 1 ; i < data.length ; i++) {
    		if(big1.data[i]==9999&&big2.data[i]!=9999) {
    			return 2;
    		}else if(big1.data[i]!=9999 && big2.data[i]==9999) {
    			return 1;
    		}else {
    			if(big1.data[i]>big2.data[i]) {
    				return 1;
    			}else if(big1.data[i]<big2.data[i]) {
    				return 2;
    			}
    		}
    	}
    	return 0;
    }
    
    public BigInteger add(BigInteger big)
    {
    	if((this.data[0]==1&&big.data[0]==1)||(this.data[0]==-1&&big.data[0]==-1)) {
    		BigInteger bs = new BigInteger(0);
    		int carry = 0;
    		int x, y,curr;
    		for(int i = 200 ; i > 0 ; i--) {
    			if(this.data[i]==9999&&big.data[i]==9999&&carry==0) continue;
    			if(this.data[i]!=9999) x = this.data[i];
    			else x = 0;
    			if(big.data[i]!=9999) y = big.data[i];
    			else y = 0;
    			curr = x+y+carry;
    			if(curr>=10) carry = 1;
    			else carry = 0;
    			bs.data[i] = curr%10;
    			curr = 0;
    		}
    		if(this.data[0]==1) {
    			bs.data[0]=1;
    		}else {
    			bs.data[0]=-1;
    		}
    		int tru = 0;
    		for(int i = 1 ; i <= 200 ; i++) {
    			if(!(bs.data[i]==0||bs.data[i]==9999)) {
    				tru = 1;
    			}
    		}
    		if(tru == 0) {
    			return new BigInteger(0);
    		}
    		return bs;
    	}else {
    		return this.subtract(big);
    	}
    }
  
    public BigInteger subtract(BigInteger big)
    {
    	int tmp = whatisbigger(this,big);
    	BigInteger z = new BigInteger(0);
    	if(tmp==2) {
    		z =  remove(big,this);
    		if(this.data[0]==-1) {
    			z.data[0] = 1;
    		}else {
    			z.data[0] = -1;
    		}
    		return z;
    	}else if(tmp==1) {
    		z =  remove(this,big);
    		if(this.data[0]==-1) {
    			z.data[0] = -1;
    		}else {
    			z.data[0] = 1;
    		}
    		return z;
    	}else {
    		return new BigInteger(0);
    	}
    }
  
    static BigInteger remove(BigInteger big1, BigInteger big2) {
    	int carry = 0;
    	int x, y, curr;
    	BigInteger ret = new BigInteger(0);
    	for(int i = 200 ; i > 0 ; i--) {
    		if(big1.data[i]==9999) x = 0;
    		else x = big1.data[i];
    		if(big2.data[i]==9999) y = 0;
    		else y = big2.data[i];
    		curr = x-y+carry;
    		if(curr<0) {
    			carry = -1;
    			curr += 10;
    		}else {
    			carry = 0;
    		}
    		ret.data[i] = curr;
    		curr = 0;
    	}
    	for(int i = 1 ; i < 201 ; i++) {
    		if(ret.data[i]!=0) {
    			break;
    		}
    		ret.data[i] = 9999;
    	}
    	return ret;
    }
    
    public BigInteger multiply(BigInteger big)
    {
    	BigInteger ret = new BigInteger(0);
    	ret.data[0] = this.data[0] * big.data[0];
    	for(int i = 200, k = 0 ; i > 0 ; i--,k++) {
    		BigInteger tmp = new BigInteger(0);
    		if(big.data[i]!=9999&&big.data[i]!=0) {
    		for(int j = 0 ; j < big.data[i] ;j++) {
    			tmp = tmp.add(this);
    		}   		
    		tmp.shiftleft(k);
    		ret = ret.add(tmp);
    		}
    	}
    	return ret;
    }
    
    public void shiftleft(int N) {
    	for(int i = 1 ; i < this.data.length ; i++) {
    		if(this.data[i]!=9999) {
    			this.data[i-N] = this.data[i];
    		}
    	}
    	for(int j = 200; j > 200-N ; j--) {
    		this.data[j] = 0;
    	}
    }
    @Override
    public String toString()
    {	
    	StringBuffer sb = new StringBuffer();
    	if(data[0] == -1) sb.append('-');
    	for(int i = 1 ; i < data.length ; i++) {
    		if(data[i]!=9999) {
    			sb.append((char)(data[i]+'0'));
    		}
    	}
    	return sb.toString();
    }
  
    static BigInteger evaluate(String input) throws IllegalArgumentException
    {
    	int i = 0;
    	BigInteger b1 = new BigInteger(1);
    	BigInteger b2 = new BigInteger(1);
    	int flag = 0;
    	int multiplication = 0;
    	while(i<input.length()) {
    		StringBuffer sb = new StringBuffer();
    		if(input.charAt(i)==' ') {
    			i++;
    			continue;
    		}else if(input.charAt(i)=='*'){
    			multiplication ++;
    			i++;
    		}else{
    			// encountered signs
    			int countminus = 0;
    			int countplus = 0;
    			while(i<input.length()&&!(input.charAt(i)>='0'&&input.charAt(i)<='9')) {
    				if(input.charAt(i)=='+') {
    					countplus++;
    				}else if(input.charAt(i)=='-') {
    					countminus++;
    				}else if(input.charAt(i)=='*'){
    					multiplication++;
    				}
    				i++;
    			}
    			if(countminus%2==1) {
    				sb.append('-');
    			}
    			int foundnum = 0;
    			while(i<input.length()&&(input.charAt(i)>='0'&&input.charAt(i)<='9')) {
    				sb.append(input.charAt(i));
    				i++;
    				foundnum++;
    			}
    			if(flag==0&&foundnum!=0) {
    				b1 = new BigInteger(sb.toString());
    				flag++;
    			}else if(flag==1&&foundnum!=0){
    				b2 = new BigInteger(sb.toString());
    				flag++;
    			}
    		}
    	}
    	if(multiplication>=2||flag!=2) {
    		throw new IllegalArgumentException();
    	}
    	if(multiplication==0) {
    		return b1.add(b2);
    	}else {
    		return b1.multiply(b2);
    	}
    }
  
    public static void main(String[] args) throws Exception
    {
        try (InputStreamReader isr = new InputStreamReader(System.in))
        {
            try (BufferedReader reader = new BufferedReader(isr))
            {
                boolean done = false;
                while (!done)
                {
                    String input = reader.readLine();
  
                    try
                    {
                        done = processInput(input);
                    }
                    catch (IllegalArgumentException e)
                    {
                        System.err.println(MSG_INVALID_INPUT);
                    }
                }
            }
        }
    }
  
    static boolean processInput(String input) throws IllegalArgumentException
    {
        boolean quit = isQuitCmd(input);
  
        if (quit)
        {
            return true;
        }
        else
        {
            BigInteger result = evaluate(input);
            System.out.println(result.toString());
            return false;
        }
    }
  
    static boolean isQuitCmd(String input)
    {
        return input.equalsIgnoreCase(QUIT_COMMAND);
    }
}
