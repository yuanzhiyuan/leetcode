class Solution {
public:
    int myAtoi(string str) {
        if(str=="") return 0;
        int i=0,sum=0;
        // int n_neg_sign=0;
        int len = str.size();
        bool sign;
        for(;i<len&&isspace(str[i]);i++);
        // for(;i<len&&(str[i]=='-'||str[i]=='+');i++){
        //     if(str[i]=='-') n_neg_sign++;
        // }
        // sign = n_neg_sign%2?false:true;
        if(str[i]=='-'){
            sign=false;
            i++;
            if(!isdigit(str[i])) return 0;
        }else if(str[i]=='+'){
            sign = true;
            i++;
            if(!isdigit(str[i])) return 0;
        }
        else{
            sign=true;
        }
        int i_bef = i;
        for(;i<len&&isdigit(str[i]);i++){
            // if(sum>214748364){
            //     sum = sign?2147483647:2147483648;
            //     break;
            // }
            // if(sum==214748364)
            sum=sum*10+(str[i]-'0');
        }
        int i_aft = i;
        int dig_len = i_aft-i_bef;
        if(dig_len>10) sum = sign?2147483647:2147483648;
        if(dig_len==10){
            if(myAtoi(str.substr(i_bef,dig_len-1))>214748364)   sum = sign?2147483647:2147483648;
            else if(myAtoi(str.substr(i_bef,dig_len-1))==214748364){
                if(sign&&(str[i_aft-1]-'0'>7)) return 2147483647;
                else if(!sign&&(str[i_aft-1]-'0'>8)) return -2147483648;
                
            }
        } 
        if(sum<0) sum = sign?2147483647:2147483648;
        return sign?sum:sum*(-1);
    }
    bool isdigit(char c){
        if(c>='0'&&c<='9') return true;
        return false;
    }
};
