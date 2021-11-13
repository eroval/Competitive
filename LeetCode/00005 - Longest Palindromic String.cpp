bool checkPalindrome(string& s, int leftIterator, int rightIterator){
        while(leftIterator<rightIterator){
            if(s[leftIterator]!=s[rightIterator]){
                return false;
            }
            ++leftIterator;
            --rightIterator;
        }
        return true;
    }
    
    string formSubstring(string& s, int& leftIterator, int& rightIterator){
        int steps = rightIterator-leftIterator+1;
        return s.substr(leftIterator, steps);
    }
    
    bool checkSize(string& currentPalindrome, int& leftIterator, int& rightIterator){
        return (rightIterator-leftIterator)+1>currentPalindrome.size();
    }
    
    void findCurrentMaximumPalindrome(string& s, string& currentPalindrome, int& rightIterator){
        for(int leftIterator = 0; leftIterator<rightIterator; ++leftIterator){
            if(checkPalindrome(s, leftIterator, rightIterator)&&checkSize(currentPalindrome,leftIterator, rightIterator)){
                currentPalindrome = formSubstring(s, leftIterator, rightIterator);
            }
        }
    }
    
    string longestPalindrome(string s) {
        
        if(s.empty()){
            return "";
        }
        if(s.size()==1){
            string z = "";
            z+=s[0];
            return z;
        }
        
        string palindrome = "";
        palindrome+=s[0];
        int rightIterator = 1;
        while(rightIterator<s.size()){
            findCurrentMaximumPalindrome(s, palindrome, rightIterator);
            ++rightIterator;
        }
        return palindrome;
    }