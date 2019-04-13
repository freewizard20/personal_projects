#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int clothes[100000];
int n;

int main(){
    int t;
    cin >> t;
    for(int z = 0 ; z < t ; z++){
       cin >>n;
       for(int i = 0 ; i < n ; i++){
           cin >> clothes[i];
       }
       int total = 0;
       sort(clothes, clothes+n, greater<int>());
	   for(int i = 0 ; i < n ; i++){
           if(i%3==2) continue;
           total += clothes[i];
       }
       cout << "#" << (z+1) << " " << total << endl;
    }
}
