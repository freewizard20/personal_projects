class Solution {
public:
    string convert(string s, int numRows) {
        vector<string> tmp(numRows,"");
        for(string s : tmp){
            s.reserve(s.size()/numRows);
        }
        int curr = 0;
        int direction = 1;
        for(int i = 0 ; i < s.size() ; i++){
            tmp.at(curr) += s[i];
            curr += direction;
            if(curr==numRows-1) direction = -1;
            if(curr==0) direction = 1;
            if(numRows == 1) curr = 0;
        }
        string ret = "";
        ret.reserve(s.size());
        for(int i = 0 ; i < tmp.size() ; i++){
            ret+=tmp.at(i);
        }
        return ret;
    }
};
