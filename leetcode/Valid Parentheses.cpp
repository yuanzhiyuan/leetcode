class Solution {
public:
    bool isValid(string s) {
        string left = "([{";
        string right = ")]}";
        stack<char> my_stack;
        for(char c:s){
            if(left.find(c)!=string::npos){
                my_stack.push(c);
            }else{
                if(my_stack.empty()||my_stack.top()!=left[right.find(c)])
                    return false;
                else
                    my_stack.pop();
            }
        }
        return my_stack.empty();
    }
};
