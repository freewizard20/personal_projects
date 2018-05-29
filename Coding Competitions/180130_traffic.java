package my;
import java.util.Scanner;
import java.util.StringTokenizer;
import java.util.Vector;

public class traffic {
		public static void main(String[] args) {
			Scanner sc = new Scanner(System.in);
			StringTokenizer st = new StringTokenizer(sc.nextLine());
			Vector<jtime> tasks = new Vector<jtime>();
			while(st.hasMoreTokens()) {
				st.nextToken();
				jtime tmp = new jtime();
				String tt = st.nextToken();
				char[] tt2 = tt.toCharArray();
				int flag = 0;
				for(int i = 0 ; i < tt2.length ; i++) {
					if(tt2[i]==':') {
						if(flag==0) {
						StringBuffer sb = new StringBuffer();
						sb.append(tt2[i-2]);
						sb.append(tt2[i-1]);
						tmp.etime.hour = Integer.parseInt(sb.toString());
						StringBuffer sb2 = new StringBuffer();
						sb2.append(tt2[i+1]);
						sb2.append(tt2[i+2]);
						tmp.etime.min = Integer.parseInt(sb2.toString());
						flag++;
						continue;
						}
						if(flag==1) {
						StringBuffer sb = new StringBuffer();
						sb.append(tt2[i+1]);
						sb.append(tt2[i+2]);
						sb.append(tt2[i+3]);
						sb.append(tt2[i+4]);
						sb.append(tt2[i+5]);
						sb.append(tt2[i+6]);
						tmp.etime.sec = Double.parseDouble(sb.toString());
						}
					}
				}
				String tt3 = st.nextToken();
				char[] tt4 = tt3.toCharArray();
				Double delta;
				StringBuffer sb = new StringBuffer();
				int zz = 0;
				while(tt4[zz]!='s') {
					sb.append(tt4[zz]);
					zz++;
				}
				delta = Double.parseDouble(sb.toString());
				tmp.stime.sec = (tmp.etime.sec+0.001) - delta;
				tmp.stime.min = tmp.etime.min;
				tmp.stime.hour = tmp.etime.hour;
				if(tmp.stime.sec < 0) {
					tmp.stime.sec += 60;
					tmp.stime.min--;
				}
				if(tmp.stime.min<0) {
					tmp.stime.min += 60;
					tmp.stime.hour--;
				}
				if(tmp.stime.hour<0) {
					tmp.etime.hour +=24;
				}
				tasks.add(tmp);
			}
			int count = 0;
			for(int i = 0 ; i < tasks.size();i++) {
				count = Math.max(count, running(tasks,tasks.get(i).etime));
				count = Math.max(count, running(tasks,tasks.get(i).stime));
			}
			System.out.println(count);
		}
		
		
		
		static int running(Vector<jtime> tasks, timej time) {
			int ret = 0;	
			timej time1 = new timej();
			time1.sec = time.sec + 0.9999;
			time1.min = time.min;
			time1.hour = time.hour;
			if(time1.sec>=60) {
				time1.min++;
				time1.sec-=60;
			}
			if(time1.min>=60) {
				time.min-=60;
				time.hour++;
			}
			if(time1.hour>=24) {
				time.hour-=24;
			}
			for(int i = 0 ; i < tasks.size();i++) {
					jtime tmp = tasks.get(i);
					if(!(comparetime(tmp.stime,time1)==1||comparetime(time,tmp.etime)==1)){
						ret++;
					}
			}
			return ret;
		}
		
		static int comparetime(timej atime, timej btime) {
			if(atime.hour>btime.hour) {
				return 1;
			}else if(atime.hour==btime.hour) {
				if(atime.min>btime.min) {
					return 1;
				}else if(atime.min==btime.min) {
					if(atime.sec>btime.sec) {
						return 1;
					}else if(atime.sec==btime.sec) {
						return 0;
					}else {
						return -1;
					}
				}else {
					return -1;
				}
				
			}else {
				return -1;
			}
		
		}
			
}

class jtime{
	timej etime;
	timej stime;
	jtime(){
		etime = new timej();
		stime = new timej();
	}
}

class timej{
	int hour;
	int min;
	double sec;
}

