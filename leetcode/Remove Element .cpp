class Solution {
public:
    int removeElement(int A[], int n, int elem) {
        if(n==0)    return 0;
        sort(A,A+n);
        int* i = find(A,A+n,elem);
        if(i==A+n)  return n;
        int* j = upper_bound(A,A+n,elem);
        copy(j,A+n,i);
        return n-distance(i,j);
    }
};
