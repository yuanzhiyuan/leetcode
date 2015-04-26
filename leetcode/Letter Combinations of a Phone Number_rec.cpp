class Solution {
public:
    
    const vector<string> keyboard{"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    
    vector<string> letterCombinations(const string& digits){
        
        vector<string> result;
        if(digits.size()==0)    return result;
        dfs(digits,0,"",result);
        return result;
    }
    
    void dfs(const string& digits,size_t cur,string path,vector<string>& result){
        if(cur==digits.size()){
            result.push_back(path);
            return;
        }
        // string a = keyboard[digits[cur]-'0'];
        for(auto c:keyboard[digits[cur]-'0']){
            dfs(digits,cur+1,path+c,result);
        }
        
    }
};
