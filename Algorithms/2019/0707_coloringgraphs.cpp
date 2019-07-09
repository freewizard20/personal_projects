#include <iostream>
#include <vector>

// from dailycodingproblem
// better need nicely coded answers to learn from
// code formatting, efficiency, and runnability needed
// might be great if greedy solution can be proved

/*
This problem was asked by Google.
Given an undirected graph represented as an adjacency matrix and an integer k, 
write a function to determine whether each vertex in the graph can be colored such 
that no two adjacent vertices share the same color using at most k colors.
*/

using namespace std;

bool isColoringDone(vector<int> & color) {
	bool ret = true;
	for (int i = 0; i < color.size(); i++) {
		if (color[i] == -1) ret = false;
	}
	return ret;
}

void dfs(int curr, vector<int> & color, vector<vector<int>> & graph, bool & ans) {
	if (ans == true) return;
	if (color[curr] != -1) return;
	if (isColoringDone(color)) ans = true;

	for (int i = 0; i < graph.size(); i++) {
		if (graph[i][curr] == 1 && color[i] == -1) {
			for (int j = 0; j < color.size(); j++) {
				color[curr] = j;
				dfs(i, color, graph, ans);
				color[curr] = -1;
			}
		}
	}
}

bool isColorable(int k, vector<vector<int>> & graph) {
	vector<int> color(k, -1);
	bool ans = 0;
	dfs(0, color, graph, ans);
	return ans;
}
