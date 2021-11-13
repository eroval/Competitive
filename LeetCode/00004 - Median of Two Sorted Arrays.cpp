class Solution {
public:
    
    void printVector(std::vector<int>& arr){
        for(int i=0; i<arr.size(); i++){
            std::cout<<arr[i]<<" ";
        }
        std::cout<<"\n";
    }
    
    std::vector<int> merge(vector<int>& nums1, vector<int>& nums2){
        std::vector<int> merged;
        int leftIterator = 0;
        int rightIterator = 0;
        while(leftIterator<nums1.size()&&rightIterator<nums2.size()){
            if(nums2[rightIterator]<nums1[leftIterator]){
                merged.push_back(nums2[rightIterator]);
                ++rightIterator;    
            }
            else {
                merged.push_back(nums1[leftIterator]);
                ++leftIterator;
            }
        }
        
        while(leftIterator<nums1.size()){
            merged.push_back(nums1[leftIterator]);
            ++leftIterator;
        }
        
        while(rightIterator<nums2.size()){
            merged.push_back(nums2[rightIterator]);
            ++rightIterator;
        }
        
        return merged;
    }
    
    
    
    double findMedian(std::vector<int>& merged){
        if(merged.size()%2==0){
            int medianOne = merged[merged.size()/2-1];
            int medianTwo = merged[merged.size()/2];
            return double(medianOne+medianTwo)/2;
        }
        else{
            return merged[merged.size()/2];
        }
    }
    
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        std::vector<int> merged = merge(nums1, nums2);
        //printVector(merged);
        return findMedian(merged);
    }
};