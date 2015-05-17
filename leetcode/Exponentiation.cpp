#include <iostream>
#include <string>
#include <math.h>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <unordered_map>
using namespace std;


class BigCal{

public: 

	struct N{
		int point;
		vector<int> num;
	};

	string pow(string s, int n,bool cache){
		
		pow_cache.clear();
		if (cache){
			return s_pow_cache(s, n);
		}
		return s_pow(s, n);
	}
	


private:

	
	unordered_map<string, string> pow_cache;//记录平方的值
	string get_cache(const string& s){
		auto pos = pow_cache.find(s);
		if (pos == pow_cache.end()){
			return pow_cache[s] = s_mul(s, s);
		}
		else{
			return pow_cache[s];
		}

	}

	N v_mul(const N& a, const N& b){
		N rst;
		int a_sz = a.num.size();
		int b_sz = b.num.size();
		rst.num.resize(a_sz + b_sz);
		for (int i = 0; i < a_sz; i++){
			for (int j = 0; j < b_sz; j++){
				rst.num[i + j] += a.num[i] * b.num[j];
				rst.num[i + j + 1] += rst.num[i + j] / 10;
				rst.num[i + j] %= 10;
			}

		}
		while (rst.num[rst.num.size() - 1] == 0){
			rst.num.pop_back();
		}//去掉高位的0
		rst.point = a.point + b.point;
		return rst;
	}

	string s_mul(const string& a, const string& b){
		return N2s(v_mul(s2N(a), s2N(b)));
	}

	string N2s(const N& a){
		string rst;
		int a_sz = a.num.size();
		//copy(a.num.rbegin(), a.num.rend(), back_inserter(rst));
		if (a.point >= a_sz){
			rst += "0.";
			rst += string(a.point - a_sz, '0');
			//copy(a.num.rbegin(), a.num.rend(), back_inserter(rst));
			for_each(a.num.rbegin(), a.num.rend(), [&](int i){rst += to_string(i); });
			return rst;
		}
		for (int i = 0, flag = 1; i < a_sz; i++){
			if (flag && i == a_sz - a.point){
				rst += '.';
				i -= 1;
				flag = 0;
				continue;
			}
			rst += to_string(a.num[a_sz - 1 - i]);

		}//还没有去掉小数点后的0

		if (a.point == 0)	return rst;
		//去掉小数点后面的0
		while (*(rst.end() - 1) == '0')	rst.pop_back();
		if (*(rst.end() - 1) == '.')	rst.pop_back();



		return rst;



	}

	N s2N(const string& s){
		N rst;
		int i = 0;
		for_each(s.rbegin(), s.rend(), [&](char c){

			if (c == '.') {
				rst.point = i;

			}
			else{
				rst.num.push_back(c - '0');
			}

			i++;
		});
		return rst;
	}

	string s_pow_cache(string s, int n){
		if (n == 1)	return s;
		if (n == 0)	return "1";
		if (n & 1){//n是奇数
			return s_mul(get_cache(s_pow(s, n / 2)), s);
		}
		else{//偶数
			return get_cache(s_pow(s, n / 2));
		}
	}

	string s_pow(string s, int n){
		
		if (n == 1)	return s;
		if (n == 0)	return "1";
		if (n & 1){//n是奇数
			return s_mul(s_mul(s_pow(s, n / 2), s_pow(s, n / 2)), s);
		}
		else{//偶数
			return s_mul(s_pow(s, n / 2), s_pow(s, n / 2));
		}
	}

};




int main(){
	/*string s;
	int n;
	while (cin >> s >> n){
		double rst = cal(s, n);

		cout << setprecision(20)<<rst << endl;
	}*/
	
	/*N a, b;
	a.num = { 5, 2 };
	b.num = { 5,2 };
	a.point = 1;
	b.point = 1;
	auto c = v_mul(a, b);*/
	int n;
	string s;
	BigCal bc;
	vector<string> rst;
	while (cin >> s >> n){
		rst.push_back(bc.pow(s, n,true));
	}
	copy(rst.begin(), rst.end(), ostream_iterator<string>(cout, "\n"));
	system("pause");
	return 0;
}