#include <string>
#include <map>
#include <iterator>
#include <algorithm>
#include <iostream>
using namespace std;
typedef string::iterator iter;
namespace std {
	template<>
	struct hash<pair<iter, iter>> {
		size_t operator()(pair<iter, iter> const& p) const {
			return ((size_t)&(*p.first)) ^ ((size_t)&(*p.second));
		}
	};
}

class Solution {
public:
	int longestValidParentheses(string s) {
		cache.clear();
		return longestValidParentheses(s.begin(), s.end());//[m,n)
	}

	int longestValidParentheses(iter first, iter last){
		pair<iter, iter> key = make_pair(first, last);
		map<pair<iter, iter>, int>::iterator pos = cache.find(key);
		if (pos != cache.end())    return pos->second;
		else return cache[key] = makeCache(first, last);
	}

	int makeCache(iter first, iter last){
		int dist = distance(first, last);
		if (dist == 0) return 0;
		if (dist == 1) return 0;
		if (dist == 2) return (*first == '(') && (*next(first) == ')')?2:0;
		int next_go = longestValidParentheses(next(first), prev(last));

		if ((*first == '(') && (*prev(last) == ')')){
			if (next_go == dist - 2) return dist;
			int max_len = 0;
			for (auto j = next(first); j != last; j++){
				max_len = max(max_len,longestValidParentheses(first, j) + longestValidParentheses(j, last));
			}
			return max_len;

			//max(longestValidParentheses(next(first), last), longestValidParentheses(first, prev(last)));
		}
		else if ((*first == ')') && (*prev(last) == ')'))   return longestValidParentheses(next(first), last);
		else if ((*first == '(') && (*prev(last) == '('))    return longestValidParentheses(first, prev(last));
		else    return longestValidParentheses(next(first), prev(last));
	}

private:
	map<pair<iter, iter>, int> cache;

};

int main(){
	Solution s;
	string a = ")()())";
	//string a = "())";
	int rst = s.longestValidParentheses(a);
	cout << rst << endl;
	system("pause");
	return 0;
}