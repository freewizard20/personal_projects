class Solution {
public:
    string longestPalindrome(string s) {
        string ret(s.begin(),s.begin()+1);
        for(int i = 0 ; i < s.size() ; i++){
            for(int j = i,k=i ; j >=-1&&k<=s.size() ; j--,k++ ){
                if(j==-1||k==s.size()||s.at(j)!=s.at(k)){
                    if(k-j-1>ret.size()){
                        string z(s.begin()+j+1,s.begin()+k);
                        ret = z;
                    }
                    break;
                }
            }
            if(i!=s.size()-1 && s[i]==s[i+1]){
                if(ret.size()<2){
                    string z(s.begin()+i,s.begin()+i+2);
                    ret = z;
                }
                for(int j = i , k = i+1 ; j>=-1&&k<=s.size();j--,k++){
                    if(j==-1||k==s.size()||s[j]!=s[k]){
                        if(k-j-1>ret.size()){
                            string z(s.begin()+j+1,s.begin()+k);
                            ret = z;
                        }
                        break;
                    }
                }
            }
        }
        return ret;
    }
};
