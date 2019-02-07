#include "stdafx.h"
#include <iostream>
#include <vector>
#include <string>
#include <random>
#include <cstring>
#include <ctime>

using namespace std;

bool iswordsquare(vector<string> * data) {
	// check if the lengths make a square
	for (int i = 0; i < data->size(); i++) {
		if (data->size() != data->at(i).size()) {
			return false;
		}
	}
	// check for transpose equality
	for (int i = 0; i < data->size(); i++) {
		for (int j = i + 1; j < data->size(); j++) {
			if (data->at(i).at(j) != data->at(j).at(i)) {
				return false;
			}
		}
	}
	return true;
}

// O(N^2) algorithm

// exhaustive way
// first sort by word length
// then if words of same length exceed the word length, look for ball
// look for all combinations nPk
// go through all words
// worst case all N same length k, >> O(N!k^2)
// best case all different lengths >> O(NlogN) ( sort and iterate )
// can make best case O(N) if compare lengths at first to check no potential case
// no. needs to do O(Nk) at minimum becuse it is counting same length strings;
// no. can put it to hash table then iterate >> O(N) max
// but checking length of string is O(k).. 

//vector<vector<int>>

//---

int * func() {
	//int b = 3;
	int * b = new int;
	*b = 3;
	return b;
}

int main999() {
	int * a[10];
	for (int i = 0; i < 10; i++) {
		a[i] = func();
	}
	for (int i = 0; i < 10; i++) {
		cout << *a[i] << endl;
	}
	// gets overwritten!!!!
	int * b = new int;
	*b = 2323;
	cout << *b << endl;
	delete b;
	cout << *b << endl;
	// gets overwritten!!
	int *as = new int[10];
	for (int i = 0; i < 10; i++) {
		as[i] = i;
	}
	for (int i = 0; i < 10; i++) {
		cout << as[i] << " ";
	}
	cout << endl;
	delete as;
	for (int i = 0; i < 10; i++) {
		cout << as[i] << " ";
	}
	while(1){}
	return 0;
}

// despacito

// what is resize?

template<typename T>
class Matrix {
private:
	int rows;
	int cols;
	int columns;
	int bombs;
	char ** arr;
	char ** fog;
	char randomelement(int i, int j);
public:
	Matrix(int row, int col, int bomb);
	Matrix();
	void resize(int row, int col, int bomb);
	T & at(int row, int col, bool firstcall);
	void print();
	bool gamewon();
};

template<typename T>
bool Matrix<T>::gamewon() {
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			if (fog[i][j] == '-') {
				return false;
			}
		}
	}
	return true;
}

template<typename T>
char Matrix<T>::randomelement(int i , int j) {
	if (bombs == 0) {
		return '0';
	}
	int left = cols * (rows - i - 1) + (cols - j);
	int it1 = rand() % left;
	//cout << it1 << " " << bombs << endl;
	if (it1 < bombs) {
		bombs--;
		return '9';
	}
	else {
		return '0';
	}
	
}

template<typename T>
Matrix<T>::Matrix() {
	resize(10, 10, 15);
}

template<typename T>
Matrix<T>::Matrix(int row, int col, int bomb) {
	resize(row, col, bomb);
}

template<typename T>
void Matrix<T>::resize(int row, int col, int bomb) {
	bombs = bomb;
	rows = row;
	cols = col;
	// make empty board
	arr = new char*[row];
	fog = new char*[row];
	for (int i = 0; i < row; i++) {
		arr[i] = new char[col];
		fog[i] = new char[col];
	}
	// fill bombs
	for(int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			// place bomb randomly based on remaining bombs/slots
			arr[i][j] = randomelement(i, j);
			fog[i][j] = '-';
		}
	}
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}
	// fill numbers
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			if (arr[i][j] != '9') {
				// count nearby bombs
				int bombcount = 0;
				for (int x = -1; x <= 1; x++) {
					for (int y = -1; y <= 1; y++) {
						if (i + x >= 0 && i + x < rows&&j + y >= 0 && j + y < cols&&arr[i + x][j + y] == '9') {
							bombcount++;
						}
					}
				}
				arr[i][j] = bombcount + '0';
			}
		}
	}
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}
	cout << "set " << row << " * " << col << "bomb game" << endl;
}

template<typename T>
void Matrix<T>::print() {
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			if (fog[i][j] == '-') {
				cout << fog[i][j];
			}
			else {
				cout << arr[i][j];
			}
			cout << " ";
		}
		cout << endl;
	}
	cout << "---------------------" << endl;
}

template<typename T>
T & Matrix<T>::at(int row, int col, bool firstcall) {
	cout << "look for " << row << " " << col << endl;
	T * beauty = new T;
	if (row >= rows || row < 0 || col >= cols || col < 0) {
		cout << "inexistent point" << endl;
		return *beauty;
	}
	if (firstcall && arr[row][col] == '9') {
		cout << "game lost" << endl;
		return *beauty;
	}
	// check nearby zeroes
	for (int i = -1; i <= 1; i++) {
		for (int j = -1; j <= 1; j++) {
			if (row + i >= 0 && row + i < rows&&col + j >= 0 && col + j < cols) {
				if (arr[row + i][col + j] == '0' && fog[row+i][col+j]=='-') {
					fog[row + i][col + j] = '.';
					at(row + i, col + j,false);
				}
				else {
					fog[row + i][col + j] = '.';
				}
			}
		}
	}
	return *beauty;
}

int main666() {
	srand(time(NULL));
	Matrix<int> game(15, 15, 20);
	while (!game.gamewon()) {
		game.print();
		cout << "pick your next point" << endl;
		int i, j;
		cin >> i >> j;
		game.at(i, j,true);
	}
	return 0;
}

// --- love what you do

void yeah(vector<int>sam) {
	return;
}



// ---- love what you do

// 스트링을 앞에서부터 확인하다가, 숫자를 만나면 숫자와 bracket
// 속의 문자열을(괄호가 중첩되어 있으면 중첩 포함)
// decompressrec(재귀함수) 에 넣어 준다.
// 그러면 그 재귀함수가 그 괄호의 결과값을 리턴하고
// 그 리턴된 값을 새로운 string에 append 한다.
// 끝까지 순회하면 buffer을 return 한다.


// 근데 여기 안에서도 마찬가지 작업을 할 것이기 때문에
// 숫자가 나타나는가? >> 대응하는 괄호와 그 안의 내용물
// 다시 재귀호출로 부르기
// 재귀호출함수 한개로 작업을 할 수 있을 듯 하다

// 아 그런데 그렇게 하는 경우에 string을 하나씩 제거해가면서
// given string이 전부 소진될때까지 재귀하려고 했는데
// 그러면 string erase가 O(N)이어서 그냥 indexing에 O(N^2)가 걸린다

// 알고리즘
// 숫자를 만날때까지 그대로 buffer에 추가하면서 iterate
// 숫자를 만나면 숫자 + 괄호 안 내용을 parse 한 후에
// rec 함수에 전달
// rec 함수 역시 필요하면 그 안의 내용을 숫자+괄호 안 내용으로 parse
// 재귀호출
// 재귀함수의 결과제출
// 그 결과를 buffer에 append하고 끝까지 진행

string decompressrec(int reps, string * data) {
	string buffer = "";
	// go through whole data;
	int i=0;
	while (i < data->size()) {
		// if just a letter, add to buffer and go through
		if (data->at(i) < '0' || data->at(i) > '9') {
			buffer += data->at(i);
			i++;
		}
		else {
			// when number detected, start parsing phase
			int reps = 0;
			while (data->at(i) != '[') {
				reps = reps * 10 + (data->at(i) - '0');
				i++;
			}
			string target = "";
			int bracketsopen = 1;
			i++;
			while (bracketsopen != 0) {
				if (data->at(i) == ']' && bracketsopen == 1) {
					i++;
					break;
				}
				else if (data->at(i) == '[') {
					bracketsopen++;
				}
				else if (data->at(i) == ']') {
					bracketsopen--;
				}
				target += data->at(i);
				i++;
			}
			// add result to buffer
			buffer += decompressrec(reps, &target);
		}
	}
	string res = "";
	for (int i = 0; i < reps; i++) {
		res += buffer;
	}
	return res ;
}

string decompress(string * data) {
	return decompressrec(1, data);
}

int main33() {
	string s = "3[abc]4[ab]c";
	cout << decompress(&s) << endl;
	while(1){}
	return 0;
}
