class Solution {
public:
	vector<vector<int>> fourSum(vector<int>& num, int target) {
		vector<vector<int>> result;
		if (num.size() < 4) return result;
		sort(num.begin(), num.end());
		unordered_multimap<int, pair<int, int>> cache;
		for (int i = 0; i + 1 < num.size(); ++i)
			for (int j = i + 1; j < num.size(); ++j)
				cache.insert(make_pair(num[i] + num[j], make_pair(i, j)));
		for (auto i = cache.begin(); i != cache.end(); ++i) {
			int x = target - i->first;
			auto range = cache.equal_range(x);
			for (auto j = range.first; j != range.second; ++j) {
			auto a = i->second.first;
			auto b = i->second.second;
			auto c = j->second.first;
			auto d = j->second.second;
			if (a != c && a != d && b != c && b != d) {
				vector<int> vec = { num[a], num[b], num[c], num[d] };
				sort(vec.begin(), vec.end());
				result.push_back(vec);
				}
			}
		}
		sort(result.begin(), result.end());
		result.erase(unique(result.begin(), result.end()), result.end());
		//unique用法：http://www.cnblogs.com/heyonggang/archive/2013/08/07/3243477.html.
		//unique本身不删除元素，只是把重复元素挪到容器最后，然后返回最后一个不重复元素，然后自己删
		//用unique之前一般先排序 
		return result;
	}
};

//用multimap把每两个组合的和哈希
//会超时 
