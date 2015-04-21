class Solution {
public:
    string convert(string s, int nRows) {
        if(nRows==1)	return s;
        int len = s.size();
        int cols = len/2+1;
        int f[nRows][len/2+1];
        string rst;
        fill_n(&f[0][0],nRows*(len/2+1),-1);
        int x=0,y=0;
        for(int i=0;i<len;i++){
            f[x][y] = s[i];
            if(x==nRows-1){
                x -= 1;
                y += 1;
                continue;
            }
            if(y%(nRows-1)==0){
                x += 1;
                continue;
            }
            x -=1;
            y+=1;
        }
        for(int i=0;i<nRows;i++){
            for(int j=0;j<cols;j++){
                if(f[i][j]!=-1){
                    rst += f[i][j];
                }
            }
        }
        return rst;
    }
};
