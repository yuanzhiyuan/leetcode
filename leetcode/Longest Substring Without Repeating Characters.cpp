class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        const int ASCII_MAX = 127;
        int last[ASCII_MAX];
        int start=0;
        
        fill(last,last+ASCII_MAX,-1);
        
        int max_len=0;
        for(int i=0;i<s.size();i++){
            int cur=s[i]-'\0';
            if(last[cur]>=start){
                if(max_len<i-start)
                    max_len=i-start;
                start=last[cur]+1;
                
                
            }
            last[cur]=i;
            
        }
        return max((int)s.size()-start,max_len);
    }
};
