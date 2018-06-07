#include <iostream>
#include <fstream>
#include <ctime>
#include <cstdlib>
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <set>
#include <random>       // std::default_random_engine
#include <chrono>       // std::chrono::system_clock

using namespace std;

int main(int argc, char ** argv){
    unsigned seed = chrono::system_clock::now().time_since_epoch().count();
    default_random_engine e(seed);
    ofstream out(argv[1]);
    int total = stoi(argv[2]);
    int density = stoi(argv[3]);
    int weight = stoi(argv[4]);
    
    // make a random graph
    srand(time(NULL));
    vector<int> rs;
    for(int i = 0 ; i < density ; i++){
        rs.push_back(i);
    }
    shuffle(rs.begin(),rs.end(),e);
    unordered_map<int,int> graph;
    for(int i = 0 ; i < total ; i++){
        int curr;
        if(i<density){
            curr = rs[i];
        }else{
            curr = (rand()*rand())%density;
        }
        out << i << " " << curr << " 3" << endl;
        graph.insert(pair<int,int>(i,curr));
    }
    out << endl;

    // make edges
    set<pair<int,int>> tmp;
    int x = 0;
    for(int i = 0 ; i < total-1;i++){
            out << i << " " << i+1 << " " << rand()*rand()%weight << endl;
        if(rand()%10>1){
            out << i+1 << " " << i << " " << rand()*rand()%weight << endl;
        }
    }

    out.close();
}