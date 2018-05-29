#include "stdafx.h"
#include <iostream>
#include <string>
using namespace std;

int main() {
	string sam;
	getline(cin, sam);
	for (int i = 0; i<sam.length() / 10; i++) {
		for (int j = 0; j<10; j++) {
			cout << sam[10*i + j];
		}
		cout << endl;
	}
	for (int i = 0; i<sam.length() % 10; i++) {
		cout << sam[10 * (sam.length() / 10) + i];
	}
}
