class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> rst;
        sort(nums.begin(),nums.end());
        
        do{rst.push_back(nums);}
        while(next_permute(nums));
        return rst;
    }
    
    bool next_permute(vector<int>& nums){
        
        int n = nums.size();
        int i=n-1;
        for(;i>0;i--){
            if(nums[i]<=nums[i-1])  continue;
            else break;
        }
        if(i==0)    return false;
        int change = i-1;
        i=n-1;
        for(;nums[i]<=nums[change];i--);
        
        int change_ = i;
        
        i=nums[change];
        nums[change] = nums[change_];
        nums[change_] = i;
        reverse(nums,change+1,n-1);
        return true;
        
    }
    void reverse(vector<int>& nums,int beg,int end){
        for(int i=beg,j=end;i<=j;i++,j--){
            int tmp;
            tmp=nums[i];
            nums[i]=nums[j];
            nums[j]=tmp;
        }
    }
};
