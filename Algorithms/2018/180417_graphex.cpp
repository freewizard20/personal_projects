#include "stdafx.h"
#include <iostream>
#include <vector>
#include <queue>
#include <functional>

using namespace std;

void getEuler(int here, vector<int> & res, vector<vector<int>> & graph) {
	cout << "called " << here << endl;
	for (int there = 0; there < graph[0].size(); there++) {
		while (graph[here][there] > 0) {
			graph[here][there]--;
			graph[there][here]--;
			getEuler(there, res, graph);
		}
	}
	res.push_back(here);
}

int distance(vector<vector<int>> & graph, int i, int j) {
	vector<int> dist(graph.size(), -1);
	vector<bool> visitedi(graph.size(), false);
	vector<bool> visitedj(graph.size(), false);
	dist[i] = 0;
	dist[j] = 0;
	queue<int> iq;
	queue<int> jq;
	iq.push(i);
	jq.push(j);
	while (iq.size() != 0 && jq.size() != 0) {
		int curri = iq.front();
		int currj = jq.front();
		iq.pop();
		jq.pop();
		// do left
		for (int i = 0; i < graph[curri].size(); i++) {
			if (visitedj[graph[curri][i]] == true) {
				// two BFS met
				return dist[curri] + dist[graph[curri][i]]+1;
			}
			else if(visitedi[graph[curri][i]]==false){
				// mark adjacent nodes and enqueue
				dist[graph[curri][i]] = dist[curri] + 1;
				visitedi[graph[curri][i]] = true;
				iq.push(graph[curri][i]);
			}
		}
		// do right
		for (int i = 0; i < graph[currj].size(); i++) {
			if (visitedi[graph[currj][i]] == true) {
				// two BFS met
				return dist[currj] + dist[graph[currj][i]]+1;
			}
			else if (visitedj[graph[currj][i]] == false) {
				// mark adjacent nodes and enqueue
				dist[graph[currj][i]] = dist[currj] + 1;
				visitedj[graph[currj][i]] = true;
				jq.push(graph[currj][i]);
			}
		}
	}
	// not met
	return 99999;
}

void addedge(vector<vector<int>> & graph, int i, int j) {
	graph[i].push_back(j);
	graph[j].push_back(i);
}

void wedge(vector < vector<pair<int, int>>> & graph, int i, int j,int w) {
	graph[i].push_back(pair<int, int>(j, w));
	graph[j].push_back(pair<int, int>(i, w));
}

vector<int> dijkstra(vector<vector<pair<int, int>>>&graph, int i) {
	vector<int> dir(graph.size(), INT_MAX);
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
	dir[i] = 0;
	q.push(pair<int, int>(0,i));
	while (q.size() != 0) {
		if (dir[q.top().second] < q.top().first) { 
			q.pop(); 
			continue; 
		}
		int curr = q.top().second;
		int cdis = q.top().first;
		q.pop();
		for (int i = 0; i < graph[curr].size(); i++) {
			if (dir[graph[curr][i].first] > cdis + graph[curr][i].second){
				dir[graph[curr][i].first] = cdis + graph[curr][i].second;
				q.push(pair<int, int>(dir[graph[curr][i].first], graph[curr][i].first));
			}
		}
	}
	return dir;
}

int main() {
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
	vector<int> rez = dijkstra(graph3, 0);
	for (int x : rez) cout << x << " ";
	cout << endl;
	while(1){}
	vector<vector<int>> graph2(10, vector<int>());
	addedge(graph2, 0, 2);
	addedge(graph2, 2, 4);
	addedge(graph2, 4, 6);
	addedge(graph2, 8, 9);
	addedge(graph2, 6, 9);
	addedge(graph2, 3, 5);
	addedge(graph2, 5, 6);
	addedge(graph2, 0, 7);
	addedge(graph2, 0, 3);
	cout << distance(graph2, 0, 9) << endl;
	while(1){}
	vector<vector<int>> graph(5, vector<int>(5, 0));
	graph[0][4] = 1;
	graph[4][0] = 1;
	graph[3][4] = 1;
	graph[4][3] = 1;
	graph[2][3] = 1;
	graph[3][2] = 1;
	graph[0][1] = 1;
	graph[1][0] = 1;
	graph[1][2] = 1;
	graph[2][1] = 1;
	graph[1][4] = 2;
	graph[4][1] = 2;
	vector<int> res;
	getEuler(1, res, graph);
	for (int x : res) cout << x << " ";
	cout << endl;
	while (1) {}
	return 0;
}
