#include "stdafx.h"
#include <vector>
#include <iostream>
#include <unordered_map>
#include <map>
#include <queue>
#include <functional>
#include <stack>
#include <unordered_set>

using namespace std;

void DFS(vector<vector<int>> & graph, vector<bool> & visited, int target) {
	if (visited[target] == false) visited[target] = true;
	cout << "visiting " << target << endl;
	for (int i = 0; i < graph[target].size(); i++) {
		if (visited[graph[target][i]] == false) DFS(graph, visited, graph[target][i]);
	}
}

int findcomponents(vector<vector<int>> & graph) {
	vector<bool> visited(graph.size(), false);
	int count = 0;
	for (int i = 0; i < graph.size(); i++) {
		if (visited[i] == false) {
			count++;
			DFS(graph, visited, i);
		}
	}
	return count;
}

bool connected(vector<vector<int>> & graph, int i, int j) {
	vector<bool> visited(graph.size(), false);
	DFS(graph, visited, i);
	return visited[j];
}

void tDFS(vector<vector<int>> & graph, vector<bool> & visited, int target, stack<int> & buffer) {
	if (visited[target] == false) visited[target] = true;
	for (int i = 0; i < graph[target].size(); i++) {
		if (visited[graph[target][i]] == false) {
			tDFS(graph, visited, graph[target][i], buffer);
		}
	}
	buffer.push(target);
}

void topologicalsort(vector<vector<int>> & graph) {
	vector<bool> visited(graph.size(), false);
	stack<int> buffer;
	for (int i = 0; i < graph.size(); i++) {
		if (visited[i] == false) {
			tDFS(graph, visited, i, buffer);
		}
	}
	// print stack
	while (buffer.size() != 0) {
		cout << buffer.top() << " ";
		buffer.pop();
	}
	cout << endl;
}

bool iscycle(vector<vector<int>> & graph) {
	vector<bool> visited(graph.size(), false);
	stack<int> buffer;
	unordered_set<int> contains;
	for (int i = 0; i < graph.size(); i++) {
		if (visited[i] == false) {
			buffer.push(i);
			contains.insert(i);
			while (buffer.size() != 0) {
				int curr = buffer.top();
				if (visited[curr] == false) visited[curr] = true;
				buffer.pop();
				// go through adjacent elements
				for (int j = 0; j < graph[curr].size(); j++) {
					// check if element is in track. if so, return true
					// because the element comes from there to here then
					// here to there making a cycle
					if (contains.find(graph[curr][j]) != contains.end()) {
						cout << i << " " << curr << " " << graph[curr][j] << endl;
						return true;
					}
					if (visited[graph[curr][j]] == false) {
						buffer.push(graph[curr][j]);
						contains.insert(graph[curr][j]);
					}
				}
			}
			contains.clear();
		}
	}
	return false;
}

bool cDFS(vector<vector<int>> & graph, vector<bool> & visited, int target, int parent) {
	visited[target] = true;
	// go to adjacent nodes. if visited and not parent, return true
	bool ret = false;
	for (int i = 0; i < graph[target].size(); i++) {
		// self cycle also considered cycle here.
		// if not wanted, do graph[target][i]!=target here
		if (visited[graph[target][i]] == true && graph[target][i] != parent&&parent != -1) {
			cout << "found at " << target << " " << parent << " " << graph[target][i] << endl;
			return true;
		}
		if (visited[graph[target][i]] == false) {
			ret |= cDFS(graph, visited, graph[target][i], target);
		}
	}
	return ret;
}

bool iscycle2(vector<vector<int>> & graph) {
	vector<bool> visited(graph.size(), false);
	// start from every unvisited cycle
	for (int i = 0; i < graph.size(); i++) {
		bool ret;
		if (visited[i] == false)
			ret = cDFS(graph, visited, i, -1);
		if (ret == true) return true;
	}
}

void addedge(vector<vector<int>> & graph, int i, int j) {
	graph[i].push_back(j);
	graph[j].push_back(i);
}

void IDFS(vector<vector<int>> & graph, vector<bool> & visited, stack<int> & res, int target) {
	visited[target] = true;
	for (int i = 0; i < graph[target].size(); i++) {
		if (visited[graph[target][i]] == false) {
			IDFS(graph, visited, res, graph[target][i]);
		}
	}
	res.push(target);
}

vector<char> language(vector<string> & data) {
	// make char vector
	vector<vector<int>> graph(26, vector<int>());
	// parse data to fill char graph
	for (int i = 0; i < data.size() - 1; i++) {
		// compare strings to find char priority
		int curr = 0;
		while (curr < data[i].size() && curr < data[i + 1].size()) {
			if (data[i][curr] == data[i + 1][curr]) curr++;
			else {
				graph[data[i][curr] - 'a'].push_back(data[i + 1][curr] - 'a');
				break;
			}
		}
	}
	// do topological sort
	stack<int> res;
	vector<bool> visited(26, false);
	for (int i = 0; i < 26; i++) {
		if (visited[i] == false) {
			IDFS(graph, visited, res, i);
		}
	}
	vector<char> ret;
	while (res.size() != 0) {
		ret.push_back(res.top() + 'a');
		res.pop();
	}
	// validate cycle
	for (int i = 0; i < 26; i++) {
		for (int j = i + 1; j < 26; j++) {
			for (int k = 0; k < graph[ret[j] - 'a'].size(); k++) {
				if (graph[ret[j] - 'a'][k] == ret[i] - 'a') return vector<char>(1, 0);
			}
		}
	}
	return ret;
}

bool findpath(vector<vector<int>> & board) {
	// make graph
	vector<vector<int>> graph(board.size()*board[0].size(), vector<int>());
	int count = 0;
	for (int i = 0; i < board.size(); i++) {
		for (int j = 0; j < board[0].size(); j++) {
			// connect adjacent nodes
			vector<vector<int>> dir = { {-1,0},{1,0},{0,1},{0,-1} };
			for (int k = 0; k < 4; k++) {
				if (i + dir[k][0] >= 0 && i + dir[k][0] < board.size() && j + dir[k][1] >= 0 && j + dir[k][1] <= board[0].size() && board[i + dir[k][0]][j + dir[k][1]] != -1) {
					if (k >= 2) addedge(graph, count, count + dir[k][2]);
					else addedge(graph, count, count + board[0].size()*dir[k][1]);
				}
			}
			count++;
		}
	}
	// do DFS
	vector<bool> visited(graph.size(), false);
	stack<int> buffer;
	buffer.push(0);
	while (buffer.size() != 0) {
		int curr = buffer.top();
		buffer.pop();
		visited[curr] = true;
		for (int i = 0; i < graph[curr].size(); i++) {
			// return when end met
			if (graph[curr][i] == graph.size() - 1) return true;
			
			if (visited[graph[curr][i]] == false) {
				buffer.push(graph[curr][i]);
			}
		}
	}
	return false;
}

int main() {
	vector<string> data = { "dictionary","english","is","ordered","ordinary","this"};
	vector<char> res = language(data);
	if (res.size() == 1) cout << "INVALID HYPOTHESIS" << endl;
	else {
		for (char x : res) cout << x;
	}
	cout << endl;
	while(1){}
	vector<vector<int>> graph(10, vector<int>());
	graph[5].push_back(7);
	graph[5].push_back(6);
	graph[6].push_back(0);
	graph[7].push_back(1);
	graph[0].push_back(1);
	graph[1].push_back(2);
	graph[9].push_back(2);
	graph[5].push_back(8);
	graph[8].push_back(3);
	graph[2].push_back(3);
	graph[3].push_back(4);
	//graph[4].push_back(5);
	topologicalsort(graph);
	cout << iscycle(graph) << endl;
	vector<vector<int>> graph2(4, vector<int>());
	//addedge(graph2, 0, 1);
	addedge(graph2, 0, 2);
	addedge(graph2, 1, 2);
	addedge(graph2, 2, 0);
	addedge(graph2, 2, 3);
	addedge(graph2, 3, 3);
	cout << iscycle2(graph2) << endl;
	while(1){}
	return 0;
}
