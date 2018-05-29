#include "stdafx.h"
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <ctime>
#include <cstdlib>
#include <cmath>
using namespace std;

// 단어 중복 있나요? >> 네
// 주어진 텍스트 파일이 하나의 스트링으로 주어진다고 가정해도 될까요? >> 네

// 안좋은 방법으로는 모든 단어를 검색하면서 최단 거리를 반환하는 방법
// O(N^2)
// 조금 더 좋은 방법으로는 한번 단어를 모두 순회한 후에 단어와 그 위치를 배열에 저장
// 아주 좋은 방법으로는 해시 테이블에 각 단어와 위치를 넣는다. 같은 단어는 같은 버킷에 저장된다
// 두 단어를 검색한 후에 나오는 인덱스 목록 중에서 가장 가까운 조합을 찾는다
// O(N) + worst case O(N^2)
// 검색한 후에 나오는 인덱스 목록 중에서 최단거리를 빠르게 구하는 방법이 있을까?

bool comparitor3(unordered_multimap<string, int>::iterator it1, unordered_multimap<string, int>::iterator it2) {
	return it1->second < it2->second;
}

int findclosest(int ref, unordered_multimap<string, int>::iterator low, unordered_multimap<string, int>::iterator high, int dist) {
	if (dist <= 3) {
		int min = INT_MAX;
		while (low != high) {
			int tmp = abs(low->second - ref);
			if (tmp < min) min = tmp;
			low++;
		}
		return min;
	}
	auto mid = low;
	advance(low, dist / 2);
	mid++;
	int disth = abs(ref - mid->second);
	mid--;
	int distm = abs(ref - mid->second);
	mid--;
	int distl = abs(ref - mid->second);
	mid++;
	if (distm - distl >= 0) {
		mid++;
		return findclosest(ref, low, mid, dist / 2 + 1);
	}
	else if (distm - disth >= 0) {
		return findclosest(ref, mid, high, dist - dist / 2);
	}
	else {
		return distm;
	}
}

int findmindistance(string * book, string s1, string s2) {
	unordered_multimap<string, int> data;
	// parse letters and put in hash table with index
	string buffer = "";
	int wordcount = 0;
	for (int i = 0; i < book->size(); i++) {
		if (book->at(i) == ' ' || i==book->size()-1) {
			data.insert(pair<string, int>(buffer, wordcount));
			wordcount++;
		}
		else {
			buffer += book->at(i);
		}
	}
	// no s1 or s2 found
	if (data.find(s1) == data.end()) {
		return 0;
	}
	if (data.find(s2) == data.end()) {
		return 0;
	}

	// get all points with s1 and s2
	auto s1s = data.equal_range(s1);
	auto s2s = data.equal_range(s2);
	int dist = 0;
	auto dt = s2s.first;
	while (dt != s2s.second) {
		dist++;
		dt++;
	}
	// compare length between all and return min length
	/*int minlength = INT_MAX;
	for (auto it1 = s1s.first; it1 != s1s.second; it1++) {
		for (auto it2 = s2s.first; it2 != s2s.second; it2++) {
			if (abs(it1->second - it2->second) < minlength) {
				minlength = abs(it1->second - it2->second);
			}
		}
	}
	return minlength;*/
	sort(s1s.first, s1s.second, comparitor3);
	sort(s2s.first, s2s.second, comparitor3);
	int minlength = INT_MAX;
	for (auto it1 = s1s.first; it1 != s1s.second; it1++) {
		int tmpmin = findclosest(it1->second, s2s.first,s2s.second, dist);
		if (tmpmin < minlength) {
			minlength = tmpmin;
		}
	}
	return minlength;
}

// compare and find min을 개선할 수 있을까?


//----------------

// 각 숫자의 2를 센다 >> 더한다
// 여러번 사용하는 경우 각 f(n) 을 캐싱해서 다시 사용할 수 있다.
// 

// algorihmically calculate number of 2s in 0 ... n sequence
int count2(int n) {
	int count = 0;
	int tmp = n;
	int flag = 0;
	int curr = 1;
	int marker = 1;
	// count number of 2s in each position
	while (flag == 0) {
		if (tmp == 0) {
			flag++;
		}
		int remain = n%(int)(pow(10, curr));
		tmp /= 10;
		// number of full counts
		// if 343 and counting 2s in tens position
		// 3 * full 100s + remainder 34
		
		// adding full here
		count += tmp * (int) pow(10,curr - 1);
		remain -= marker;
		
		// adding remainder here
		if (remain < 0) {
			remain = 0;
		}
		if (remain > (int)pow(10, curr - 1)) {
			remain = (int)pow(10, curr - 1);
		}
		
		// go to next position
		count += remain;
		marker *= 10;
		marker += 9;
		curr++;
	}
	return count;
}

int count22(int n) {
	int ret = 0;
	for (int i = 0; i <= n; i++) {
		int tmp = i;
		while (tmp != 0) {
			if (tmp % 10 == 2) {
				ret++;
			}
			tmp /= 10;
		}
	}
	return ret;
}

int main() {
	cout << count2(12343) << endl;
	cout << count22(12343) << endl;
	while (1) {}
	return 0;
}


//

// 음수가 존재하나요? // 네
// 중복이 존재하나요? // 네
// 정렬되어 있나요? // 아니요(네)
// 모든 "경우의 수"를 구하는건지 아니면 가능한 "정수쌍만 구하는건지"
// 11 22 > 4 가지가 되는지 아니면 1+2 라는 한가지로 세는건지

// 처음 드는 생각은 하나씪 전부 하면서 값을 세는 방법이네요
// O(n^2) 시간 복잡도 공간 복잡도 O(1) 입니다.

int countsum3(vector<int> * data, int target) {
	int low = 0;
	int high = data->size() - 1;
	int count = 0;
	// move low and high comparing curr sum with target
	// high-- results smaller sum
	// low++ results bigger sum
	// return when no more to consider(low<high)
	while (low < high && (low<data->size()&&high>0)) {
		if (data->at(low) + data->at(high) < target) {
			low++;
		}
		else if (data->at(low) + data->at(high) > target) {
			high--;
		}
		else {
			int samecountlow = 1;
			int samecounthigh = 1;
			while (data->at(low) == data->at(low + 1)) {
				samecountlow++;
				low++;
			}
			low++;
			while (data->at(high) == data->at(high-1)) {
				samecounthigh++;
				high--;
			}
			high--;
			count += samecountlow * samecounthigh;
		}
	}
	return count;
}

int countsum2(vector<int> * data, int target) {
	int count = 0;
	// check all cases and return if target met
	for (int i = 0; i < data->size(); i++) {
		for (int j = i + 1; j < data->size(); j++) {
			if (target == data->at(i) + data->at(j)) {
				count++;
			}
		}
	}
	return count;
}


int countsum(vector<int> * data, int target) {
	unordered_map<int, int> tmp;
	// prepare hash table
	for (int i = 0; i < data->size(); i++) {
		auto it = tmp.find(data->at(i));
		if (it != tmp.end()){
			it->second++;
		}
		else {
			tmp.insert(pair<int, int>(data->at(i), 1));
		}
	}

	// iterate through hash table to count cases
	int count = 0;
	while(tmp.size()!=0){
		auto it2 = tmp.begin();
		auto it3 = tmp.find(target - it2->first);
		if (it3 != tmp.end()) {
			count += it2->second * it3->second;
			tmp.erase(it2);
			tmp.erase(it3);
		}
		else {
			tmp.erase(it2);
		}
	}

	return count;
}

int main121222() {
	vector<int> data = { -10,-8,-6,-4,4,4,4,20,20,20,20,22 };
	cout << countsum(&data, 12) << endl;
	cout << countsum2(&data, 12) << endl;
	cout << countsum3(&data, 12) << endl;
	while(1){}
	return 0;
}

// 베스트 케이스 O(N)
// 해시 테이블을 사용 >> 갯수를 센다
// 만약 합한 값을 찾는다면
// 해시 테이블을 순회하면서 대응하는 값을 찾고 삭제(없어도 삭제)
// 만약 두개씩 등장했다면 두 값을 곱한걸 더한다.
// 해시 테이블이 비면 값을 리턴


////
int rand5() {
	return rand() % 5;
}

int rand7() {
	return (rand5() + rand5()) % 7;
}

int main44() {
	srand(time(NULL));
	cout << rand7() << endl;
	while (1) {}
	return 0;
}


// 입력을 string으로 가정해도 좋은가요?
// 띄어쓰기로 구분된 것이 한 단어라고 생각하면 되겠죠?
// 어짜피 한번이라도 탐색하면 전체를 탐색해야 하니 공간
// 복잡도는 좀 있겠지만 hash table에 단어들과 그 횟수를 저장해 두었다가
// 반환하는 것이 좋겠다.

void fill(unordered_map<string, int> * data, string * book) {
	// iterate book and find letters
	string tmp = "";
	for (int i = 0; i < book->size(); i++) {
		if (book->at(i) == ' ' || i == book->size() - 1) {
			// cut letter and fill hash table
			auto it = data->find(tmp);
			if (it != data->end()) {
				it->second++;
			}
			else {
				data->insert(pair<string, int>(tmp, 1));
			}
			tmp = "";
		}
		else {
			tmp += book->at(i);
		}
	}
}

int findcount(unordered_map<string, int> * data, string s) {
	auto it = data->find(s);
	if (it != data->end()){
		return it->second;
	}
	else {
		return 0;
	}
}

int main1122() {
	unordered_map<string, int> data;
	data.reserve(1000);
	string book = "hello all the hello eyes hello bye";
	fill(&data, &book);
	cout << findcount(&data, "hello") << endl;
	while(1){}
}



///

int returnmaxrec(vector<int> * data, int maxsum, int curr) {
	if (curr == data->size()) {
		return maxsum;
	}
	if (curr == 0) {
		return returnmaxrec(data, data->at(curr), curr + 1);
	}
	if (maxsum + data->at(curr) > data->at(curr)) {
		return returnmaxrec(data, data->at(curr) + maxsum, curr+1);
	}
	else {
		return returnmaxrec(data, data->at(curr), curr + 1);
	}
}

int returnmax(vector<int> * data) {
	return returnmaxrec(data, 0, 0);
}

int main888() {
	vector<int> data = { -4,1,3,-8,11,3,-2,4,8 };
	cout << returnmax(&data) << endl;
	while (1) {}
	return 0;
}

///

string toenglish(int n) {
	int givenarr[4];
	for (int i = 0; i < 4; i++) {
		givenarr[3 - i] = n % 10;
		n = n / 10;
	}
	string onearr[] = { "zero","one","two","three","four","five","six","seven","eight","nine" };
	string tenarr[] = { "twenty","thirty","fourty","fifty","sixty","seventy","eighty","ninety" };
	string tenarr2[] = { "ten","eleven","twelve","thirteen","fourteen","fifteen","sixteen","seventeen","eighteen","nineteen" };
	string ret = "";
	if (givenarr[0] != 0) {
		string s = onearr[givenarr[0]];
		ret += s;
		ret += " thousand";
	}
	if (givenarr[1] != 0) {
		//ret = ret + " " + onearr[givenarr[1]] + " hundred";
		ret += " ";
		ret += onearr[givenarr[1]];
		ret += " hundred";
	}
	if (givenarr[2] == 1) {
		//ret = ret + " " + tenarr2[givenarr[3]];
		ret += " ";
		ret += tenarr2[givenarr[3]];
		return ret;
	}
	if (givenarr[2] != 0) {
		//ret = ret + " " + tenarr[givenarr[2] - 2];
		ret += " ";
		ret += tenarr[givenarr[2] - 2];
	}
	if (givenarr[3] != 0){
		//ret = ret + " " + onearr[givenarr[3]];
		ret += " ";
		ret += onearr[givenarr[3]];
	}
	return ret;
}

int main11() {
	string s = "";
	//cout << s + "hello" + "world" + "sam" << endl;
	cout << toenglish(3232) << endl;
	while(1){}
	return 0;
}

////

int recfun(int n, int value) {
	if (n == 0) {
		return value;
	}
	int ret = recfun(n - 1, value * 2);
	ret = ret * 3;
	return ret;
}

int main333() {
	cout << recfun(3, 1) << endl;
	while(1){}
	return 0;
}

pair<int,int> findzeroesrec2(int n, int k) {
	if (k == 0) {
		return pair<int,int>(1,0);
	}
	pair<int,int> count = findzeroesrec2(n, k - 1);
	int curr = count.first * k;
	int c = count.second;
	while (curr % 10 == 0) {
		curr /= 10;
		c++;
	}
	return pair<int, int>(curr, c);
}


int findzeroesrec(int n, int k, int currvalue, int zerocount) {
	if (n <= k-1) {
		return zerocount;
	}
	
	int value;
	if (k == 1) {
		value = 1;
		return findzeroesrec(n, k + 1, value, zerocount);
	}
	else {
		value = currvalue;
		value = value * k;
		while (value % 10 == 0) {
			zerocount++;
			value /= 10;
		}
		return findzeroesrec(n, k + 1, value, zerocount);
	}
}

int findzeroes(int n) {
	//return findzeroesrec(n, 1, 0, 0);
	return findzeroesrec2(n, n).second;
}

int fact(int n) {
	if (n == 0) {
		return 1;
	}
	return fact(n - 1) * n;
}

int main2323() {
	cout << fact(10) << endl;
	cout << findzeroes(10) << endl;
	while (1) {}
	return 0;
}

//

pair<int, int> findchange2(vector<int> * data) {
	// find increasing range from start
	int i;
	for (i = 0; i < data->size()-1; i++) {
		if (data->at(i) > data->at(i + 1)) {
			break;
		}
	}
	// return 0,0 if list is already sorted
	if (i == data->size() - 1) {
		return pair<int, int>(0, 0);
	}
	// find decreasing range from end
	int j;
	for (j = data->size() - 1; j > 1; j--) {
		if (data->at(j) < data->at(j - 1)) {
			break;
		}
	}
	//find minimum from range i+1 ~ end
	int min = data->at(i + 1);
	for (int z = i + 1; z < data->size(); z++) {
		if (data->at(z) < min) {
			min = data->at(z);
		}
	}
	// check start ascending range to find m
	int m = i+1;
	for (int z = 0; z <= i; z++) {
		if (data->at(z) > min) {
			m = z;
			break;
		}
	}
	//find maximum from range 0 ~ j-1
	int max = data->at(0);
	for (int z = 0; z <= j - 1; z++) {
		if (max < data->at(z)) {
			max = data->at(z);
		}
	}
	// check end descending range to find n
	int n = j-1;
	for (int z = data->size() - 1; z >= j; z--) {
		if (data->at(z) < max) {
			n = z;
			break;
		}
	}
	return pair<int, int>(m, n);
}

pair<int, int> findchangerec(vector<int> *data, int low, int high) {
	if (low >= high) {
		return pair<int, int>(0, 0);
	}
	int min = data->at(low);
	int minindex = low;
	int max = data->at(low);
	int maxindex = low;
	for (int i = low; i <= high; i++) {
		if (min > data->at(i)) {
			min = data->at(i);
			minindex = i;
		}
		if (max < data->at(i)) {
			max = data->at(i);
			maxindex = i;
		}
	}
	if (minindex == low && maxindex == high) {
		return findchangerec(data, low + 1, high - 1);
	}
	else if (minindex == low) {
		return findchangerec(data, low + 1, high);
	}
	else if (maxindex == high) {
		return findchangerec(data, low, high - 1);
	}
	else {
		return pair<int, int>(low, high);
	}
}

pair<int,int> findchange(vector<int> * data) {
	return findchangerec(data, 0, data->size() - 1);
}

int main42() {
	vector<int> data = { 5,6,7,1,2,3,4,10,11 };
	pair<int, int> res = findchange2(&data);
	cout << res.first << " " << res.second << endl;
	while (1) {}
	return 0;
}

// 아까 그 문제 iteratively 풀기
// 아까 그 문제 생각했던 recursive solution으로 풀기
// largest subarray  문제 iteratively 랑 분할정복으로 풀기

bool comparitor(pair<int, int> a, pair<int, int> b) {
	if (a.first > b.first) return true;
	else if (b.first > a.first) return false;
	if (a.first == b.first) {
		if (a.second > b.second) {
			return true;
		}
		else {
			return false;
		}
	}
}

void maxtower(vector<pair<int, int>> * data) {
	sort(data->begin(), data->end(),comparitor);
	vector<vector<pair<int,int>>> tmp;
	vector<pair<int,int>> t;
	t.push_back(data->at(0));
	tmp.push_back(t);
	for (int i = 1; i < data->size(); i++) {
		if (data->at(i).second > data->at(i - 1).second) {
			vector<pair<int,int>> t = { data->at(i) };
			tmp.push_back(t);
		}
		else {
			for (int j = 0; j < tmp.size(); j++) {
				tmp.at(j).push_back(data->at(i));
			}
		}
	}
	int maxat = 0;
	for (int i = 0; i < tmp.size(); i++) {
		if (tmp.at(maxat).size() < tmp.at(i).size()) {
			maxat = i;
		}
	}
	cout << "max size : " << tmp.at(maxat).size() << endl;
	cout << "values : ";
	for (int i = 0; i < tmp.at(maxat).size(); i++) {
		cout << "( " << tmp.at(maxat).at(i).first << " , " << tmp.at(maxat).at(i).second << " )"<< endl;
	}
}

int countmax(vector<pair<int, int>> *data, int curr, int currmin, int currcount) {
	if(curr==data->size()-1){
		return currcount;
	}
	if (currmin <= 0) {
		return 0;
	}

}

void maxtower2(vector<pair<int, int>> *data) {
	sort(data->begin(), data->end(), comparitor);
	//cout << "max number is : " << countmax(data, 0, data->size()-1) << endl;
}

int main12() {
	vector < pair<int, int> >t;
	t.push_back(pair<int, int>(65, 100));
	t.push_back(pair<int, int>(70, 150));
	t.push_back(pair<int, int>(56, 90));
	t.push_back(pair<int, int>(75, 190));
	t.push_back(pair<int, int>(60, 95));
	t.push_back(pair<int, int>(68, 110));
	maxtower(&t);
	while (1) {}
	return 0;
}

int main122() {
	string s1 = "hello world";
	string s2 = "hello world";
	int s = s1 == s2;
	cout << s << endl;
	while (1) {}
	return 0;
}

int countx(vector<int> * data, int n, int remain) {
	if (remain == 0) {
		return 1;
	}
	if (n < 0) {
		return 0;
	}
	else if (data->at(n) > remain) {
		return 0;
	}

	int count = 0;
	count += countx(data, n - 1, remain);
	count += countx(data, n - 1, remain - data->at(n));
	return count;
}

int main4() {
	vector<int> data = { 2,4,6,10 };
	cout << countx(&data, data.size() - 1, 16) << endl;
	while (1) {}
	return 0;
}

/*


int findcombination(int n) {
	int count = 0;
	for (int i = 0; i <= n / 25; i++) {
		for (int j = 0; j <= (n - 25 * i) / 10; j++) {
			for (int k = 0; k <= (n - 25 * i - 10 * j) / 5; k++) {
				count = count++;
			}
		}
	}
	return count;
}

int tmp[] = { 25,10,5,1 };

int recursive(int n, int k) {
	int count = 0;
	if (k == 3) {
		return 1;
	}
	for (int i = 0; i <= n / tmp[k]; i++) {
		count += recursive(n - tmp[k] * i, k + 1);
	}
	return count;
}

int main2() {
	cout << findcombination(100) << endl;
	cout << recursive(100, 0);
	while (1) {}
	return 0;
}

int bsearch(vector<int> * data, int x, int low, int high) {
	if (low == high) {
		if (x == data->at(low)) return low;
		else return -1;
	}
	int mid = (low + high) / 2;
	if (data->at(mid) == x) {
		return mid;
	}
	else if (data->at(mid) > x) {
		return bsearch(data, x, low, mid);
	}
	else {
		return bsearch(data, x, mid + 1, high);
	}
}

int findmin(vector<int> * data, int low, int high) {
	cout << low << " " << high << endl;
	if (high - low == 1) {
		return data->at(low) > data->at(high) ? high : low;

	}
	int mid = (low + high) / 2;
	if (data->at(low) > data->at(mid) && data->at(mid)<data->at(high)) {
		return findmin(data, low, mid);
	}
	else if(data->at(low)<data->at(mid)&&data->at(mid)>data->at(high)){
		return findmin(data, mid, high);
	}
	else if(data->at(low)<data->at(mid)&&data->at(mid)<data->at(high)){
		return low;
	}
	else if (data->at(low) == data->at(mid) && data->at(mid) == data->at(high)) {
		return low;
	}
	else if (data->at(low) == data->at(mid) && data->at(mid) > data->at(high)) {
		return findmin(data, mid, high);
	}
	else if (data->at(low) > data->at(high) && data->at(mid) == data->at(high)) {
		return findmin(data, low, mid);
	}
	else {
		return low;
	}
}

int findx(vector<int> * data, int x, int low, int high) {
	//base case
	if (low == high - 1) {
		if (data->at(low) == x) {
			return low;
		}
		else if (data->at(high) == x) {
			return high;
		}
		else {
			return -1;
		}
	}
	//check if recursion needed
	int mid = (low + high) / 2;
	if (data->at(mid) == x) {
		return mid;
	}
	if (data->at(low) <= data->at(mid)) {
		if (x >= data->at(low) && x <= data->at(mid)) {
			return findx(data, x, low, mid);
		}
	}
	else {
		if (x <= data->at(mid) && x >= data->at(low)) {
			return findx(data, x, low, mid);
		}
	}
	if (data->at(mid) <= data->at(high)) {
		if (x >= data->at(mid) && x <= data->at(high)) {
			return findx(data, x, mid, high);
		}
	}
	else {
		if (x >= data->at(mid) && x <= data->at(high)) {
			return findx(data, x, mid, high);
		}
	}
	//if else crash (found edge case)
	return -9999;
}


int main1() {
	vector<int> v1 = { 1,1,1,1,1,2,3,4,5 }; // { 7,9,11,14,17,18,19,20,1,3,4,5 };
	cout << v1.at(findx(&v1,2, 0, v1.size() - 1)) << endl;;
	while(1){ }
	return 0;
}
*/
