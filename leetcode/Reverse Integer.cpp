class Solution {
public:
    int reverse(int x) {
        if(x==-2147483648) return 0;
        bool sign=(x>=0)?true:false;
        x = sign?x:-x;
        int rst=0;
        do{
            if(x/10==0&&x!=0){
                if(rst>214748364)   return 0;
                else if(sign&&rst==214748364&&x%10>7) return 0;
                else if(!sign&&rst==214748364&&x%10>8)  return 0;
                    
                
            }
            rst=x%10+rst*10;
        }while((x/=10));
        return sign?rst:rst*(-1);
    }
};
