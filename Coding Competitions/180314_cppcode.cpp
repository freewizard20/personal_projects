// ConsoleApplication1993.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
#include <vector>
#include <cstdlib>
#include <iostream>
#include <ctime>
#include <list>
//#include <iterator>

using namespace std;

int bsearch(vector<int>  ref, int num,int low,int high);
int func(vector<int> & ref);
int func2(int* ref2);
int solve(int N);

int main() {
	int M;
	cin >> M;
	for (int z = 0; z < M; z++) {
		int N;
		cin >> N;
		cout << "#" << (z + 1) << " " << solve(N);
	}
}

int solve(int N) {
	if (N < 10) {
		return N;
	}
	int tmp = N;
	int total = 0;
	while (tmp != 0) {
		total = total + tmp % 10;
		tmp = tmp / 10;
	}
	return solve(total);
}

int main12() {
	int * arr = new int[10];
	for (int i = 0; i < 11; i++) {
		arr[i] = i;
	}
	func2(arr);
	for (int i = 0; i < 11; i++){
		cout << arr[i] << endl;
	}
	while (1) {}
	return 0;
}

int func2(int * ref) {
	ref[0] = 1;
	return 0;
}

int main11() {
	vector<int> * ar;
	ar = new vector<int>[10];
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < i; j++) {
			ar[i].push_back(j);
		}
	}
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < ar[i].size(); j++) {
			cout << ar[i].at(j) << " ";
		}
		cout << endl;
	}
	while (1) {}
}

int main10() {
	vector<int> ar = { 1,2,3,4,5 };
	auto ptr = ar.begin();
	auto ftr = ar.end();
	cout << *ar.begin() << endl;
	cout << *ptr << " " << *(ftr--) << endl;
	auto it = next(ptr, 3);
	auto it2 = prev(ftr, 1);
	cout << *it << " " << *it2 << endl;
	while (1) {}
	return 0;
}

int main9() {
	vector<int> ar = { 1,2,3,4,5 };
	vector<int>::iterator ptr = ar.begin();
	advance(ptr, 3);
	cout << *ptr << " " << endl;
	while (1) {}
	return 0;
}

int main8() {
	vector<int> vect;
	for (int i = 0; i < 10; i++) {
		vect.push_back(i);
	}
	for (vector<int>::iterator cit = vect.begin(); cit != vect.end(); cit++) {
		cout << *cit;
	}
	while (1) {}
	return 0;
}

class Graph {
	int V;
	list<int> * adj;
	void DFSUtil(int v, bool visited[]);
public:
	Graph(int V);
	void addEdge(int v, int w);
	void DFS(int v);
};

Graph::Graph(int V) {
	this->V = V;
	adj = new list<int>[V];
}

void Graph::addEdge(int v, int w) {
	adj[v].push_back(w);
}

void Graph::DFSUtil(int v, bool visited[]) {
	visited[v] = true;
	cout << v << " ";
	list<int>::iterator i;
	for (i = adj[v].begin(); i != adj[v].end(); i++)
		if (!visited[*i])
			DFSUtil(*i, visited);
}

void Graph::DFS(int v) {
	bool *visited = new bool[V];
	for (int i = 0; i < V; i++) {
		visited[i] = false;
	}
	DFSUtil(v, visited);
}

int main7() {
	Graph g(4);
	g.addEdge(0, 1);
	g.addEdge(0, 2);
	g.addEdge(1, 2);
	g.addEdge(2, 0);
	g.addEdge(2, 3);
	g.addEdge(3, 3);
	cout << "DFS traversal" << endl;
	g.DFS(2);
	while (1) {}
	return 0;
}

int main6() {
	vector<int> ref;
	for (int i = 0; i < 10; i++) {
		ref.push_back(10);
	}
	cout << ref.size() << endl;
	while (1) {  }
	return 0;
}

int main5() {
	vector<int> ref;
	for (int i = 0; i < 10; i++) {
		ref.push_back(i);
	}
	cout << ref.size() << endl;
	cout << func(ref) << endl;
	cout << ref.size() << endl;
	while(1){}
	return 0;
}

int func(vector<int> & ref) {
	int total = 0;
	for (int i = 0; i < ref.size(); i++) {
		total = total + ref.at(i);
	}
	ref.push_back(100);
	return total;
}

int main4() {
	vector<int> ref;
	for (int i = 0; i < 15; i = i + 2) {
		ref.push_back(i);
	}
	cout << bsearch(ref, 14, 0, ref.size()-1) << endl;
	while (1) {}
	return 0;
}

int main3() {
	time_t result = time(NULL);
	cout << result << endl;
	cout << asctime(localtime(&result)) << endl;
	while (1) {}
	return 0;
}


int main2()
{
	srand(time(NULL));
	vector<int> sample;
	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		sample.push_back(i);
	}
	vector<int> result;
	for (int i = N; i > 0; i--) {
		int target = rand() % i;
		result.push_back(sample.at(target));
		sample.erase(sample.begin() + target);
	}

	for (int i = 0; i < N; i++) {
		int flag = 0;
		for (int j = i-1; j >= 0; j--) {
			if (result.at(j) < result.at(i)) {
				cout << "swap " << i << " and " << j << endl;
				result.insert(result.begin() + j+1, result.at(i));
				result.erase(result.begin() + i + 1);
				flag = 1;
				break;
			}
		}
		if (flag == 0) {
			result.insert(result.begin(), result.at(i));
			result.erase(result.begin() + i + 1);
		}
	}

	for (int i = 0; i < N+1; i++) {
		cout << result.at(i) << endl;
	}
	while (1) {}
    return 0;
}

int bsearch(vector<int>  ref, int num,int low, int high) {
	if (low == high) {
		if (ref.at(low) == num) {
			return low;
		}
		else {
			return -1;
		}
	}
	int mid = (low + high) / 2;
	int bl = bsearch(ref, num, low, mid);
	int br = bsearch(ref, num, mid + 1, high);
	if (bl != -1) {
		return bl;
	}
	if (br != -1) {
		return br;
	}
	return -1;
}

