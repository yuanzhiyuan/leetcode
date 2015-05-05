class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int sz = nums.size();
        if(sz==1){
            if(nums[0]==target) return {0,0};
            else return {-1,-1};
        }
        int lo=0;
        int hi=nums.size()-1;
        while(hi>=lo){
            int mid = (lo+hi)/2;
            if(nums[mid]==target){
                
                int left=mid,right=mid;
                
                while(nums[left]==target){
                    
                    left--;
                    if(left==-1) break;
                }
                while(nums[right]==target){
                    
                    right++;
                    if(right==sz) break;
                }
                return {left+1,right-1};
                
                
                
                
            }else if(nums[mid]>target){
                hi = mid-1;
            }else{
                lo = mid+1;
            }
        }
        return {-1,-1};
    }
};
