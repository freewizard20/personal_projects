# include <iostream>
# include <vector>
# include <unordered_set>

using namespace std;

void permutation(int n, int k, vector<int> buffer) {
	if (k == 0) {
		for (int i = 0; i < buffer.size(); i++) {
			cout << buffer[i] << " ";
		}
		cout << endl;
		return;
	}

	int min = buffer.empty()? 0 : buffer.back() + 1;

	for (int i = min; i < n; i++) {
		buffer.push_back(i);
		permutation(n, k - 1, buffer);
		buffer.pop_back();
	}
}

void combination(int n, int k, vector<int> buffer, unordered_set<int> set) {
	if (k == 0) {
		for (int i = 0; i < buffer.size(); i++) {
			cout << buffer[i] << " ";
		}
		cout << endl;
		return;
	}

	for (int i = 0; i < n; i++) {
		if (set.find(i) == set.end()) {
			set.insert(i);
			buffer.push_back(i);
			combination(n, k - 1, buffer, set);
			buffer.pop_back();
			set.erase(i);
		}
	}
}

void rotation(int n, int k, vector<int> buffer) {
	if (k == 0) {
		for (int i = 0; i < buffer.size(); i++) {
			cout << buffer[i] << " ";
		}
		cout << endl;
		return;
	}

	for (int i = 0; i < n; i++) {
		buffer.push_back(i);
		rotation(n, k - 1, buffer);
		buffer.pop_back();
	}
}

int main() {

	permutation(5, 3, vector<int>());
	combination(5, 3, vector<int>(), unordered_set<int>());
	rotation(5, 3, vector<int>());

	while(1){}

}
