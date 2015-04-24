class Solution {
public:
    int romanToInt(string s) {
        typedef pair<char,int> pa;
        const pa init_val[]={
            pa('I',1),
            pa('V',5),
            pa('X',10),
            pa('L',50),
            pa('C',100),
            pa('D',500),
            pa('M',1000)
        };
        const unordered_map<char,int> roman(init_val,init_val+7);
        int rst;
        for(int i=0;i<s.size();i++){
            if(i+1<s.size()&&roman.find(s[i+1])->second>roman.find(s[i])->second) //不能直接用roman[s[i]]否则会报错
                rst-=roman.find(s[i])->second;
            else
                rst+=roman.find(s[i])->second;
        }
        return rst;
    }
};

//或者用inline function 代替hash  速度更快
//http://www.cplusplus.com/articles/2LywvCM9/  有关内联函数(inline function)的解释 
inline int map(const char c) {
switch (c) {
	case 'I': return 1;
	case 'V': return 5;
	case 'X': return 10;
	case 'L': return 50;
	case 'C': return 100;
	case 'D': return 500;
    case 'M': return 1000;
	default: return 0;
	}
} 

