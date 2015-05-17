#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <iterator>
using namespace std;

class Solution{

public:
   void crack(const string& a){
   istringstream iss(a);
  vector<string> b;
   copy(istream_iterator<string>(iss),istream_iterator<string>(),back_inserter(b));
 for(int i=0;i<b.size();i++){
  string each = b[i];
   reverse(each.begin(),each.end());
   kaisa(each,i+1);
cout << each << " ";
}

}

void kaisa(string& a,int b){
for(char& i:a){
i=(i+b)%26;
}

}

};


int main(){

Solution s;
string a;
while(cin >> a){

s.crack(a);
cout << endl;
}
return 0;
}
