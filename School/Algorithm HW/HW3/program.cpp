#include <iostream>
#include <vector>
#include <fstream>
#include <ctime>
#include <chrono>
#include <stack>

using namespace std;

void sccmatrix(vector<vector<int>> & matrix){

    // check time
    chrono::time_point<chrono::high_resolution_clock> start, end;
    start = chrono::high_resolution_clock::now();
    
    // print time
    end = chrono::high_resolution_clock::now();
    chrono::duration<double> elapsed_seconds = end - start;
    cout << elapsed_seconds.count() << "s" << endl;

}

void scclist(vector<vector<int>> & list){

    // check time
    chrono::time_point<chrono::high_resolution_clock> start, end;
    start = chrono::high_resolution_clock::now();
        
    // the node stack we want to obtain
    stack<int> vert;
    // stack resulting by dfs
    stack<int> tmp;
    // recurring stack
    stack<int> buffer;
    // visited vector
    vector<int> visited(list.size(),0);

    // do dfs and gather terminating sequence
    for(int i = 0; i < list.size() ; i++){
        if(visited[i]==0){
            buffer.push(i);
            while(buffer.size()!=0){
                tmp.push(buffer.top());
                int curr = buffer.top();
                visited[curr]=1;
                buffer.pop();
                for(int j = 0 ; j < list[i].size() ; j++){
                    if(visited[list[i][j]]==0){
                        buffer.push(list[i][j]);
                    }
                }
            }
        }
    }

    // fill vert buffer
    while(tmp.size()!=0){
        vert.push(tmp.top());
        tmp.pop();
    }

    // make a reverted graph
    vector<vector<int>> trans(list.size(),vector<int>());

    for(int i = 0 ; i < list.size() ; i++){
        for(int j = 0 ; j < list[i].size() ; j++){
            trans[list[i][j]].push_back(i);
        }
    }

    // do dfs on trans by vert order

    for(int x : visited) x = 0;

    vector<vector<int>> result(list.size(), vector<int>(list.size()));

    for(int i = 0 ; i < list.size() ; i++){
        if(visited[i]==0){
            buffer.push(i);
            while(buffer.size()!=0){
                
            }
        }
    }
    // print time
    end = chrono::high_resolution_clock::now();
    chrono::duration<double> elapsed_seconds = end - start;
    cout << elapsed_seconds.count() << "s" << endl;

}

void sccarray(vector<int> & ref, vector<int> & seq){

    // check time
    chrono::time_point<chrono::high_resolution_clock> start, end;
    start = chrono::high_resolution_clock::now();
    



    // print time
    end = chrono::high_resolution_clock::now();
    chrono::duration<double> elapsed_seconds = end - start;
    cout << elapsed_seconds.count() << "s" << endl;
    
}

int main(int argc, char ** argv){
    
    // check arguments
    if(argc!=2){
        cout << "[ERROR] invalid arguments";
        return 0;
    }

    // open file and initialize graphs
    ifstream openfile(argv[1]);

    int n;
    openfile >> n;
    vector<vector<int>> matrix(n,vector<int>(n,0));
    vector<vector<int>> adjlist(n,vector<int>()); 
    vector<int> arref(n,0);
    vector<int> arseq;

    for(int i = 0 ; i < n ; i++){
        int x;
        openfile >> x;
        for(int j = 0 ; j < x ; j++){
            int tmp;
            openfile >> tmp;
            matrix[i][tmp]=1;
            adjlist[i].push_back(tmp);
            arseq.push_back(tmp);
        }
        if(x!=0) arref.push_back(arseq.size());
        else arref.push_back(0);
    }
    
    for(int i = 0 ; i < matrix.size() ; i++){
        for(int j = 0 ; j < matrix[i].size(); j++){
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    for(int i = 0 ; i < adjlist.size() ; i++){
        for(int j = 0 ; j < adjlist.size() ; j++){
            cout << adjlist[i][j] << " ";
        }
        cout << endl;
    }

    for(int x : arseq) cout << x << " ";
    cout << endl;
    for(int x : arref) cout << x << " ";
    cout << endl;

    // print results

    sccmatrix(matrix);
    scclist(adjlist);
    sccarray(arref, arseq);

    return 0;
}