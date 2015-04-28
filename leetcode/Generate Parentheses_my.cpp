#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;


class Solution {
public:
    vector<string> generateParenthesis(int n) {
		
		
		
		
        vector<string> result;
        result = gen(n);

        return result;
    }
	/*void func0(string& s){
		s = s + "()";
	}
	void func1(string& s){
		s = "()" + s;

	}
	void func2(string& s){
		s = "(" + s + ")";
	}*/
	
    
	/*struct{
		void operator()(string& s,int i){
			switch (i){
			case 0:s = "()" + s; return;
			case 1:s = "(" + s + ")"; return;
			case 2:s = s + "()"; return;
			default:return;
			}
		}
	}func;*/
	/*function object（专门用来代替function pointer）不可行，因为
		1、定义三个函数对象的话，类型不同，不可在一个容器中。
		2、若按照上面定义也不可行，因为for_each第三个参数的函数只能是一个参数*/
	//function object 讲解 : http ://stackoverflow.com/questions/2351437/when-do-you-use-function-objects-in-c


	////用function pointer也不可行。具体原因没搞明白，
		//function pointer讲解：http :stackoverflow.com/questions/252748/how-can-i-use-an-array-of-function-pointers
    vector<string> gen(int n){
        vector<string> rst;
        if(n==1)    {string a("()") ;   rst.push_back(a);return rst;}
        
        vector<string> last = gen(n-1);
        rst.resize(3*last.size());
        for(int i=0;i<3;i++){
            copy(last.begin(),last.end(),rst.begin()+i*last.size());
			if (i==0)
				for_each(rst.begin() + i*last.size(), rst.begin() + (i + 1)*last.size(), [](string& s){s = s + "()"; });
			else if (i==1)
				for_each(rst.begin() + i*last.size(), rst.begin() + (i + 1)*last.size(), [](string& s){s = "()" + s; });
			else
				for_each(rst.begin() + i*last.size(), rst.begin() + (i + 1)*last.size(), [](string& s){s = "("+s + ")"; });
        }
		sort(rst.begin(), rst.end());
		rst.erase(unique(rst.begin(), rst.end()), rst.end());
        return rst;
        
        
    }
};

int main(){
	Solution s;
	vector<string> a = s.generateParenthesis(2);
	for(string s:a){
		cout << s <<endl;
		 
	}
	system("pause");
	return 0;
	
}

