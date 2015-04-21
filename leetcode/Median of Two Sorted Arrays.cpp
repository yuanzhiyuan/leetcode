class Solution {
public:
    double findMedianSortedArrays(int A[], int m, int B[], int n) {
        int* conv = new int[m+n];
        int i,j,k;
        double result;
        i=j=k=0;
        while(i<m||j<n){
            if(i>=m){
                for(;j<n;j++){
                    conv[k++]=B[j];
                }
            }else if(j>=n){
                for(;i<m;i++){
                    conv[k++]=A[i];
                }
            }else{
                if(A[i]<B[j]){
                    conv[k++] = A[i];
                    i++;
                }else{
                    conv[k++] = B[j];
                    j++;
                }
            }
        }
        result = k&1?conv[k/2]:((conv[k/2-1]+conv[k/2])/2.0);
        delete[] conv;
        return result;
    }
};
