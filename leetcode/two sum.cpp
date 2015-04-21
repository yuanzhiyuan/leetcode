class Solution {
public:
    vector<int> twoSum(vector<int> &number, int target) {
        
        unordered_map<int,int> mapping;
        vector<int> result;
        for(int i=0;i<number.size();i++){
            mapping[number[i]] = i;
        }
        for(int i=0;i<number.size();i++){
            int gap = target-number[i];
            if(mapping.find(gap)!=mapping.end()&&mapping[gap]!=i){
                int result1=i+1;
                int result2=mapping[gap]+1;
                
                result.push_back(result1>result2?result2:result1);
                result.push_back(result1>result2?result1:result2);
            }
        }
        return result;
    }
};
