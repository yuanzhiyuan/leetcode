#include <string>
#include <vector>
#include <iterator>
using namespace std;
class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> rst;
//        if(words.size()==0) return {0};
        if(s.size()==0) return rst;
        typedef string::iterator siter;
        typedef vector<string>::iterator viter;
        size_t words_len = words.size()*words[0].size();
        size_t word_len = words[0].size();
        for(siter i=s.begin();i!=s.end()-words_len+1;i++){
            siter old_i = i;
            vector<string> old_words = words;
            while(i!=s.end()-word_len+1){
                string cur_word(i,i+word_len);
                viter ve = find_if(words.begin(),words.end(),[&](string& s)->bool{return s.compare(cur_word)==0;});
                if(ve==words.end()) break;
                else{
                    i+=word_len;
                    words.erase(ve);
                }
            }
            if(words.size()==0)  rst.push_back(distance(s.begin(),old_i));
            words = old_words;
            i = old_i;
        }
    }
};

int main(){
	string s= "lingmindraboofooowingdingbarrwingmonkeypoundcake";
	string words_val[] = {"fooo","barr","wing","ding","wing"};
	vector<string> words(words_val,words_val+sizeof(words_val)/sizeof(words_val[0]));
	copy(words.begin(),words.end(),iostream_iterator<string>(cout," "));
	return 0;
}
