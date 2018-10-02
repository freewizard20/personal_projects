#include <iostream>

using namespace std;

int main(){
    int n;
    cin >> n;
    for(int z = 0 ; z < n ; z++){
        int curr = 0;
        for(int i = 0 ; i < 10 ; i++){
            int x;
            cin >> x;
            if(x%2==1) curr+=x;
        }
        cout << "#" << (z+1) << " " << curr << endl;
    }
}
