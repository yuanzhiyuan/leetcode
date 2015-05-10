#include "h.h"

class Solution {
public:
	int jump(vector<int>& nums) {
		int min_step = nums.size() - 1;
		int cur_step = 0;
		dfs(nums, min_step, cur_step, 0);
		return min_step;
	}

	void dfs(vector<int>& nums, int& min_step, int& cur_step, int pos){
		if (pos + nums[pos] >= nums.size() - 1){
			min_step = min(min_step, cur_step + 1);
			return;
		}
		if (min_step <= cur_step - 1)	return;
		for (int i = 1; i <= nums[pos]; i++){
			dfs(nums, min_step, ++cur_step, i + pos);
		}
	}
};
int main(){
	Solution s;
	vector<int> nums = { 2, 3, 1, 1, 4 };
	int rst = s.jump(nums);
	cout << rst << endl;

	system("pause");
	return 0;
}