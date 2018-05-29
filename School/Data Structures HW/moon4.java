import java.io.*;
import java.util.*;

public class SortingTest
{
	public static void main(String args[])
	{	
		//already();
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

		try
		{
			boolean isRandom = false;	// 입력받은 배열이 난수인가 아닌가?
			int[] value;	// 입력 받을 숫자들의 배열
			String nums = br.readLine();	// 첫 줄을 입력 받음
			if (nums.charAt(0) == 'r')
			{
				// 난수일 경우
				isRandom = true;	// 난수임을 표시

				String[] nums_arg = nums.split(" ");

				int numsize = Integer.parseInt(nums_arg[1]);	// 총 갯수
				int rminimum = Integer.parseInt(nums_arg[2]);	// 최소값
				int rmaximum = Integer.parseInt(nums_arg[3]);	// 최대값

				Random rand = new Random();	// 난수 인스턴스를 생성한다.

				value = new int[numsize];	// 배열을 생성한다.
				for (int i = 0; i < value.length; i++)	// 각각의 배열에 난수를 생성하여 대입
					value[i] = rand.nextInt(rmaximum - rminimum + 1) + rminimum;
			}
			else
			{
				// 난수가 아닐 경우
				int numsize = Integer.parseInt(nums);

				value = new int[numsize];	// 배열을 생성한다.
				for (int i = 0; i < value.length; i++)	// 한줄씩 입력받아 배열원소로 대입
					value[i] = Integer.parseInt(br.readLine());
			}

			// 숫자 입력을 다 받았으므로 정렬 방법을 받아 그에 맞는 정렬을 수행한다.
			while (true)
			{
				//if(test(value)) System.out.println("match");
				//report(value);
				int[] newvalue = (int[])value.clone();	// 원래 값의 보호를 위해 복사본을 생성한다.

				String command = br.readLine();

				long t = System.currentTimeMillis();
				switch (command.charAt(0))
				{
					case 'B':	// Bubble Sort
						newvalue = DoBubbleSort(newvalue);
						break;
					case 'I':	// Insertion Sort
						newvalue = DoInsertionSort(newvalue);
						break;
					case 'H':	// Heap Sort
						newvalue = DoHeapSort(newvalue);
						break;
					case 'M':	// Merge Sort
						newvalue = DoMergeSort(newvalue);
						break;
					case 'Q':	// Quick Sort
						newvalue = DoQuickSort(newvalue);
						break;
					case 'R':	// Radix Sort
						newvalue = DoRadixSort(newvalue);
						break;
					case 'X':
						return;	// 프로그램을 종료한다.
					default:
						throw new IOException("잘못된 정렬 방법을 입력했습니다.");
				}
				if (isRandom)
				{
					// 난수일 경우 수행시간을 출력한다.
					System.out.println((System.currentTimeMillis() - t) + " ms");
				}
				else
				{
					// 난수가 아닐 경우 정렬된 결과값을 출력한다.
					for (int i = 0; i < newvalue.length; i++)
					{
						System.out.println(newvalue[i]);
					}
				}

			}
		}
		catch (IOException e)
		{
			System.out.println("입력이 잘못되었습니다. 오류 : " + e.toString());
		}
	}

// TESTER FUNCTION FOR REPORT
	private static void report(int[] value){
		int[] tmp;
		int t;
		int[][] result = new int[6][30];
		for(int j = 0 ; j < 30 ; j++){
			tmp = (int[]) value.clone();
			t = (int)System.currentTimeMillis();
			//DoBubbleSort(tmp);
			result[0][j]= (int)System.currentTimeMillis() - t;
		}
		System.out.println("done..");
		for(int j = 0 ; j < 30 ; j++){
			tmp = (int[]) value.clone();
			t = (int)System.currentTimeMillis();
			//DoInsertionSort(tmp);
			result[1][j]= (int)System.currentTimeMillis() - t;
		}
		System.out.println("done..");
		for(int j = 0 ; j < 30 ; j++){
			tmp = (int[]) value.clone();
			t = (int)System.currentTimeMillis();
			//DoHeapSort(tmp);
			result[2][j]= (int)System.currentTimeMillis() - t;
		}
		System.out.println("done..");
		for(int j = 0 ; j < 30 ; j++){
			tmp = (int[]) value.clone();
			t = (int)System.currentTimeMillis();
			//DoMergeSort(tmp);
			result[3][j]= (int)System.currentTimeMillis() - t;
		}
		System.out.println("done..");
		for(int j = 0 ; j < 30 ; j++){
			tmp = (int[]) value.clone();
			t = (int)System.currentTimeMillis();
			//DoQuickSort(tmp);
			result[4][j]= (int)System.currentTimeMillis() - t;
		}
		System.out.println("done..");
		for(int j = 0 ; j < 30 ; j++){
			tmp = (int[]) value.clone();
			t = (int)System.currentTimeMillis();
			DoRadixSort(tmp);
			result[5][j]= (int)System.currentTimeMillis() - t;
		}
		System.out.println("done..");
		// calculate result
		System.out.println("Average for "+value.length+ " reps");
		for(int i = 0 ; i < 6 ; i++){
			int sum=0;
			int min = 20000000;
			int max = -20000000;
			for(int j = 0 ; j <30 ; j++){
				sum+=result[i][j];
				if(min>result[i][j]) min = result[i][j];
				if(max<result[i][j]) max =result[i][j];
			}
			float res = sum/30;
			System.out.println("---");
			System.out.println("mean : " + res);
			System.out.println("max : " + max);
			System.out.println("min : "+min);
			float sigma = 0;
			for(int j = 0 ; j < 30 ; j++){
				sigma+=(result[i][j]-res)*(result[i][j]-res);
			}
			sigma/=30;
			sigma = (float) Math.sqrt(sigma);
			System.out.println("sigma : " + sigma);
		}
	}
	
	private static void already(){
		int[] value = new int[5000];
		for(int i = 0 ; i < value.length ; i++){
			value[i]=i;
		}
		int t = (int)System.currentTimeMillis();
		DoInsertionSort(value);
		System.out.println("Insertion sort on already sorted : " + ((int)System.currentTimeMillis()-t) + "ms");

		t = (int)System.currentTimeMillis();
		DoQuickSort(value);
		System.out.println("Quick sort on already sorted : " + ((int)System.currentTimeMillis()-t) + "ms");
	}

// TESTER FUNCTION FOR INTERNAL TEST

	private static boolean test(int[] value){
		System.out.println("testing..");
		int[] tmp = (int[]) value.clone();
		int[] newvalue = DoBubbleSort(tmp);
		tmp = (int[]) value.clone();
		int[] newvalue2 = DoInsertionSort(tmp);
		for(int i = 0 ; i < value.length;i++){
			if(newvalue[i]!=newvalue2[i]){
				System.out.println("Error at insertsort");
				for(int x : newvalue) System.out.print(x+" ");
				System.out.println();
				for(int x : newvalue2) System.out.print(x+ " ");
				System.out.println();
				return false;
			}
			
		}
				tmp = (int[]) value.clone();
		newvalue2 = DoHeapSort(tmp);
		for(int i = 0 ; i < value.length;i++){
						if(newvalue[i]!=newvalue2[i]){
				System.out.println("Error at hinsertsort");
				for(int x : newvalue) System.out.print(x+" ");
				System.out.println();
				for(int x : newvalue2) System.out.print(x+ " ");
				System.out.println();
				return false;
			}
			
		}
				tmp = (int[]) value.clone();
		newvalue2 = DoMergeSort(tmp);
		for(int i = 0 ; i < value.length;i++){
						if(newvalue[i]!=newvalue2[i]){
				System.out.println("Error at minsertsort");
				for(int x : newvalue) System.out.print(x+" ");
				System.out.println();
				for(int x : newvalue2) System.out.print(x+ " ");
				System.out.println();
				return false;
			}
			
		}
				tmp = (int[]) value.clone();
		newvalue2 = DoQuickSort(tmp);
		for(int i = 0 ; i < value.length;i++){
						if(newvalue[i]!=newvalue2[i]){
				System.out.println("Error at qinsertsort");
				for(int x : newvalue) System.out.print(x+" ");
				System.out.println();
				for(int x : newvalue2) System.out.print(x+ " ");
				System.out.println();
				return false;
			}
			
		}
		tmp = (int[]) value.clone();
		newvalue2 = DoRadixSort(tmp);
		for(int i = 0 ; i < value.length;i++){
						if(newvalue[i]!=newvalue2[i]){
				System.out.println("Error at rinsertsort");
				for(int x : newvalue) System.out.print(x+" ");
				System.out.println();
				for(int x : newvalue2) System.out.print(x+ " ");
				System.out.println();
				return false;
			}
			
		}
		return true;
	}

// BUBBLE SORT

	private static int[] DoBubbleSort(int[] value)
	{
		for(int i = 0 ; i < value.length-1; i++){
			for(int j = 0 ; j < value.length-1-i ; j++){
				if(value[j]>value[j+1]){
					int tmp = value[j];
					value[j] = value[j+1];
					value[j+1] = tmp;
				}
			}
		}
		return (value);
	}

// INSERT SORT

	private static int[] DoInsertionSort(int[] value)
	{
		for(int i = 1 ; i < value.length ; i++){
			
			// no need to sort when biggest value
			if(value[i-1]>value[i]){
				
				// sorting process
				int tmp = value[i];
				for(int j = i-1 ; j >= 0 ; j--){
					if(tmp>value[j]){
						value[j+1] = tmp;
						break;
					}else{
						value[j+1] = value[j];
					}
					// when smallest value, swap without comparision at the end
					if(j==0) value[0]=tmp;
				}
			}
		}
		return (value);
	}

// HEAP SORT

	// the sorted array
	private static int[] cache;

	// get relative elements
	private static int parent(int curr){
		if(curr==0) return -1;
		else return curr/2;
	}

	private static int leftc(int curr,int last){
		int ret = curr*2+1;
		return (ret>last)? -1:ret;
	}

	private static int rightc(int curr,int last){
		int ret = curr*2+2;
		return (ret>last)? -1:ret;
	}

	// replace the current element to right place
	private static void replace(int curr, int last){
		if(curr>cache.length-1) return;
		int left = leftc(curr,last);
		int right = rightc(curr,last);
		int change = curr;
		if(left!=-1&&cache[left]>cache[curr]){
			change = left;
		}
		if(right!=-1&&cache[right]>cache[change]){
			change=right;
		}
		if(change!=curr){
			int tmp = cache[curr];
			cache[curr] = cache[change];
			cache[change] = tmp;
			replace(change,last);
		}
	}

	// initially builds total heap
	private static void heapify(int last){
		for(int i = cache.length/2; i>=0 ; i--){
			replace(i,last);
		}
	}

	// heapsort function
	private static void heapsort(){
		
		// heapify the array
		heapify(cache.length-1);
		// pop then swap with last element, reheapify
		for(int i = cache.length-1; i>=1 ;i--){
			int tmp = cache[i];
			cache[i]=cache[0];
			cache[0]=tmp;
			replace(0,i-1);
		}

	}

	// wrapper function
	private static int[] DoHeapSort(int[] value)
	{
		cache = value;
		heapsort();
		return cache;
	}

// MERGE SORT

	// Merge two seperated array
	private static void Merge(int low, int high){
		int mid = (low+high)/2;
		
		// fill temporary arrays
		int[] arr1= new int[mid-low+1];
		int[] arr2= new int[high-mid];
		for(int i = low ; i <= high ; i++){
			if(i<=mid){
				arr1[i-low]=cache[i];
			}else{
				arr2[i-mid-1]=cache[i];
			}
		}

		// merge the arrays
		int i1 = 0;
		int i2 = 0;
		int i3 = low;
		
		// merge smaller element
		while(i1<arr1.length&&i2<arr2.length){
			if(arr1[i1]<arr2[i2]){
				cache[i3]=arr1[i1];
				i1++;
				i3++;
			}else{
				cache[i3]=arr2[i2];
				i2++;
				i3++;
			}
		}

		// merge left elements
		while(i1<arr1.length){
			cache[i3]=arr1[i1];
			i3++;
			i1++;
		}
		while(i2<arr2.length){
			cache[i3]=arr2[i2];
			i2++;
			i3++;
		}

	}

	// seperate to subarrays then merge
	private static void Mergesort(int low, int high){
		if(low==high) return;
		int mid = (low+high)/2;
		Mergesort(low,mid);
		Mergesort(mid+1,high);
		Merge(low,high);
	}

	// wrapper function
	private static int[] DoMergeSort(int[] value)
	{
		cache = value;
		Mergesort(0,value.length-1);
		return cache;
	}

// QUICK SORT

	// partition function to split array into smaller - bigger sections
	private static int partition(int low, int high){
		int ret = low;

		// split-swap smaller ones
		for(int i = low; i<high ; i++){
			if(cache[i]<cache[high]){
				int tmp = cache[i];
				cache[i] = cache[ret];
				cache[ret] = tmp;
				ret++;
			}
		}

		// put high into position
		int tmp2 = cache[ret];
		cache[ret] = cache[high];
		cache[high] = tmp2;
		
		return ret;
	}

	// Quicksort helper function
	private static void qs(int low, int high){
		if(low>=high) return;
		int x = partition(low,high);

		// Quicksort splitted subarrays
		qs(low,x-1);
		qs(x+1,high);
		return;
	}

	// Quicksort wrapper function
	private static int[] DoQuickSort(int[] value)
	{
		cache = value;
		qs(0,value.length-1);
		return cache;
	}


// RADIX SORT

	// need to seperate plus and minus for radix sort
	// using long to prevent overflow
	private static ArrayList<Long> mcache;

	// Count sort function
	private static void countsort(long curr, int test){
		ArrayList<Long> tcache = new ArrayList<Long>();
		for(int i = 0 ; i < mcache.size();i++){
			tcache.add(mcache.get(i));
		}
		// count sort on the current radix
		int[] carr = new int[10];
		for(int i = 0 ; i < mcache.size() ; i++){
			long test2 = ((Math.abs(mcache.get(i).longValue())%(curr*10L))/curr);
			carr[(int)test2]++;
		}

		// set to position array
		if(test==1){
			for(int i = 1 ; i < 10 ; i++){
				carr[i] = carr[i]+carr[i-1]; 
			}
		}else{
			for(int i = 8 ; i>=0 ;i--){
				carr[i] = carr[i]+carr[i+1];
			}
		}
		for(int i = 0 ; i < 10 ; i++) carr[i]--;

		// reallocate them
		for(int i = mcache.size()-1 ; i >=0 ; i--){
			int cur = (int)((Math.abs(tcache.get(i).longValue())%(curr*10L))/curr);
			mcache.set(carr[cur],tcache.get(i));
			carr[cur]--;
		}

	}

	// Radix sort function
	private static void RadixSort(int test){

		// Look for maximum number
		long max = 0;
		for(int i = 0 ; i < mcache.size() ; i++){
			if(max<Math.abs(mcache.get(i).longValue())){
				max = Math.abs(mcache.get(i).longValue());
			}
		}
		// do count sort
		for(long i = 1 ; i <= Math.abs(max);i*=10){
			countsort(i,test);
		}
	}

	private static int[] DoRadixSort(int[] value)
	{

		// split into minus and plus integers for radix sort
		mcache = new ArrayList<Long>();
		ArrayList<Long> pcache = new ArrayList<Long>();
		for(int i = 0 ; i < value.length ; i++){
			if(value[i]>=0) pcache.add((long)value[i]);
			else mcache.add((long)value[i]);
		}

		// do radix sort on minus values
		RadixSort(0);
		
		// append them to return array
		int i = 0;
		for( ; i < mcache.size();i++){
			value[i] = mcache.get(i).intValue(); 
		}

		// do radix sort on plus values
		mcache = new ArrayList<Long>();
		for(int k = 0 ; k < pcache.size();k++){
			mcache.add(pcache.get(k));
		}
		RadixSort(1);

		// append them to return array
		int rmp = i;
		for(; i<mcache.size()+rmp ; i++){
			value[i] = mcache.get(i-rmp).intValue();
		}
		return value;
	}
}
