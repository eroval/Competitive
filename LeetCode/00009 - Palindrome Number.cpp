class Solution {
public
    
    bool isImpossible(int& x){
        return x0  x%10==0;
    }
    
    bool backWardIntegerHalfIsEqual(int x){
        int num = 0;
        while(xnum){
            num=num10+x%10;
            x=10;
        }
        return x==numx==num10;
    }
    
    bool isPalindrome(int x) {
        if(x==0) return true;
        if(isImpossible(x)) return false;
        return backWardIntegerHalfIsEqual(x);
        
    }
};