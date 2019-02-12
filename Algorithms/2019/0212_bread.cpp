#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

int n,m,k;

int main(){
    int t;
    cin >> t;
    for(int z = 0 ; z < t ; z++){
        cin >> n >> m >> k;
        int total = 0;
        vector<int> customers;
        for(int i = 0 ; i < n ; i++){
            int tmp;
            cin >> tmp;
            customers.push_back(tmp);
        }
        sort(customers.begin(), customers.end());
        int curr = 0;
        int possible = 1;
        for(int i = 0 ; i < 11112 ; i++){
            if(i!=0 && i%m==0){
                total += k;
            }
            while(curr < n && customers[curr]<=i){
                total--;
                if(total<0){
                    possible = 0;
                    break;
                }
                curr++;
            }
            if(possible==0){
                break;
            }
        }
        if(possible==1){
            cout << "#" << (z+1) << " " << "Possible" << '\n';
        }else{
            cout << "#" << (z+1) << " " << "Impossible" << "\n";
        }
    }
}
