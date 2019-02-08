#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;


int arr[] = { 1,2,3,4 };

void swap(int *a, int *b) {
	int tmp;
	tmp = *a;
	*a = *b;
	*b = tmp;
}

void print_arr(int size) {
	for (int i = 0; i < size; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
}

void permutation(int n, int r, int depth) {

	if (r == depth) {
		print_arr(depth);
		return;
	}

	for (int i = depth; i < n; i++) {
		swap(&arr[i], &arr[depth]);
		permutation(n, r, depth + 1);
		swap(&arr[i], &arr[depth]);
	}

}

int main() {
	permutation(sizeof(arr) / sizeof(int), 3, 0);
	while(1){}
	return 0;
}
