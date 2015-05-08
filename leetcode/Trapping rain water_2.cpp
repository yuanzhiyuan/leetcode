class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        if(n==0)    return 0;
        int max_i=0;
        //找出最高峰，然后把整个数组一分为二。就保证了左右都有“靠山” 
        for(int i=1;i<n;i++){
            if(height[i]>height[max_i]) max_i = i;
        }
        int sum;
        //发现小于左边当前最高时，因为右边有靠山，所以可以直接加sum 
        for(int i=0,peak=0;i<max_i;i++){
            if(height[i]<peak) sum+=peak-height[i];
            else    peak = height[i];
        }
        for(int i=n-1,peak=0;i>max_i;i--){
            if(height[i]<peak) sum+=peak-height[i];
            else    peak = height[i];
        }
        return sum;
    }
};
