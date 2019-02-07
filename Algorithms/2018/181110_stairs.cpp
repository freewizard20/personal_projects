#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int n;
int board[10][10];
int time[10][2];
int people;
int lat[10][2];
vector<int> one;
vector<int> two;
int stairs[2][2];
int length[2];

int solve(int m) {
	cout << "solve " << m << endl;
	if (m == people) {
		// do simulation
		vector<int> tmp1 = one;
		vector<int> tmp2 = two;
		sort(one.begin(), one.end());
		sort(two.begin(), two.end());
		int it1 = 0;
		int it2 = 0;
		int time = 0;
		queue<int> ladone;
		queue<int> ladtwo;
		for (int i = 0; i < one.size(); i++) {
			cout << one[i] << " ";
		}
		cout << endl;
		for (int i = 0; i < two.size(); i++) {
			cout << two[i] << " ";
		}
		cout << endl;
		while (!(it1 == one.size() && it2 == two.size() && ladone.size()==0 && ladtwo.size()==0)) {
			cout << "time---" << endl;
			cout << time << endl;
			cout << it1 << endl;
			cout << it2 << endl;
			// unload queues
			while (ladone.size()!=0 && ladone.front() <= time) {
				cout << "pop ladder one : " << ladone.front() << endl;
				ladone.pop();
			}
			while (ladtwo.size()!=0 && ladtwo.front() <= time) {
				cout << "pop ladder two : " << ladtwo.front() << endl;
				ladtwo.pop();
			}

			// load queues
			while (it1<one.size() && one[it1] <= time && ladone.size()<3) {
				ladone.push(one[it1] + 1 + length[0]);
				it1++;
			}
			while (it2<two.size() && two[it2] <= time && ladtwo.size()<3) {
				ladtwo.push(two[it2] + 1 + length[1]);
				it2++;
			}

			time++;
		}

		one = tmp1;
		two = tmp2;
		cout << "result >>>> " << time-1 << endl;
		return time-1;
	}

	int ret = 9999999;

	// push to one
	int dir = abs(stairs[0][0] - lat[m][0]) + abs(stairs[0][1] - lat[m][1]);
	one.push_back(dir);
	ret = min(ret,solve(m + 1));
	one.pop_back();

	// push to two
	dir = abs(stairs[1][0] - lat[m][0]) + abs(stairs[1][1] - lat[m][1]);
	//cout << stairs[1][0] << " " << lat[m][0] << " " << stairs[1][1] << " " << lat[m][1] << endl;
	//cout << "dir two " << dir << endl;
	two.push_back(dir);
	ret = min(ret,solve(m + 1));
	two.pop_back();

	return ret;
}

int main() {

	int t;
	cin >> t;
	for (int z = 0; z < t; z++) {
		people = 0;
		int flag = 0;
		cin >> n;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cin >> board[i][j];
				if (board[i][j] == 1) {
					lat[people][0] = i;
					lat[people][1] = j;
					people++;					
				}
				if (board[i][j] >= 2) {
					length[flag] = board[i][j];
					stairs[flag][0] = i;
					stairs[flag][1] = j;
					flag++;
				}
			}
		}

		cout << "#" << (z + 1) << " " << solve(0) << '\n';

	}

}
