#include <iostream>
#include <vector>

using namespace std;

int n, l;
int points[20];
int calories[20];

int findmax(int m, int remainder){
    if(m==n){
        return 0;
    }
    int ret = 0;
    if(remainder >= calories[m]){
        ret = max(findmax(m+1, remainder-calories[m])+points[m], findmax(m+1, remainder));
    }else{
        ret = findmax(m+1, remainder);
    }
    return ret;
}

int main(){
    int t;
    cin >> t;
    for(int z = 0 ; z < t ; z++){
        cin >> n >> l;
        for(int i = 0 ; i < n ; i++){
            cin >> points[i] >> calories[i];
        }
        cout << "#" << (z+1) << " " << findmax(0, l) << endl;
    }
}
