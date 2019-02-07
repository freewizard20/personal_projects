string csort(string s) {
	vector<int> count(26, 0);
	// go through and count
	for (int i = 0; i < s.size(); i++) {
		count[s[i] - 'a']++;
	}
	// make new string using count
	string ret;
	ret.reserve(s.size());
	for (int i = 0; i < 26; i++) {
		for (int j = 0; j < count[i]; j++) {
			ret.push_back('a' + i);
		}
	}
	return ret;
}

vector<vector<string>> anagrams(vector<string> * data) {
	// use inner hash table
	unordered_map<string, vector<string>> tmp;
	// go through data and sort string, find key and append at vector
	for (int i = 0; i < data->size(); i++) {
		string s = csort(data->at(i));
		auto it = tmp.find(s);
		if (it != tmp.end()) {
			it->second.push_back(data->at(i));
		}
		else {
			// if this anagram is new
			vector<string> ss;
			ss.push_back(data->at(i));
			tmp.insert(pair<string, vector<string>>(s, ss));
		}
	}
	// append all vectors to return vector
	vector<vector<string>> ret;
	for (auto it = tmp.begin(); it != tmp.end(); it++) {
		ret.push_back(it->second);
	}
	return ret;
}

int main() {
	vector<string> data = { "eat", "tea", "tan", "ate", "nat", "bat" };
	vector<vector<string>> ret = anagrams(&data);
	for (int i = 0; i < ret.size(); i++) {
		for (int j = 0; j < ret.at(i).size(); j++) {
			cout << ret.at(i).at(j) << " ";
		}
		cout << endl;
	}
	while(1){}
	return 0;
}
