#include "stdafx.h"
#include <vector>
#include <queue>
#include <iostream>
#include <functional>

using namespace std;

vector<pair<int,vector<int>>> dijkstra(vector<vector<pair<int, int>>> & graph, int start) {
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
	vector<pair<int,vector<int>>> dist(graph.size(), pair<int,vector<int>>(INT_MAX,vector<int>()));
	dist[start].first = 0;
	dist[start].second.push_back(start);
	q.push(pair<int, int>(dist[start].first, start));
	while (q.size() != 0) {
		auto it = q.top();
		int currd = it.first;
		int curr = it.second;
		q.pop();
		if (currd > dist[curr].first) continue;
		// update adjacent elements
		for (int i = 0; i < graph[curr].size(); i++) {
			int newdist = currd + graph[curr][i].second;
			if (dist[graph[curr][i].first].first > newdist ) {
				dist[graph[curr][i].first].first = newdist;
				vector<int> tmp = dist[curr].second;
				tmp.push_back(graph[curr][i].first);
				dist[graph[curr][i].first].second=tmp;
				q.push(pair<int, int>(newdist, graph[curr][i].first));
			}
		}
	}
	return dist;
}

void wedge(vector < vector<pair<int, int>>> & graph, int i, int j, int w) {
	graph[i].push_back(pair<int, int>(j, w));
	graph[j].push_back(pair<int, int>(i, w));
}

double findmin(vector<vector<pair<int, double>>> & graph) {
	vector<double> dist(graph.size(), 999999999);
	priority_queue<pair<double, int>, vector<pair<double, int>>, greater<pair<double, int>>> q;
	dist[0] = 1;
	q.push(pair<double, int>(1, 0));
	while (q.size() != 0) {
		int curr = q.top().second;
		double currd = q.top().first;
		q.pop();
		if (currd > dist[curr]) continue;
		// check adjacent elements
		for (int i = 0; i < graph[curr].size(); i++) {
			int n = graph[curr][i].first;
			double nd = graph[curr][i].second;
			if (dist[n] > currd*nd) {
				dist[n] = currd * nd;
				q.push(pair<double, int>(dist[n], n));
			}
		}
	}
	return dist[graph.size() - 1];
}

int main() {
	vector<vector<pair<int, double>>> graph(7, vector<pair<int, double>>());
	graph[0].push_back(pair<int, double>(1, 1.3));
	graph[0].push_back(pair<int, double>(2, 1.1));
	graph[0].push_back(pair<int, double>(3, 1.24));
	graph[3].push_back(pair<int, double>(4, 1.17));
	graph[3].push_back(pair<int, double>(5, 1.24));
	graph[3].push_back(pair<int, double>(1, 2));
	graph[1].push_back(pair<int, double>(2, 1.31));
	graph[1].push_back(pair<int, double>(2, 1.26));
	graph[1].push_back(pair<int, double>(4, 1.11));
	graph[1].push_back(pair<int, double>(5, 1.37));
	graph[5].push_back(pair<int, double>(4, 1.24));
	graph[4].push_back(pair<int, double>(6, 1.77));
	graph[5].push_back(pair<int, double>(6, 1.11));
	graph[2].push_back(pair<int, double>(6, 1.2));
	cout << findmin(graph) << endl;
	while(1){}
	vector < vector<pair<int, int>>> graph3(7, vector<pair<int, int>>());
	wedge(graph3, 0, 1, 5);
	wedge(graph3, 0, 2, 1);
	wedge(graph3, 2, 3, 2);
	wedge(graph3, 3, 4, 5);
	wedge(graph3, 1, 3, 1);
	wedge(graph3, 1, 5, 3);
	wedge(graph3, 1, 6, 3);
	wedge(graph3, 5, 6, 2);
	wedge(graph3, 3, 5, 3);
	vector<pair<int, vector<int>>> res = dijkstra(graph3, 0);
	for (int i = 0; i < res.size(); i++) {
		vector<int> tmp = res[i].second;
		cout << i << "th node min distance : " << res[i].first << endl;
		cout << "path : ";
		for (int x : tmp) cout << x << " ";
		cout << endl;
	}
	while(1){}
	return 0;
}
