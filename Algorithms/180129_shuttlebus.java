package my;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;
import java.util.Vector;

public class shuttlebus {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int n = Integer.parseInt(br.readLine());
		int t = Integer.parseInt(br.readLine());
		int m = Integer.parseInt(br.readLine());
		StringTokenizer st = new StringTokenizer(br.readLine());
		Vector<int[]> times = new Vector<int[]>();
		while(st.hasMoreTokens()) {
			String tmp = st.nextToken();
			char [] tm = tmp.toCharArray();
			int[] tt = new int[2];
			int flag = 0;
			for(int i = 0 ; i < tm.length;i++) {
				if(Character.isDigit(tm[i])) {
					StringBuffer sb = new StringBuffer();
					sb.append(tm[i]);
					sb.append(tm[i+1]);
					tt[flag] = Integer.parseInt(sb.toString());
					flag++;
					i = i+2;
				}
			}
			times.add(tt);
		}
		for(int i = 0 ; i < times.size();i++) {
			for(int j = i ; j < times.size();j++) {
				if(isbigger(times.get(i),times.get(j))==1) {
					int[] tmp1 = times.get(i);
					int[] tmp2 = times.get(j);
					times.remove(tmp1);
					times.remove(tmp2);
					times.add(i, tmp2);
					times.add(j ,tmp1);
				}
			}
		}
		int[][][] busses = new int[n][m][2];
		for(int i = 0 ; i < n ; i++) {
			for(int j = 0 ; j < m ; j++) {
				for(int k = 0 ; k < 2 ; k++) {
					busses[i][j][k] = -23;
				}
			}
		}
		int[] time = {9,0};
		for(int z = 0 ; z < n ; z++) {
			int mm = 0;
			while(times.size()>0&&mm<m && !(isbigger(time,times.get(0))==-1)) {
				busses[z][mm][0]=times.get(0)[0];
				busses[z][mm][1]=times.get(0)[1];
				times.remove(0);
				mm++;
			}
			time = addtime(time,t);
		}
		int last = -24;
		for(int i = 0 ; i < m ; i++) {
			if(busses[n-1][i][0]==-23) {
				last = i-1;
			}
		}
		int[] ans = new int[2];
		if(last==-24) {
			ans = subtracttime(busses[n-1][m-1],1);
		}else {
			ans = subtracttime(time,t);
		}
		StringBuffer sb = new StringBuffer();
		sb.append("\"");
		if(ans[0]>=10) {
			sb.append(Integer.toString(ans[0]));
		}else {
			sb.append("0"+Integer.toString(ans[0]));
		}
		sb.append(":");
		if(ans[1]>=10) {
			sb.append(Integer.toString(ans[1]));
		}else {
			sb.append("0"+Integer.toString(ans[1]));
		}
		sb.append("\"");
		System.out.println(sb.toString());
	}
	
	static int isbigger(int[] first, int[] second) {
		if(first[0]>second[0]) {
			return 1;
		}else if(first[0]==second[0]) {
			if(first[1]==second[1]) {
				return 0;
			}else if(first[1]>second[1]) {
				return 1;
			}else {
				return -1;
			}
		}else {
			return -1;
		}
	}
	
	static int[] addtime(int[] time, int minutes) {
		if(time[1]+minutes>=60) {
			time[0]++;
			time[1] = time[1]+minutes-60;
		}else {
			time[1]=time[1]+minutes;
		}
		return time;
	}
	
	static int[] subtracttime(int[] time, int minutes) {
		if(time[1]-minutes<0) {
			time[0]--;
			time[1] = time[1] - minutes + 60;
		}else{
			time[1] = time[1] - minutes;
		}
		return time;
	}
}
