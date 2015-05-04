class Solution {
public:
    int longestValidParentheses(string s) {
        int max_len=0,last=-1;//position of last unmatched ')'
        stack<int> lefts; //unmatched '('
        for(int i=0;i<s.size();i++){
            if(s[i]=='('){
                lefts.push(i);
            }else{
                if(lefts.empty()){
                    last = i;
                }else{
                    //a valid pair
                    lefts.pop();
                    if(lefts.empty())   max_len = max(max_len,i-last);
                    else    max_len = max(max_len,i-lefts.top());
                }
            }
        }
        return max_len;
    }
};
