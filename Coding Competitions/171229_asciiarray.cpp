// mexicancode.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
#include <iostream>
#include <string>
using namespace std;
int main() {
	char sam[5] = "5432";
	cout << (int) sam[3] + (int) sam[2] - 2 * '0' << endl;
}
