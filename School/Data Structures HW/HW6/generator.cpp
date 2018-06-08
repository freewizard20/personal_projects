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
    
    vector<vector<vector<int>>> nodes;
    srand(time(NULL));
    nodes.push_back(vector<vector<int>>());
    for(int i = 0 ; i < total; i ++){
        if(rand()%(total/20)==0){
            // make new line
            nodes.push_back(vector<vector<int>>());
        }
        nodes[nodes.size()-1].push_back({i,i});
    }

    // make duplicate nodes
    int count = total;
    for(int i = 0 ; i < density ; i++){
        int num = rand()%10;
        vector<vector<int>> tmp;
        for(int j = 0 ; j < num ; j++){
            int curr = rand()%(nodes.size());
            int curr2 = rand()%(nodes[curr].size());
            tmp.push_back({curr,curr2});
        }
        for(int j = 0 ; j < tmp.size() ; j++){
            nodes[tmp[j][0]][tmp[j][1]][1] = count;
        }
        count++;
    }

    for(int i = 0 ; i < nodes.size() ; i++){
        nodes[i][0][1] = 76767676;
    }


    // rename nodes
    unordered_map<int,int> map;
    count = 0;
    for(int i = 0 ; i < nodes.size() ; i++){
        for(int j = 0 ; j < nodes[i].size() ; j++){
            if(map.find(nodes[i][j][1])==map.end()){
                map.insert(pair<int,int>(nodes[i][j][1],count));
                nodes[i][j][1]=count;
                count++;
            }else{
                nodes[i][j][1] = map.find(nodes[i][j][1])->second;
            }
        }
    }

    cout << count << endl;

    // print nodes
    for(int i = 0 ; i < nodes.size() ; i++){
        for(int j = 0 ; j < nodes[i].size() ; j++){
            out << nodes[i][j][0] << " " << nodes[i][j][1] << " " << i << endl;
        }
    }
    out << endl;

    // print edges

    for(int i = 0 ; i < nodes.size() ; i++){
        for(int j = 0 ; j < nodes[i].size()-1 ; j++){
            out << nodes[i][j][0] << " " << nodes[i][j+1][0] << " " << (rand()*rand())%weight << endl;
            if(rand()%10<8) out << nodes[i][j+1][0] << " " << nodes[i][j][0] << " " << (rand()*rand())%weight << endl;
        }
    }




/*    // make a random graph
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
    }*/

    out.close();
}