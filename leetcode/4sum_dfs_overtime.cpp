#include<iostream>
#include<vector>
#include<string> 
#include<numeric>
#include<algorithm>
using namespace std;
class Solution {
public:
	vector<vector<int> > fourSum(vector<int> &num, int target) {
		vector<vector<int> > result;
		if (num.size()<4)    return result;
		if (num.size() == 4)   return accumulate(num.begin(), num.end(), 0) == target ? vector<vector<int> >{num} : result;
		sort(num.begin(), num.end());
		dfs(num, num.begin(), vector<int>(), 0, 0, result, target);
		return result;

	}


	void dfs(const vector<int>& num, vector<int>::iterator trace, vector<int> path, int cur_sum, int depth, vector<vector<int> >& result, int target){
		if (depth == 0){
			for (; trace<num.end() - 3; trace++){
				path.push_back(*trace);


				dfs(num, trace, path, cur_sum + *trace, depth + 1, result, target);
				path.erase(path.end() - 1);
			}
			return;
		}
		
		if (depth == 4){
			if (cur_sum == target){
				result.push_back(path);
				return;
			}
			else{
				return;
			}
		}
		int max_sum = accumulate(num.end() - (4 - depth), num.end(), cur_sum);
		int min_sum = accumulate(next(trace), trace + (5 - depth), cur_sum);
		if (target>max_sum || target<min_sum)  return;
		if (target == max_sum){
			copy(num.end() - (4 - depth), num.end(), back_inserter(path));
			result.push_back(path);
			return;
		}
		if (target == min_sum){
			copy(next(trace), next(trace) + (4 - depth), back_inserter(path));
			result.push_back(path);
			return;
		}
		trace++;
		for (; trace<num.end() - (4-depth); trace++){
			path.push_back(*trace);


			dfs(num, trace, path, cur_sum + *trace, depth + 1, result, target);
			path.erase(path.end() - 1);
		}
		return;
	}
};


int main(){

	Solution s;
	vector<int> num{ 1, 0, -1, 0, -2, 2 };
	int target = 0;

	vector<vector<int> > result = s.fourSum(num, target);
	cout << "[ ";
	for (int i = 0; i<result.size(); i++){
		vector<int> cur = result[i];
		cout << "[";
		for (int j = 0; j<cur.size(); j++){
			cout << cur[j] << ",";
		}
		cout << "]";
	}
	cout << " ]" << endl;
	
	system("pause");

	return 0;
}
