#include <iostream>
#include <vector>

using namespace std;

void dfs(int curr, vector<int> & visited, vector<vector<int>> & graph) {
	
	if (visited[curr] == 1) return;
	visited[curr] = 1;
	cout << curr << " ";

	for (int i = 0; i < graph.size(); i++) {
		if (graph[curr][i] == 1 && visited[i] == 0) {
			dfs(i, visited, graph);
		}
	}
}

int main() {

	vector<vector<int>> graph = { {0,1,1,0,0},{1,0,0,1,1},{1,0,0,1,0},{0,1,1,0,1},{0,1,0,1,0} };
	vector<int> visited(graph.size(), 0);
	dfs(0, visited, graph);

}
