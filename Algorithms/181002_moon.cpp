#include <iostream>
#include <cstdio>

using namespace std;

int main(){
	do{
		float a;
		cin >> a;
		if(a==-1.0) break;
		printf("Objects weighing %.2f on Earth will weigh %.2f on the moon.\n", a, a * 0.167);
	}while(1);
}
