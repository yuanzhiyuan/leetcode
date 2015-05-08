class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        if(n==0)    return 0;
        int max_i=0;
        //�ҳ���߷壬Ȼ�����������һ��Ϊ�����ͱ�֤�����Ҷ��С���ɽ�� 
        for(int i=1;i<n;i++){
            if(height[i]>height[max_i]) max_i = i;
        }
        int sum;
        //����С����ߵ�ǰ���ʱ����Ϊ�ұ��п�ɽ�����Կ���ֱ�Ӽ�sum 
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
