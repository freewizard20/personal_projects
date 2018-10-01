#include <iostream>
#include <queue>


using namespace std;

pair<int, int> jp(int N, int K) {
	queue<int> kill;
	for (int i = 1; i <= N; i++) {
		kill.push(i);
	}
	// do simulation

	int count = 0;
	kill.pop();
	while (kill.size() != 2) {
		while (count < K - 1) {
			int tmp = kill.front();
			kill.pop();
			count++;
			kill.push(tmp);
		}
		kill.pop();
		count = 0;
	}
	int ret1 = kill.front();
	kill.pop();
	int ret2 = kill.front();
	if (ret1 < ret2) {
		return pair<int, int>(ret1, ret2);
	}
	else {
		return pair<int, int>(ret2, ret1);
	}
}

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int M, K;
		cin >> M >> K;
		auto it = jp(M,K);
		cout << it.first << " " << it.second << endl;
	}


}
