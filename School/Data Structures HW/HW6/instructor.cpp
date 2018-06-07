#include <iostream>
#include <fstream>
#include <ctime>
#include <cstdlib>
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <set>

using namespace std;

int main(int argc, char ** argv){
    ofstream out(argv[1]);
    int total = stoi(argv[2]);
    int density = stoi(argv[3]);
    
    // make a random graph
    srand(time(NULL));

    for(int i = 0 ; i < total ; i++){
        if(rand()%10<6){
            out << rand()%density << " " << rand()%density << endl;
        }else{
            out << rand()%density << " " << rand()%density << " !"<< endl;
        }
    }
    out << "QUIT" << endl;
    out.close();
}