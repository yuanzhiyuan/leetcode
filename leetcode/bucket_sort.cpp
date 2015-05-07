#include <iostream>

using namespace std; 


void bucket_sort(int A[], int n) {
for (int i = 0; i < n; i++) {
while (A[i] != i + 1) {
if (A[i] <= 0 || A[i] > n || A[i] == A[A[i] - 1])
break;
swap(A[i], A[A[i] - 1]);
}
}
}


int main(){
	int A[]={3,5,8,6,7,1,1,2,4};
	bucket_sort(A,9);
	for(int i=0;i<sizeof(A)/sizeof(A[0]);i++){
		cout << A[i] << " ";
	}
	return 0;
}
