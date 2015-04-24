class Solution {
public:
    int maxArea(vector<int>& height) {
        int start = 0;
        int end = height.size()-1;
        int rst = INT_MIN;
        while(start<end){
            int cur = min(height[end],height[start]) * (end-start);
            rst = max(cur,rst);
            if(height[end]<height[start])   end--;
            else    start ++;
        }
        return rst;
    }
};
