class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        gen(n,0,0,"",result);
        return result;
    }
    
    
    void gen(int n,int l,int r,string cur,vector<string>& result){
        if(n==l){
            result.push_back(cur.append(n-r,')'));
            return;
        }
        gen(n,l+1,r,cur+'(',result);
        if(l>r){
            gen(n,l,r+1,cur+")",result);
        }
        
    }
};
