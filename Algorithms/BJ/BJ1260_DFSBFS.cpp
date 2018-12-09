#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <queue>

using namespace std;

int graph[1000][1000];
int visited[1000];
int start, n, m;

void bfs(int curr) {
	queue<int> buffer;
	buffer.push(curr);
	while (buffer.size() != 0) {
		int t = buffer.front();
		buffer.pop();
		if (visited[t] == 0) {
			cout << t + 1 << " ";
			visited[t] = 1;
		}
		for (int i = 0; i < n; i++) {
			if (graph[t][i] == 1 && visited[i] == 0) {
				buffer.push(i);
			}
		}
	}
}

void dfs(int curr) {
	visited[curr] = 1;
	cout << curr+1 << " ";
	
	for (int i = 0; i < n; i++) {
		if (graph[curr][i] == 1 && visited[i] == 0) {
			dfs(i);
		}
	}
}

int main() {
	
	cin >> n >> m >> start;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			graph[i][j] = 0;
		}
		visited[i] = 0;
	}

	for (int i = 0; i < m; i++) {
		int one, two;
		cin >> one >> two;
		graph[one-1][two-1] = 1;
		
		graph[two-1][one-1] = 1;
	}

	dfs(start-1);
	
	for (int i = 0; i < n; i++) {
		visited[i] = 0;
	}
	cout << endl;
	bfs(start-1);
	
	while(1){}
}
