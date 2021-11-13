class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        std::vector<int> outputArr;
        
        for(int i=0; i<nums1.size(); i++){
            int j=0;
            for(; j<nums2.size(); j++){
                if(nums1[i]==nums2[j]){
                    break;
                }
            }
            int val = nums1[i];
            while(j<nums2.size()){
                if(nums2[j]>val){
                    val = nums2[j];
                    break;
                }
                ++j;
            }
            if(val==nums1[i]){
                outputArr.push_back(-1);
            }
            else {
                outputArr.push_back(val);
            }
        }
        
        return outputArr;
    }
};