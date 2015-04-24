class Solution {
public:
    Solution(){
        init_map(roman);
    }
    string intToRoman(int num) {
        typedef map<int,char>::reverse_iterator iter;
        string rst;
        
        for(iter i =roman.rbegin();i!=roman.rend();i++){
        	int rep=0;
            while(num>=i->first){
                num -= i->first;
                rst += i->second;
                rep++;
                if(rep==4) {rst=rst.substr(0,rst.size()-4)+(i)->second+prev(i)->second;}
                if(rst[rst.size()-1]==rst[rst.size()-3]&&rst[rst.size()-1]==prev(i)->second)    rst = rst.substr(0,rst.size()-3)+i->second+prev(prev(i))->second;
            }
            if(num==0)  return rst;
        }
    }
    void print_map() const{
    	typedef map<int,char>::const_iterator iter;
    	for(iter i=roman.begin();i!=roman.end();i++){
    		cout << i->first << " " << i->second << endl;
    	}
    }
private:
    map<int,char> roman;
    void init_map(map<int,char>& roman){
        roman[1]='I';
        roman[5]='V';
        roman[10]='X';
        roman[50]='L';
        roman[100]='C';
        roman[500]='D';
        roman[1000]='M';
        
        
    }
    
};
