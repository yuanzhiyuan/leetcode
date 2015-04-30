class Solution {
public:
    int removeDuplicates(int A[], int n) {
        if(n==0)    return 0;
        if(n==1)    return 1;
        //k表示因重复而留下的空位数
        int k;
        int i=1;
        for(;i<n;i++){
            if(A[i]==A[i-1])    k++;
            else if(k!=0)   A[i-k]=A[i];
        }
        return n-k;
    }
};
