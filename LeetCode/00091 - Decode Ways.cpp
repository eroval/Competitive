class Solution {
public:
    
    bool isValid(char& a,char& b){
        return a == '1'||(a == '2' && b <='6');
    }
    
    bool isValid(char& a){
        return a != '0';
    }
    
    
    int numDecodings(string& s) {
        int n = s.size();
        if ( n == 0 || s[0] == '0' ) return 0;
        if ( n == 1 ) return 1;
        int sum = 1, lastSum = 1, value;
        for ( int i = 1; i < n; i++ ) {
            value = 0;
            if ( !isValid(s[i]) && !isValid(s[i-1], s[i]) ) return 0;
            if ( isValid(s[i]) ) value = sum;
            if ( isValid(s[i-1], s[i]) ) value += lastSum;
            lastSum = sum;
            sum = value;
        }
        return value;
    }
};