class Solution {
public:
    //Normal DFS with mask is too slow.
    //So I went for a reverse approach instead of the bottom commented code
    /*
    bool isOnEdge(int& value, unsigned long size){
        return value<1||value>=size-1;
    }
    
    bool isValid(int i, int j, std::vector<std::vector<char>>& board, char& value){
        if((isOnEdge(i, board.size())||isOnEdge(j, board[i].size()))&&value=='O'){
            return false;
        }
        return true;
    }
    
    void solve(vector<vector<char>>& board) {
        std::vector<std::vector<bool>> visited(board.size(), std::vector<bool>(board[0].size(), false));
        std::vector<std::vector<int>> q;
        
        for(int i=1; i<board.size()-1; i++){
            for(int j=1; j<board[i].size()-1; j++){
                if(board[i][j]=='O'&&!visited[i][j]){
                    q.push_back(std::vector<int>{i, j});
                    visited[i][j]=true;
                    int tmp_i, tmp_j;
                    bool transform=true;
                    for(int k=0; k<q.size(); k++){
                        tmp_i = q[k][0];
                        tmp_j = q[k][1];
                        
                        if(tmp_i-1>=0&&board[tmp_i-1][tmp_j]=='O'&&!visited[tmp_i-1][tmp_j]){
                            if(isValid(tmp_i-1, tmp_j, board, board[tmp_i-1][tmp_j])){
                                q.push_back(std::vector<int>{tmp_i-1,tmp_j});
                                visited[tmp_i-1][tmp_j]=true;
                            }
                            else {
                                transform=false;
                            }
                        }
                        if(tmp_i+1<board.size()&&board[tmp_i+1][tmp_j]=='O'&&!visited[tmp_i+1][tmp_j]){
                            if(isValid(tmp_i+1, tmp_j, board, board[tmp_i+1][tmp_j])){
                                q.push_back(std::vector<int>{tmp_i+1,tmp_j});
                                visited[tmp_i+1][tmp_j]=true;
                            }
                            else {
                                transform=false;
                            }
                        }
                        if(tmp_j+1<board[tmp_i].size()&&board[tmp_i][tmp_j+1]=='O'&&!visited[tmp_i][tmp_j+1]){
                            if(isValid(tmp_i, tmp_j+1, board, board[tmp_i][tmp_j+1])){
                                q.push_back(std::vector<int>{tmp_i,tmp_j+1});
                                visited[tmp_i][tmp_j+1]=true;
                            }
                            else {
                                transform=false;
                            }
                        }
                        if(tmp_j-1>=0&&board[tmp_i][tmp_j-1]=='O'&&!visited[tmp_i][tmp_j-1]){
                            if(isValid(tmp_i, tmp_j-1, board, board[tmp_i][tmp_j-1])){
                                q.push_back(std::vector<int>{tmp_i,tmp_j-1});
                                visited[tmp_i][tmp_j-1]=true;
                            }
                            else {
                                transform=false;
                            }
                        }
                    }
                    if(transform){
                        while(!q.empty()){
                            board[q.front()[0]][q.front()[1]]='X';
                            q.erase(q.begin());
                        }
                    }
                    else {
                        while(!q.empty()){
                            q.erase(q.begin());
                        }
                    }
                }
            }
        }
    }
    */
    
    //Transform The Bounding Neighbours to a T recursively
    //Also I was too lazy to write an iterative version for this
    //(Instead I did simple copy&paste for the second functions)
    void transformEdgeNeighbours(std::vector<std::vector<char>>& board, int i, int j){
        if(i<0||i>=board.size()||j<0||j>=board[i].size()||board[i][j]=='X'||board[i][j]=='T'){
            return;
        }
        board[i][j]='T';
        
        transformEdgeNeighbours(board, i-1, j);
        transformEdgeNeighbours(board, i+1, j);
        transformEdgeNeighbours(board, i, j-1);
        transformEdgeNeighbours(board, i, j+1);
    }
    
    void transformEdges(std::vector<std::vector<char>>& board){
        unsigned long n = board.size()-1;
        unsigned long m = board[0].size()-1;
        
        for(auto j=0; j<=m; j++){
            if(board[0][j]=='O') transformEdgeNeighbours(board, 0, j);
            if(board[n][j]=='O') transformEdgeNeighbours(board, n, j);
        }
        
        for(auto i=1; i<n; i++){
            if(board[i][0]=='O') transformEdgeNeighbours(board, i, 0);
            if(board[i][m]=='O') transformEdgeNeighbours(board, i, m);
        }
    }
    
    //Reverse them back to their normal form
    void revertEdgeNeighbours(std::vector<std::vector<char>>& board, int i, int j){
        if(i<0||i>board.size()-1||j<0||j>=board[i].size()||board[i][j]=='X'||board[i][j]=='O'){
            return;
        }
        
        board[i][j]='O';
        
        revertEdgeNeighbours(board, i-1, j);
        revertEdgeNeighbours(board, i+1, j);
        revertEdgeNeighbours(board, i, j-1);
        revertEdgeNeighbours(board, i, j+1);
    }
    
    void revertEdges(std::vector<std::vector<char>>& board){
        unsigned long n = board.size()-1;
        unsigned long m = board[0].size()-1;
        
        for(auto j=0; j<=m; j++){
            if(board[0][j]=='T') revertEdgeNeighbours(board, 0, j);
            if(board[n][j]=='T') revertEdgeNeighbours(board, n, j);
        }
        
        for(auto i=1; i<n; i++){
            if(board[i][0]=='T') revertEdgeNeighbours(board, i, 0);
            if(board[i][m]=='T') revertEdgeNeighbours(board, i, m);
        }
    }
    
    void solve(vector<vector<char>>& board) {
        transformEdges(board);
        for(int i=0; i<board.size(); i++){
            for(int j=0; j<board[i].size(); j++){
                if(board[i][j]=='O') board[i][j]='X';
            }
        }
        revertEdges(board);
    }
};