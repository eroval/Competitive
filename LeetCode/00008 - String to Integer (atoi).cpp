class Solution {
public:
    bool whiteSpace(char& value){
        return value==' '||value=='\n';
    }
    
    bool checkNumber(char& value){
        return value>='0'&&value<='9';
    }
    
    bool sign(char& value){
        return value=='-'||value=='+';
    }
    
    void read(string& s, int& readIterator, string& value, bool& currentNumber){
        while(readIterator<s.length()&&whiteSpace(s[readIterator])){
            ++readIterator;
        }
        
        if(readIterator<s.length()&&sign(s[readIterator])){
            value+=s[readIterator];
            ++readIterator;
        }
        else if(readIterator<s.length()&&checkNumber(s[readIterator])){
            value+="+";
        }
        
        while(s[readIterator]=='0'){
            ++readIterator;
        }
        
        while(readIterator<s.length()&&checkNumber(s[readIterator])){
            currentNumber=true;
            value+=s[readIterator];
            ++readIterator;
        }
    }
    
    bool checkOutsidePositive(int& valueOne, int& valueTwo, bool& outside){
        if(INT_MAX-valueOne<=valueTwo){
            outside=true;
        }
        else outside=false;
        
        return outside;
    }
        
    bool checkOutsideNegative(int& valueOne, int& valueTwo, bool& outside){
        if(INT_MAX-valueOne<=valueTwo-1){
            outside=true;
        }
        else outside=false;
        
        return outside;
    }
    
    bool checkOutside(int& valueOne, int& valueTwo, bool& outside, char sign){
        if(sign=='-'){
            return checkOutsideNegative(valueOne, valueTwo, outside);
        }
        else return checkOutsidePositive(valueOne, valueTwo, outside);
    }
    
    int MaxIfNecessary(string& value, int readIterator){
        if(value[readIterator]=='-'){
            return INT_MIN;
        }
        return INT_MAX;
    }
    
    int transformString(string& value){
        int readIterator=value.length()-1;
        int intValue=0;
        int currentPower=0;
        int tmpValue;
        bool outside=false;
        
        if(value.size()>11){
            return MaxIfNecessary(value, 0);
        }
        
        while(readIterator>0){
            if(value[readIterator]-'0'>2&&currentPower>=9){
                readIterator=0;
                outside=true;
                break;
            }
            tmpValue = (value[readIterator]-'0')*pow(10,currentPower);
            if(checkOutside(intValue, tmpValue, outside, value[0])){
                readIterator=0;
                break;
            }
            intValue+=(value[readIterator]-'0')*pow(10,currentPower);
            ++currentPower;
            --readIterator;
        }
        
        if(outside){
            return MaxIfNecessary(value, 0);
        }
        
        if(value[readIterator]=='-'){
            return -intValue;
        }
        return intValue;
    }
    
    int myAtoi(string s) {
        int readIterator=0;
        bool currentNumber=false;
        string value="";
        read(s, readIterator, value, currentNumber);
        std::cout<<value<<"\n";
        if(!currentNumber){
            return 0;
        }
        else return transformString(value);
    }
};