#include <vector>
#include <algorithm>
#include <iterator>
#include <iostream>
#include <functional>
using namespace std;
class Solution {
public:
	void nextPermutation(vector<int> &num) {
		typedef vector<int>::reverse_iterator riter;
		riter rfirst = num.rbegin();
		riter rlast = num.rend();
		riter ri = next(rfirst);

		//for (; ri != num.rend() && *ri >= *prev(ri); ri++);
		//从右向左找，找出第一个违反“递增趋势”的数
		while (ri != rlast&&*ri >= *prev(ri))	ri++;
		//没找到，说明已经是最大的了，就返回最小的
		if (ri == rlast)    { reverse(rfirst, rlast); return; }
		riter first_small = ri;
		//riter first_big = upper_bound(rfirst, first_small, *first_small);
		//从右往左找，找到第一个大于first_small的数，肯定能找到，因为第一步“违反递增趋势”
		riter first_big = find_if(rfirst, first_small, bind1st(less<int>(), *first_small));
		//交换前两部找到的数
		swap(*first_small, *first_big);
		//first_small原来所在的位置的下一个，到结尾，反转
		reverse(rfirst, first_small);

	}
};

int main(){
	Solution s;
	vector<int> num = { 1, 3, 2 };
		/*for (auto i = num.rbegin(); i != num.rend(); i++){
		cout << *i << endl;
	}*/
	
	s.nextPermutation(num);
	copy(num.begin(), num.end(), ostream_iterator<int>(cout, " "));
	system("pause");
}