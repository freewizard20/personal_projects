#include <vector>
#include <iostream>
#include <fstream>

using namespace std;

class rbt{
public:
  rbt(){
      vector<int> tmp(1000,0);
      data = tmp;
  }
  int insert(int x);
  int remove(int x);
  int select(int x);
  int rank(int x);
private:
  vector<int>  data;
};

int rbt::insert(int x){
    if(data[x]==0){
        data[x]=1;
        return x;
    }else{
        return 0;
    }
    return 0;
}

int rbt::remove(int x){
    if(data[x]==1){
        data[x]=0;
        return x;
    }else{
        return 0;
    }
    return 0;
}

int rbt::select(int x){
    int count = 0;
    for(int i = 0 ; i < 1000 ; i++){
        if(data[i]==1) count++;
        if(count==x) return i;
    }
    return 0;
}

int rbt::rank(int x){
    if(data[x]==0){
        return 0;
    }else{
        int count = 0;
        for(int i = 0 ; i <= x ; i++){
            if(data[i]==1) count++;
        }
        return count;
    }
    return 0;
}

int main(int argc, char **argv){   
    vector<pair<char,int> > inst;
    vector<int> res;
    // checker for valid arguments
    if(argc!=3){
        cout << "[ERROR] invalid arguments : give input and output!" << endl;
        return 0;
    }
    // read file to memory
   ifstream openfile(argv[1]);
   ifstream openfile2(argv[2]);
   while(openfile && !openfile.eof()){
        char tmp1;
        int tmp2;
        openfile >> tmp1 >> tmp2;
        //if(openfile.eof()) break;
        inst.push_back(pair<char,int>(tmp1,tmp2));
    }
    while(openfile2 && !openfile2.eof()){
        int sam;
        openfile2 >> sam;
        if(openfile2.eof()) break;
        res.push_back(sam);
    }

    if(res.size()!=inst.size()){
        cout << "[ERROR] input and output files don't match" << endl;
        return 0;
    }
    
    // do instructions and match result
    rbt book;
    int right = 0;
    for(int i = 0 ; i < inst.size();i++){
        char x = inst[i].first;
        int comp = -1;
        switch(x){
            case 'I':
                comp = book.insert(inst[i].second);
                break;
            case 'R':
                comp = book.rank(inst[i].second);
                break;
            case 'S':
                comp = book.select(inst[i].second);
                break;
            case 'D':
                comp = book.remove(inst[i].second);
                break;
            default:
                cout << "invalid input found";
                return 0;
                break;
        }
        if(comp==res[i]) right++;
        else{
            cout << "[ERROR] " << "on " << i+1 <<"th instuction, done " << inst[i].first << " " << inst[i].second <<  " expected " << comp << " but " << res[i] << " found" << endl;
        }
    }
    
    // print result
    cout << (float)right*100/inst.size() << "% matched" << endl;
    return 0;
}
