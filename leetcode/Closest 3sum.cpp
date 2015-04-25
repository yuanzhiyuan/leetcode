
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int result = 0;
        int min_gap = INT_MAX;
        sort(nums.begin(),nums.end());
        
        for(auto i=nums.begin();i!=prev(nums.end(),2);++i){
            auto j = next(i);
            auto k = prev(nums.end());
            while(j<k){
                const int sum = *i+*j+*k;
                const int gap = abs(sum-target);
                if(gap<min_gap){
                    min_gap = gap;
                    result = sum;
                }
                if(sum<target)  j++;
                else    k--;
            }
        }
        return result;
    }
};




