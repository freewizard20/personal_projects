#include <fstream>
#include <iostream>
#include <cstdlib>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <string>
#include <chrono>
#include <iomanip>
#include <algorithm>

using namespace std;

/* rdselect program
* goes through array to check if given int is kth smallest number.
* prints result.
*/

int detfindKthelement(vector<int> & target, int K, int low, int high);

int fib(int n) {
	if (n <= 1) return 1;
	return fib(n - 1) + fib(n - 2);
}

// basic swapper function with reference variables
void swap(int &a, int &b) {
	int tmp = a;
	a = b;
	b = tmp;
}

// partition array by end element
int partition(vector<int> & target, int low, int high) {
	int curr = low;
	for (int i = low; i < high; i++) {
		if (target[i]<=target[high]) {
			swap(target[i], target[curr]);
			curr++;
		}
	}
	swap(target[curr], target[high]);
	return curr;
}

// pick a random element and use it as partition by swapping it to last
int randompartition(vector<int> & target, int low, int high) {
	if (low != high) {
		int pickarandom = rand() % (high - low) + low;
		swap(target[pickarandom], target[high]);
	}
	return partition(target, low, high);
}

// random select function
int randomfindKthelement(vector<int> & target, int K, int low, int high) {
	int where = randompartition(target, low, high);
	if (where<K - 1) return randomfindKthelement(target, K, where + 1, high);
	else if (where == K - 1) return target[where];
	else return randomfindKthelement(target, K, low, where - 1);
}

//bubble sort as shifting whole array every time may consume time
void bubblesort(vector<int> & target, int low, int high) {
	for (int i = low; i <= high; i++) {
		for (int j = i + 1; j <= high; j++) {
			if (target[i]>target[j]) swap(target[i], target[j]);
		}
	}
}

void insertsort(vector<int> &target, int low, int high) {
	for (int i = low; i <= high; i++) {
		int tmp = target[i];
		for (int j = i - 1; j >= low; j--) {
			if (target[j] >= tmp) {
				target[j + 1] = target[j];
			}
			else {
				target[j+1] = tmp;
				break;
			}
			if (j == low) target[low] = tmp;
		}
	}
}

int findmedian(vector<int> & target, int low, int high) {
	insertsort(target, low, high);
	return target[(low + high) / 2];
}

// deterministic selection algorithm
int detpartition(vector<int> & target, int low, int high) {
	if (target.size() == 1) return low;
	vector<int> medians;

	// make a median array from medians of 5
	medians.reserve((high - low + 1) / 5);
	for (int i = 0; i < (high - low + 1) / 5; i++) {
		medians.push_back(findmedian(target, low + 5 * i, low + 5 * i + 4));
		if (i == (high - low + 1) / 5 - 1) {
			medians.push_back(findmedian(target, low + 5 * i + 5, high));
		}
	}
	if ((high - low + 1) / 5 == 0) medians.push_back(findmedian(target, low, high));

	// find the medians of medians
	int meds = detfindKthelement(medians, medians.size() / 2 + 1, 0, medians.size() - 1);

	// find the meds in target and swap with back
	for (int i = low; i <= high; i++) {
		if (target[i] == meds) {
			swap(target[i], target[high]);
			break;
		}
	}

	return partition(target, low, high);

}

// deterministic select fundtion
int detfindKthelement(vector<int> & target, int K, int low, int high) {
	int where = detpartition(target, low, high);
	if (where == K - 1) return target[where];
	else if (where<K - 1) return detfindKthelement(target, K, where + 1, high);
	else return detfindKthelement(target, K, low, where - 1);
}

// printing function
void printer(int flag, long long time, int found, int K) {
	if (flag == 0) {
		cout << "[Randomized select result]" << endl;
	}
	else {
		cout << "[Derterministic select result]" << endl;
	}
	cout << K << "th smallest element : " << found << endl;
	cout << "Program running time : ";
	if (time > 1000000000) cout << ((double)time / (double)1000000000) << " seconds" << endl;
	else if (time >1000) cout << ((double)time / (double)1000000) << " msecs" << endl;
	else cout << time << " nanoseconds" << endl;
}


int main(int argc, char ** argv) {
	srand(time(NULL));
	// read the arguments
	int K =  atoi(argv[1]);
	ifstream data(argv[2]);

	// load the data into memory
	vector<int> book;
	while (!data.eof()) {
		int t;
		data >> t;
		// to prevent reading last element twice
		if (data.eof()) break;
		book.push_back(t);
	}
	data.close();
	// get time interval
	int small = 0;
	int same = 0;
	int ref = 51;
	for (int i = 0; i < book.size(); i++) {
		if (book[i] < ref) small++;
		if (book[i] == ref) same++;
	}
	//cout << small << " " << small + same << endl;
	vector<int> book2 = book;
	auto start = chrono::high_resolution_clock::now();
	int randres = randomfindKthelement(book, K, 0, book.size() - 1);
	auto end = chrono::high_resolution_clock::now();
	printer(0, (end - start).count(), randres, K);
	auto start2 = chrono::high_resolution_clock::now();
	int detres = detfindKthelement(book2, K, 0, book.size() - 1);
	auto end2 = chrono::high_resolution_clock::now();
	printer(1, (end2 - start2).count(), detres, K);
}
