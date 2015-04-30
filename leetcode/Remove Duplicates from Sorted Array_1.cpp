class Solution {
public:
    int removeDuplicates(int A[], int n) {
        if(n==0)    return 0;
        //指向真正返回的数组的栈顶
        int index=0;
        //i指向扫描的栈顶
        for(int i=1;i<n;i++){
            if(A[index]!=A[i]){
                A[++index]=A[i];
            }
            
        }
        return index+1;
    }
};
