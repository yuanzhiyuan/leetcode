class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> rst;
        vector<int> path;
        dfs(rst,nums,path);
        return rst;
    }
    
    void dfs(vector<vector<int>>& rst,const vector<int>& nums,vector<int>& path){
        if(path.size()==nums.size()){
            rst.push_back(path);
            return;
        }
        for(int i:nums){
            auto pi = find(path.begin(),path.end(),i);
            if(pi==path.end()){
                path.push_back(i);
                dfs(rst,nums,path);
                path.pop_back();
            }
        }
    }
    
    
};
