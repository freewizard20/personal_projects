#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>

using namespace std;

int count(int N, unordered_set<int> curr, vector<vector<int>> & graph) {
	if (curr.size() == N) return 1;

	// pick new one
	int x;
	for (int i = 0; i < N; i++) {
		if (curr.find(i) == curr.end()) {
			x = i;
			curr.insert(i);
			break;
		}
	}

	// pick all available second ones and check availability
	int ret = 0;

	for (int i = 0; i < N; i++) {
	
		if (curr.find(i) == curr.end()) {
			if (graph[x][i] == 1) {
				curr.insert(i);
				ret += count(N, curr, graph);
				curr.erase(i);
			}
		}
	
	}

	return ret;
}

int main() {

	int T;
	cin >> T;
	for (int z = 0; z < T; z++) {

		int N, M;
		cin >> N >> M;
		vector<vector<int>> graph(N, vector<int>(N,0));
		for (int i = 0; i < M; i++) {
			int x, y;
			cin >> x >> y;
			graph[x][y] = 1;
			graph[y][x]=1;
		}
		cout << count(N, unordered_set<int>(), graph) << endl;
	}

}
