#include "head.h"
using namespace std;

class Solution {
public:
    string countAndSay(int n) {
        if(n==0)    return "";
        if(n==1)    return "1";
        string pre = countAndSay(n-1);
        string rst;
        for(auto cur = pre.begin();cur!=pre.end();cur++){
            auto rep = next(cur);
            while(rep!=pre.end()&&*rep==*(prev(rep)))   rep++;
            int nrep = distance(cur,rep);
            rst += to_string(nrep)+*cur;
            cur = prev(rep);
        }
        return rst;
    }
};


