 
#include "head.h"
using namespace std;
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int sz = nums.size();
        if(sz==0)   return 0;
        if(sz==1)   return nums[0]>=target?0:1;
        int lo=0;
        int hi=sz-1;
        while(lo<=hi){
            int mid = (lo+hi)/2;
            if(nums[mid]==target)   return mid;
            else if(nums[mid]>target){
                hi = mid-1;
                
            }else{
            	
                lo = mid+1;
            }
        }
        return lo;
    }
    
};

int main(){
	Solution s;
	int a[] = {1,3,5};
	vector<int> aa(a,a+3);
	int rst = s.searchInsert(aa,5);
	cout << rst << endl;
	return 0;
}
