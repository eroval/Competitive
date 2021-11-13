class Solution {
public:
    
    std::string stackWords(int& left, int& right, vector<string>& words, int& currentLength, int& maxWidth){
        int numberOfWords = right-left-1;
        if(numberOfWords==0){
            currentLength=words[right].length();
            return lastLine(left, right, words, maxWidth);
        }
        
        std::string line="";
        int differenceSpaces = maxWidth-currentLength;
        int evenSpaces = differenceSpaces/numberOfWords;
        int unevenSpaces = differenceSpaces%numberOfWords;
        while(left<right-1){
            line+=words[left]+" ";
            for(int i=0; i<evenSpaces; i++){
                line+=" ";
            }
            if(unevenSpaces>0){
                line+=" ";
                --unevenSpaces;
            }
            ++left;
        }
        line+=words[left];
        ++left;
        currentLength=words[left].length();
        return line;
    }
    
    std::string lastLine(int& left, int& right, vector<string>& words, int& maxWidth){
        std::string line="";
        while(left<right-1){
            line+=words[left]+" ";
            ++left;
        }
        line+=words[left];
        while(line.length()<maxWidth){
            line+=" ";
        }
        ++left;
        return line;
    }
    
    
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> fullList;
        int currentLength=-1;
        int left=0;
        int right=0;
        while(right<words.size()){
            if(currentLength+words[right].length()+1>maxWidth){
                fullList.push_back(stackWords(left, right, words, currentLength, maxWidth));
            }
            else{
                currentLength+=words[right].length()+1;
            }
            ++right;
        }
        fullList.push_back(lastLine(left, right, words, maxWidth));
        return fullList;
    }
};