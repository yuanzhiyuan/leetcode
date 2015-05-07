#include "h.h"
using namespace std;



class Solution {
public:
	vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
		sort(candidates.begin(), candidates.end());
		vector<int> path;
		vector<vector<int>> rst;
		dfs(candidates, 0, rst, path, target);
		return rst;
	}
	void dfs(vector<int>& candidates, int index, vector<vector<int>>& rst, vector<int>& path, int remain){
		if (remain == 0){
			rst.push_back(path);
			return;
		}
		if (index == candidates.size())  return;
		int pre = -1;
		for (int i = index; i<candidates.size(); i++){
			if (pre == candidates[i]) continue;

			if (remain >= candidates[i]){
				path.push_back(candidates[i]);
				dfs(candidates, i + 1, rst, path, remain - candidates[i]);
				path.pop_back();
			}
			else{
				return;
			}
			pre = candidates[i];
		}

	}
};

int main(){
	Solution s;
	vector<int> can = { 1, 2 };
	vector<vector<int>> rst=s.combinationSum2(can,2);
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