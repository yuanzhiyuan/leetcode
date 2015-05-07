class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        unordered_map<int,int>  n_i_map;
        for(auto each:nums){
            n_i_map[each] = 1;
        }
        int i=1;
        for(;;i++){
            if(n_i_map.find(i)==n_i_map.end()) break;
        }
        return i;
    }
};
