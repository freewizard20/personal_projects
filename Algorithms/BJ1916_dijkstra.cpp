// extreamly fast 44ms algo(time limit : 500ms)

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <queue>
#include <unordered_map>
#include <climits>

using namespace std;

int main() {
	int nodes;
	int edges;
	scanf("%d", &nodes);
	scanf("%d", &edges);
	vector<vector<pair<int,int>>> graph(nodes, vector<pair<int,int>>());
	vector<int> dist(nodes, INT_MAX);
	int from, to, weight;
	for (int i = 0; i < edges; i++) {
		scanf("%d %d %d", &from, &to, &weight);
		from--;
		to--;
		graph[from].push_back(pair<int, int>(to, weight));
	}
	int start, end;
	scanf("%d %d", &start, &end);
	start--;
	end--;
	int x,y,z;
	priority_queue < pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> queue;
	queue.push(pair<int, int>(0,start));
	while (queue.size() != 0) {
		pair<int, int> curr = queue.top();
		y = curr.first;
		z = curr.second;
		queue.pop();
		if (dist[z] > y) {
			dist[z] = y;
			x = y;
			for (int i = 0; i < graph[z].size(); i++) {
				if (dist[graph[z][i].first] > x + graph[z][i].second) {
					queue.push(pair<int, int>(x + graph[z][i].second, graph[z][i].first));
				}
			}
		}
	}
	cout << dist[end] << endl;
	while(1){}
}
