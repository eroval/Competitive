class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int n=9;
        std::vector<std::vector<bool>> row(n, std::vector<bool>(n, false));
        std::vector<std::vector<bool>> col(n, std::vector<bool>(n, false));
        std::vector<std::vector<bool>> box(n, std::vector<bool>(n, false));
        
        int r, c, b;
        int tmp;
        
        for(r=0; r<n; r++){
            for(c=0; c<n; c++){
                tmp = board[r][c]-'1';
                if(tmp>=0&&tmp<=8){
                    b=c/3+(r/3)*3;
                    
                    if(row[r][tmp]||col[c][tmp]||box[b][tmp]){
                        return false;
                    }
                    
                    row[r][tmp]=true;
                    col[c][tmp]=true;
                    box[b][tmp]=true;
                }
            }
        }
        return true;
    }
};