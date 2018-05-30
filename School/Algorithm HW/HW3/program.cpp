#include <iostream>
#include <vector>
#include <fstream>
#include <ctime>
#include <chrono>
#include <stack>
#include <algorithm>
#include <unordered_set>
#include <queue>

using namespace std;

bool custom(vector<int> a, vector<int> b){
    return a[0]<b[0];
}

void sccmatrix(vector<vector<int>> & matrix){

    // check time
    chrono::time_point<chrono::high_resolution_clock> start, end;
    start = chrono::high_resolution_clock::now();
    
    // print time
    end = chrono::high_resolution_clock::now();
    chrono::duration<double> elapsed_seconds = end - start;
    cout << elapsed_seconds.count() << "s" << endl;

}

void filldfs(int curr, vector<int> & visited, vector<vector<int>> & list, stack<int> & vert){
    if(visited[curr]==1) return;
    visited[curr]=1;
    for(int i = 0 ;i<list[curr].size();i++){
        if(visited[list[curr][i]]==0) filldfs(list[curr][i],visited,list,vert);
    }
    vert.push(curr);
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
            tmp.push(i);
            while(buffer.size()!=0){
                int curr = buffer.top();
                buffer.pop();
                if(visited[curr]==0) {
                    visited[curr]=1;
                    tmp.push(curr);
                    for(int j = 0 ; j < list[i].size() ; j++){
                        if(visited[list[i][j]]==0){
                            buffer.push(list[i][j]);
                        }
                    }
                }
            }
            unordered_set<int> checker;
            while(tmp.size()!=0){
                auto it = checker.find(tmp.top());
                if(it==checker.end()){
                    vert.push(tmp.top());
                    checker.insert(tmp.top());
                }
                tmp.pop();
            }
        }
    }



    // fill vert buffer
    /*cout << "see tmp buffer" << endl;

    while(tmp.size()!=0){
        vert.push(tmp.top());
        cout << tmp.top() << " ";
        tmp.pop();
    }

    cout << endl;
    */
    
    /*for(int i = 0 ; i < list.size() ; i++){
        if(visited[i]==0) filldfs(i,visited,list,vert);
    }*/
    
    
    /*cout << "see vert" << endl;
    while(vert.size()!=0){
        tmp.push(vert.top());
        cout << vert.top() << " ";
        vert.pop();
    }
    cout << endl;
    while(tmp.size()!=0){
        vert.push(tmp.top());
        tmp.pop();
    }*/

    // make a reverted graph
    vector<vector<int>> trans(list.size(),vector<int>());

    for(int i = 0 ; i < list.size() ; i++){
        for(int j = 0 ; j < list[i].size() ; j++){
            trans[list[i][j]].push_back(i);
        }
    }

    /*
    cout << "see trans buffer" << endl;
    for(int i = 0 ; i < trans.size() ; i++){
        for(int j = 0 ; j < trans[i].size() ; j++){
            cout << trans[i][j] << " ";
        }
        cout << endl;
    }
    */

    // do dfs on trans by vert order

    for(int i = 0 ; i < visited.size() ; i++){
        visited[i]=0;
    }

    vector<vector<int>> result;

    while(vert.size()!=0){
        int i = vert.top();
        vert.pop();
        if(visited[i]==0){
            //cout << "big : " << i << endl;
            buffer.push(i);
            result.push_back(vector<int>());
            while(buffer.size()!=0){
                int curr = buffer.top();
                //cout << "curr : " << curr << " ";
                if(visited[curr]==0){
                    result[result.size()-1].push_back(buffer.top());
                    visited[curr]=1;
                }
                buffer.pop();
                for(int j = 0 ; j < trans[curr].size() ; j++){
                    if(visited[trans[curr][j]]==0){
                        //cout << "pushing " << trans[curr][j] << endl;
                        buffer.push(trans[curr][j]);
                    }
                }
            }
            cout << endl;
        }
    }
    // print time
    end = chrono::high_resolution_clock::now();


    // sort and print result
    for(int i = 0 ; i < result.size() ; i++){
        sort(result[i].begin(),result[i].end());
    }

    sort(result.begin(),result.end(),custom);

    cout << "print result" << endl;
    ofstream out("out.txt");

    for(int i = 0 ; i < result.size() ; i++){
        for(int j = 0 ; j < result[i].size();j++){
            if(j==result[i].size()-1){
                cout << (result[i][j]+1) << endl;
                out << (result[i][j]+1) << " " << endl;
            }else{
                cout << (result[i][j]+1) << " " ;
                out << (result[i][j]+1) << " " ;
            }
        }
    }

    out.close();

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
    vector<int> arref;
    vector<int> arseq;

    for(int i = 0 ; i < n ; i++){
        int x;
        openfile >> x;
        for(int j = 0 ; j < x ; j++){
            int tmp;
            openfile >> tmp;
            tmp--;
            matrix[i][tmp]=1;
            adjlist[i].push_back(tmp);
            arseq.push_back(tmp);
        }
        if(x!=0) arref.push_back(arseq.size());
        else arref.push_back(0);
    }
    /*
    cout << "see matrix" << endl;
    for(int i = 0 ; i < matrix.size() ; i++){
        for(int j = 0 ; j < matrix[i].size(); j++){
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    
    cout << "see list" << endl;
    for(int i = 0 ; i < adjlist.size() ; i++){
        for(int j = 0 ; j < adjlist[i].size() ; j++){
            cout << adjlist[i][j] << " ";
        }
        cout << endl;
    }

    cout << "see arr" << endl;
    for(int x : arseq) cout << x << " ";
    cout << endl;
    for(int x : arref) cout << x << " ";
    cout << endl;
    */
    // print results

    sccmatrix(matrix);
    scclist(adjlist);
    sccarray(arref, arseq);

    return 0;
}