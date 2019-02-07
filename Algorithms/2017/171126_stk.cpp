#include "stdafx.h"
#include <iostream>
using namespace std;
#include <cstdlib>
#include <ctime>
#include "stcktp1.h"
const int Num = 10;
int main() {
	srand(time(0)); // random value seed
	cout << "스택의 크기를 입력하십시오";
	int stacksize;
	cin >> stacksize;
	Stack<const char *>st(stacksize);
	const char*in[Num] = { //char * pointer으로 문자열을 받을수 있는듯
		"1:ㅇㅇㅇ","2:aaa","3:ㅂㅂㅈ","4:ㄱㄱㄷ","5:ㅎㅎㅎ","6:ㅛㅅㄱ","7:23ㅁ","8:ㄹㅈㅈ","9:ㅗㅎㄹ","10:ㄷㄷㄷ"
	};
	const char * out[Num];
	int processed = 0;
	int nextin = 0;
	while (processed < Num) {
		if (st.isempty()) 
			st.push(in[nextin++]); // 이 포인터 원소를 저장한다
		else if (st.isfull())
			st.pop(out[processed++]); // out[processed]에 pop하고 덧셈
		else if (rand() % 2 && nextin < Num)//rand()함수는 1 ~ RAND_MAX 까지의 랜덤 재생
			st.push(in[nextin++]);
		else
			st.pop(out[processed++]);
	}
	for (int i = 0; i < Num; i++)
		cout << out[i] << endl;
	cout << "end" << endl;
	return 0;
}
