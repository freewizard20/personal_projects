#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

void merge(vector<int> & tmp, int low, int r, int high) {

	int n1 = r - low + 1;
	int n2 = high - r;
	vector<int> arr1;
	vector<int> arr2;
	for (int i = 0; i < n1; i++) {
		arr1.push_back(tmp[low + i]);
	}
	for (int i = 0; i < n2; i++) {
		arr2.push_back(tmp[r + 1 + i]);
	}
	arr1.push_back(99999999);
	arr2.push_back(99999999);
	int i = 0;
	int j = 0;
	for (int k = low; k <= high; k++) {
		if (arr1[i] <= arr2[j]) {
			tmp[k] = arr1[i];
			i++;
		}
		else {
			tmp[k] = arr2[j];
			j++;
		}
	}

}

void mergesort(vector<int> &tmp, int low, int high) {
	if (low < high) {

		int mid = (low + high) / 2;
		mergesort(tmp, low, mid);
		mergesort(tmp, mid + 1, high);
		merge(tmp, low, mid, high);

	}
}

int main() {

	vector<int> tmp = { 5,1,3,2,4 };
	mergesort(tmp, 0, 4);
	for (int i = 0; i < 5; i++) {
		cout << tmp[i] << " ";
	}
	while(1){}

}
