#include <iostream>
#include <vector>
#include <string>

using namespace std;

int ok(vector<string> & jackpots, vector<string> & poles, int i, int j){
    int ret = 1;
    for(int k = 0 ; k < 8 ; k++){
        if(jackpots[j][k]=='*') continue;
        if(jackpots[j][k] != poles[i][k]){
            ret = 0;
            break;
        }
    }
    return ret;
}

int main(){
    int t;
    cin >> t;
    for(int z = 0 ; z < t ; z++){
        int n, m;
        cin >> n >> m;
        vector<string> jackpots;
        vector<int> points;
        vector<string> poles;
        for(int i = 0 ; i < n ; i++){
            string tmp;
            int tmp2;
            cin >> tmp >> tmp2;
            jackpots.push_back(tmp);
            points.push_back(tmp2);
        }
        for(int i = 0 ; i < m ; i++){
            string tmp;
            cin >> tmp;
            poles.push_back(tmp);
        }
        // check total earnings
        int total = 0;
        for(int i = 0 ; i < m ; i++){
            for(int j = 0 ; j < n ; j++){
                if(ok(jackpots, poles, i, j)) total += points[j];
            }
        }
        cout << "#" << (z+1) << " " << total << endl;
    }
}
