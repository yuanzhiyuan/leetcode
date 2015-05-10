#include "h.h"


typedef vector<int> bigint;

class Solution {
public:
	string multiply(string num1, string num2) {
		return bigint2string(multiply(string2bigint(num1), string2bigint(num2)));
	}

	bigint string2bigint(const string& n){
		auto n_begin = find_if(n.begin(), n.end(), [=](char a)->bool{return a != '0'; });
		int n_sz = distance(n_begin, n.end());
		bigint x(n_sz);
		for (int i = n.size() - 1,j=0; i != n.size() - n_sz - 1; i--,j++){
			x[j]=n[i]-'0';
		}
		return x;
	}
	string bigint2string(const bigint& n){
		auto n_end = find_if(n.rbegin(), n.rend(), [=](int a)->bool{return a != 0; });
		int n_sz = distance(n_end, n.rend());
		string x;
		transform(n_end, n.rend(), back_inserter(x), [](int a){return a + '0'; });
		return x;
	}

	bigint multiply(const bigint& n1, const bigint& n2){
		int n1_sz = n1.size();
		int n2_sz = n2.size();
		bigint n3(n1_sz + n2_sz);

		for (int i = 0; i<n1_sz; i++){
			for (int j = 0; j<n2_sz; j++){
				n3[i + j] += n1[i] * n2[j];
				n3[i + j + 1] += n3[i + j] / 10;
				n3[i + j] %= 10;
			}

		}
		auto n3_end = find_if(n3.rbegin(), n3.rend(), [=](int a)->bool{return a != 0; });
		n3.resize(distance(n3_end, n3.rend()));
		return n3;
	}


};

//int main(){
//	Solution s;
//	string rst = s.multiply("98", "9");
//	cout << rst << endl;
//
//	system("pause");
//}