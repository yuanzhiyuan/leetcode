#include <string>
#include <vector>
#include <iterator>
#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;
class Solution {
public:
	vector<int> findSubstring(string s, vector<string>& words) {
		vector<int> rst;
		//        if(words.size()==0) return {0};
		if (s.size() == 0) return rst;
		typedef string::iterator siter;
		typedef vector<string>::iterator viter;
		typedef unordered_map<string, int>::iterator miter;
		size_t words_len = words.size()*words[0].size();
		size_t word_len = words[0].size();
		unordered_map<string, int> words_dic;
		for_each(words.begin(), words.end(), [&](string& s){++words_dic[s]; });

		for (siter i = s.begin(); i < s.end() - words_len + 1; i++){
			siter old_i = i;
			unordered_map<string, int> tmp_dic = words_dic;
			while (i != s.end() - word_len + 1){
				string cur_word(i, i + word_len);
				miter ppair = tmp_dic.find(cur_word);
				if (ppair == tmp_dic.end()) break;
				else{
					if (--ppair->second == 0)  tmp_dic.erase(ppair);

					i += word_len;

					if (tmp_dic.size() == 0)	break;
				}
			}
			if (tmp_dic.size() == 0){
				rst.push_back(distance(s.begin(), old_i));
				continue;
			}

			i = old_i;
		}
		return rst;
	}
};
//int main(){
	//string s = "barfoothefoobarman";
	//string words_val[] = { "foo","bar" };
	//vector<string> words(words_val, words_val + sizeof(words_val) / sizeof(words_val[0]));
	////copy(words.begin(), words.end(), ostream_iterator<string>(cout, " "));
	//Solution ss;
	//auto rst= ss.findSubstring(s, words);
	//copy(rst.begin(), rst.end(), ostream_iterator<int>(cout, " "));
	//system("pause");
	//return 0;

	
//}