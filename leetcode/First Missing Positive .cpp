class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        if(nums.size()==0)  return 1;
        
        sort(nums.begin(),nums.end());
        auto i = upper_bound(nums.begin(),nums.end(),0);
        int j=1;
        int pre = -1;
        for(;i!=nums.end();i++,j++){
            if(pre==*i){
                j--;
                continue;
            }
            if(j!=*i)   return j;
            pre = *i;
        }
        return j;
    }
};
