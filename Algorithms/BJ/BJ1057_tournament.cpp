#include <iostream>
#include <vector>

using namespace std;

int main() {

	int N, a, b;
	cin >> N >> a >> b;
	vector<int> players;
	for (int i = 1; i <= N; i++) {
		if (i == a || i == b) {
			players.push_back(-i);
		}
		else {
			players.push_back(i);
		}
	}

	int round = 1;
	while (true) {

		/*for (int i = 0; i < players.size(); i++) {
			cout << players[i] << " ";
		}
		cout << endl;*/

		if (players.size() == 2) {
			if (players[0] < 0 && players[1] < 0) {
				cout << round << endl;
				return 0;
			}
			else {
				cout << "-1" << endl;
				return 0;
			}
		}


		for (int i = 0; i < players.size(); i++) {
			if (i == players.size() - 1) break;
			if (players[i] < 0&&players[i+1]<0) {
				cout << round << endl;
				return 0;
			}
			else if(players[i]<0){
				//cout << "here " << i << endl;
				players.erase(players.begin() + i+1);
			}
			else if (players[i + 1] < 0) {
				//cout << "there " << i << endl;
				players.erase(players.begin() + i);
			}
			else {
				//cout << "erase " << i << endl;
				players.erase(players.begin() + i);
			}
		}

		round++;
	}

	return 0;

}
