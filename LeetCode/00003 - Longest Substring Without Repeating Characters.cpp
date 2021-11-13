class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int j;
        int maxSum=0;
        std::unordered_map<char, int> currentMap;
        for(int i=0; i<s.size(); i++){
            ++currentMap[s[i]];
            j=i+1;
            while(j<s.size()){
                ++currentMap[s[j]];
                if(currentMap[s[j]]>1){
                    --currentMap[s[j]];
                    break;
                }
                ++j;
            }
            if(j-i>maxSum){
                maxSum=j-i;
            }
            while(j>i){
                --j;
                currentMap[s[j]]=0;
            }
        }
        return maxSum;
    }
};