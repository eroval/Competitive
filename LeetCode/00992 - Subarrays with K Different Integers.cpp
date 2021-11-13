class Solution {
public:
      int subarraysWithKDistinct(vector<int>& nums, int k) {
        std::unordered_map<int, int> keys;
        std::unordered_map<int, int>::iterator it;
        int maxSum = 0;
        int start = 0;
        int right = 0;
        int tmp=0;
        for(;right<nums.size(); ++right){
            ++keys[nums[right]];
            
            while(keys.size()>k){
                it = keys.find(nums[start]);
                if(--it->second==0){
                    keys.erase(it);
                }
                ++start;
                tmp=0;
            }
            if(keys.size()==k){
                while(start<right){
                    if(keys[nums[start]]>1){
                        --keys[nums[start]];
                    }
                    else{
                        break;
                    }
                    ++start;
                    ++tmp;
                }
                maxSum+=(1+tmp);
            }
        }
        return maxSum;
    }   
};