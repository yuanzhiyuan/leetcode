#inclide "h.h"

class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        unordered_map<int,int> n_count;
        for(int i:nums){
            n_count[nums[i]]++;
        }
        vector<vector<int>> rst;
        vector<int> path;
        dfs(nums,n_count,rst,path);
        sort(rst.begin(),rst.end());
        rst.erase(unique(rst.begin(),rst.end()),rst.end());
        return rst;
    }
    
    
    void dfs(const vector<int>& nums,unordered_map<int,int>& n_count,vector<vector<int>>& rst,vector<int>& path){
        if(path.size()==nums.size()){
            rst.push_back(path);
            return;
        }
        for(int i:nums){
            auto map_pos = n_count.find(i);
            if(map_pos!=n_count.end()){
                if(map_pos->second>0){
                    map_pos->second--;
                    path.push_back(i);
                    dfs(nums,n_count,rst,path);
                    path.pop_back();
                    map_pos->second++;
                }else{
                    continue;
                }
            }else{
                return;
            }
        }
    }
    
};


