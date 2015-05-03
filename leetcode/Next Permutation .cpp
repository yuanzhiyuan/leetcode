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
		//���������ң��ҳ���һ��Υ�����������ơ�����
		while (ri != rlast&&*ri >= *prev(ri))	ri++;
		//û�ҵ���˵���Ѿ��������ˣ��ͷ�����С��
		if (ri == rlast)    { reverse(rfirst, rlast); return; }
		riter first_small = ri;
		//riter first_big = upper_bound(rfirst, first_small, *first_small);
		//���������ң��ҵ���һ������first_small�������϶����ҵ�����Ϊ��һ����Υ���������ơ�
		riter first_big = find_if(rfirst, first_small, bind1st(less<int>(), *first_small));
		//����ǰ�����ҵ�����
		swap(*first_small, *first_big);
		//first_smallԭ�����ڵ�λ�õ���һ��������β����ת
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