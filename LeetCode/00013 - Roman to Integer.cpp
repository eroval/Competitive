class Solution {
public:
    int getValue(char& c){
        static std::unordered_map<char, int> values = {
            {'I',    1},    //I, V, X, L, C, D, and M,
            {'V',    5},
            {'X',   10}, 
            {'L',   50},
            {'C',  100},
            {'D',  500},
            {'M', 1000}
        };
        return values[c];
    }
    
    bool transformIfBigger(string& s, int& i, int& sum){
        if(i+1<s.size()){
            if(getValue(s[i])<getValue(s[i+1])){
                sum+=getValue(s[i+1])-getValue(s[i]);
                ++i;
                return true;
            }
            return false;
        }
        return false;
    }
    
    int romanToInt(string s) {
        if(s.empty()) return 0;
        int sum=0;
        for(int i=0; i<s.size(); i++){
            if(!transformIfBigger(s, i, sum)){
                sum+=getValue(s[i]);
            }
        }
        return sum;
    }
};