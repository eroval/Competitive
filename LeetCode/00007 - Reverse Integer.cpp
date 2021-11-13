class Solution {
public:
    
    bool checkOverflow(int& addition, int& res, int& x){
        if(x>0&&INT_MAX-addition<res) return true;
        if(x<0&&INT_MIN-addition>res) return true;
        return false;
    }
    
    bool checkInitialOverflow(int& x, int& power){
        if(power==1000000000&&x%10>2){
            return true;
        }
        return false;
    }
    
    int reverse(int x) {
        if(x==0||x==INT_MIN){return 0;}
        int result = 0;
        int addition;  
        int power=pow(10, (int)log10(abs(x)));
        
        if(checkInitialOverflow(x, power)){
            return 0;
        }
        
        while(abs(x)>0){
            addition = x%10*power;
            
            if(checkOverflow(addition, result, x)){
                return 0;
            }
            
            result += addition;
            power/=10;
            x/=10;
        }
        
        return result;
    }
};