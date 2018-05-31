#include <iostream>
#include <fstream>
#include <ctime>
#include <cstdlib>
#include <vector>
#include <string>

int main(int argc, char ** argv){
    ofstream out(argv[1]);
    int total = stoi(argv[2]);
    int density = stoi(argv[3]);
    
    // make a random graph
    srand(time(NULL));
    vector<vector<int>> matrix(total,vector<int>(total,0));
    for(int i = 0 ; i < (density*total)/5; i++){
        int x = rand()%total;
        int y = rand()%total;
        matrix[x][y] = 1;
    }

    // print result
    out << total << endl;
    for(int i = 0 ; i < total ; i++){
        int count = 0;
        for(int j = 0 ; j < total ; j++){
            if(matrix[i][j]==1) count++;
        }
        out << count << " ";
        for(int j = 0 ; j < total ; j++){
            if(matrix[i][j]==1) out << j << " ";
        }
        out << endl;
    }

    out.close();
    
}