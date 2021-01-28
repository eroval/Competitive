#include <bits/stdc++.h>

using namespace std;

// Complete the organizingContainers function below.
string organizingContainers(vector<vector<int>> container) {
    int szxy=container.size();
    
    int* balls=new int[szxy]{}; 
    int* containerSz=new int[szxy]{};
    
    
    for(int i=0; i<szxy; i++){
        for(int j=0; j<szxy; j++){
            balls[j]+=container[i][j];
            containerSz[i]+=container[i][j];         
        }
    }
    
    bool* checked=new bool[szxy]{};
    for(int i=0; i<szxy; i++){
        bool flag=false;
        for(int j=0; j<szxy; j++){
            if(balls[i]==containerSz[j]&&!checked[j]){
                flag=true;
            }            
        }
        if(!flag){
            return "Impossible";
        }        
    }
    
    return "Possible";
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int q;
    cin >> q;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int q_itr = 0; q_itr < q; q_itr++) {
        int n;
        cin >> n;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        vector<vector<int>> container(n);
        for (int i = 0; i < n; i++) {
            container[i].resize(n);

            for (int j = 0; j < n; j++) {
                cin >> container[i][j];
            }

            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        string result = organizingContainers(container);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}
