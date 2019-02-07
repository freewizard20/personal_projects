#include <iostream>

using namespace std;

int n;

int main(){
    cin >> n;
    for(int i = 1 ; i <= n; i++){
        int count = 0;
        int tmp = i;
        while(tmp!=0){
            if(tmp%10==3 || tmp%10==6 || tmp%10==9){
                count++;
            }
            tmp /= 10;
        }
        if(count==0){
            cout << i << " ";
        }else{
            for(int j = 0 ; j < count ; j++){
                cout << "-";
            }
            cout << " ";
        }
    }
}
