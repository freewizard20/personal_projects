#include <fstream>
#include <iostream>
#include <cstdlib>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <string>

using namespace std;

/* rdchecker program
* goes through array to check if given int is kth smallest number.
* prints result.
*/

int main(int argc, char ** argv){
    
    // read the arguments
    int K = atoi(argv[1]);
    int res = atoi(argv[3]);
    ifstream data(argv[2]);

    // load the data into memory
    vector<int> book;
    while(!data.eof()){
        int t;
        data >> t;
        // to prevent reading last element twice
        if(data.eof()) break;
        book.push_back(t);
    }
    data.close();

    // iterate through book to find number of elements smaller than res
    int countsmaller = 0;
    int countsame = 0;
    for(int i = 0 ; i < book.size() ; i++){
        if(book[i]<res) countsmaller++;
        if(book[i]==res) countsame++;
    }

    // if K is in range of countsmaller ~ countsmaller + countsame ok.
    if(K>=countsmaller && K<=countsmaller+countsame){
        cout << "result matched. correct search for " << K <<"th element that is " << res << endl;
    }else{
        cout << "error " << res <<" is found from " << countsmaller << " to " << countsmaller+countsame << endl;
        cout << "and you said " << K << endl;
    }
}
