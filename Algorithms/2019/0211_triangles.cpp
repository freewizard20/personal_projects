#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <algorithm>
#include <iomanip>

using namespace std;

int sam;

void solve(int m, vector<vector<int>> & graph, vector<int> & tmp) {
	if (m == 3) {

		// check if makes triangle
		if (graph[tmp[0]][tmp[1]] == 1 && graph[tmp[1]][tmp[2]] == 1 && graph[tmp[2]][tmp[0]] == 1) {
			sam++;
		}


		return;
	}

	int small = tmp.size() == 0 ? 0 : tmp.back() + 1;
	for (int i = small; i < graph.size(); i++) {
		tmp.push_back(i);
		solve(m + 1, graph, tmp);
		tmp.pop_back();
	}
}

int main() {
	int t;
	cin >> t;
	for (int z = 0; z < t; z++) {

		int n, m;
		cin >> n >> m;
		vector<vector<int>> graph(n, vector<int>(n, 0));
		for (int i = 0; i < m; i++) {
			int a, b;
			cin >> a >> b;
			graph[a - 1][b - 1] = 1;
			graph[b - 1][a - 1] = 1;
		}

		sam = 0;
		vector<int> tmp;
		solve(0, graph, tmp);
		cout << "#" << (z + 1) << " " << sam << endl;
	}
}
