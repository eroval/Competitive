class Solution {
public:
    
    void quickSort(vector<int>& nums){
        std::queue<int> bounds;
        long long left, right, start, end;
        long long pivot;
        
        bounds.push(0);
        bounds.push(nums.size()-1);
        
        while(!bounds.empty()){
            start = left = bounds.front();
            bounds.pop();
            end = right = bounds.front();
            bounds.pop();
            pivot = nums[(left+right)/2];
            
            while(left<=right){
                while(nums[left]<pivot){
                    ++left;
                }
                while(nums[right]>pivot){
                    --right;
                }
                
                if(left<=right){
                    std::swap(nums[left], nums[right]);
                    --right;
                    ++left;
                }
            }
            
            if(right>start){
                bounds.push(start);
                bounds.push(right);
            }
            if(left<end){
                bounds.push(left);
                bounds.push(end);
            }
            
        }
    }
    
    vector<int> sortArray(vector<int>& nums) {
        quickSort(nums);
        return nums;
    }
};