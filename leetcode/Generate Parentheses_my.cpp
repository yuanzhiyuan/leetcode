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
	/*function object��ר����������function pointer�������У���Ϊ
		1������������������Ļ������Ͳ�ͬ��������һ�������С�
		2�����������涨��Ҳ�����У���Ϊfor_each�����������ĺ���ֻ����һ������*/
	//function object ���� : http ://stackoverflow.com/questions/2351437/when-do-you-use-function-objects-in-c


	////��function pointerҲ�����С�����ԭ��û�����ף�
		//function pointer���⣺http :stackoverflow.com/questions/252748/how-can-i-use-an-array-of-function-pointers
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

