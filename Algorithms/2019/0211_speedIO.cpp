#include <iostream>

using namespace std;

int main(){
    
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    
    int t;
    cin >> t;
    for(int z = 0 ; z < t ; z++){
        int tmp;
        cin >> tmp;
        int ret = 0;
        if(tmp < 100){
        }else if(tmp >= 100 && tmp < 1000){
            ret = 1;
        }else if(tmp >= 1000 && tmp < 10000){
            ret = 2;
        }else if(tmp >= 10000 && tmp < 100000){
            ret = 3;
        }else if(tmp >= 100000 && tmp < 1000000){
            ret = 4;
        }else{
            ret = 5;
        }
        cout << "#" << (z+1) << " " << ret << "\n";
    }
}
