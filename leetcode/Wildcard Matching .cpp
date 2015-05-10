#include "h.h"


class Solution {
public:
	bool isMatch(string s, string p) {
		auto i = s.begin(), j = p.begin();
		char former = '\0';
		for (; i < s.end()&& j < p.end(); i++, j++){
			if (*j == '*'){
				while (j < p.end() && *j == '*')	j++;
				j--;
			}
			if (*i == *j || *j == '?')  continue;
			if (*j != '?'&&*j != '*')    return false;
			int k = 0;
			for (; i + k<s.end(); k++){
				bool im = isMatch(string(i + k, s.end()), string(j + 1, p.end()));
				if (im)  return true;

			}
			if (k + i == s.end())    return false;


		}
		if (i == s.end()){
			if (j == p.end() || isstar(string(j, p.end())))   return true;
			else return false;
		}
		else{
			return false;
		}

	}

	bool isstar(string& s){
		auto b = find_if(s.begin(), s.end(), [=](char c)->bool{return c != '*'; });
		if (b == s.end())  return true;
		else return false;
	}
};

//int main(){
//	Solution a;
//	string s = "abbaabbbbababaababababbabbbaaaabbbbaaabbbabaabbbbbabbbbabbabbaaabaaaabbbbbbaaabbabbbbababbbaaabbabbabb";
//	string p = "***b**a*a*b***b*a*b*bbb**baa*bba**b**bb***b*a*aab*a**";
//	cout << a.isMatch(s, p) << endl;
//
//
//	/*string a = "12345";
//	string b(a.begin(), a.end()-1);
//	cout << b;*/
//	system("pause");
//	return 0;
//}
