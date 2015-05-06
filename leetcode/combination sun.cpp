#include "h.h"
using namespace std;


class Solution {
public:
	typedef vector<int>::iterator iter;
	vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
		sort(candidates.begin(), candidates.end());
		vector<vector<int>> rst;
		vector<int> path;
		dfs(candidates, candidates.begin(), path, 0, target, rst);
		return rst;
	}
	void dfs(vector<int>& candidates, vector<int>::iterator start, vector<int>& path, int sum, int target, vector<vector<int>>& rst){
		if (sum == target){
			rst.push_back(path);
			return;
		}

		for (auto i = start; i != candidates.end(); i++){
			if (*i + sum>target)   return;
			else{
				path.push_back(*i);
				sum += *i;
				dfs(candidates, i, path, sum, target, rst);
				path.erase(path.end()-1);;
				sum -= *i;

			}
		}
	}


};

int main(){
	Solution s;
	vector<int> can = { 1 };
	auto rst = s.combinationSum(can, 1);
	cout << "[ ";
	for (auto a : rst){
		cout << "[ ";
		for (auto b : a){
			cout << b << ",";
		}
		cout << " ]";
	}
	cout << " ]";
	system("pause");
}