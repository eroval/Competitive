class Solution {
public:
    // key -> [index, second index of finding if it exists]
    vector<int> twoSum(vector<int>& nums, int target) {
        std::map<int, int> values;
        std::map<int, int>::iterator it;
        for(int i=0; i<nums.size(); i++){
            values[nums[i]]=i;
        }
        
        for(int i=0; i<nums.size(); i++){
            it = values.find(target-nums[i]);
            if(it!=values.end()){
                if(it->second!=i){
                    return std::vector<int>{it->second, i};
                }
            }
        }
        return std::vector<int>{-1};
    }
};