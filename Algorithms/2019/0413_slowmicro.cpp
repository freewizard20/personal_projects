#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int current;
int target;
int add;
int multiply;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	for (int z = 0; z < t; z++) {
		cin >> current >> target >> add >> multiply;
		if (current == target) {
			cout << "#" << (z + 1) << " " << 0 << endl;
		}
		queue<pair<long long, int>> q;
		vector<int> answers;
		q.push(pair<long long, int>(current, 0));
		while (q.size() != 0) {
			long long curr = q.front().first;
			int reps = q.front().second;
			q.pop();
			long long nextadd = curr + add;
			long long nextmul = curr * multiply;
			reps++;
			if (nextadd == target)	answers.push_back(reps);
			if (nextmul == target) 	answers.push_back(reps);
			if (nextadd < target) q.push(pair<long long, int>(nextadd, reps));
			if (nextmul < target && multiply != 1) q.push(pair<long long, int>(nextmul, reps));
		}
		if (answers.size() == 0) cout << "#" << (z + 1) << " " << -1 << endl;
		else {
			int min = 99999999;
			for (int i = 0; i < answers.size(); i++) {
				if (min > answers[i]) min = answers[i];
			}
			cout << "#" << (z + 1) << " " << min << endl;
		}
	}
}
