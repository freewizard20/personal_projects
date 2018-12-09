#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>
#include <queue>

using namespace std;

int n,m;
int arr[100001];

int main() {
	
	for (int i = 0; i < 100001; i++) {
		arr[i] = -1;
	}
	
	cin >> n >> m;
	queue<int> buffer;
	if (n != m) {
		buffer.push(n);
		arr[n] = 0;
	}
	int ans = 0;
	while (buffer.size() != 0) {
		int it = buffer.front();
		buffer.pop();

		int curr = it + 1;
		if (curr == m) {
			ans = arr[it] + 1;
			break;
		}
		else if(curr<=100000 && curr>=0&&arr[curr]==-1){
			arr[curr] = arr[it] + 1;
			buffer.push(curr);
		}

		curr = it - 1;
		if (curr == m) {
			ans = arr[it] + 1;
			break;
		}
		else if (curr <= 100000 && curr >= 0 && arr[curr] == -1) {
			arr[curr] = arr[it] + 1;
			buffer.push(curr);
		}

		curr = it * 2;
		if (curr == m) {
			ans = arr[it] + 1;
			break;
		}
		else if (curr <= 100000 && curr >= 0 && arr[curr] == -1) {
			arr[curr] = arr[it] + 1;
			buffer.push(curr);
		}
	}

	cout << ans << endl;
}
