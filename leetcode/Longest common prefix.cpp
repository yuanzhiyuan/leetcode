class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size()==0)  return "";
        if(strs.size()==1)  return strs[0];
        if(strs.size()==2){
            int i=0;
            for(;i<strs[0].size()&&i<strs[1].size();i++){
                if(strs[0][i]==strs[1][i])  continue;
                else    return strs[0].substr(0,i);
            }
            if(i==strs[0].size()) return strs[0];
            else    return strs[1];
        }
        vector<string> two_part;
        vector<string> former(strs.begin(),strs.begin()+strs.size()/2);
        vector<string> latter(strs.begin()+strs.size()/2,strs.end());
        two_part.push_back(longestCommonPrefix(former));
        two_part.push_back(longestCommonPrefix(latter));
        return longestCommonPrefix(two_part);
        
        
        
        
        
    }
};
