class Solution {
public:
    int longestPalindrome(string s) {
        std::unordered_map<char, int> mymap;
        
        for(int i=0; i<s.size(); i++){
            ++mymap[s[i]];
        }
        int maxSum=0;
        bool set=false;
        for(auto x : mymap){
            std::cout<<x.first<<": "<<x.second<<"\n";
            if(x.second%2==0){
                maxSum+=x.second;
            }
            else{
                maxSum+=x.second-1;
                set=true;
            }
        }
        if(set){
            return maxSum+1;
        }
        return maxSum;
    }
};