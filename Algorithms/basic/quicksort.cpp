#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int partition(vector<int> &a, int p, int r);

void quicksort(vector<int> & a, int p, int r) {
	if (p < r) {
		int q = partition(a, p, r);
		quicksort(a, p, q - 1);
		quicksort(a, q + 1, r);
	}
}

int partition(vector<int> & a, int p, int r) {
	int x = a[r];
	int i = p - 1;
	for (int j = p; j < r; j++) {
		if (a[j] <= x) {
			i = i + 1;
			swap(a[i], a[j]);
		}
	}
	swap(a[i + 1], a[r]);
	return i + 1;
}

int main() {

	vector<int> tmp = { 4,3,2,1,5 };
	quicksort(tmp, 0, 4);
	for (int i = 0; i < tmp.size(); i++) {
		cout << tmp[i] << " ";
	}
	while (1){}

}
