class Solution {
public:
    string getRomanValue(int value){
        static std::unordered_map<int, string> values = {
            {1,    "I"},    //I, V, X, L, C, D, and M,
            {5,    "V"},
            {10,   "X"}, 
            {50,   "L"},
            {100,  "C"},
            {500,  "D"},
            {1000, "M"}
        };
        
        return values[value];
    }
    
    void transform(string& roman, int& normalValue, int number){
        if(number!=0){
            //std::cout<<number<<"\n";
            if(number==9){
                if(normalValue==1){
                    roman+="IX";
                }
                else {
                    roman+=getRomanValue(normalValue)+getRomanValue(normalValue*10);
                }
            }
            else if (number==4){
                if(normalValue==1){
                    roman+="IV";
                }
                else {
                    roman+=getRomanValue(normalValue)+getRomanValue(normalValue*5);
                }
            }
            else {
                if(number<5){
                    while(number>0){
                        roman+=getRomanValue(normalValue);
                        --number;
                    }
                }
                else {
                    roman+=getRomanValue(normalValue*5);
                    while(number-5>0){
                        roman+=getRomanValue(normalValue);
                        --number;
                    }
                }
            }
        }
    }
    
    
    string intToRoman(int num) {
        string roman="";
        unsigned short size = log10(num)+1;
        int normalValue = pow(10, size-1);
        while(size>0){
            transform(roman, normalValue, num/normalValue%10);
            --size;
            normalValue/=10;
        }
        return roman;
    }
};