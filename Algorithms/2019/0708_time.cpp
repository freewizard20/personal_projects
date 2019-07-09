// SWE7732

#include <iostream>
#include <string>
#include <cmath>
#include <vector>

using namespace std;

void filltime(string given, vector<int> & numbers) {
	int num = 0;
	num = (given[0] - '0') * 10;
	num += given[1] - '0';
	numbers.push_back(num);

	num = (given[3] - '0') * 10;
	num += given[4] - '0';
	numbers.push_back(num);

	num = (given[6] - '0') * 10;
	num += given[7] - '0';
	numbers.push_back(num);
}

// returns true if tocompare is bigger
bool isbigger(vector<int> tocompare, vector<int> standard) {
	int tocompare1 = tocompare[2] + tocompare[1] * pow(10, 2) + tocompare[0] * pow(10, 4);
	int standard1 = standard[2] + standard[1] * pow(10, 2) + standard[0] * pow(10, 4);
	return tocompare1 > standard1;
}

string int2string(int x) {
	string ret = "";
	ret.push_back(x / 10 + '0');
	ret.push_back(x % 10 + '0');
	return ret;
}

// arrtime이 무조건 크게 들어와야 한다.
string subtract(vector<int> arrtime, vector<int> currtime) {
	if (!isbigger(arrtime, currtime)) return "-1:-1:-1";
	vector<int> result;
	result.push_back(arrtime[0] - currtime[0]);
	result.push_back(arrtime[1] - currtime[1]);
	result.push_back(arrtime[2] - currtime[2]);
	if (result[2] < 0) {
		result[2] += 60;
		result[1]--;
	}
	if (result[1] < 0) {
		result[1] += 60;
		result[0]--;
	}
	return int2string(result[0]) + ":" + int2string(result[1]) + ":" + int2string(result[2]);
}

int main(int argc, char** argv)
{

	int test_case;
	int T;
	cin >> T;
	for (test_case = 1; test_case <= T; ++test_case)
	{

		vector<int> currtime;
		vector<int> arrtime;


		string curr;
		string arrangement;

		cin >> curr;
		cin >> arrangement;

		filltime(curr, currtime);
		filltime(arrangement, arrtime);

		if (isbigger(currtime, arrtime)) {
			arrtime[0] += 24;
			cout << "#" << test_case << " " << subtract(arrtime, currtime) << endl;
		}
		else {
			cout << "#" << test_case << " " << subtract(arrtime, currtime) << endl;
		}

	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
