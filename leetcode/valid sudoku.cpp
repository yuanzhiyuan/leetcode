namespace std {
template<>
struct hash<pair<int, char>> {
size_t operator()(pair<int, char> const& p) const {
return ((size_t) &(p.first)) ^ ((size_t) &(p.second));
}
};
}

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_map<pair<int,char>,int> row;
        unordered_map<pair<int,char>,int> col;
        unordered_map<pair<int,char>,int> grid;
        for(auto row_=board.begin();row_!=board.end();row_++){
            for(auto ele=row_->begin();ele!=row_->end();ele++){
                if(*ele!='.'){
                    auto row_key = make_pair(distance(board.begin(),row_),*ele);
                    if(row.find(row_key)!=row.end())    return false;
                    else    row.insert(make_pair(row_key,1));
                    
                    auto col_key = make_pair(distance(row_->begin(),ele),*ele);
                    if(col.find(col_key)!=col.end())    return false;
                    else    col.insert(make_pair(col_key,1));
                   
                    
                    
                    int grid_ = (distance(board.begin(),row_)/3)*3+distance(row_->begin(),ele)/3;
                    auto grid_key = make_pair(grid_,*ele);
                    if(grid.find(grid_key)!=grid.end()) return false;
                    else    grid.insert(make_pair(grid_key,1));
                }
            }
        }
        return true;
        
    }
    
};
