class Solution {
public:
    void printRow(vector<vector<char>>& rowValues){
        for(int i=0; i<rowValues.size(); i++){
            for(int j=0; j<rowValues[i].size(); j++){
                std::cout<<rowValues[i][j]<<" ";
            }
            std::cout<<"\n";
        }
    }
    
    void findValuesForInput(vector<vector<char>>& board, vector<vector<char>>& rowValues, vector<vector<bool>>& mask, int& count){
        char value;
        
        for(int i=0; i<board.size(); i++){
            for(int j=0; j<board.size(); j++){
                value = board[i][j];
                if(value!='.'){
                        mask[i][value-'1']=true;
                        ++count;
                }
            }
            for(int j=0; j<mask.size(); j++){
                if(!mask[i][j]){
                    value = j+'1';
                    rowValues[i].push_back(value);
                }
            }
        }
    }
    
    bool possible(vector<vector<char>>& board, char& value, int& x, int& y){
        int boxStartX;
        int boxStartY;
        int boxStart = x-x%3;
        for(int i=0; i<board.size(); i++){
            boxStartX = x-x%3+i/3;
            boxStartY = y-y%3+i%3;
            if(board[i][y]==value||board[boxStartX][boxStartY]==value){
                return false;
            }
        }
        return true;
    }
    
    bool filled(int& count){
        return count==81;
    }
    
    void solve(vector<vector<char>>& board, vector<vector<char>>& rowValues, vector<vector<bool>>& mask, int& count){
        for(int i=0; i<board.size(); i++){
            for(int j=0; j<board.size(); j++){
                if(board[i][j]=='.'){
                    for(int k=0; k<rowValues[i].size(); k++){
                        char value = rowValues[i][k];
                        if(!mask[i][value-'1']&&possible(board, value, i, j)){
                            board[i][j]=value;
                            mask[i][value-'1']=true;
                            ++count;
                            solve(board, rowValues, mask, count);
                            if(filled(count)){
                                return;
                            }
                            board[i][j]='.';
                            mask[i][value-'1']=false;
                            --count;
                        }
                    }
                    return;
                }
            }
        }
    }
    
    void solveSudoku(vector<vector<char>>& board) {
        vector<vector<char>> rowValues(board.size(), vector<char>());
        vector<vector<bool>> mask(board.size(), vector<bool>(board.size(), false));
        int count=0;
        
        findValuesForInput(board, rowValues, mask, count);
        printRow(rowValues);
        
        
        solve(board, rowValues, mask, count);
    }
};