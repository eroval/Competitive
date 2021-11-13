class Solution {
public:
    int threeSumClosest(vector<int>& nums, int& target) {
        std::sort(nums.begin(), nums.end());
        int absDiff=INT_MAX;
        int Sum=-1;
        int sz = nums.size();
        int leftIterator;
        int rightIterator;
        for(int i=0; i<sz-2; i++){
            leftIterator = i+1;
            rightIterator = sz-1;
            while(leftIterator<rightIterator){
                if(nums[i]+nums[leftIterator]+nums[rightIterator]==target){
                    return target;
                }
                if(abs(target-(nums[i]+nums[leftIterator]+nums[rightIterator]))<absDiff){
                    absDiff = abs(target-(nums[i]+nums[leftIterator]+nums[rightIterator]));
                    Sum= nums[i]+nums[leftIterator]+nums[rightIterator];
                }
                
                if(target>(nums[i]+nums[leftIterator]+nums[rightIterator])){
                    ++leftIterator;
                }
                else{
                    --rightIterator;
                }
            }
        }
        return Sum;
    }
};