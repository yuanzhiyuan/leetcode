#include <iostream>
#include <string>
#include <algorithm> 
using namespace std;
class Solution {
public:
    int strStr(string haystack, string needle) {
        size_t haystack_sz = haystack.size();
        size_t needle_sz = needle.size();
        if(haystack_sz<needle_sz)   return -1;
        if(haystack_sz==needle_sz)  return haystack.compare(needle)==0?0:-1;
        typedef string::iterator iter;
        iter p_advance = haystack.begin();
        iter p = haystack.begin();
        p_advance = p+needle_sz-1;
        
        for(;p_advance!=haystack.end();p_advance++){
            iter q = needle.begin();
            iter old_p = p;
            int a = p-haystack.begin() ;
            int b = q-needle.begin(); 
            while(q!=needle.end()&&*p==*q){
            	
            	
                q++;
                p++;
            }
            if(q==needle.end()) return distance(haystack.begin(),old_p);
            p = old_p+1;
        }
        return -1;
    }
};

int main(){
	Solution s;
	int rst = s.strStr("aaa","a");
	cout << rst << endl;
	return 0;
}
