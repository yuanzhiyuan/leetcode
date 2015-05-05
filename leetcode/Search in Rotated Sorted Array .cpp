class Solution {
public:
    int search(vector<int>& nums, int target) {
        int sz = nums.size();
        int mid = nums[0];
        int rot = 0;
        if(target==mid) return 0;
        if(target>mid)  
        {   auto pnum = nums.begin();
            for(;pnum!=prev(nums.end())&&(*pnum<*next(pnum));pnum++){
                if(target==*next(pnum))   return distance(nums.begin(),next(pnum));
            }
            return -1;
            
        }
        if(target<mid){
            if(target>nums[sz-1])   return -1;
            if(target==nums[sz-1])  return sz-1;
            for(auto pn=nums.rbegin();pn!=prev(nums.rend())&&(*pn>*next(pn));pn++){
                if(target==*next(pn))   return sz-distance(nums.rbegin(),next(pn))-1;
            }
            return -1;
        }
        
    }
};
