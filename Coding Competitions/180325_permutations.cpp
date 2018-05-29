#include "stdafx.h"
#include <iostream>
#include <vector>

using namespace std;

// 우선 갯수가 n팩토리얼 개이므로 최소 시간 복잡도도 마찬가지겠네요.
// n진법 수로 생각한 후에 하나씩 더할 수 있을까 생각했는데 이건 중복이 있어 순회가 아니고
// for 루프를 n번 반복해서 사용하면 구할 수 있겠는데, 우리가 for 루프를 타이핑 할 수는 업스니까
// for 루프를 재귀적으로 호출하면서 출력해 보겠습니다.
// 근데 또 찾아야 되는 부분이니까 result에 저장을..?
// 재귀적으로 for 루프를 돌릴껀데, tmp에 각각의 재귀상태를 넣어가면서 하면
// tmp도 계속 인수로 넣어서 돌려줘야되나..
//알고리즘
// for 루프로 string의 각 원소를 하나씩 뺀다. buffer에 넣는다.
// 재귀 호출로 하나 빠진 string에서 for 루프를 돌리면서 다시 원소를 하나씩 빼고 buffer에 넣는다.
// string.size()==0이 되면 더 이상 뽑을 string이 없으므로 그 buffer을 result에 추가한다.
void findpermutations(vector<vector<char>> * result, vector<char> buffer, string s) {
	if (s.size()==0 ) {
		result->push_back(buffer);
		return;
	}
	for (int i = 0; i < s.size(); i++) {
		buffer.push_back(s.at(i));
		char t = s.at(i);
		s.erase(s.begin() + i);
		findpermutations(result, buffer, s);
		buffer.erase(buffer.end() - 1);
		s.insert(s.begin() + i, t);
	}
	return;
}
// 시간 복잡도는 for 루프가 하나씩 줄어들면서 계속 반복되므로 O(n!)
// 공간 복잡도는 n!개의 string을 저장해야 하므로 O(n!)
//qwe
// string qe
// buffer w

int main5() {
	vector<vector<char>> result;
	vector<char> tmp;
	string s = "querty";
	findpermutations(&result, tmp, s);
	for (int i = 0; i < result.size(); i++) {
		for (int j = 0; j < result.at(i).size(); j++) {
			cout << result.at(i).at(j);
		}
		cout << endl;
	}
	while (1) {}
	return 0;
}

// 중복이 있는 경우.....
// result 를 unordered_set(해시테이블)으로 옮기면 되겠습니다.
// 다만 vector 간 동치가 곧 원소의 동치라는 operator overloading만 있으면 되겠다.
// 시간 복잡도는 어짜피 똑같이 O(2^n) 이겠다.

void findsubsets2(vector<vector<int>> & result, int n) {
	for (int i = 0; i < pow(2, n); i++) {
		vector<int> tmp;
		int t = i;
		int k = 0;
		while (t != 0) {
			if (t % 2 != 0) {
				tmp.push_back(k);
			}
			t /= 2;
			k++;
		}
		result.push_back(tmp);
	}
	for (int i = 0; i < result.size(); i++) {
		for (int j = 0; j < result.at(i).size(); j++) {
			cout << result.at(i).at(j) << " ";
		}
		cout << endl;
	}
}

void findsubsets(vector<vector<int>> & result, int n) {
	vector<int> tmp;
	result.push_back(tmp);
	for (int i = 0; i < n; i++) {
		int k = result.size();
		for (int j = 0; j < k; j++) {
			tmp = result.at(j);
			tmp.push_back(i);
			result.push_back(tmp);
		}
	}
	for (int i = 0; i < result.size(); i++) {
		for (int j = 0; j < result.at(i).size(); j++) {
			cout << result.at(i).at(j) << " ";
		}
		cout << endl;
	}
}

int main4() {
	vector<vector<int>> result;
	findsubsets2(result, 4);
	while (1) {}
	return 0;
}

// n = 3
//subset >> 공집합, 0, 1, 01 , 2 , 02, 12, 012
//i = 0
//i = 1
//i = 2


/*int main() {
	vector<vector<int>> sam;
	for (int i = 0; i < 10; i++) {
		vector<int> tmp;
		sam.push_back(tmp);
		for (int j = 0; j < 10; j++) {
			sam.at(i).push_back(10 * i + j);
		}
	}
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			cout << sam.at(i).at(j) << " ";
		}
		cout << endl;
	}
	cout << "hello" << endl;
	while (1) {}
	return 0;
}
*/

/*
// 집합의 원소는 어떤 것들인가요? >> 정수.
// 중복은 존재하나요? >> 네.
// 순서는? 부분집합의 순서는?
// 집합 부분집합이 2^n개라고들 하는데
// 1 1 1 >> 1,1 1, 1 1 1 >> 3개밖에 안되는데..
// 0 ~ n의 부분집합을 고르는 경우라고 생각한다면
// 각각을 포함/미포함으로 vector을 만들어서 vector array를 채운다.
// for 루프를 돌면서 int i = 0 부터 2^n-1까지 1씩 증가시키면서
// 해당 int의 binary가 1인 i를 전부 2^n-1번째 vector array에 채운다.
// time complexity O(N*2^N)
// space complexity >> vector array를 채우지 않고 바로 출력해 주는 경우
// 필요하지 않을지도
// time complexity 역시 vector array를 굳이 채우지 않고 그 binary를
// 정답이라고 생각하면 O(2^N) 일 수 있겠네요

void allsubsets(int n) {
	for (int i = 0; i < pow(2, n) - 1; i++) {
		cout << i << endl;
	}
}

// 동적 재생성의 경우.. 
// 공집합 0
// 공집합 0 1 01
// 이런 식으로 n-1의 전체 부분집합 + n을 추가한 n-1의 전체 부분집합
// 을 해주면 n의 전체 부분집합이 됩니다.
// 자료구조를 어떻게 하는게 좋을까?
// 

// 숫자에 범위가 있나요? >> 음수값 존재 가능합니다.
// 만약 범위가 있다면 인덱스 또는 값이 그 범위 이하인 경우까지만 세면 된다.
// 예를 들어 나이이면 100 까지만 보면 된다. >> 범위 없음.
// 중복은 존재하나요? // 존재하지 않음.
// 여러개 존재하면 전부 찾아야 하나요?


// 특징 : 정렬되어 있기 때문에 만약 A[0] = 7 이면 그 다음 숫자는
// 8 이상이기 때문에 바로 A[8] 까지 jump 가능 어 근데 A[8]은 
// 최소 15 이기 때문에 결국 전부 마술 인덱스거나 전부 아닌거 같은데
// 숫자가 정수인가요?
// 그냥 검색하면 O(N)인데
// 이걸 O(logN) 까지 줄일 수 있을까?
// 그냥 검색하면 O(N)이다.

void magicnumber(vector<int> & result, vector<int> data, int i) {
	for (int z = 0; z < data.size(); i++) {
		if (data.at(z) == z) {
			result.push_back(z);
		}
	}
}

// 최악의 경우는 O(N)인데, 
// 알고리즘
// A[i]<i >> 중간 이하 재탐색, A[i]>i >> 중간 이후 재탐색
// 첫 매직 넘버 발견
// 그때부터 1. 종결지점까지 양방향 선형탐색 전부 담는다.
// 붙어있지 않은 매직넘버는 존재할 수 없다.
// 최악의 경우 O(N), 평균 O(logN)
//TODO 한 번이라도 A[i]>i인 경우 그때 바로 종결(그 이후는 존재 안함)


int findfirst(vector<int> &result, vector<int> *data, int i, int low, int high) {
	if (low == high) {
		if (data->at(low) == i) {
			result.push_back(i);
			return i;
		}
		return -1;
	}
	int mid = (low + high) / 2;
	if (data->at(mid) > mid) {
		findfirst(result, data, i, low, mid);
	}
	else if (data->at(mid) < mid) {
		findfirst(result, data, i, mid + 1, high);
	}
	else {
		result.push_back(mid);
		return mid;
	}
}

void findmagicnumber(vector<int> &result, vector<int> *data, int i) {
	int firstfound = findfirst(result, data, i, 0, data->size() - 1);
	if (firstfound == -1) {
		return;
	}
	int tmp = firstfound - 1;
	while (tmp == data->at(tmp)) {
		result.push_back(tmp);
		tmp--;
	}
	tmp = firstfound + 1;
	while (tmp == data->at(tmp)) {
		result.push_back(tmp);
		tmp++;
	}
}

// 코드 분석
// 상수개 존재한다면 O(logN), 근데 매직넘버가 N에 비례해서 존재한다고 하면
// N/k개 존재한다고 할때 결국에는 점근적으로 O(N)이 될 가능성이 있다.
// space complexity : ~ O(N) 100 >> 2 매직넘버가 존재 한다고 보장?
// ok

// 중복이 존재하는 경우
// 성질 : A[0]=8 , 8 8 8 8 8 8 8 8 8 ok A[8] = 8
// 기본적으로 전체 검색을 하면 time complexity O(N) 알고리즘
// 유사하게는 가능할 듯
// 하지만 매직 넘버가 더 이상 붙어있지 않을 수 있다.
// 순회를 하되, A[i] > i 이면 A[A[i]]로 바로 점프한다.
// binary search를 한 후에 하나를 찾고, 좌우로 또 binary search
// 최악의 경우 

void findmagic(vector<int> result, vector<int> data, int i) {
	int m = 0;
	while (m < data.size()) {
		if (m == data.at(m)) {
			result.push_back(m);
			m++;
		}
		else {
			if (m < data.at(m)) {
				m = data.at(m);
			}
			else {
				m++;
			}
		}
	}
}

// 마지막에 i가 있고 그 전에 쭉 작으면 >> O(N)
// 첫 번째 숫자가 i를 초과 >> 바로 끝
// depends.. N/k ~ 64 > 6
// O(N)

// 중간값으로 판단할 수 있는게 있을까?













// board[][] 어레이를 통해 0과 1로 각각 지나갈 수 있음, 없음이 구분된다고 하고
// 결과값은 vector을 통해 좌표값을 순서대로 제시한다고 하겠습니다.

int board[100][100];
//vector<pair<int,int>> result;
//vector<pair<int, int>> result[100][100];


void findpath2(int M, int N, int x, int y) {

}

void findpath(int M, int N, int x, int y) {
	pair<int, int> tmp(x, y);
	result.push_back(tmp);
	if (x == M - 1 && y == N - 1) {
		for (int i = 0; i < result.size(); i++) {
			board[result.at(i).first][result.at(i).second] = 2;
		}
		return;
	}
	int flag = 0;
	if (x != M - 1 && board[x + 1][y] == 0) {
		findpath(M, N, x + 1, y);
		flag++;
	}
	if (y != N - 1 && board[x][y + 1] == 0) {
		findpath(M, N, x, y + 1);
		flag++;
	}
	if (flag == 0) {
		result.erase(result.end() - 1);
	}
	return;
}

//time complexity : O(2^n)
//space complexity : O(N)

int main3() {
	for (int i = 0; i < 100; i++) {
		for (int j = 0; j < 100; j++) {
			board[i][j] = 0;
		}
	}
	//board[18][19] = 1;
	//board[19][18] = 1;
	findpath(3, 3, 0, 0);
	for (int i = 0; i < 100; i++) {
		for (int j = 0; j < 100; j++) {
			cout << board[i][j];
		}
		cout << endl;
	}
	while (1) {}
	return 0;
}

int cache2[100][100];

int totalmaze(int x, int y, int M, int N) {
	if (x == M - 1 || y == N - 1) {
		return 1;
	}
	if (cache2[x][y] != -1) {
		return cache2[x][y];
	}
	int ret = totalmaze(x + 1, y, M, N) + totalmaze(x, y + 1, M, N);
	cache2[x][y] = ret;
	return ret;
}

// space complexity : O(M*N)
// time complexity : O(M*N)

int main2() {
	for (int i = 0; i < 100; i++) {
		for (int j = 0; j < 100; j++) {
			cache2[i][j] = -1;
		}
	}
	cout << totalmaze(0, 0, 20, 5) << endl;
	while(1){}
	return 0;
}



int cache[500];

int numberofcases(int n) {
	if (n == 1) {
		return 1;
	}
	else if (n == 2) {
		return 2;
	}
	if (cache[n] != -1) {
		return cache[n];
	}
	int ret = numberofcases(n - 1) + numberofcases(n - 2);
	cache[n] = ret;
	return ret;
}

//time complexity : O(N)
//space complexity : O(N)

int main1() {
	for (int i = 0; i < 500; i++) {
		cache[i] = -1;
	}
	cout << numberofcases(20) << endl;
	while (1) {}
	return 0;
}*/
