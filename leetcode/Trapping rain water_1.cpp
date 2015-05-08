class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int max_left[n];
        int max_right[n];
        fill_n(max_left,n,0);
        fill_n(max_right,n,0);
        //找出在i以左（右）最高的高度 
        for(int i=1;i<n;i++){
            max_left[i] = max(max_left[i-1],height[i-1]);
            max_right[n-i-1] = max(max_right[n-i],height[n-i]);
        }
        int sum=0;
        
        for(int i=0;i<n;i++){
            int h = min(max_left[i],max_right[i]);
            if(h>height[i]) sum+=h-height[i];
        }
        return sum;
    }
};
