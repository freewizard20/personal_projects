#include <iostream>
#include <string>

using namespace std;

int main(){
    int t;
    cin >> t;
    for(int z = 0 ; z < t ; z++){
        string s;
        cin >> s;
        // first line
        cout << "..#";
        for(int i = 0 ; i < s.size()-1; i++){
            cout << "...#";
        }
        cout << ".." << endl;
        // second line
        for(int i = 0 ; i < s.size() * 2 ; i++){
            cout << ".#";
        }
        cout << "." << endl;
        // third line
        for(int i = 0 ; i < s.size() ; i++){
            cout << "#." << s[i] <<".";
        }
        cout << "#" << endl;
        // fourth line
        for(int i = 0 ; i < s.size() * 2 ; i++){
            cout << ".#";
        }
        cout << "." << endl;
        // fifth line
        cout << "..#";
        for(int i = 0 ; i < s.size()-1; i++){
            cout << "...#";
        }
        cout << ".." << endl;
    }
}
