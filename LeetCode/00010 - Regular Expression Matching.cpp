
    /*
    void printMatrix(std::vector<std::vector<bool>>& matrix){
        for(int i=0; i<matrix.size(); i++){
            std::cout<<i+1<<": ";
            for(int j=0; j<matrix[i].size(); j++){
                std::cout<<matrix[i][j]<<" ";
            }
            std::cout<<"\n";
        }
    }
    
    void firstRow(std::vector<std::vector<bool>>& matrix, string& p){
        for(int i=2; i<matrix[0].size(); i++){
            if(p[i-1]=='*'){
                matrix[0][i]=matrix[0][i-2];
            }
        }
    }
    
    void process(std::vector<std::vector<bool>>& matrix, string& s, string& p){
        for(int i=1; i<matrix.size(); i++){
            for(int j=1; j<matrix[0].size(); j++){
                if(p[j-1]=='.'||p[j-1]==s[i-1]){
                    matrix[i][j]=matrix[i-1][j-1];
                }
                else if (p[j-1]=='*'){
                    matrix[i][j]=matrix[i][j-2];
                    if(p[j-2]=='.'||p[j-2]==s[i-1]){
                        matrix[i][j] = matrix[i][j]||matrix[i-1][j];
                    }
                }
                else matrix[i][j]=false;
            }
        }
    }
    
    bool isMatch(string& s, string& p) {
        std::vector<std::vector<bool>> matrix(s.size()+1, std::vector<bool>(p.size()+1, false));
        matrix[0][0]=true;
        
        firstRow(matrix, p);
        printMatrix(matrix);
        
        process(matrix, s, p);
        printMatrix(matrix);
        
        return matrix[s.length()][p.length()];
    }
    */
    
    bool isMatch(string& s, string& p) {
        int m = s.size(), n = p.size();
        std::vector<bool> matrix(n+1, false);
        for(int i=0; i<=m; i++){
            bool pre = matrix[0];
            matrix[0]=!i;
            for(int j=1; j<=n; j++){
                bool temp = matrix[j];
                
                if(p[j-1]=='*'){
                    matrix[j] = matrix[j-2]||(i&&matrix[j]&&(s[i-1]==p[j-2]||p[j-2]=='.'));
                }
                else {
                    matrix[j] = i && pre && (s[i-1]==p[j-1]||p[j-1]=='.');
                }
                pre = temp;
            }
        }
        
        return matrix[n];
    }