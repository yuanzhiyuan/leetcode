class Solution {
public:
    bool solveSudoku(vector<vector<char>>& board) {
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(board[i][j]=='.'){
                    for(int k=0;k<9;k++){
                        board[i][j] = '1'+k;
                        if(isValid(board,i,j)&& solveSudoku(board)) return true;  
                        board[i][j] = '.';
                    }
                    return false;
                }
            }
        }
        return true;
    }
private:
    bool isValid(const vector<vector<char>>& board,int x,int y){
        //check xth row
        char target = board[x][y];
        for(int i=0;i<9;i++){
            if(y==i)    continue;
            if(board[x][i]=='.') continue;
            if(board[x][i]==target) return false;
        }
        //check yth col
        for(int i=0;i<9;i++){
            if(x==i)    continue;
            if(board[i][y]=='.')    continue;
            if(board[i][y]==target) return false;
        }
        
        //check grid
        int grid_x = x/3;
        int grid_y = y/3;
        int start_x = grid_x*3;
        int start_y = grid_y*3;
        for(int i=start_x;i<start_x+3;i++){
            for(int j=start_y;j<start_y+3;j++){
                if(i==x&&j==y)  continue;
                if(board[i][j]=='.')    continue;
                if(board[i][j]==target) return false;
            }
        }
        return true;
        
    }
};
