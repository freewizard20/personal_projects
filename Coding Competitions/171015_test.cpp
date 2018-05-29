// theseventh.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

int main()
{
	int *p;
	int a = 12;
	p = &a;
	cout << *p << endl;
	while (1) {}
    return 0;
}
