#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>
#include <queue>
#include <unordered_set>

using namespace std;

int tk[1001];
int kim[1001];


int jup[1001];
int jung[1001];

int ai[21];
int bj[21];

int k;
int a, b;
int n, m;

int ja[21];
int jb[21];
int jat[21];
int jbt[21];

int main() {
	
	int t;
	cin >> t;
	for (int z = 0; z < t; z++) {
		for (int i = 0; i < 20; i++) {
			ja[i] = -9999;
			jb[i] = -9999;
			jat[i] = -9999;
			jbt[i] = -9999;
		}

		cin >> n >> m >> k >> a >> b;
		for (int i = 0; i < n; i++) {
			cin >> ai[i];
		}
		for (int i = 0; i < m; i++) {
			cin >> bj[i];
		}
		for (int i = 0; i < k; i++) {
			cin >> tk[i];
		}

		queue<int> jaq;
		queue<int> jbq;

		int time = 0;
		int numbering = 1;
		while (time <= 1000 || jaq.size() != 0 || jbq.size() != 0) {

			// unload worker
			for (int i = 0; i < m; i++) {
				if (jbt[i] != -9999) {
					jbt[i]--;
				}
				if (jbt[i] == 0) {
					jbt[i] = -9999;
					jb[i] = -9999;
				}
			}

			// unload jupsu
			for (int i = 0; i < n; i++) {
				if (jat[i] != -9999) {
					jat[i]--;
				}
				if (jat[i] == 0) {
					jat[i] = -9999;
					jbq.push(ja[i]);
					ja[i] = -9999;
				}
			}

			// fill worker
			for (int i = 0; i < m; i++) {
				if (jb[i] == -9999 && jbq.size() != 0) {
					jb[i] = jbq.front();
					jbq.pop();
					jung[jb[i]] = i;
					jbt[i] = bj[i];
				}
			}

			// fill first queue
			for (int i = 0; i < k; i++) {
				if (tk[i] == time) {
					kim[i] = numbering;
					jaq.push(numbering);
					numbering++;
				}
			}

			// fill jupsu
			for (int i = 0; i < n; i++) {
				if (ja[i] == -9999 && jaq.size() != 0) {
					ja[i] = jaq.front();
					jup[ja[i]] = i;
					jaq.pop();
					jat[i] = ai[i];
				}
			}
			
			/*cout << time << "---" << endl;
			for (int i = 0; i < n; i++) {
				cout << ja[i] << " ";
			}
			cout << endl;
			for (int i = 0; i < m; i++) {
				cout << jb[i] << " ";
			}
			cout << endl;*/

			time++;

		}

		int tot = 0;
		for (int i = 0; i <= k; i++) {
			if (jup[i] == a-1 && jung[i] == b-1) {
				tot += i;
			}
		}
		if (tot != 0) {
			cout << "#" << (z + 1) << " " << tot << '\n';
		}
		else {
			cout << "#" << (z + 1) << " " << "-1" << '\n';
		}
	}
	while(1){}
}
