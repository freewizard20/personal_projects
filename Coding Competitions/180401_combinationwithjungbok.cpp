#include <stack>

using namespace std;

vector<vector<int>> findcombinations(int topick, vector<int> data, int startindex, vector<int> maker) {
	// terminate if no more to pick
	if (topick == 0) {
		vector<vector<int>> tmp;
		tmp.push_back(maker);
		return tmp;
	}
	// terminate if no reference remains
	if (startindex == data.size()){
		vector<vector<int>> tmp;
		return tmp;
	}
	vector<vector<int>> ret;
	int currfirst = startindex;
	for (int i = startindex; i < data.size(); i++) {
		// find distinct number sets and use first, send remaining to lower recursion
		if (i == data.size() - 1 || data[i] != data[i + 1]) {
			maker.push_back(data[i]);
			vector<vector<int>> tmp = findcombinations(topick - 1, data, currfirst + 1, maker);
			maker.pop_back();
			ret.insert(ret.end(), tmp.begin(), tmp.end());
			currfirst = i + 1;
		}
	}
	return ret;
}

int main() {
	vector<int> t = { 1,1,1,2,2,2,3,3,4,5,6 };
	vector<vector<int>> res = findcombinations(3, t, 0, vector<int>());
	for (int i = 0; i < res.size(); i++) {
		cout << "(";
		for (int j = 0; j < res.at(i).size(); j++) {
			cout << res.at(i).at(j) << " ";
		}
		cout << ")" << endl;
	}
	while(1){}
	return 0;
}
