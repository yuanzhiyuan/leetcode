#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
    bool isMatch(string s, string p) {
        int i=0,j=0;
        for(;i<s.size()&&j<p.size();){
        	
//        	if(p[j]=='.'){
//                return isMatch(s.substr(i,s.size()-i),s[i]+p.substr(j+1,p.size()-j-1));
//            }
        	
        	
            if(p[j+1]=='*'){
                int k=0;
                if(isMatch(s.substr(i+k,s.size()-i-k),p.substr(j+2,p.size()-j-2)))	return true;
                k++;
                for(;i+k-1<s.size()&&(p[j]==s[i+k-1]||p[j]=='.');k++){
                    if(isMatch(s.substr(i+k,s.size()-i-k),p.substr(j+2,p.size()-j-2)))	return true;
                }
//                if(i+k==s.size())   return true;
                return false;
            }
            
            
            
            if(!isSp(p[j])){
                if(p[j]==s[i]){
                    i++;
                    j++;
                    continue;
                }else{
                    return false;
                }
                
            }
			else if(p[j]=='.'){
                return isMatch(s.substr(i,s.size()-i),s[i]+p.substr(j+1,p.size()-j-1));
            }
        }
        if(i==s.size()&&j==p.size())	return true;
        return false;
    }
    bool isSp(char c){
        return c=='.'||c=='*';
    }
};


int main(){
	Solution s;
	bool rst = s.isMatch("aaaa",".*.*");
	cout << rst << endl;
	return 0;
}
