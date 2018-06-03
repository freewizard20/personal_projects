#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <queue>
#include <unordered_map>

using namespace std;

int main() {
	// get inputs and make graph
	int nodes;
	int edges;
	scanf("%d %d", &nodes, &edges);
	unordered_map<int, int> locator;
	vector < vector<pair<int, int>>> graph(nodes, vector < pair<int, int>>());
	int numbering = 0;
	for (int i = 0; i < edges; i++) {
		int from;
		int to;
		int weight;
		scanf("%d %d %d", &from, &to, &weight);
		auto it = locator.find(from);
		if (it != locator.end()) {
			from = it->second;
		}
		else {
			locator.insert(pair<int, int>(from, numbering));
			from = numbering;
			numbering++;
		}
		it = locator.find(to);
		if (it != locator.end()) {
			to = it->second;
		}
		else {
			locator.insert(pair<int, int>(to, numbering));
			to = numbering;
			numbering++;
		}
		graph[from].push_back(pair<int, int>(to, weight));
		graph[to].push_back(pair<int, int>(from, weight));
	}

	// do prim mst
	vector<int> included(nodes, 0);
	priority_queue < pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> queue;
	vector<pair<int, int>> total;
	long long sum = 0LL;

	for (int k = 0; k < nodes; k++) {
		if (included[k] == 0) {
			included[k] = 1;
			for (int i = 0; i < graph[k].size(); i++) {
				queue.push(pair<int, pair<int, int>>(graph[k][i].second, pair<int, int>(k, graph[k][i].first)));
			}

			// go through all candidates
			while (queue.size() != 0) {
				pair<int, pair<int, int>> curr = queue.top();
				queue.pop();
				if (included[curr.second.second] == 0) {
					included[curr.second.second] = 1;
					total.push_back(pair<int, int>(curr.second.first, curr.second.second));
					sum += curr.first;
					for (int i = 0; i < graph[curr.second.second].size(); i++) {
						if(included[graph[curr.second.second][i].first]==0)
							queue.push(pair<int, pair<int, int>>(graph[curr.second.second][i].second, pair<int, int>(curr.second.second, graph[curr.second.second][i].first)));
					}
				}
			}
		}
	}
	cout << sum << endl;
}
