pair<int,int> longestpalindrome(string s){
	currmax = 0;
	pair<int,int> currret;
for(int i = 0 ; i < s.size() ; i++){
		// expand from here until not palindrome
	for(int j = 0 ; j < 2 ; j++){
		int head = i-1;
		int tail = i+1;
		int blength = 1;
		while(head>=0 && tail < s.size() && s[head]==s[tail]){
			blength+=2;
			head--;
			tail++;
		}
		if(blength>currmax){
			currmax = blength;
			currret = pair<int,int>(head+1,tail-1);
		}
		// if next index is same, do a even number palindrome check
		if(i!=s.size()-1 && s[i]==s[i+1]){
			head = i-1;
			tail = i+2;
			blength = 2;
			while(head>=0&&tail<s.size() && s[head]==s[tail]){
				blength+=2;
				head--;
				tail++;
			}
		if(blength > currmax){
			currret = pair<int,int>(head+1,tail-1);
			currmax = blength;
		}
	}
	return currret;
}

void removeduplicates(string & s, int curr){
	
	// base case
if(curr==s.size()) return;
	
	// general case
	if(s[curr]==s[curr+1]) {
s.erase(s.begin()+curr);
		// s’s length is reduced by one, therefore curr indexing next element
removeduplicates(s,curr);
	}else{
		removeduplicates(s,curr+1);

}


bool canrotate(const string & s, const string & t){
	// generate rotated strings
	string left = s;
	string right = s;
	for(int i = 0 ; i < 2 ; i++){
left+=left[0];
	left.erase(left.begin());
	right.insert(right.begin(),*(--right.end()));
	right.pop_back();
}

// compare with generated strings
if(t==left || t== right) return true;
return false;
}

bool isanagram(string s, string t){
	// base screening case
	if(s.size()!=t.size()) return false;

	vector<int> counts(26,0);
	vector<int> countt(26,0);

// count first string
	for(int i = 0 ; i < s.size() ; i++){
		counts[s[i]-’a’]++;
	}
	//count second string
	for(int i = 0 ; i < t.size() ; i++){
		countt[t[i]-’a’]++;
	}
	
	// compare
	if(counts==countt) return true;
	return false;
}


int LCS(const string & s, const string & t, int m, int n){
	// base case
if(m==s.size() || n==t.size()) return 0;

// general case
if(s[m]==t[n]) return LCS(m-1,n-1);
else return max(LCS(m-1,n),LCS(m,n-1);
}

int countadds(string s){
	int head = 0;
	int tail = s.size()-1;
	int count = 0;
	while(head<tail){
		if(s[head]!=s[tail]){
			head++;
			count++:
		}else{
			head++;
			tail--;
		}
	}
	return count;
}

int longestdistinct(const string & data){
	// make a cache array
	vector<int> cache(26,0);
	int currhead = data[0]-’a’;
	int maxret = 1;
	// go through array
	for(int i = 1 ; i <data.size() ; i++){
		if(data[i]==currhead+’a’){
			// duplicate met
			if(maxret < i-1-cache[currhead]+1) maxret = i-cache[currhead];
			cache[currhead] = i;
			// find new head
			for(int j = 0 ; j < cache.size() ; j++){
				if(cache[currhead]>cache[j]) currhead = j;
			}
		}else{
			cache[data[i]-’a’] = i;
		}
	}
	return maxret;
}

int atoi(const string & s){
	int ret = s[0]-’0’;
	for(int i = 1 ; i < s.size() ; i++){
		ret *= 10;
		ret += s[i]-’0’;
	}
	return ret;
}

int strstr(string s, string t){
	for(int i = 0 ; i < s.size() ; i++){
		int count = 0 ;
		while(s[i]==t[count]){
			count++;
			if(count==t.size()) return i;
		}
	}
	return -1;
}

string LCPA(const vector<string> & data){
	string ret = “”;
	int curr=0;
while(true){
	if(curr==data[0].size()) break;
		for(int i = 0 ; i < data.size() ; i++){
			if(curr>=data[i].size() || data[i][curr]!=data[0][curr]) break;
		}
		ret += data[0][curr];
    curr++;
	}
	if(ret.size()==0) return “-1”;
	return ret;
}

bool canrearrange(const string & s){
	vector<int> counter(26,0);
	// count elements
	for(int i = 0 ; i < s.size() ; i++){
		counter[s[i]-’a’]++;
	}
	// find max element and add all other
	int sum = 0;
	int max = 0;
	for(int i = 0 ; i < 26 ; i++){
		sum+=counter[i];
		if(counter[i]>counter[max]) max = i;
	}
	// print result
	if(sum-count[max]<count[max]-1) return 0;
	else return 1;
}

		
